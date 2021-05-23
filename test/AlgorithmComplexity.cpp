//
// Created by nunoa on 21/05/21.
//

#include <gtest/gtest.h>
#include <chrono>
#include <random>
#include <fstream>

#include "algorithm/TravelingSalesman.h"
#include "algorithm/NearestNeighbour.h"
#include "algorithm/Pathfinding.h"
#include "src/utils/algorithm/MinimumSpanningTrees.h"

/// TESTS ///

#define GRAPH_SIZE 120
#define PATH_NODE_MAX 1000
#define PATH_NODE_INC 6
#define SAMPLES 32
#define PATH_SAMPLES 200
#define MIN_POS -10000
#define MAX_POS 10000
#define BASE_RADIUS ((MAX_POS)*2)
#define BASE_NODES 1000
#define BASE_EDGES 1000
#define PARK_PERCENTAGE 20
#define EDGES_PER_NODE 3

Graph<int> genRandomGraph(size_t graph_size) {
    std::uniform_real_distribution<double> distrib(MIN_POS, MAX_POS);
    std::random_device rd;

    double a = rd() ^(std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count());
    std::mt19937 rng(a);

    Graph<int> graph;

    for (size_t j = 0; j < graph_size; j++) {
        graph.addNode(j, j, Position(GRID, distrib(rng), distrib(rng)));
    }

    return graph;
}

Graph<NodeInfo> genRandomGraphInfo(size_t graph_size, size_t edge_num) {
    std::uniform_real_distribution<double> distrib(MIN_POS, MAX_POS);
    std::uniform_real_distribution<double> parkDistrib(0, 100);
    std::uniform_int_distribution<int> edgeDistrib(0, graph_size - 1);

    std::random_device rd;

    double a = rd() ^(std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count());
    std::mt19937 rng(a);

    Graph<NodeInfo> graph;

    for (size_t j = 0; j < graph_size; j++) {
        NodeInfo info;

        info.setCurrentCapacity(parkDistrib(rng));
        if (parkDistrib(rng) < 100 - PARK_PERCENTAGE) info.setType(NodeType::NORMAL);
        else {
            info.setType(NodeType::PARK);
        }
        info.setMaxCapacity(info.getCurrentCapacity() + parkDistrib(rng));
        info.setPriceFunction([](int, int, int) { return (double) 10; });

        graph.addNode(j, info, Position(GRID, distrib(rng), distrib(rng)));
    }

    for(size_t i = 0; i < graph_size; i++) {
        for(size_t j = 0; j < edge_num; j++) {
            graph.addEdge(i, edgeDistrib(rng), parkDistrib(rng));
        }
    }

    return graph;
}

double compareNodes(const Graph<int> &graph, const std::vector<int> &expected, const std::vector<int> &actual) {
    double distanceExpected = 0;
    double distanceActual = 0;

    for (size_t i = 0; i < expected.size() - 1; i++) {
        distanceExpected += Distances::getEuclideanDistance(graph.findNode(expected.at(i))->getPos(),
                                                            graph.findNode(expected.at(i + 1))->getPos());

        distanceActual += Distances::getEuclideanDistance(graph.findNode(actual.at(i))->getPos(),
                                                          graph.findNode(actual.at(i + 1))->getPos());
    }

    return (double) distanceExpected / distanceActual;
}

TEST(ComplexityTest, tspAlgos) {
    Graph<int> graph;

    std::ofstream file;

    file.open("results.csv");

    file << "GRAPH SIZE,BRUTE FORCE TIME,MST TIME,MST CORRECT,NEAREST TIME,NEAREST CORRECT\n" << std::flush;

    std::vector<int> bruteResult;
    std::vector<int> mstResult;
    std::vector<int> nearestResult;
    bool calcBrute;
    double sum_mst_correctness, sum_nearest_correctness;
    std::chrono::duration<double, std::milli> sum_mst_time(
            0), sum_nearest_time(0), sum_brute_time(0);

    for (size_t i = 2; i <= GRAPH_SIZE; i++) {
        sum_mst_correctness = sum_nearest_correctness = 0;
        sum_mst_time = sum_nearest_time = sum_brute_time = std::chrono::duration<double, std::milli>(0);
        calcBrute = i <= 12;

        for (size_t sample = 0; sample < SAMPLES; sample++) {
            graph.freeGraph();
            graph = genRandomGraph(i);

            Node<int> *origin = graph.findNode(0);
            Node<int> *destination = graph.findNode(i - 1);

            std::vector<Node<int> *> nodeSet = graph.getNodeSet();

            std::vector<Node<int> *> poi = std::vector<Node<int> *>(nodeSet.begin() + 1, nodeSet.end() - 1);

            auto t1 = std::chrono::high_resolution_clock::now();
            mstResult = MinimumSpanningTrees<int>::calculateTreeKruskal(poi, origin, destination);
            auto t2 = std::chrono::high_resolution_clock::now();

            sum_mst_time += t2 - t1;

            t1 = std::chrono::high_resolution_clock::now();
            nearestResult = NearestNeighbour<int>::getTour(poi, origin, destination);
            t2 = std::chrono::high_resolution_clock::now();

            sum_nearest_time += t2 - t1;

            bruteResult.clear();

            if (calcBrute) {
                t1 = std::chrono::high_resolution_clock::now();
                bruteResult = TravelingSalesman<int>::bruteForce(poi, origin, destination);
                t2 = std::chrono::high_resolution_clock::now();

                sum_brute_time += (t2 - t1);

                sum_mst_correctness += compareNodes(graph, bruteResult, mstResult);
                sum_nearest_correctness += compareNodes(graph, bruteResult, nearestResult);
            }
        }

        file << i - 2 << ",";

        if (calcBrute) file << sum_brute_time.count() / SAMPLES;
        file << "," << sum_mst_time.count() / SAMPLES << ",";
        if (calcBrute) file << sum_mst_correctness / SAMPLES;
        file << "," << sum_nearest_time.count() / SAMPLES << ",";
        if (calcBrute) file << sum_nearest_correctness / SAMPLES;
        file << "\n" << std::flush;
    }

    file.close();
}

TEST(ComplexityTest, pathfinding) {
    Graph <NodeInfo> graph;
    return;
    std::ofstream file;

    file.open("resultspath.csv");

    file << "NODE SIZE,DIJKSTRA TIME,DIJ IT,ASTAR TIME,AST IT\n" << std::flush;

    std::vector<Node < NodeInfo>*> parks;
    std::chrono::duration<double, std::milli> sum_dijkstra_time(0),
    sum_astar_time(0);

    for (size_t i = 2; i <= PATH_NODE_MAX; i += PATH_NODE_INC) {
        sum_dijkstra_time = std::chrono::duration<double, std::milli>(0);
        sum_astar_time = std::chrono::duration<double, std::milli>(0);

        for (size_t sample = 0; sample < PATH_SAMPLES; sample++) {
            // INCREMENTING NODES
            graph = genRandomGraphInfo(i, EDGES_PER_NODE);
            parks.clear();

            auto t1 = std::chrono::high_resolution_clock::now();
            Pathfinding::dijkstraAdaptation<NodeInfo>(graph, parks, 0, BASE_RADIUS);
            auto t2 = std::chrono::high_resolution_clock::now();

            sum_dijkstra_time += t2 - t1;

            graph.freeGraph();
            graph = genRandomGraphInfo(i, EDGES_PER_NODE);

            t1 = std::chrono::high_resolution_clock::now();
            Pathfinding::aStarAdaptation<NodeInfo>(graph, 0, i-1);
            t2 = std::chrono::high_resolution_clock::now();

            sum_astar_time += t2 - t1;
            graph.freeGraph();
//            // INCREMENTING EDGES
//            graph = genRandomGraphInfo(BASE_NODES, i);
//            parks.clear();
//
//            t1 = std::chrono::high_resolution_clock::now();
//            Pathfinding::dijkstraAdaptation<NodeInfo>(graph, parks, 0, BASE_RADIUS);
//            t2 = std::chrono::high_resolution_clock::now();
//
//            sum_dijkstra_edges_time += t2 - t1;
//            graph.freeGraph();
//
//            // INCREMENTING EDGES/NODES
//            graph = genRandomGraphInfo(i, i);
//            parks.clear();
//
//            t1 = std::chrono::high_resolution_clock::now();
//            Pathfinding::dijkstraAdaptation<NodeInfo>(graph, parks, 0, BASE_RADIUS);
//            t2 = std::chrono::high_resolution_clock::now();
//
//            sum_dijkstra_edges_nodes_time += t2 - t1;
//            graph.freeGraph();


            // KEEP EDGES PER NODE ALWAYS THE SAME

        }

        file << i;
        file << "," << sum_dijkstra_time.count() / PATH_SAMPLES;
        file << "," << sum_astar_time.count() / PATH_SAMPLES;
        file << "\n" << std::flush;
    }

    file.close();
}

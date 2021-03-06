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

#define GRAPH_SIZE 256
#define PATH_NODE_MAX 1024
#define PATH_NODE_INC 8
#define SAMPLES 32
#define PATH_SAMPLES 256
#define PARK_PERCENTAGE 20
#define EDGES_PER_NODE 4

Graph<int> genRandomGraph(size_t graph_size) {
    std::uniform_real_distribution<double> latDistr(-90, 90);
    std::uniform_real_distribution<double> longDistr(-180, 180);
    std::random_device rd;

    double a = rd() ^(std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count());
    std::mt19937 rng(a);

    Graph<int> graph;

    for (size_t j = 0; j < graph_size; j++) {
        graph.addNode(j, j, Position(COORDS, latDistr(rng), longDistr(rng)));
    }

    return graph;
}

Graph<NodeInfo> genRandomGraphInfo(size_t graph_size, size_t edge_num) {
    std::uniform_real_distribution<double> latDistr(-90, 90);
    std::uniform_real_distribution<double> longDistr(-180, 180);
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

        graph.addNode(j, info, Position(COORDS, latDistr(rng), longDistr(rng)));
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

double getDistance(const Graph<int> &graph, const std::vector<int> &actual) {
    double distanceActual = 0;

    for (size_t i = 0; i < actual.size() - 1; i++) {
        distanceActual += Distances::getEuclideanDistance(graph.findNode(actual.at(i))->getPos(),
                                                          graph.findNode(actual.at(i + 1))->getPos());
    }

    return distanceActual;
}

TEST(ComplexityTest, tspAlgos) {
    Graph<int> graph;

    std::ofstream file;

    file.open("results.csv");

    file << "GRAPH SIZE,BRUTE FORCE TIME,BRUTE FORCE MEDIAN,MST TIME,MST MEDIAN,MST CORRECT,NEAREST TIME,NEAREST MEDIAN,NEAREST CORRECT\n" << std::flush;

    std::vector<int> bruteResult;
    std::vector<int> mstResult;
    std::vector<int> nearestResult;
    bool calcBrute;
    double sum_mst_correctness, sum_nearest_correctness;
    std::chrono::duration<double, std::milli> sum_mst_time(
            0), sum_nearest_time(0), sum_brute_time(0);
    std::vector<double> bruteForceDurations;
    bruteForceDurations.reserve(SAMPLES);
    std::vector<double>mstDurations;
    mstDurations.reserve(SAMPLES);
    std::vector<double>nearestDurations;
    nearestDurations.reserve(SAMPLES);

    for (size_t i = 2; i <= GRAPH_SIZE; i++) {
        sum_mst_correctness = sum_nearest_correctness = 0;
        sum_mst_time = std::chrono::duration<double, std::milli>(0);
        sum_nearest_time = std::chrono::duration<double, std::milli>(0);
        sum_brute_time = std::chrono::duration<double, std::milli>(0);
        nearestDurations.clear();
        mstDurations.clear();
        bruteForceDurations.clear();
        calcBrute = i <= 12;

        for (size_t sample = 0; sample < SAMPLES; sample++) {
            graph.freeGraph();
            graph = genRandomGraph(i);

            Node<int> *origin = graph.findNode(0);
            Node<int> *destination = graph.findNode(i - 1);

            auto nodeMap = graph.getNodeSet();

            std::vector<Node<int> *> nodeSet;

            for(auto it = nodeMap.begin(); it != nodeMap.end(); it++) {
                nodeSet.push_back(it->second);
            }

            std::vector<Node<int> *> poi = std::vector<Node<int> *>(nodeSet.begin() + 1, nodeSet.end() - 1);

            auto t1 = std::chrono::high_resolution_clock::now();
            mstResult = MinimumSpanningTrees<int>::calculateTreeKruskal(poi, origin, destination);
            auto t2 = std::chrono::high_resolution_clock::now();

            sum_mst_time += t2 - t1;
            mstDurations.push_back(((std::chrono::duration<double, std::milli>) (t2-t1)).count());

            t1 = std::chrono::high_resolution_clock::now();
            nearestResult = NearestNeighbour<int>::getTour(poi, origin, destination);
            t2 = std::chrono::high_resolution_clock::now();

            sum_nearest_time += t2 - t1;
            nearestDurations.push_back(((std::chrono::duration<double, std::milli>) (t2-t1)).count());


            bruteResult.clear();

            if (calcBrute) {
                t1 = std::chrono::high_resolution_clock::now();
                bruteResult = TravelingSalesman<int>::bruteForce(poi, origin, destination);
                t2 = std::chrono::high_resolution_clock::now();

                sum_brute_time += (t2 - t1);
                bruteForceDurations.push_back(((std::chrono::duration<double, std::milli>) (t2-t1)).count());

                sum_mst_correctness += compareNodes(graph, bruteResult, mstResult);
                sum_nearest_correctness += compareNodes(graph, bruteResult, nearestResult);
            } else {
                sum_mst_correctness += getDistance(graph, mstResult);
                sum_nearest_correctness += getDistance(graph, nearestResult);
            }
        }

        file << i - 2 << ",";

        if(calcBrute) {
            file << sum_brute_time.count() / SAMPLES;
            if(bruteForceDurations.size()%2==0) {
                file << "," << (bruteForceDurations[bruteForceDurations.size()/2] + bruteForceDurations[bruteForceDurations.size()/2 - 1])/2;
            } else {
                file << "," << (bruteForceDurations[bruteForceDurations.size()/2]);
            }
        } else {
            file << ",";
        }
        file << "," << sum_mst_time.count() / SAMPLES;
        if(mstDurations.size()%2==0) {
            file << "," << (mstDurations[mstDurations.size()/2] + mstDurations[mstDurations.size()/2 - 1])/2;
        } else {
            file << "," << (mstDurations[mstDurations.size()/2]);
        }
        file << "," << sum_mst_correctness / SAMPLES;
        file << "," << sum_nearest_time.count() / SAMPLES;
        if(nearestDurations.size()%2==0) {
            file << "," << (nearestDurations[nearestDurations.size()/2] + nearestDurations[nearestDurations.size()/2 - 1])/2;
        } else {
            file << "," << (nearestDurations[nearestDurations.size()/2]);
        }
        file << "," << sum_nearest_correctness / SAMPLES;
        file << "\n" << std::flush;
    }

    file.close();
}

TEST(ComplexityTest, indivBrute) {
    auto graph = genRandomGraph(13);

    Node<int> *origin = graph.findNode(0);
    Node<int> *destination = graph.findNode(13 - 1);

    auto nodeMap = graph.getNodeSet();

    std::vector<Node<int> *> nodeSet;

    for(auto it = nodeMap.begin(); it != nodeMap.end(); it++) {
        nodeSet.push_back(it->second);
    }

    std::vector<Node<int> *> poi = std::vector<Node<int> *>(nodeSet.begin() + 1, nodeSet.end() - 1);

    auto t1 = std::chrono::high_resolution_clock::now();
    TravelingSalesman<int>::bruteForce(poi, origin, destination);
    auto t2 = std::chrono::high_resolution_clock::now();

    std::cout << (t2-t1).count() << std::endl;
}

TEST(ComplexityTest, pathfinding) {
    Graph <NodeInfo> graph;
    std::ofstream file;

    file.open("resultspath.csv");

    file << "NODE SIZE,DIJKSTRA TIME,DIJKSTRA MEDIAN,DIJKSTRA IT,ASTAR TIME,ASTAR MEDIAN,ASTAR IT\n" << std::flush;

    std::vector<Node < NodeInfo>*> parks;
    std::vector<double> dijkstraDurations;
    dijkstraDurations.reserve(PATH_SAMPLES);
    std::vector<double>astarDurations;
    astarDurations.reserve(PATH_SAMPLES);
    std::chrono::duration<double, std::milli> sum_dijkstra_time(0), sum_astar_time(0);
    int count, sum_dijkstra_count, sum_astar_count;


    for (size_t i = PATH_NODE_INC; i <= PATH_NODE_MAX; i += PATH_NODE_INC) {
        dijkstraDurations.clear();
        astarDurations.clear();

        sum_dijkstra_time = std::chrono::duration<double, std::milli>(0);
        sum_astar_time = std::chrono::duration<double, std::milli>(0);

        sum_astar_count = 0;
        sum_dijkstra_count = 0;

        for (size_t sample = 0; sample < PATH_SAMPLES; sample++) {
            // INCREMENTING NODES
            graph = genRandomGraphInfo(i, EDGES_PER_NODE);

            auto t1 = std::chrono::high_resolution_clock::now();
            Pathfinding::dijkstraAdaptation(graph, 0, i-1, count);
            auto t2 = std::chrono::high_resolution_clock::now();

            dijkstraDurations.push_back(((std::chrono::duration<double, std::milli>) (t2-t1)).count());
            sum_dijkstra_time += t2 - t1;
            sum_dijkstra_count += count;

            t1 = std::chrono::high_resolution_clock::now();
            Pathfinding::aStarAdaptation<NodeInfo>(graph, 0, i-1, count);
            t2 = std::chrono::high_resolution_clock::now();

            astarDurations.push_back(((std::chrono::duration<double, std::milli>) (t2-t1)).count());
            sum_astar_time += t2 - t1;
            sum_astar_count += count;

            graph.freeGraph();

        }

        std::sort(dijkstraDurations.begin(), dijkstraDurations.end());
        std::sort(astarDurations.begin(), astarDurations.end());

        file << i;
        file << "," << sum_dijkstra_time.count() / PATH_SAMPLES;
        if(dijkstraDurations.size()%2==0) {
            file << "," << (dijkstraDurations[dijkstraDurations.size()/2] + dijkstraDurations[dijkstraDurations.size()/2 - 1])/2;
        } else {
            file << "," << (dijkstraDurations[dijkstraDurations.size()/2]);
        }

        file << "," << sum_dijkstra_count / PATH_SAMPLES;
        file << "," << sum_astar_time.count() / PATH_SAMPLES;
        if(astarDurations.size()%2==0) {
            file << "," << (astarDurations[astarDurations.size()/2] + astarDurations[astarDurations.size()/2 - 1])/2;
        } else {
            file << "," << (astarDurations[astarDurations.size()/2]);
        }

        file << "," << sum_astar_count / PATH_SAMPLES;
        file << "\n" << std::flush;
    }

    file.close();
}

int ackermann(int n, int m) {
    return (n == 0) ? m+1 : (m == 0) ? ackermann(n-1,1) : ackermann(n-1,ackermann(n,m-1));
}

int ackermann(int n) {
    return ackermann(n, n);
}

int inverse_ackermann(int n) {
    int i = 1;
    while(ackermann(i, 1) < log2(n)) i++;

    return i;
}


TEST(complex, ackermann) {
    std::ofstream file;

    file.open("ackermann.csv");

    file << "ackerman\n" << std::flush;

    for(int n = 0; n <= GRAPH_SIZE-2; n++) {
        file << inverse_ackermann(n) << "\n" << std::flush;
    }

    file.close();
}

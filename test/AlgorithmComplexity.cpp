//
// Created by nunoa on 21/05/21.
//

#include <gtest/gtest.h>
#include <chrono>
#include <random>
#include <fstream>

#include "algorithm/TravelingSalesman.h"
#include "algorithm/NearestNeighbour.h"
#include "src/utils/algorithm/MinimumSpanningTrees.h"

/// TESTS ///

#define GRAPH_SIZE 120
#define SAMPLES 25

Graph<int> genRandomGraph(size_t graph_size) {
    std::uniform_real_distribution<double> distrib(-10000, 10000);
    std::random_device rd;

    double a = rd() ^(std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count());
    std::mt19937 rng(a);

    Graph<int> graph;

    for (size_t j = 0; j < graph_size; j++) {
        graph.addNode(j, j, Position(COORDS, distrib(rng), distrib(rng)));
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
    double mst_correctness, nearest_correctness, sum_mst_correctness, sum_nearest_correctness;
    std::chrono::duration<double, std::milli> mst_time(0), nearest_time(0), brute_time(0), sum_mst_time(
            0), sum_nearest_time(0), sum_brute_time(0);

    for (size_t i = 2; i <= GRAPH_SIZE; i++) {
        sum_mst_correctness = sum_nearest_correctness = 0;
        sum_mst_time = sum_nearest_time = sum_brute_time = std::chrono::duration<double, std::milli>(0);
        calcBrute = i <= 12;

        for (size_t sample = 0; sample < SAMPLES; sample++) {
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

        if(calcBrute) file << sum_brute_time.count() / SAMPLES;
        file << "," << sum_mst_time.count() / SAMPLES << ",";
        if(calcBrute) file << sum_mst_correctness / SAMPLES;
        file << "," << sum_nearest_time.count() / SAMPLES << ",";
        if(calcBrute) file << sum_nearest_correctness / SAMPLES;
        file << "\n" << std::flush;
    }

    file.close();
}

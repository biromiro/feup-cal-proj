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

#define GRAPH_SIZE 250

Graph<int> genRandomGraph(size_t graph_size) {
    std::uniform_real_distribution<double> distrib(-10000, 10000);
    std::random_device rd;

    double a  = rd() ^ (std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
    std::mt19937 rng(a);

    Graph<int> graph;

    for(size_t j = 0; j < graph_size; j++) {
        graph.addNode(j, j, Position(COORDS, distrib(rng), distrib(rng)));
    }

    return graph;
}

double compareNodes(const Graph<int> &graph, const std::vector<int> &expected, const std::vector<int> &actual) {
    double distanceExpected = 0;
    double distanceActual = 0;

    for(size_t i = 0; i < expected.size() - 1; i++) {
        distanceExpected += Distances::getEuclideanDistance(graph.findNode(expected.at(i))->getPos(),
                                                            graph.findNode(expected.at(i+1))->getPos());

        distanceActual += Distances::getEuclideanDistance(graph.findNode(actual.at(i))->getPos(),
                                                            graph.findNode(actual.at(i+1))->getPos());
    }

    return (double) distanceExpected / distanceActual;
}


TEST(ComplexityTest, tspAlgos) {
    Graph<int> graph;

    std::ofstream file;

    file.open("results.csv");

    file << "GRAPH SIZE,BRUTE FORCE TIME,MST TIME,MST CORRECT\n" << std::flush;

    std::vector<int> bruteResult;
    std::vector<int> comparativeResult;
    double mst_correctness, nearest_correctness;

    for(size_t i = 2; i <= GRAPH_SIZE; i++) {
        graph = genRandomGraph(i);

        Node<int>* origin = graph.findNode(0);
        Node<int>* destination = graph.findNode(i-1);

        std::vector<Node<int>*> nodeSet = graph.getNodeSet();

        std::vector<Node<int>*> poi = std::vector<Node<int>*>(nodeSet.begin()+1, nodeSet.end()-1);

        auto t1 = std::chrono::high_resolution_clock::now();
        comparativeResult = MinimumSpanningTrees<int>::calculateTreeKruskal(poi, origin, destination);
        auto t2 = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> mst_time  = t2 - t1;

        std::chrono::duration<double, std::milli> brute_time = std::chrono::duration<double, std::milli>(0);

        bruteResult.clear();

        if(i <= 12) {
            t1 = std::chrono::high_resolution_clock::now();
            bruteResult = TravelingSalesman<int>::bruteForce(poi, origin, destination);
            t2 = std::chrono::high_resolution_clock::now();

            brute_time = (t2 - t1);
        }

        if(!bruteResult.empty()) {
            mst_correctness = compareNodes(graph, bruteResult, comparativeResult);
        } else {
            mst_correctness = 0;
        }


        file << i-2 << "," << brute_time.count()  << "," << mst_time.count() << "," << mst_correctness  << "\n" << std::flush;
    }

    file.close();
}

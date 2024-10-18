//
// Created by DELL on 15/10/2024.
//

#ifndef GRAPHLIST_H
#define GRAPHLIST_H

#include <vector>
#include <list>
#include <limits>
#include <string>

const int INF = std::numeric_limits<int>::max(); // Constante pour l'infini

class Edge {
public:
    int vertex;
    int weight;

    Edge(int v, int w) : vertex(v), weight(w) {}
};

class GraphList {
private:
    int numVertices;
    int numEdges;
    int startVertex;
    int endVertex;
    std::vector<std::list<Edge>> adjacencyList;
    std::vector<int> distances;
    std::vector<int> predecessors;

public:
    GraphList();
    void readGraphFromFile(const std::string& filename);
    void dijkstra();
    void writeOutputToFile(const std::string& filename);

    // Getters
    int getStartVertex() const;
    int getEndVertex() const;
};




#endif //GRAPHLIST_H

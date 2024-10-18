//
// Created by DELL on 16/10/2024.
//

#ifndef GRAPHGENERAL_H
#define GRAPHGENERAL_H

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <algorithm>

const int INF = std::numeric_limits<int>::max();
class GraphGeneral {
public:
    GraphGeneral(int vertices, int edges, int start, int end);
    void addEdge(int u, int v, int weight);
    void dijkstra();
    void outputResults(const std::string& outputFile);

private:
    int n; // Nombre de sommets
    int m; // Nombre d'arêtes
    int start; // Sommet de départ
    int end; // Sommet de fin
    std::vector<std::vector<int>> graph; // Matrice d'adjacence
    std::vector<int> dist; // Distances
    std::vector<int> prev; // Prédécesseurs
    int minDistance(const std::vector<bool>& visited);
};



#endif //GRAPHGENERAL_H

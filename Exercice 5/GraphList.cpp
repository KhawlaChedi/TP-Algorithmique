//
// Created by DELL on 15/10/2024.
//

#include "GraphList.h"
#include <fstream>
#include <queue>
#include <algorithm>
#include <iostream>

// Constructeur par défaut
GraphList::GraphList() : numVertices(0), numEdges(0), startVertex(0), endVertex(0) {}

// Lecture du graphe depuis un fichier
void GraphList::readGraphFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier " << filename << std::endl;
        return;
    }

    inFile >> numVertices >> numEdges >> startVertex >> endVertex;
    adjacencyList.resize(numVertices + 1);

    for (int i = 0; i < numEdges; ++i) {
        int u, v, weight;
        inFile >> u >> v >> weight;
        adjacencyList[u].emplace_back(v, weight);
        adjacencyList[v].emplace_back(u, weight); // Graphe non orienté
    }
}

// Algorithme de Dijkstra pour le plus court chemin
void GraphList::dijkstra() {
    std::vector<bool> visited(numVertices + 1, false);
    distances.assign(numVertices + 1, INF);
    predecessors.assign(numVertices + 1, -1);

    distances[startVertex] = 0;
    using Pair = std::pair<int, int>;
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> pq;
    pq.push({0, startVertex});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (const auto& edge : adjacencyList[u]) {
            int v = edge.vertex;
            int weight = edge.weight;

            if (!visited[v] && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                predecessors[v] = u;
                pq.push({distances[v], v});
            }
        }
    }
}

// Écriture des résultats dans un fichier
void GraphList::writeOutputToFile(const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier " << filename << std::endl;
        return;
    }

    // Écriture de la distance la plus courte
    outFile << distances[endVertex] << std::endl;

    // Construction et écriture du chemin le plus court
    std::vector<int> path;
    for (int at = endVertex; at != -1; at = predecessors[at]) {
        path.push_back(at);
    }
    std::reverse(path.begin(), path.end());

    for (size_t i = 0; i < path.size(); ++i) {
        outFile << path[i];
        if (i < path.size() - 1) outFile << " → ";
    }
    outFile << std::endl;
}

// Getters
int GraphList::getStartVertex() const {
    return startVertex;
}

int GraphList::getEndVertex() const {
    return endVertex;
}

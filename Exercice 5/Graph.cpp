//
// Created by DELL on 15/10/2024.
//

#include "Graph.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>

// Constructeur pour initialiser un graphe vide
Graph::Graph() : n(0), m(0), start(0), end(0) {}

// Méthode pour lire le graphe à partir d'un fichier
void Graph::readGraph(const std::string& filename) {
    std::ifstream inFile(filename);
    inFile >> n >> m >> start >> end;

    adjMatrix.resize(n + 1, std::vector<int>(n + 1, INF));
    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        inFile >> u >> v >> weight;
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight; // Graphe non orienté
    }
}

// Méthode pour implémenter Dijkstra
std::pair<std::vector<int>, std::vector<int>> Graph::dijkstra() const {
    std::vector<int> dist(n + 1, INF);
    std::vector<int> prev(n + 1, -1);
    std::vector<bool> visited(n + 1, false);

    dist[start] = 0;
    using Pair = std::pair<int, int>; // {distance, sommet}
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> pq;
    pq.push({0, start}); // {distance, sommet}

    while (!pq.empty()) {
        int u = pq.top().second; // sommet avec la plus petite distance
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (int v = 1; v <= n; ++v) {
            if (adjMatrix[u][v] != INF && !visited[v]) {
                if (dist[u] + adjMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjMatrix[u][v];
                    prev[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    return {dist, prev}; // Retourne la distance minimale et les chemins
}

// Méthode pour écrire les résultats dans un fichier
void Graph::writeOutput(const std::string& filename, const std::vector<int>& dist, const std::vector<int>& prev) const {
    std::ofstream outFile(filename);
    outFile << dist[end] << std::endl; // Distance la plus courte

    // Construction du chemin
    std::vector<int> path;
    for (int at = end; at != -1; at = prev[at]) {
        path.push_back(at);
    }
    std::reverse(path.begin(), path.end());

    // Écriture du chemin
    for (size_t i = 0; i < path.size(); ++i) {
        outFile << path[i];
        if (i < path.size() - 1) outFile << " → ";
    }
    outFile << std::endl;
}

// Accesseurs pour start et end
int Graph::getStart() const {
    return start;
}

int Graph::getEnd() const {
    return end;
}


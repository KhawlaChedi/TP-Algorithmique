//
// Created by DELL on 15/10/2024.
//

#include "GraphTas.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <stack>

// Constructeur du graphe
GraphTas::GraphTas(int vertices) : numVertices(vertices) {
    adjMatrix.resize(vertices, std::vector<int>(vertices, INF));
    adjList.resize(vertices);
}

// Ajouter une arête avec poids
void GraphTas::addEdge(int u, int v, int weight) {
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight;  // Graphe non-orienté
    adjList[u].emplace_back(v, weight);
    adjList[v].emplace_back(u, weight);  // Graphe non-orienté
}

// Algorithme de Dijkstra avec un tas (priority queue)
void GraphTas::dijkstraWithHeap(int start, int end, std::vector<int>& dist, std::vector<int>& prev) {
    dist.assign(numVertices, INF);
    prev.assign(numVertices, -1);
    dist[start] = 0;

    using Pair = std::pair<int, int>;
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> pq;  // Tas min
    pq.push({0, start});  // Ajouter le sommet de départ au tas

    while (!pq.empty()) {
        int u = pq.top().second;  // Extraire le sommet avec la distance minimale
        pq.pop();

        if (u == end) break;  // Si nous atteignons le sommet final, arrêtez

        // Parcourir tous les voisins de u
        for (const auto& [v, weight] : adjList[u]) {
            if (dist[u] + weight < dist[v]) {  // Relaxation
                dist[v] = dist[u] + weight;
                prev[v] = u;
                pq.push({dist[v], v});  // Ajouter le voisin dans le tas
            }
        }
    }
}

// Charger le graphe à partir d'un fichier
void GraphTas::loadFromFile(const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Erreur lors de l'ouverture du fichier d'entrée\n";
        return;
    }

    int n, m, u, v, w, start, end;
    infile >> n >> m >> start >> end;
    for (int i = 0; i < m; ++i) {
        infile >> u >> v >> w;
        addEdge(u - 1, v - 1, w);  // Indices des sommets dans le fichier sont 1-based
    }
}

// Sauvegarder les résultats dans un fichier
void GraphTas::saveToFile(const std::string& filename, int distance, const std::vector<int>& path) {
    std::ofstream outfile(filename);
    if (!outfile) {
        std::cerr << "Erreur lors de l'ouverture du fichier de sortie\n";
        return;
    }

    // Sauvegarder la distance
    outfile << distance << "\n";

    // Sauvegarder le chemin
    for (int i = path.size() - 1; i >= 0; --i) {
        outfile << path[i] + 1;  // Convertir en indices 1-based
        if (i > 0) outfile << " → ";
    }
    outfile << "\n";
}

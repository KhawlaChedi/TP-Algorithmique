//
// Created by DELL on 16/10/2024.
//

#include "GraphGeneral.h"

GraphGeneral::GraphGeneral(int vertices, int edges, int start, int end)
    : n(vertices), m(edges), start(start), end(end), graph(vertices, std::vector<int>(vertices, INF)),
      dist(vertices, INF), prev(vertices, -1) {
    dist[start] = 0; // La distance du sommet de départ à lui-même est 0
    prev[start] = -1; // Pas de prédécesseur pour le sommet de départ
}

void GraphGeneral::addEdge(int u, int v, int weight) {
    graph[u][v] = weight;
    graph[v][u] = weight; // Graphe non-orienté
}

int GraphGeneral::minDistance(const std::vector<bool>& visited) {
    int min = INF;
    int min_index = -1;

    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void GraphGeneral::dijkstra() {
    std::vector<bool> visited(n, false);

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(visited);
        if (u == -1) break; // Si u est -1, tous les sommets accessibles ont été visités
        visited[u] = true; // Marquer ce sommet comme visité

        // Mettre à jour la distance des sommets voisins
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u; // Stocker le prédécesseur
            }
        }
    }
}

void GraphGeneral::outputResults(const std::string& outputFile) {
    std::ofstream outfile(outputFile);
    if (!outfile) {
        std::cerr << "Erreur d'ouverture du fichier " << outputFile << "\n";
        return;
    }

    if (dist[end] != INF) {
        outfile << dist[end] << "\n"; // Distance la plus courte
        // Construire le chemin depuis 'end' vers 'start'
        std::vector<int> path;
        for (int at = end; at != -1; at = prev[at]) {
            path.push_back(at);
        }
        std::reverse(path.begin(), path.end());
        for (size_t j = 0; j < path.size(); j++) {
            if (j > 0) outfile << " → ";
            outfile << path[j] + 1; // Convertir en indice 1-based pour la sortie
        }
        outfile << "\n"; // Afficher le chemin
    } else {
        outfile << "Aucun chemin trouvé\n"; // Si aucun chemin n'existe
    }

    outfile.close();
}

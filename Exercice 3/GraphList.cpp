//
// Created by DELL on 14/10/2024.
//

#include "GraphList.h"

// Constructeur pour initialiser un graphe avec 'n' sommets
GraphList::GraphList(int n) : n(n), adj(n + 1) {}

// Ajouter une arête au graphe
void GraphList::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Algorithme de Prim pour obtenir un arbre couvrant
std::vector<Edge> GraphList::primAlgorithm() {
    std::vector<bool> visited(n + 1, false);
    std::vector<Edge> treeEdges;
    std::queue<int> q;
    q.push(1); // Commencer à partir du sommet 1
    visited[1] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Parcourir les voisins de u
        for (int v : adj[u]) {
            if (!visited[v]) {
                treeEdges.push_back(Edge(u, v));
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return treeEdges;
}

// Lecture du fichier d'entrée pour construire le graphe
GraphList readGraphList(const std::string& inputFile) {
    std::ifstream inFile(inputFile);
    if (!inFile) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier d'entrée.\n";
        exit(1);
    }

    int n, m;
    inFile >> n >> m;
    GraphList graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        inFile >> u >> v;
        graph.addEdge(u, v);
    }

    return graph;
}

// Écriture du résultat dans un fichier de sortie
void writeOutput(const std::string& outputFile, const std::vector<Edge>& treeEdges) {
    std::ofstream outFile(outputFile);
    if (!outFile) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier de sortie.\n";
        return;
    }

    for (const auto& edge : treeEdges) {
        outFile << edge.u << " " << edge.v << std::endl;
    }

    outFile.close();
}


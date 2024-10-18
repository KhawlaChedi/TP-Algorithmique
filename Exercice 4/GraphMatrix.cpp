//
// Created by DELL on 14/10/2024.
//

#include "GraphMatrix.h"

// Constructeur pour initialiser une matrice d'adjacence
GraphMatrix::GraphMatrix(int n) : n(n), adj(n + 1, std::vector<int>(n + 1, 0)) {}

// Ajouter une arête au graphe
void GraphMatrix::addEdge(int u, int v) {
    adj[u][v] = adj[v][u] = 1; // Matrice d'adjacence
}

// Fonction DFS pour explorer les sommets
void GraphMatrix::dfs(int v, std::vector<bool>& visited, std::vector<int>& component) {
    visited[v] = true; // Marquer le sommet comme visité
    component.push_back(v); // Ajouter le sommet à la composante

    for (int i = 1; i <= n; ++i) {
        if (adj[v][i] == 1 && !visited[i]) { // Vérifier les voisins
            dfs(i, visited, component); // Récursion sur le voisin
        }
    }
}

// Trouver toutes les composantes connexes
void GraphMatrix::findConnectedComponents() {
    std::vector<bool> visited(n + 1, false);
    std::vector<std::vector<int>> components;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            std::vector<int> component;
            dfs(i, visited, component); // Explorer la composante
            components.push_back(component);
        }
    }

    // Écrire le résultat
    std::ofstream outFile("D:\\CHEDI_khawla_BENYOUSSEF_nour\\Exercice 4\\OUTCONGRAPH.txt");
    if (!outFile) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier de sortie.\n";
        return;
    }

    outFile << components.size() << std::endl; // Nombre de composantes
    for (size_t i = 0; i < components.size(); ++i) {
        outFile << "composante connexe " << i + 1 << std::endl;
        for (int vertex : components[i]) {
            outFile << vertex << " ";
        }
        outFile << std::endl;
    }

    outFile.close();
}

// Lecture du fichier d'entrée pour construire le graphe
GraphMatrix readGraphMatrix(const std::string& inputFile) {
    std::ifstream inFile(inputFile);
    if (!inFile) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier d'entrée.\n";
        exit(1);
    }

    int n, m;
    inFile >> n >> m;
    GraphMatrix graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        inFile >> u >> v;
        graph.addEdge(u, v);
    }

    return graph;
}


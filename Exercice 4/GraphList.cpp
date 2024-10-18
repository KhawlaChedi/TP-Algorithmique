//
// Created by DELL on 14/10/2024.
//

#include "GraphList.h"

// Constructeur pour initialiser une liste d'adjacence
GraphList::GraphList(int n) : n(n), adj(n + 1) {}

// Ajouter une arête au graphe
void GraphList::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // Liste d'adjacence
}

// Fonction DFS pour explorer les sommets
void GraphList::dfs(int v, std::vector<bool>& visited, std::vector<int>& component) {
    visited[v] = true; // Marquer le sommet comme visité
    component.push_back(v); // Ajouter le sommet à la composante

    for (int neighbor : adj[v]) { // Vérifier les voisins
        if (!visited[neighbor]) {
            dfs(neighbor, visited, component); // Récursion sur le voisin
        }
    }
}

// Trouver toutes les composantes connexes
void GraphList::findConnectedComponents() {
    std::vector<bool> visited(n + 1, false);
    components.clear(); // Vider les composantes précédentes

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            std::vector<int> component;
            dfs(i, visited, component); // Explorer la composante
            components.push_back(component); // Ajouter à l'attribut components
        }
    }

    // Écrire le résultat
    writeOutput("D:\\CHEDI_khawla_BENYOUSSEF_nour\\Exercice 4\\OUTCONGRAPH.txt"); // Écrire dans le même fichier
}


// Écriture du résultat dans le fichier de sortie
void GraphList::writeOutput(const std::string& outputFile) {
    std::ofstream outFile(outputFile);
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


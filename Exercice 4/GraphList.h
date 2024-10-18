//
// Created by DELL on 14/10/2024.
//

#ifndef GRAPHLIST_H
#define GRAPHLIST_H

#include <iostream>
#include <vector>
#include <list>
#include <fstream>

class GraphList {
    int n; // Nombre de sommets
    std::vector<std::list<int>> adj; // Liste d'adjacence
    std::vector<std::vector<int>> components; // Composantes connexes

public:
    GraphList(int n); // Constructeur
    void addEdge(int u, int v); // Ajouter une arête
    void findConnectedComponents(); // Trouver les composantes connexes
    void dfs(int v, std::vector<bool>& visited, std::vector<int>& component); // DFS pour explorer le graphe
    void writeOutput(const std::string& outputFile); // Écrire le résultat
};

GraphList readGraphList(const std::string& inputFile); // Lecture du fichier d'entrée




#endif //GRAPHLIST_H

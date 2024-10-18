//
// Created by DELL on 14/10/2024.
//

#ifndef GRAPHMATRIX_H
#define GRAPHMATRIX_H


#include <iostream>
#include <vector>
#include <fstream>

class GraphMatrix {
    int n; // Nombre de sommets
    std::vector<std::vector<int>> adj; // Matrice d'adjacence

public:
    GraphMatrix(int n); // Constructeur
    void addEdge(int u, int v); // Ajouter une arête
    void findConnectedComponents(); // Trouver les composantes connexes
    void dfs(int v, std::vector<bool>& visited, std::vector<int>& component); // DFS pour explorer le graphe
    void writeOutput(const std::string& outputFile); // Écrire le résultat
};

GraphMatrix readGraphMatrix(const std::string& inputFile); // Lecture du fichier d'entrée

#endif //GRAPHMATRIX_H

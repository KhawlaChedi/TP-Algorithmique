//
// Created by DELL on 14/10/2024.
//

#ifndef GRAPHMATRIX_H
#define GRAPHMATRIX_H



#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

// Structure pour représenter une arête
struct Edge {
    int u, v;
    Edge(int u, int v) : u(u), v(v) {}
};

// Union-Find structure pour l'algorithme de Kruskal
class UnionFind {
    std::vector<int> parent, rank;

public:
    UnionFind(int n); // Constructeur
    int find(int u);  // Trouver le représentant de l'ensemble
    void unite(int u, int v); // Union de deux ensembles
};

// Classe pour représenter un graphe avec une matrice d'adjacence
class GraphMatrix {
    int n; // Nombre de sommets
    std::vector<std::vector<int>> adj; // Matrice d'adjacence

public:
    GraphMatrix(int n); // Constructeur
    void addEdge(int u, int v); // Ajouter une arête
    std::vector<Edge> kruskalAlgorithm(); // Algorithme de Kruskal
};

// Lecture du fichier d'entrée pour construire le graphe
GraphMatrix readGraphMatrix(const std::string& inputFile);

// Écriture du résultat (arbre couvrant) dans un fichier de sortie
void writeOutputMatrix(const std::string& outputFile, const std::vector<Edge>& treeEdges);



#endif //GRAPHMATRIX_H

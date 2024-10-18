//
// Created by DELL on 14/10/2024.
//

#ifndef GRAPHLIST_H
#define GRAPHLIST_H



#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <cstring>

// Structure pour représenter une arête
struct Edge {
    int u, v;
    Edge(int u, int v) : u(u), v(v) {}
};

// Classe pour représenter un graphe sous forme de liste d'adjacence
class GraphList {
    int n; // Nombre de sommets
    std::vector<std::vector<int>> adj; // Liste d'adjacence

public:
    GraphList(int n); // Constructeur

    // Ajouter une arête au graphe
    void addEdge(int u, int v);

    // Algorithme de Prim pour obtenir un arbre couvrant
    std::vector<Edge> primAlgorithm();
};

// Lecture du fichier d'entrée pour construire le graphe
GraphList readGraphList(const std::string& inputFile);

// Écriture du résultat (arbre couvrant) dans un fichier de sortie
void writeOutput(const std::string& outputFile, const std::vector<Edge>& treeEdges);



#endif //GRAPHLIST_H

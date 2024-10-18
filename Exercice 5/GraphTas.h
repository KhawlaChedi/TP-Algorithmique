//
// Created by DELL on 15/10/2024.
//

#ifndef GRAPHTAS_H
#define GRAPHTAS_H

#include <vector>
#include <list>
#include <queue>
#include <limits>
#include <fstream>
#include <iostream>

const int INF = std::numeric_limits<int>::max();

class GraphTas {
private:
    int numVertices;  // Nombre de sommets
    std::vector<std::vector<int>> adjMatrix; // Matrice d'adjacence
    std::vector<std::list<std::pair<int, int>>> adjList; // Liste d'adjacence

public:
    GraphTas(int vertices);  // Constructeur
    void addEdge(int u, int v, int weight);  // Ajouter une arête
    void dijkstraWithHeap(int start, int end, std::vector<int>& dist, std::vector<int>& prev); // Dijkstra avec tas
    void loadFromFile(const std::string& filename);  // Charger le graphe à partir d'un fichier
    void saveToFile(const std::string& filename, int distance, const std::vector<int>& path);  // Sauvegarder les résultats
};



#endif //GRAPHTAS_H

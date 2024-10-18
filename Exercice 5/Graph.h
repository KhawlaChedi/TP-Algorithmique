//
// Created by DELL on 15/10/2024.
//

#ifndef GRAPH_H
#define GRAPH_H


#include <vector>
#include <string>
#include <limits>

const int INF = std::numeric_limits<int>::max();

class Graph {
private:
    int n; // nombre de sommets
    int m; // nombre d'arêtes
    int start; // sommet de départ
    int end; // sommet de destination
    std::vector<std::vector<int>> adjMatrix; // matrice d'adjacence

public:
    // Constructeur pour initialiser un graphe vide
    Graph();

    // Méthode pour lire le graphe à partir d'un fichier
    void readGraph(const std::string& filename);

    // Méthode pour implémenter Dijkstra
    std::pair<std::vector<int>, std::vector<int>> dijkstra() const;

    // Méthode pour écrire les résultats dans un fichier
    void writeOutput(const std::string& filename, const std::vector<int>& dist, const std::vector<int>& prev) const;

    // Accesseurs pour start et end
    int getStart() const;
    int getEnd() const;
};




#endif //GRAPH_H

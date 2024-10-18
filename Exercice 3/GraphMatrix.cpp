//
// Created by DELL on 14/10/2024.
//

#include "GraphMatrix.h"

// Constructeur pour initialiser un Union-Find avec 'n' éléments
UnionFind::UnionFind(int n) : parent(n + 1), rank(n + 1, 0) {
    for (int i = 0; i <= n; ++i) parent[i] = i;
}

// Trouver le représentant de l'ensemble contenant 'u'
int UnionFind::find(int u) {
    if (parent[u] != u) parent[u] = find(parent[u]);
    return parent[u];
}

// Union de deux ensembles contenant 'u' et 'v'
void UnionFind::unite(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) parent[rootV] = rootU;
        else if (rank[rootU] < rank[rootV]) parent[rootU] = rootV;
        else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

// Constructeur pour initialiser un graphe avec 'n' sommets
GraphMatrix::GraphMatrix(int n) : n(n), adj(n + 1, std::vector<int>(n + 1, 0)) {}

// Ajouter une arête au graphe
void GraphMatrix::addEdge(int u, int v) {
    adj[u][v] = adj[v][u] = 1; // Matrice d'adjacence
}

// Algorithme de Kruskal pour obtenir un arbre couvrant
std::vector<Edge> GraphMatrix::kruskalAlgorithm() {
    UnionFind uf(n);
    std::vector<Edge> edges;

    // Récupérer toutes les arêtes
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (adj[i][j]) {
                edges.push_back(Edge(i, j));
            }
        }
    }

    // Trier les arêtes (pas de poids, donc ordre arbitraire)
    std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.u < b.u || (a.u == b.u && a.v < b.v);
    });

    // Appliquer l'algorithme de Kruskal pour trouver l'arbre couvrant
    std::vector<Edge> treeEdges;
    for (const auto& edge : edges) {
        if (uf.find(edge.u) != uf.find(edge.v)) {
            uf.unite(edge.u, edge.v);
            treeEdges.push_back(edge);
        }
    }

    return treeEdges;
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

// Écriture du résultat dans un fichier de sortie
void writeOutputMatrix(const std::string& outputFile, const std::vector<Edge>& treeEdges) {
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


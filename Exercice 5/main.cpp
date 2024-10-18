
//#include "Graph.h"
//#include "GraphList.h"
//#include "GraphTas.h"

#include "GraphGeneral.h"


int main() {
    ////////////////////////////////////////////////// pour Matrix
   /* Graph graph;
    // Lecture du graphe
    graph.readGraph("D:\\CHEDI_khawla_BENYOUSSEF_nour\\Exercice 5\\INPDIJGRAPH.txt");
    // Exécution de l'algorithme de Dijkstra
    auto [dist, prev] = graph.dijkstra();
    // Écriture du résultat dans le fichier
    graph.writeOutput("D:\\CHEDI_khawla_BENYOUSSEF_nour\\Exercice 5\\OUTCONGRAPH.txt", dist, prev);*/

    ///////////////////////////////////////////////// pour List
  /*  GraphList graph;
    // Lecture du graphe depuis un fichier
    graph.readGraphFromFile("D:\\CHEDI_khawla_BENYOUSSEF_nour\\Exercice 5\\INPDIJGRAPH.txt");
    // Algorithme de Dijkstra pour trouver le plus court chemin
    graph.dijkstra();
    // Écriture du résultat dans un fichier
    graph.writeOutputToFile("D:\\CHEDI_khawla_BENYOUSSEF_nour\\Exercice 5\\OUTCONGRAPH.txt");*/

    ///////////////////////////////////////////// pour Tas
 /*   GraphTas graph(6); // Initialiser un graphe de 6 sommets
    graph.loadFromFile("D:\\CHEDI_khawla_BENYOUSSEF_nour\\Exercice 5\\INPDIJGRAPH.txt");
    std::vector<int> dist, prev;
    int start = 0, end = 3; // Sommets 1 et 4 dans le fichier, mais indices 0-based
    // Exécuter l'algorithme de Dijkstra avec un tas
    graph.dijkstraWithHeap(start, end, dist, prev);
    // Trouver le chemin le plus court
    std::vector<int> path;
    for (int at = end; at != -1; at = prev[at]) {
        path.push_back(at);
    }
    // Sauvegarder les résultats dans OUTDIJGRAPH.TXT
    graph.saveToFile("D:\\CHEDI_khawla_BENYOUSSEF_nour\\Exercice 5\\OUTCONGRAPH.txt", dist[end], path);*/

    ///////////////////////////////////////////// pour GraphGeneral
    std::ifstream inFile("D:\\CHEDI_khawla_BENYOUSSEF_nour\\Exercice 5\\INPDIJGRAPH.txt");
    if (!inFile) {
        std::cerr << "Erreur d'ouverture du fichier d'entrée\n";
        return 1;
    }

    int n, m, start, end;
    inFile >> n >> m >> start >> end;

    GraphGeneral graph(n, m, start - 1, end - 1); // Conversion 1-based to 0-based

    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        inFile >> u >> v >> weight;
        graph.addEdge(u - 1, v - 1, weight); // Conversion 1-based à 0-based
    }

    graph.dijkstra();
    graph.outputResults("D:\\CHEDI_khawla_BENYOUSSEF_nour\\Exercice 5\\OUTCONGRAPH.txt");

    return 0;
}


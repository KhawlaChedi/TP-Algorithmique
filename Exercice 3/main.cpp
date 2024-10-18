#include <iostream>

//#include "GraphList.h"
#include "GraphMatrix.h"

int main() {
    std::string inputFile = "D:\\CHEDI_khawla_BENYOUSSEF_nour\\Exercice 3\\INPARBGRAPH.txt";
    std::string outputFile = "D:\\CHEDI_khawla_BENYOUSSEF_nour\\Exercice 3\\OUTARBGRAPH.txt";

 /*   // Lire le graphe à partir du fichier
    GraphList graph = readGraphList(inputFile);

    // Trouver l'arbre couvrant avec l'algorithme de Prim
    std::vector<Edge> treeEdges = graph.primAlgorithm();

    // Écrire l'arbre couvrant dans le fichier de sortie
       writeOutput(outputFile, treeEdges);    */

    // Lire le graphe à partir du fichier
    GraphMatrix graph = readGraphMatrix(inputFile);

    // Trouver l'arbre couvrant avec l'algorithme de Kruskal
    std::vector<Edge> treeEdges = graph.kruskalAlgorithm();

    // Écrire l'arbre couvrant dans le fichier de sortie
    writeOutputMatrix(outputFile, treeEdges);

    return 0;
}

#include <iostream>

//#include "GraphMatrix.h"
#include "GraphList.h"

int main() {
  /*  GraphMatrix graph = readGraphMatrix("D:\\CHEDI_khawla_BENYOUSSEF_nour\\Exercice 4\\INPCONGRAPH.txt");
    graph.findConnectedComponents(); // Trouver et écrire les composantes connexes  */

    GraphList graph = readGraphList("D:\\CHEDI_khawla_BENYOUSSEF_nour\\Exercice 4\\INPCONGRAPH.txt");
    graph.findConnectedComponents(); // Trouver et écrire les composantes connexes
    return 0;
}
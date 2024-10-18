//
// Created by DELL on 11/10/2024.
//

#ifndef MONOSEQ_H
#define MONOSEQ_H

#include <vector>
#include <string>

class MonoSeq {
public:
    // Fonction pour lire l'entrée à partir d'un fichier
    void readInput(const std::string& inputFile);

    // Fonction pour résoudre le problème
    void findLongestIncreasingSubsequence();

    // Fonction pour écrire les résultats dans un fichier
    void writeOutput(const std::string& outputFile) const;

private:
    int n; // Nombre d'éléments
    std::vector<int> A; // Tableau d'éléments
    std::vector<int> LIS; // Longueur des sous-séquences croissantes
    std::vector<int> prev; // Tableau pour reconstruire la sous-séquence
    std::vector<int> result; // La sous-séquence croissante finale
    std::vector<int> resultIndices; // Indices des éléments dans la sous-séquence finale
};



#endif //MONOSEQ_H

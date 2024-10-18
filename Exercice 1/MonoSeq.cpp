//
// Created by DELL on 11/10/2024.
//

#include "MonoSeq.h"
#include <fstream>
#include <iostream>
#include <algorithm>

void MonoSeq::readInput(const std::string& inputFile) {
    std::ifstream inFile(inputFile);
    if (!inFile) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier d'entrée.\n";
        return;
    }

    // Lecture du nombre d'éléments
    inFile >> n;

    // Lecture des éléments du tableau A
    A.resize(n);
    for (int i = 0; i < n; ++i) {
        inFile >> A[i];
    }

    inFile.close();
}

void MonoSeq::findLongestIncreasingSubsequence() {
    LIS.resize(n, 1);
    prev.resize(n, -1);

    // Remplissage de LIS avec une approche dynamique
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (A[i] > A[j] && LIS[i] < LIS[j] + 1) {
                LIS[i] = LIS[j] + 1;
                prev[i] = j;
            }
        }
    }

    // Trouver la longueur maximale de la sous-séquence croissante
    int maxLength = 0, maxIndex = 0;
    for (int i = 0; i < n; ++i) {
        if (LIS[i] > maxLength) {
            maxLength = LIS[i];
            maxIndex = i;
        }
    }

    // Reconstruire la sous-séquence croissante en partant de l'indice maxIndex
    int index = maxIndex;
    while (index != -1) {
        result.push_back(A[index]);
        resultIndices.push_back(index + 1);
        index = prev[index];
    }

    // Inverser la sous-séquence pour obtenir l'ordre croissant
    std::reverse(result.begin(), result.end());
    std::reverse(resultIndices.begin(), resultIndices.end());
}

void MonoSeq::writeOutput(const std::string& outputFile) const {
    std::ofstream outFile(outputFile);
    if (!outFile) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier de sortie.\n";
        return;
    }

    // Écrire la longueur de la sous-séquence
    outFile << result.size() << std::endl;

    // Écrire chaque élément de la sous-séquence avec son indice
    for (size_t i = 0; i < result.size(); ++i) {
        outFile << "a[" << resultIndices[i] << "] = " << result[i] << std::endl;
    }

    outFile.close();
}
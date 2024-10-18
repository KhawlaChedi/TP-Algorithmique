//
// Created by DELL on 11/10/2024.
//

#include "DivSeq.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
void DivSeq::readInput(const std::string& inputFile) {
    std::ifstream inFile(inputFile);
    if (!inFile) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier d'entrée.\n";
        return;
    }

    inFile >> n >> k;
    A.resize(n);
    for (int i = 0; i < n; ++i) {
        inFile >> A[i];
    }

    inFile.close();
}

void DivSeq::findLongestDivisibleSubsequence() {
    // Table pour stocker la longueur maximale des sous-séquences pour chaque reste
    std::vector<int> dp(k, -1);  // dp[i] représente la longueur maximale d'une sous-séquence dont la somme est congruente à i mod k
    std::vector<int> sum(k, 0);  // sum[i] représente la somme correspondante pour dp[i]
    std::vector<std::vector<int>> subsequence(k); // Pour garder la trace des sous-séquences

    dp[0] = 0; // Pour la somme 0, la longueur est 0

    // Parcourir tous les éléments du tableau
    for (int num : A) {
        // On fait une copie de dp pour éviter d'écraser les valeurs pendant la mise à jour
        std::vector<int> newDp = dp;
        std::vector<int> newSum = sum;
        std::vector<std::vector<int>> newSubsequence = subsequence;

        // Pour chaque reste possible, on tente d'ajouter l'élément `num`
        for (int r = 0; r < k; ++r) {
            if (dp[r] != -1) {  // Si une sous-séquence existe pour ce reste
                int newR = (r + num % k + k) % k;

                // Mettre à jour dp[newR] si cela permet d'obtenir une sous-séquence plus longue
                if (newDp[newR] < dp[r] + 1) {
                    newDp[newR] = dp[r] + 1;
                    newSum[newR] = sum[r] + num;
                    newSubsequence[newR] = subsequence[r];
                    newSubsequence[newR].push_back(num);
                }
            }
        }

        // Ajout du nouvel élément en tant que nouvelle sous-séquence indépendante
        int newR = num % k;
        if (newDp[newR] < 1) {
            newDp[newR] = 1;
            newSum[newR] = num;
            newSubsequence[newR] = { num };
        }

        // Remplacer dp et sum par les nouveaux résultats
        dp = newDp;
        sum = newSum;
        subsequence = newSubsequence;
    }

    // La plus longue sous-séquence dont la somme est divisible par k est dp[0]
    longestResult = subsequence[0];
    maxSum = sum[0];
}

void DivSeq::writeOutput(const std::string& outputFile) const {
    std::ofstream outFile(outputFile);
    if (!outFile) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier de sortie.\n";
        return;
    }

    // Écrire la longueur de la sous-séquence
    outFile << longestResult.size() << std::endl;

    // Écrire chaque élément de la sous-séquence
    for (size_t i = 0; i < longestResult.size(); ++i) {
        outFile << "a[" << (i + 1) << "] = " << longestResult[i] << std::endl; // Indexation 1-based
    }

    // Écrire la somme des éléments de la sous-séquence
    outFile << "Sum = " << maxSum << std::endl;

    outFile.close();
}

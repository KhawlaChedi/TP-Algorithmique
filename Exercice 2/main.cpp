//
// Created by DELL on 11/10/2024.
//

#include "DivSeq.h"
#include <iostream>

int main() {
    DivSeq divSeq;

    // Lire l'entrée depuis le fichier
    divSeq.readInput("D:\\CHEDI_khawla_BENYOUSSEF_nour\\Exercice 2\\INPDIVSEQ.txt");

    // Trouver la sous-séquence avec la somme divisible par k
    divSeq.findLongestDivisibleSubsequence();

    // Écrire la sortie dans le fichier
    divSeq.writeOutput("D:\\CHEDI_khawla_BENYOUSSEF_nour\\Exercice 2\\OUTDIVSEQ.txt");

    return 0;
}


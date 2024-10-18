#include <iostream>
#include "monoSeq.h"
int main()
{
    MonoSeq monoSeq;

    // Lire l'entrée depuis le fichier
    monoSeq.readInput("D:\\CHEDI_khawla_BENYOUSSEF_nour\\Exercice 1\\INPMONOSEQ.txt");

    // Trouver la plus longue sous-séquence croissante
    monoSeq.findLongestIncreasingSubsequence();

    // Écrire la sortie dans le fichier
    monoSeq.writeOutput("D:\\CHEDI_khawla_BENYOUSSEF_nour\\Exercice 1\\OUTMONOSEQ.txt");

    return 0;
}

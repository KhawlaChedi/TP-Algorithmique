//
// Created by DELL on 11/10/2024.
//

#ifndef DIVSEQ_H
#define DIVSEQ_H

#include <vector>
#include <string>

class DivSeq {
public:
    void readInput(const std::string& inputFile);
    void findLongestDivisibleSubsequence();
    void writeOutput(const std::string& outputFile) const;

private:
    int n, k;
    std::vector<int> A;
    std::vector<int> longestResult;
    int maxSum = 0;
};



#endif //DIVSEQ_H

#ifndef ALGO_H
#define ALGO_H

#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include "constants.h"

/* Structure which holds the four numbers in an expression */

struct point
{
    int num1;
    int num2;
    int num3;
    int num4;
};

class Algo
{
private:
    std::vector <point> numPermutations;
    std::vector <std::string> opPermutations;
    int goal;
public:
    Algo(int input_given[], int finalNum);
    std::vector<std::string> getAnswer();
    std::string to_string(int number);
    void getPermutations(std::string operatorBank[], int operatorCount,
                         std::string permutation[], int permutationLength,
                         int curIndex);
    void injectPermutation(std::string permutation[], int length);
};

#endif

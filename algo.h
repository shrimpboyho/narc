#ifndef ALGO_H
#define ALGO_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct point{
    int num1;
    int num2;
    int num3;
    int num4;
};

class Algo{
    private:
        std::vector <point> numPermutations; 
        std::vector <string> opPermutations;
        int goal;
    public:  
        Algo(int input_given[],int finalNum);
        std::vector<string> getAnswer();
        string to_string(int number);
        void getPermutations(string operatorBank[], int operatorCount,string permutation[],int permutationLength, int curIndex);
        void injectPermutation(string permutation[], int length);
     
};

#endif
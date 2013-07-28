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
        vector <point> numPermutations; 
        int goal;
    public:  
        Algo(int input_given[],int finalNum);
        std::vector<string> getAnswer();
     
};

#endif
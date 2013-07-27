#ifndef ALGO_H
#define ALGO_H

#include <string>
#include <iostream>

struct point{
    int num1;
    int num2;
    int num3;
    int num4;
};

class Algo{
    public:  
        Algo(int input_given[],int finalNum);
        std::string getAnswer();
    private:
        vector <point> numPermutations;  
};

#endif
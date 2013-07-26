#include "algo.h"
#include <iostream>

#include <vector>
#include <algorithm>

Algo::Algo(int input_given[]){
    
    std::cout << "Recieved array: " << input_given[0] << input_given[1] << input_given[2] << input_given[3] << input_given[4];
    
}

std::string Algo::getAnswer(){
    return "sample string";
}
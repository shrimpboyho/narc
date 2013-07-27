#include <iostream>
#include <string>
#include "parser.h"
#include "algo.h"
#include <stdlib.h>

int main() {

    /* Set up the local variables */
    
    int raw_input[4];
    int finalNum;
    
    std::cout << "Welcome to narc. Enter the four digits provided and the digit needed:\n";
    
    /* Get input */
    
    std::cin >> raw_input[0];
    std::cin >> raw_input[1];
    std::cin >> raw_input[2];
    std::cin >> raw_input[3];
    std::cin >> finalNum;
    
    /* Create the object */
    
    Algo newone(raw_input,finalNum);
    
    
    return 0; 
}

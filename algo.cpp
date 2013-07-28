#include "algo.h"
#include <iostream>

#include <vector>
#include <algorithm>

Algo::Algo(int input_given[],int finalNum){
      
    std::cout << "Recieved array: " << input_given[0] << input_given[1] << input_given[2] << input_given[3] << std::endl;
    
    // Set up final size
    
    this -> goal = finalNum;
    std::cout << "Calculating to: " << this -> goal << std::endl;
    
    // Set up permutations for numbers
    
    std::sort(input_given, input_given +4);
    
    do {
        std::cout << "Pushing in: " << input_given[0] << ' ' << input_given[1] << ' ' << input_given[2] << ' ' << input_given[3] << '\n';
        
        point p;
        p.num1 = input_given[0];
        p.num2 = input_given[1];
        p.num3 = input_given[2];
        p.num4 = input_given[3];
        
        this -> numPermutations.push_back(p);
        
    } while ( std::next_permutation(input_given, input_given + 4) );

    std::cout << "After loop: " << input_given[0] << ' ' << input_given[1] << ' ' << input_given[2] << ' ' << input_given[3]<< '\n';
    
    // Set up permutations for operators
    
    string operatorBank[4] = {"+","-","*","/"};
    
     do {
        
        string currentPerm = operatorBank[0] + operatorBank[1] + operatorBank[2] + operatorBank[3];
        
        this -> opPermutations.push_back(currentPerm);
        
    } while ( std::next_permutation(operatorBank, operatorBank + 4) );
}

std::vector<string> Algo::getAnswer(){
    
    int i;
    vector <string> answerSlots;
    
    // Print out all the permuations
    
    std::cout << "Testing: \n";
    
    for(i = 0; i < this -> numPermutations.size(); i++){
        std::cout << numPermutations[i].num1 << ' ' << numPermutations[i].num2 << ' ' << numPermutations[i].num3 << ' ' << numPermutations[i].num4 << '\n';
    }
    
    for(i = 0; i < this -> opPermutations.size(); i++){
        std::cout << opPermutations[i] << '\n';
    }
    
    /* TODO: Begin the proccess of testing stuff here */
    
    return answerSlots;
}
#include "algo.h"
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

Algo::Algo(int input_given[],int finalNum){
      
    std::cout << "Recieved array: " << input_given[0] << input_given[1] << input_given[2] << input_given[3] << std::endl;
    
    // Set up final size
    
    this -> goal = finalNum;
    std::cout << "Calculating to: " << this -> goal << std::endl;
    
    // Set up permutations
    
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
    
}

std::vector<string> Algo::getAnswer(){
    
    int i;
    vector <string> answerSlots;
    
    // Print out all the permuations
    cout << "Testing: \n";
    for(i = 0; i < this -> numPermutations.size(); i++){
        cout << numPermutations[i].num1 << ' ' << numPermutations[i].num2 << ' ' << numPermutations[i].num3 << ' ' << numPermutations[i].num4 << '\n';
    }
    
    return answerSlots;
}
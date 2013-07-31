#include "algo.h"
#include <iostream>

#include <vector>
#include <math.h>
#include <algorithm>
#include "parser.h"

void Algo::injectPermutation(string permutation[], int length){
    int i;
    for (i=0;i<length;i++){
        this -> opPermutations.push_back(permutation[0] + permutation[1] + permutation[2]);
    }
}

void Algo::getPermutations(string operatorBank[], int operatorCount, 
    string permutation[],int permutationLength, int curIndex){
    int i;
    //stop recursion condition
    if(curIndex == permutationLength){
        injectPermutation(permutation,permutationLength);
    }
    else{
        for(i = 0; i < operatorCount; i++){
            permutation[curIndex] = operatorBank[i];
            getPermutations(operatorBank,operatorCount,permutation,
                permutationLength,curIndex+1);
        }
    }
}

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
    
    int operatorCount = 4;
    int permutationLength = 3;
    string operatorBank[] = {"+","-","*","/"};
    string permutation[] = {"","","",""};
    int curIndex = 0;
    getPermutations(operatorBank,operatorCount,permutation,permutationLength,curIndex);
}

std::vector<string> Algo::getAnswer(){
    
    int i;
    int k;
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
    
    for(i = 0; i < numPermutations.size(); i++){
        
        for(k = 0; k < opPermutations.size(); k++){
            
            string testy = to_string(numPermutations[i].num1) + opPermutations[k].at(0) + to_string(numPermutations[i].num2) + opPermutations[k].at(1) + to_string(numPermutations[i].num3) + opPermutations[k].at(2) + to_string(numPermutations[i].num4);
            cout << "Testing: " << testy;
            
            // Test the equation
            
            ExpressionParser <int> parser;
            if(parser.eval(testy) == this-> goal){
                cout << " SUCCESS\n";
            }else{
                cout << " FAIL\n";
            }
            
        }
        
    }
    
    return answerSlots;
}

string Algo::to_string(int number){
    string number_string = "";
    char ones_char;
    int ones = 0;
    while(true){
        ones = number % 10;
        switch(ones){
            case 0: ones_char = '0'; break;
            case 1: ones_char = '1'; break;
            case 2: ones_char = '2'; break;
            case 3: ones_char = '3'; break;
            case 4: ones_char = '4'; break;
            case 5: ones_char = '5'; break;
            case 6: ones_char = '6'; break;
            case 7: ones_char = '7'; break;
            case 8: ones_char = '8'; break;
            case 9: ones_char = '9'; break;
            default : ;
        }
        number -= ones;
        number_string = ones_char + number_string;
        if(number == 0){
            break;
        }
        number = number/10;
    }
    return number_string;
}
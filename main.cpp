#include <iostream>
#include <string>
#include "parser.h"
#include <stdlib.h>

int main() {

    /* Set up the local variables */
    
    int numOne;
    int numTwo;
    int numThree;
    int numFour;
    int finalNum;
    
    std::cout << "Welcome to narc. Enter the four digits provided and the digit needed:\n";
    
    /* Get input */
    
    std::cin >> numOne;
    std::cin >> numTwo;
    std::cin >> numThree;
    std::cin >> numFour;
    std::cin >> finalNum;
    
    ExpressionParser<int> parser;
    std::string expr("(0 + ~(0xFF & 1000)*3) /-2");

  try {
    std::cout << expr << " = " << parser.eval(expr) << std::endl;
  }
  catch (parser_error& e) {
    std::cerr << e.what() << std::endl;
  }
    
    return 0; 
}

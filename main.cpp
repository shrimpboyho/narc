#include <iostream>
#include <stdlib.h>
#include "parser.h"
#include "algo.h"

int main()
{

    /* Set up the local variables */

    int raw_input[4];
    int finalNum;
    int i;

    std::cout << "Welcome to narc. Enter the four digits provided and the digit needed:\n";

    /* Get input */

    std::cin >> raw_input[0];
    std::cin >> raw_input[1];
    std::cin >> raw_input[2];
    std::cin >> raw_input[3];
    std::cin >> finalNum;

    /* Create the object */

    Algo newone(raw_input, finalNum);

    std::vector <std::string> answers = newone.getAnswer();

    /* Print out the successful answers */

    std::cout << "\nANSWERS:\n";

    for (i = 0; i < answers.size(); i++)
    {
        std::cout << answers[i] << std::endl;
    }

    return 0;
}

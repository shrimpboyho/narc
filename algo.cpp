#include "algo.h"
#include "parser.h"

/* Injects permutations into the vector */

void Algo::injectPermutation(std::string permutation[], int length)
{
    this -> opPermutations.push_back(permutation[0] + permutation[1] + permutation[2]);
}

/* Creates permutations */

void Algo::getPermutations(std::string operatorBank[], int operatorCount,
                           std::string permutation[], int permutationLength, int curIndex)
{
    int i;

    //stop recursion condition
    if (curIndex == permutationLength)
    {
        injectPermutation(permutation, permutationLength);
    }
    else
    {
        for (i = 0; i < operatorCount; i++)
        {
            permutation[curIndex] = operatorBank[i];
            getPermutations(operatorBank, operatorCount, permutation,
                            permutationLength, curIndex + 1);
        }
    }
}

/* The constructor for the class */

Algo::Algo(int input_given[], int finalNum)
{

    std::cout << "Recieved array: " << input_given[0] << input_given[1] << input_given[2] << input_given[3] << std::endl;

    // Set up final size
    this -> goal = finalNum;
    std::cout << "Calculating to: " << this -> goal << std::endl;

    // Set up permutations for numbers
    std::sort(input_given, input_given + 4);

    do
    {
        std::cout << "Pushing in: " << input_given[0] << ' ' << input_given[1] << ' ' << input_given[2] << ' ' << input_given[3] << '\n';

        point p;
        p.num1 = input_given[0];
        p.num2 = input_given[1];
        p.num3 = input_given[2];
        p.num4 = input_given[3];

        this -> numPermutations.push_back(p);

    }
    while ( std::next_permutation(input_given, input_given + 4) );

    std::cout << "After loop: " << input_given[0] << ' ' << input_given[1] << ' ' << input_given[2] << ' ' << input_given[3] << '\n';

    // Set up permutations for operators

    int operatorCount = 4;
    int permutationLength = 3;
    std::string operatorBank[] = {"+", "-", "*", "/"};
    std::string permutation[] = {"", "", "", ""};
    int curIndex = 0;
    getPermutations(operatorBank, operatorCount, permutation, permutationLength, curIndex);

}

/* Returns answers */

std::vector<std::string> Algo::getAnswer()
{

    int i;
    int k;
    std::vector <std::string> answerSlots;

    // Print out all the permuations

    std::cout << "Testing: \n";

    for (i = 0; i < this -> numPermutations.size(); i++)
    {
        std::cout << numPermutations[i].num1 << ' ' << numPermutations[i].num2 << ' ' << numPermutations[i].num3 << ' ' << numPermutations[i].num4 << '\n';
    }

    for (i = 0; i < this -> opPermutations.size(); i++)
    {
        std::cout << opPermutations[i] << '\n';
    }

    for (i = 0; i < numPermutations.size(); i++)
    {

        for (k = 0; k < opPermutations.size(); k++)
        {

            std::string testy = to_string(numPermutations[i].num1) + opPermutations[k].at(0) + to_string(numPermutations[i].num2) + opPermutations[k].at(1) + to_string(numPermutations[i].num3) + opPermutations[k].at(2) + to_string(numPermutations[i].num4);
            std::cout << "Testing: " << testy;

            std::string firstJoint = to_string(numPermutations[i].num1) + opPermutations[k].at(0) + to_string(numPermutations[i].num2);
            std::string secondJoint = opPermutations[k].at(1) + to_string(numPermutations[i].num3);
            std::string thirdJoint = opPermutations[k].at(2) + to_string(numPermutations[i].num4);

            // Test the equation

            ExpressionParser <int> parser;
            int firstJointEval = parser.eval(firstJoint);
            int secondJointEval = parser.eval(to_string(firstJointEval) + secondJoint);
            int thirdJointEval = parser.eval(to_string(secondJointEval) + thirdJoint);

            if (thirdJointEval == this -> goal)
            {
                std::cout << " SUCCESS\n";
                answerSlots.push_back(testy);
            }
            else
            {
                std::cout << " FAIL\n";
            }

        }

    }

    return answerSlots;

}

/* Converts integers to string integers */

std::string Algo::to_string(int number)
{
    std::stringstream ss;
    ss << number;
    return ss.str();
}

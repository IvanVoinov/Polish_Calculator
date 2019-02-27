#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <limits>
#include "calculator.h"

static const char DELIM(' ');
static const size_t VAL_ARR_SIZE = 2;
static const size_t LAST_TO_PARSE = 1;
static const double INVALID_RESULT = 0;

//std::numeric_limits<double>::max();
//std::numeric_limits<double>::min();

bool checkOperations(const char c)
{
    return (c == '+')
           || (c == '-')
           || (c == '*')
           || (c == '/');
}

bool checkAditionSpaces(const std::string & str)
{
    return str.empty();
}

//bool checkSign(const char c)
//{
//    return c == '+' || c == '-'
//}

void mathOperations(const char c, std::vector< double > & arr)
{
    double result = 0;
    std::cout << "Operation result: " << c << std::endl;
    if (c == '+')
    {
        result = arr[0] + arr[1];
        std::cout << "Result: " << arr[0] + arr[1] << std::endl;
    }
    else if (c == '-')
    {
        result = arr[0] - arr[1];
        std::cout << "Result: " << arr[0] - arr[1] << std::endl;
    }
    else if (c == '*')
    {
        result = arr[0] * arr[1];
        std::cout << "Result: " << arr[0] * arr[1] << std::endl;
    }
    else if (c == '/')
    {
        if (static_cast<int>(arr[1]) == 0)
        {
            //TODO think about errors handling
            std::cout << "You can't devide on zero!" << std::endl;
            result = INVALID_RESULT;
        }
        else
        {
            result = arr[0] / arr[1];
            std::cout << "Result: " << arr[0] / arr[1] << std::endl;
        }
    }

    arr.clear();
    arr.push_back(result);
    std::cout << "Result operations: " <<  arr[0] << std::endl;
}

double calculate(const std::string & eval)
{
    if (eval.empty() )
    {
        std::cout << "Emty input string!!" << std::endl;
        return INVALID_RESULT;
    }

    std::vector<double> valArr;
    size_t beginPos = 0, delimPos = 0, diffSize = 0;

    std::string tempCopy(eval);

    while (!tempCopy.empty() )
    {
        delimPos = tempCopy.find(DELIM, beginPos);
        diffSize = delimPos - beginPos;

        std::string str(tempCopy, beginPos, diffSize);
        std::cout << str << " \nstr.size(" << str.size() << ")" << std::endl;
        for (size_t i = 0; i != str.size(); i++)
        {
            if (isalpha(str[i]) && ('e' != str[i]) )
            {
                return INVALID_RESULT;
            }
        }

        if (tempCopy.size() == LAST_TO_PARSE)
        {
            tempCopy.clear();
        }

        if (checkOperations(str[0]) && str.size() == LAST_TO_PARSE)
        {
            if (valArr.size() < VAL_ARR_SIZE)
            {
                return INVALID_RESULT;
            }
            mathOperations(str[0], valArr);
        }
        else if (checkAditionSpaces(str) )
        {
            tempCopy.erase(beginPos, diffSize + 1);
            continue;
        }
        else
        {
            std::cout << "Added to vector: " << std::stod(str) << std::endl;

            valArr.push_back(std::stod(str.c_str() ) );
            //use separete method
            if (valArr.size() > VAL_ARR_SIZE)
            {
                return INVALID_RESULT;
            }
        }

        tempCopy.erase(beginPos, diffSize + 1);
//        std::cout << "Left to parse:" << std::endl;
//        for (int i = 0; i < tempCopy.size(); i++)
//        {
//            std::cout << tempCopy[i] << std::endl;
//        }
    }
    return valArr[0];
}

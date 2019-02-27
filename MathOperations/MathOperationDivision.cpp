#include "MathOperationDivision.h"

MathOperationDivision::MathOperationDivision()
{

}

MathOperationDivision::~MathOperationDivision()
{

}

double MathOperationDivision::executeOperation(const double firstVal, const double secondVal)
{
    //TODO use constants in the future
    if (static_cast<int>(secondVal) == 0)
    {
        return 0;
    }
    else
    {
        return firstVal / secondVal;
    }

}

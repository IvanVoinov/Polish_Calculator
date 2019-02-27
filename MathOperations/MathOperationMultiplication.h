#ifndef MATHOPERATIONMULTIPLICATION_H
#define MATHOPERATIONMULTIPLICATION_H

#include "MathOperationsBase.h"

class MathOperationMultiplication : public MathOperationsBase
{
public:
    MathOperationMultiplication();
    virtual ~MathOperationMultiplication();
    virtual double executeOperation(const double firstVal, const double secondVal);
};

#endif // MATHOPERATIONMULTIPLICATION_H

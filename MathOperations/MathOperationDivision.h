#ifndef MATHOPERATIONDIVISION_H
#define MATHOPERATIONDIVISION_H

#include "MathOperationsBase.h"


class MathOperationDivision : public MathOperationsBase
{
public:
    MathOperationDivision();
    virtual ~MathOperationDivision();
    virtual double executeOperation(const double firstVal, const double secondVal);
};

#endif // MATHOPERATIONDIVISION_H

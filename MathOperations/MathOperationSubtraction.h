#ifndef MATHOPERATIONSUBTRACTION_H
#define MATHOPERATIONSUBTRACTION_H

#include "MathOperationsBase.h"

class MathOperationSubtraction : public MathOperationsBase
{
public:
    MathOperationSubtraction();
    virtual ~MathOperationSubtraction();
    virtual double executeOperation(const double firstVal, const double secondVal);
};

#endif // MATHOPERATIONSUBTRACTION_H

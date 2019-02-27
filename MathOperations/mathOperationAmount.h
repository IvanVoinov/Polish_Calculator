#ifndef MATHOPERATIONAMOUNT_H
#define MATHOPERATIONAMOUNT_H

#include "MathOperationsBase.h"


class MathOperationAmount : public MathOperationsBase
{
public:
    MathOperationAmount();
    virtual ~MathOperationAmount();
    virtual double executeOperation(const double firstVal, const double secondVal) final;
};

#endif // MATHOPERATIONAMOUNT_H

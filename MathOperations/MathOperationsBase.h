#ifndef MATHOPERATIONSBASE_H
#define MATHOPERATIONSBASE_H


class MathOperationsBase
{
public:
    MathOperationsBase();
    virtual double executeOperation(const double firstVal, const double secondVal) = 0;
    virtual ~MathOperationsBase() = 0;
};

#endif // MATHOPERATIONSBASE_H

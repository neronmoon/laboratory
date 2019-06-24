#include "contract.h"

class Group
{
public:
    Group(int length);

    ~Group();

    void Print();

    int Size();

    void PutContract(int i, Contract &Contract);

    Contract &GetContract(int i);

    double Average();

    double Average(int limit);

    Contract &operator[](int i);

private:
    int length;
    Contract *contracts;
};

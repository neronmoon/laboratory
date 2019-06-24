#include "group.h"
#include <iostream>

using namespace std;

Group::Group(int length)
{
    this->length = length;
    this->contracts = new Contract[length];
};

Group::~Group()
{
    delete[] this->contracts;
}

void Group::Print()
{
    for (int i = 0; i < this->length; ++i)
    {
        this->contracts[i].Print();
    }
}

int Group::Size()
{
    return this->length;
}

void Group::PutContract(int i, Contract &Contract)
{
    this->contracts[i] = Contract;
}

Contract &Group::GetContract(int i)
{
    return this->contracts[i];
}

// Вычисление среднего-арифметического площадей стран в группе
double Group::Average()
{
    double sum = 0;
    for (int i = 0; i < this->length; ++i)
    {
        sum += this->contracts[i];
    }
    return sum / this->length;
}

// Вычисление среднего-арифметического площадей, не превышающих limit
double Group::Average(int limit)
{
    double sum = 0;
    int count = 0;
    for (int i = 0; i < this->length; ++i)
    {
        if (this->contracts[i] <= limit)
        {
            sum += this->contracts[i];
            count++;
        }
    }
    return sum / count;
}

// позволяет написать group[5]
Contract &Group::operator[](int i)
{
    return this->contracts[i];
}

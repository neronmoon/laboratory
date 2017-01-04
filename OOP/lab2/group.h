#include "country.h"

class Group {
public:
    Group(int length);

    ~Group();

    void Print();

    int Size();

    void PutCountry(int i, Country &country);

    Country &GetCountry(int i);

    double Area();

    double Area(int limit);

    Country &operator[](int i);

private:
    int length;
    Country *countries;
};
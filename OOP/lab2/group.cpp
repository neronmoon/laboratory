#include "group.h"
#include <iostream>

using namespace std;

Group::Group(int length) {
    this->length = length;
    this->countries = new Country[length];
};

Group::~Group() {
    delete[]this->countries;
}

void Group::Print() {
    for (int i = 0; i < this->length; ++i) {
        this->countries[i].Print();
    }
}

int Group::Size() {
    return this->length;
}

void Group::PutCountry(int i, Country &country) {
    this->countries[i] = country;
}

Country &Group::GetCountry(int i) {
    return this->countries[i];
}

// Вычисление среднего-арифметического площадей стран в группе
double Group::Area() {
    double sum = 0;
    for (int i = 0; i < this->length; ++i) {
        sum += this->countries[i];
    }
    return sum / this->length;
}

// Вычисление среднего-арифметического площадей, не превышающих limit
double Group::Area(int limit) {
    double sum = 0;
    int count = 0;
    for (int i = 0; i < this->length; ++i) {
        if (this->countries[i] <= limit) {
            sum += this->countries[i];
            count++;
        }
    }
    return sum / count;
}

// позволяет написать group[5]
Country &Group::operator[](int i) {
    return this->countries[i];
}

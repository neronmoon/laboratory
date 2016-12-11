#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "main.h"

using namespace std;

Country::Country() {
    strcpy(name, "<country name>");
    strcpy(polity, "<country polity>");
    area = 0.f;
}

Country::Country(char *name, char *polity, float area) {
    strcpy(this->name, name);
    strcpy(this->polity, polity);
    this->area = area;
}

void Country::Print() {
    cout << "Country " << name << " has " << polity << " polity and area " << area << endl;
}

void Country::Input() {
    cin >> name >> polity >> area;
}


int main() {
    Country c1("Russia", "Republican", 99999.f);
    c1.Print();

    Country *c2 = new Country;
    c2->Print();
    delete (c2);

    Country c3;
    cout << "Enter new country" << endl;
    c3.Input();
    c3.Print();

    return 0;
}
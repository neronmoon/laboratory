// Полдключаем библиотеки
#include <stdlib.h>
#include <string.h>
#include <iostream>

// подключаем заголовок нашего класса
#include "country.h"

// мне не хочется писать std::<<cout так что пусть я сразу буду находится в std окружении
using namespace std;

// Реализация конструктора без аргументов
Country::Country() {
    // Присваиваем значение this->name = <country_name>
    strcpy(name, "<country name>");
    strcpy(polity, "<country polity>");
    // по умолчанию у несуществующей страны нет площади
    area = 0.f;
}

// Реализация конструктора с аргументами
Country::Country(char *name, char *polity, float area) {
    strcpy(this->name, name);
    strcpy(this->polity, polity);
    this->area = area;
}

// Реализация метода вывода
void Country::Print() {
    cout << "Country " << name << " has " << polity << " polity and area " << area << endl;
}

// Реализация метода ввода
void Country::Input() {
    cin >> name >> polity >> area;
}

// реализация оператора приведения типа
Country::operator double() {
    return this->area;
}

// реализация оператора сложения
double operator+(Country &c1, Country &c2) {
    return c1.area + c2.area;
}


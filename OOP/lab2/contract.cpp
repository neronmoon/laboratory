// Полдключаем библиотеки
#include <stdlib.h>
#include <string.h>
#include <iostream>

// подключаем заголовок нашего класса
#include "contract.h"

// мне не хочется писать std::<<cout так что пусть я сразу буду находится в std окружении
using namespace std;

// Реализация конструктора без аргументов
Contract::Contract()
{
    // Присваиваем значение this->number = <Contract_number>
    number = 123123;
    strcpy(director, "<Contract director>");
    // по умолчанию у несуществующей страны нет площади
    summ = 0.f;
}

// Реализация конструктора с аргументами
Contract::Contract(int number, char *director, float summ)
{
    this->number = number;
    strcpy(this->director, director);
    this->summ = summ;
}

// Реализация метода вывода
void Contract::Print()
{
    cout << "Contract " << number << " has " << director << " director and summ " << summ << endl;
}

// Реализация метода ввода
void Contract::Input()
{
    cin >> number >> director >> summ;
}

// реализация оператора приведения типа
Contract::operator double()
{
    return this->summ;
}

// реализация оператора сложения
double operator+(Contract &c1, Contract &c2)
{
    return c1.summ + c2.summ;
}

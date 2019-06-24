// Полдключаем библиотеки
#include <stdlib.h>
#include <string.h>
#include <iostream>
// подключаем заголовок нашего класса
#include "main.h"

// мне не хочется писать std::<<cout так что пусть я сразу буду находится в std окружении
using namespace std;

// Реализация конструктора без аргументов
Contract::Contract()
{
    // Присваиваем значение this->number = <Contract_number>
    this->number = 123;
    this->director = "<Unknown director>";
    this->summ = 100500.10;
}

// Реализация конструктора с аргументами
Contract::Contract(int number, char *director, float summ)
{
    this->number = number;
    this->director = director;
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

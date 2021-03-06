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

int main()
{
    Contract c1(200, "Vasiliy", 99999.f); // Создаем "статический" объект с1
    c1.Print();

    Contract *c2 = new Contract; // создаем динамический объект с2
    c2->Print();                 // -> Contract <Contract name> has <Contract director> director and summ 0
    delete (c2);                 // удаляем объект

    Contract c3;                          // создаем статический объект с3
    cout << "Enter new Contract" << endl; // Пишем в консоль чего ожидаем от пользователя
    c3.Input();                           // Вводим данные
    c3.Print();                           // выводим данные

    return 0; // мы завершились успешно!
}

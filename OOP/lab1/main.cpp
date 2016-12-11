// Полдключаем библиотеки
#include <stdlib.h>
#include <string.h>
#include <iostream>
// подключаем заголовок нашего класса
#include "main.h"

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


int main() {
    Country c1("Russia", "Republican", 99999.f); // Создаем "статический" объект с1
    c1.Print(); // -> Country Russia has Repoblican polity and area 99999

    Country *c2 = new Country; // создаем динамический объект с2
    c2->Print(); // -> Country <country name> has <country polity> polity and area 0
    delete (c2); // удаляем объект

    Country c3; // создаем статический объект с3
    cout << "Enter new country" << endl; // Пишем в консоль чего ожидаем от пользователя
    c3.Input(); // Вводим данные
    c3.Print(); // выводим данные

    return 0; // мы завершились успешно!
}
#include <iostream>
#include "group.h"


int main() {

    // данные для тестирования
    char names[5][25] = {"Russia", "USA", "Ukraine", "Finland", "Japan"};
    char polities[5][25] = {"Foobar", "keklol", "barbaz", "bazwut", "wutfoo"};
    float areas[5] = {120.f, 130.f, 140.f, 150.f, 160.f};

    // заполняем группу
    Group group(5);
    for (int i = 0; i < 5; ++i) {
        Country c(names[i], polities[i], areas[i]); // создаем объект
        group.PutCountry(i, c); // заносим его в группу
    }

    group.Print(); // пробуем вывести всю группу

    std::cout <<  group.GetCountry(2) << std::endl; // тест получения страны по айди

    // тест методов вычисления площадей
    std::cout << group.Area() << std::endl;
    std::cout << group.Area(130) << std::endl;

//    Country country = group.GetCountry(2);
//    Country country = group[2]; // <- that's better

    // тест оператора индексирования
    group[3].Print();

    // тест оператора сложения
    double sum = group[1] + group[3];
    std::cout << sum << std::endl;

    return 0;
}
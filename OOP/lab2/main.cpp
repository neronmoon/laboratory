#include <iostream>
#include "group.h"

int main()
{
    // данные для тестирования
    char directors[3][25] = {"Fedor", "Vasiliy", "Vitaliy"};
    int numbers[3] = {123, 321, 456};
    float summs[3] = {320.5, 500.5, 100};

    // заполняем группу
    Group group(5);
    for (int i = 0; i < 5; ++i)
    {
        Contract c(numbers[i], directors[i], summs[i]); // создаем объект
        group.PutContract(i, c);                        // заносим его в группу
    }

    group.Print(); // пробуем вывести всю группу

    std::cout << group.GetContract(2) << std::endl; // тест получения страны по айди

    // тест методов вычисления площадей
    std::cout << group.Average() << std::endl;
    std::cout << group.Average(130) << std::endl;

    //    Contract Contract = group.GetContract(2);
    //    Contract Contract = group[2]; // <- that's better

    // тест оператора индексирования
    group[3].Print();

    // тест оператора сложения
    double sum = group[1] + group[3];
    std::cout << sum << std::endl;

    return 0;
}

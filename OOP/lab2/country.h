//Это заголовочный файл

// объявляем класс Страна
class Country {
    // объявляем методы и констукторы
    // По-умолчанию они и так были бы public, но почему бы и не написать
public:
    Country(char *name, char *polity, float area);

    Country();

    void Print();

    void Input();

    operator double ();

    friend double operator+(Country& c1, Country& c2);

private: // Приватные свойства. Здесь хранятся данные
    char name[25];
    char polity[25];
    float area;
};
//Это заголовочный файл

// объявляем класс Договор
class Contract
{
    // объявляем методы и констукторы
    // По-умолчанию они и так были бы public, но почему бы и не написать
public:
    Contract();

    Contract(int number, char *director, float summ);

    void Print();

    void Input();

    operator double();

    friend double operator+(Contract &c1, Contract &c2);

private: // Приватные свойства. Здесь хранятся данные
    int number;
    char director[25];
    float summ;
};

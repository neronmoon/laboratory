//Это заголовочный файл

// объявляем класс Договор
class Contract
{
    // объявляем методы и констукторы
    // По-умолчанию они и так были бы public, но почему бы и не написать
public:
    Contract(int number, char *director, float summ);

    Contract();

    void Print();
    void Input();

private: // Приватные свойства. Здесь хранятся данные
    int number;
    char *director;
    float summ;
};

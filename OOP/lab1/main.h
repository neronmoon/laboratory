class Country {
public:
    Country(char *name, char *polity, float area);

    Country();

    void Print();
    void Input();

private:
    char name[25];
    char polity[25];
    float area;
};

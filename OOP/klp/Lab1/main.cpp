#include <iostream>

using namespace std;

class Exam
{
public:
    char *name;
    int date;
    int score;

    Exam()
    {
        name = (char *)"Krasnoperov Vitaliy";
        date = 20190618;
        score = 5;
        this->print((char *)"Constructed!");
    };

    Exam(char *name, int date, int score)
    {
        this->name = name;
        this->date = date;
        this->score = score;
        this->print((char *)"Constructed!");
    }

    char *getName()
    {
        return name;
    }

    void setName(char *name)
    {
        this->name = name;
    }

    int getDate()
    {
        return date;
    }
    void setDate(int date)
    {
        this->date = date;
    }
    int getScore()
    {
        return score;
    }
    void setScore(int score)
    {
        this->score = score;
    }
    ~Exam()
    {
        this->print((char *)"Desctucted!");
    };

    void print(char *suffix)
    {
        cout << "Exam:"
             << " name: " << name
             << " date: " << date
             << " score: " << score
             << " " << suffix << endl;
    };
};

int main()
{
    Exam *exam = new Exam();

    exam->setDate(20190617);
    exam->setName((char *)"Kekus Pekus");
    exam->setScore(4);

    delete exam;

    Exam *newExam = new Exam((char *)"Sergey Krasnoperov", 19980202, 5);

    void (Exam::*printFunction)(char *);
    printFunction = &Exam::print;

    (newExam->*printFunction)((char *)"Is Awesome!");

    delete newExam;

    return 0;
}

#ifndef LAB3_OOP_CLASS_H
#define LAB3_OOP_CLASS_H

#define Border std::cout << "=================================" << std::endl;

#include <iostream>
#include <string>
#include <cmath>

typedef struct Elem
{
    int num = 0;
    std::string str;
} Elem;

class Stack {
private:
    Elem* Array;
    int Stackpointer;
    int Max_size;

public:
    Stack()
    {
        Array = new Elem[10];
        Stackpointer = 10;
        Max_size = 10;
    }
    ~Stack()
    {
        delete [] Array;
    }

    void Set_int (int num);
    void Set_str (std::string & str);
    void Set_array (Elem *array, int size);

    int Get_int ();
    std::string Get_str ();
    [[nodiscard]] int Get_size () const;

    void Push (int & num, std::string & str);
    Elem Pop ();

    [[nodiscard]] int Check () const;
};

template <typename T>
int getNum(T &Num);

void getStr (std::string & Str);

template <typename T>
T* Realloc (T* ptr, int size);

void Show_stack (Stack & S);
void New_Elem (Stack & S);
void Last_Elem (Stack & S);
void Condition_of_stack (Stack & S);
void Delete_all (Stack & S);
void Enter_array (Stack & S);

#endif //LAB3_OOP_CLASS_H

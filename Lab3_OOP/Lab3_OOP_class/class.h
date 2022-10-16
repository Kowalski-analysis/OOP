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
        Max_size = 3;
        Array = new Elem[Max_size];
        Stackpointer = 0;
    }
    Stack(const Stack & S) : Stackpointer(S.Stackpointer), Max_size(S.Max_size)
    {
        Array = new Elem[S.Max_size];
        int size = S.Get_size();
        for (int i = 0; i < size; ++i)
        {
            this->Array[i].num = S.Array[i].num;
            this->Array[i].str = S.Array[i].str;
        }
    }
    ~Stack()
    {
        delete [] Array;
    }

    void Set_int (int num);
    void Set_str (std::string & str);
    void Set_array (Elem *array, int size);

    std::string Get_prev_elem ();
    [[nodiscard]] int Get_size () const;

    int Push (int & num, std::string & str);
    int Pop (Elem & el);

    [[nodiscard]] int Check () const;

    friend std::ostream & operator << (std::ostream & out, Stack & S);
    Elem operator -- ();
    Elem operator -- (int value);
    Stack & operator + (Elem & parameter);
    Stack & operator = (const Stack & S);
    Stack & operator = (Stack && S) noexcept;
};

template <typename T>
int getNum(T &Num);
void getStr (std::string & Str);

Elem* Realloc (Elem* ptr, int size);

void Show_stack (Stack & S);
void New_Elem (Stack & S);
void Last_Elem (Stack & S);
void Condition_of_stack (Stack & S);
void Delete_all (Stack & S);
void Enter_array (Stack & S);
void Show_prev_elem (Stack & S);

#endif //LAB3_OOP_CLASS_H

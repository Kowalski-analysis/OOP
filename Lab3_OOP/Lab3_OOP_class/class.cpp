#include "class.h"

void Stack::Set_int (int num)
{
    Array[Stackpointer].num = num;
}
void Stack::Set_str (std::string & str)
{
    Array[Stackpointer].str = std::move(str);
}
void Stack::Set_array (Elem *array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        Push(array[i].num, array[i].str);
    }
    delete [] array;
}

std::string Stack::Get_prev_elem ()
{
    return Array[Stackpointer].str;
}
int Stack::Get_size () const
{
    return Stackpointer;
}

int Stack::Push (int & num, std::string & str)
{
    if (num == INT32_MIN)
        return 1;
    if (Stackpointer == Max_size && Stackpointer != 0) {
        Array = Realloc(Array, Max_size);
        Max_size = Max_size * 2;
    }
    Set_int(num);
    std::string buf = std::move(str);
    Set_str(buf);
    ++Stackpointer;
    return 0;
}
int Stack::Pop (Elem & el)
{
    if (Stackpointer == 0)
    {
        return 1;
    }
    --Stackpointer;
    el = Array[Stackpointer];
    return 0;
}

int Stack::Check () const
{
    if (Stackpointer < 0)
    {
        throw std::runtime_error ("Stack size error");
    }
    if (Stackpointer == Max_size)
    {
        return 1;
    }
    if (Stackpointer == 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

Elem Stack::operator -- ()
{
    Elem buf;
    if (Get_size())
    {
        Pop(buf);
        Show_stack(*this);
    }
    else
    {
        buf.str = "Stack is empty\n";
        buf.num = INT32_MIN;
    }
    return buf;
}
Elem Stack::operator -- (int value) {
    Elem buf;
    if (Get_size())
    {
        Show_stack(*this);
        Pop(buf);
    }
    else
    {
        buf.str = "Stack is empty\n";
        buf.num = INT32_MIN;
    }
    return buf;
}
Stack & Stack::operator + (Elem & parameter) {
    Push(parameter.num, parameter.str);
    return *this;
}
std::ostream & operator << (std::ostream & out, Stack & S)
{
    out << "Max size of stack: " << S.Max_size << std::endl;
    out << "Current size of stack: " << S.Stackpointer << std::endl;
    Show_stack(S);
    return out;
}
Stack & Stack::operator = (const Stack & S)
{
    if (this != &S)
    {
        this->Max_size = S.Max_size;
        this->Stackpointer = S.Stackpointer;
        Elem buf;
        int size = S.Get_size();
        delete [] this->Array;
        this->Array = new Elem[Max_size];
        for (int i = 0; i < size; ++i)
        {
            this->Array[i].num = S.Array[i].num;
            this->Array[i].str = S.Array[i].str;
        }
    }
    return *this;
}
Stack & Stack::operator = (Stack && S) noexcept
{
    int buf = Stackpointer;
    Stackpointer = S.Stackpointer;
    S.Stackpointer = buf;
    buf = Max_size;
    Max_size = S.Max_size;
    S.Max_size = buf;
    Elem* buf_arr = Array;
    Array = S.Array;
    S.Array = buf_arr;
    return *this;
}

template <typename T>
int getNum (T &Num)
{
    while (!(std::cin >> Num) || Num == INT32_MIN)
    {
        if (std::cin.eof()) // If we have reached EOF, break of the loop or exit.
            return -1; // End of stream;

        std::cin.clear(); // Clear the error state of the stream.

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore rest of the line.

        std::cout << "Invalid value" << std::endl; // Ask more fresh input.
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 1;
}
void getStr (std::string & Str) {
    std::cin >> Str;
}

Elem* Realloc (Elem* ptr, int size)
{
    Elem* new_ptr = new Elem[2 * size];
    for (int i = 0; i < size; ++i) {
        new_ptr[i].num = ptr[i].num;
        new_ptr[i].str = ptr[i].str;
    }
    delete [] ptr;
    return new_ptr;
}

void Show_stack (Stack & S)
{
    Stack S_Copy;
    Elem buf;
    int size = S.Get_size();
    if (size == 0)
    {
        std::cout << "Stack is empty" << std::endl;
        return;
    }
    for (int i = 0; i < size; ++i)
    {
        S.Pop(buf);
        S_Copy.Push(buf.num, buf.str);
    }
    Border
    for (int i = 0; i < size; ++i)
    {
        S_Copy.Pop(buf);
        std::cout << "Element №" << i + 1 << '\t' << buf.num << '\t' << buf.str << std::endl;
        S.Push(buf.num, buf.str);
    }
    Border
}
void New_Elem (Stack & S)
{
    int Num;
    std::string Str;
    std::cout << "Enter a number (the 1st parameter)" << std::endl;
    getNum(Num);
    std::cout << "Enter a string (the 2nd parameter)" << std::endl;
    getStr(Str);
    if (S.Push(Num, Str))
    {
        std::cout << "Invalid element" << std::endl;
    }
}
void Last_Elem (Stack & S)
{
    Elem buf;
    if (S.Pop(buf))
    {
        std::cout << "Stack is empty" << std::endl;
    }
    else
    {
        std::cout << "Element №" << S.Get_size() + 1 << '\t' << buf.num << '\t' << buf.str << std::endl;
    }
}
void Condition_of_stack (Stack & S)
{
    try
    {
        int cond = S.Check();
        if (cond == 1)
        {
            std::cout << "Stack has " << S.Get_size() << " element(s)" << std::endl;
            std::cout << "Stack is full" << std::endl;
        }
        if (cond == -1)
        {
            std::cout << "Stack is empty" << std::endl;
        }
        if (cond == 0)
        {
            std::cout << "Stack has " << S.Get_size() << " element(s)" << std::endl;
        }
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
    }
}
void Delete_all (Stack & S)
{
    int size = S.Get_size();
    Elem buf;
    for (int i = 0; i < size; ++i)
    {
        S.Pop(buf);
    }
    std::cout << "Stack is empty" << std::endl;

}
void Enter_array (Stack & S)
{
    int size;
    do
    {
        std::cout << "Enter a positive size of a massive" << std::endl;
        getNum(size);
    } while (size <= 0);
    Elem *array = new Elem[size];
    for (int i = 0; i < size; ++i) {
        std::cout << "Enter " << i + 1 << " element of massive" << std::endl;
        std::cout << "Enter a number" << std::endl;
        getNum(array[i].num);
        std::cout << "Enter a string" << std::endl;
        std::cin >> array[i].str;
    }
    S.Set_array(array, size);
}
void Show_prev_elem (Stack & S)
{
    std::cout << S.Get_prev_elem() << std::endl;
}

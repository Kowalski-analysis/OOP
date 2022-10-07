#include "class.h"

void Stack::Set_int (int num)
{
    Array[Max_size - Stackpointer].num = num;
}
void Stack::Set_str (std::string & str)
{
    std::string buf = std::move(str);
    Array[Max_size - Stackpointer].str = buf;
}
void Stack::Set_array (Elem *array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (Stackpointer == 0)
        {
            delete [] array;
            throw std::runtime_error ("Stack is overflow");
        }
        Push(array[i].num, array[i].str);
    }
    delete [] array;
}

int Stack::Get_int ()
{
    return Array[Max_size - Stackpointer].num;
}
std::string Stack::Get_str ()
{
    return Array[Max_size - Stackpointer].str;
}
int Stack::Get_size () const
{
    return Max_size - Stackpointer;
}

void Stack::Push (int & num, std::string & str)
{
    if (Stackpointer == 0) {
        throw std::runtime_error ("Stack is overflow");
    }
    Set_int(num);
    std::string buf = std::move(str);
    Set_str(buf);
    --Stackpointer;
}
Elem Stack::Pop ()
{
    if (Stackpointer == Max_size)
    {
        throw std::runtime_error ("Stack is empty");
    }
    ++Stackpointer;
    return Array[Max_size - Stackpointer];
}

int Stack::Check () const
{
    if (Stackpointer < 0)
    {
        throw std::runtime_error ("Stack size error");
    }
    if (Stackpointer == 0)
    {
        return 1;
    }
    if (Stackpointer == Max_size)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

template <typename T>
int getNum (T &Num)
{
    while (!(std::cin >> Num))
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

template <typename T>
T* Realloc (T* ptr, int size)
{
    T* new_ptr = new T[size + 1];
    for (int i = 0; i < size; ++i) {
        new_ptr[i] = ptr[i];
    }
    delete [] ptr;
    return new_ptr;
}

void Show_stack (Stack & S)
{
    try {
        Stack S_Copy;
        int size = S.Get_size();
        for (int i = 0; i < size; ++i)
        {
            Elem buf = S.Pop();
            S_Copy.Push(buf.num, buf.str);
        }
        Border
        for (int i = 0; i < size; ++i)
        {
            Elem buf = S_Copy.Pop();
            std::cout << "Element №" << i + 1 << '\t' << buf.num << '\t' << buf.str << std::endl;
            S.Push(buf.num, buf.str);
        }
        Border
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
    }
}
void New_Elem (Stack & S)
{
    try
    {
        int Num;
        std::string Str;
        std::cout << "Enter a number (the 1st parameter)" << std::endl;
        getNum(Num);
        std::cout << "Enter a string (the 2nd parameter)" << std::endl;
        getStr(Str);
        S.Push(Num, Str);
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
    }
}
void Last_Elem (Stack & S)
{
    try
    {
        Elem buf = S.Pop();
        std::cout << "Element №" << S.Get_size() + 1 << '\t' << buf.num << '\t' << buf.str << std::endl;
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
    }
}
void Condition_of_stack (Stack & S)
{
    try
    {
        int cond = S.Check();
        if (cond == 1)
        {
            std::cout << "Stack is overflow" << std::endl;
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
    for (int i = 0; i < size; ++i)
    {
        S.Pop();
    }
    std::cout << "Stack is empty" << std::endl;
}
void Enter_array (Stack & S)
{
    try
    {
        int size;
        std::cout << "Enter a size of a massive" << std::endl;
        getNum(size);
        if (size <= 0)
        {
            throw std::runtime_error ("Size of a massive must be positive");
        }
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
    catch (std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
    }
}

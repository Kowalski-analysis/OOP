#include "gtest/gtest.h"
#include "class.h"

TEST (Constructor, Default)
{
    Stack S;
    Elem E;
    ASSERT_EQ(0, S.Get_size());
    S.Pop(E);
    ASSERT_EQ(1, S.Pop(E));
    ASSERT_EQ(-1, S.Check());
}

TEST (Method, Get_size)
{
    Stack S;
    Elem E;
    ASSERT_EQ(0, S.Get_size());
    std::string str1;
    std::string str2 = "X";
    for (int i = 0; i < 12; ++i)
    {
        str1 += str2;
        ASSERT_NO_THROW(S.Push(i, str1));
    }
    int i = 5;
    ASSERT_NO_THROW(S.Push(i, str1));
    ASSERT_EQ(13, S.Get_size());
    S.Pop(E);
    ASSERT_EQ(i, E.num);
    ASSERT_EQ(12, S.Get_size());
}

TEST (Method, Push_and_Pop)
{
    Stack S;
    Elem E;
    std::string str1;
    std::string str2 = "X";
    for (int i = 0; i < 10; ++i)
    {
        str1 += str2;
        S.Push(i, str1);
        S.Pop(E);
        ASSERT_EQ(i, E.num);
    }
}

TEST (Method, Set_array)
{
    Stack S;
    Elem E;
    Elem *array = new Elem[12];
    std::string str1;
    std::string str2 = "X";
    for (int i = 0; i < 12; ++i)
    {
        str1 += str2;
        array[i].str = str1;
        array[i].num = i;
    }
    S.Set_array(array, 12);
    S.Pop(E);
    ASSERT_EQ(11, E.num);
}

TEST (Method, Check)
{
    Stack S;
    Elem E;
    ASSERT_EQ(-1, S.Check());
    std::string str1;
    std::string str2 = "X";
    for (int i = 0; i < 5; ++i)
    {
        str1 += str2;
        S.Push(i, str1);
        S.Pop(E);
        ASSERT_EQ(i, E.num);
    }
    ASSERT_EQ(-1, S.Check());
    for (int i = 5; i < 10; ++i)
    {
        str1 += str2;
        S.Push(i, str1);
        S.Pop(E);
        ASSERT_EQ(i, E.num);
    }
    ASSERT_EQ( -1, S.Check());
}

TEST (Operators, Overloaded)
{
    Stack S;
    Elem E;
    ASSERT_EQ(-1, S.Check());
    std::string str1;
    std::string str2 = "X";
    for (int i = 0; i < 5; ++i)
    {
        str1 += str2;
        S.Push(i, str1);
    }
    Stack A(S);
    E = S--;
    ASSERT_EQ(E.num, 4);
    E = --S;
    ASSERT_EQ(E.num, 3);
    S = S + E;
    E = S--;
    ASSERT_EQ(E.num, 3);
    Delete_all(S);
    ASSERT_EQ(0, S.Get_size());
    E = --S;
    ASSERT_EQ(INT32_MIN, E.num);
}
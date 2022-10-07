#include "gtest/gtest.h"
#include "class.h"

TEST (Constructor, Default)
{
    Stack S;
    ASSERT_EQ(0, S.Get_size());
    ASSERT_ANY_THROW(S.Pop());
    ASSERT_EQ(-1, S.Check());
}

TEST (Method, Get_size)
{
    Stack S;
    ASSERT_EQ(0, S.Get_size());
    std::string str1;
    std::string str2 = "X";
    for (int i = 0; i < 12; ++i)
    {
        str1 += str2;
        if (i < 10)
        {
            (S.Push(i, str1));
        }
        else
        {
            ASSERT_ANY_THROW(S.Push(i, str1));
        }
    }
    int i = 5;
    ASSERT_ANY_THROW(S.Push(i, str1));
    ASSERT_EQ(10, S.Get_size());
    ASSERT_NO_THROW(S.Pop());
    ASSERT_EQ(9, S.Get_size());
}

TEST (Methods, Push_and_Pop)
{
    Stack S;
    std::string str1;
    std::string str2 = "X";
    for (int i = 0; i < 10; ++i)
    {
        str1 += str2;
        S.Push(i, str1);
        ASSERT_EQ(i, S.Pop().num);
    }
}

TEST (Method, Set_array)
{
    Stack S;
    Elem *array = new Elem[12];
    std::string str1;
    std::string str2 = "X";
    for (int i = 0; i < 12; ++i)
    {
        str1 += str2;
        array[i].str = str1;
        array[i].num = i;
    }
    ASSERT_ANY_THROW(S.Set_array(array, 12));
    ASSERT_EQ(9, S.Pop().num);
    delete [] array;
}

TEST (Method, Check)
{
    Stack S;
    ASSERT_EQ(-1, S.Check());
    std::string str1;
    std::string str2 = "X";
    for (int i = 0; i < 5; ++i)
    {
        str1 += str2;
        S.Push(i, str1);
        ASSERT_EQ(i, S.Pop().num);
    }
    ASSERT_EQ(0, S.Check());
    for (int i = 5; i < 10; ++i)
    {
        str1 += str2;
        S.Push(i, str1);
        ASSERT_EQ(i, S.Pop().num);
    }
    ASSERT_EQ( 1, S.Check());
}
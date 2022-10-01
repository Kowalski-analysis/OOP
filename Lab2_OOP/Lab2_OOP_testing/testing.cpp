#include "gtest/gtest.h"
#include "class.h"
#include <iostream>

TEST (Constructor, Constructor)
{
    Hypocycloid H;
    ASSERT_DOUBLE_EQ(4.0, H.Get_R_Extern());
    ASSERT_DOUBLE_EQ(1.0, H.Get_R_Intern());
    ASSERT_DOUBLE_EQ(1.0, H.Get_l());
    ASSERT_DOUBLE_EQ(0.0, H.Get_Coordinates().X);
    ASSERT_DOUBLE_EQ(0.0, H.Get_Coordinates().Y);
}

TEST (Method, Getter_and_Setter_Radii)
{
    Hypocycloid H;
    ASSERT_ANY_THROW(H.Set_Radii(0.0, 0.0));
    ASSERT_ANY_THROW(H.Set_Radii(0.0, 7.0));
    ASSERT_ANY_THROW(H.Set_Radii(3.0, 0.0));
    ASSERT_ANY_THROW(H.Set_Radii(0.0, -12.0));
    ASSERT_ANY_THROW(H.Set_Radii(-8.5, 0.0));
    ASSERT_ANY_THROW(H.Set_Radii(-9.0, -0.5));
    ASSERT_ANY_THROW(H.Set_Radii(2.0, 3.0));
    ASSERT_ANY_THROW(H.Set_Radii(6.2, -1.0));
    ASSERT_NO_THROW(H.Set_Radii(6.0, 0.3));
    ASSERT_DOUBLE_EQ(6.0, H.Get_R_Extern());
    ASSERT_DOUBLE_EQ(0.3, H.Get_R_Intern());
}

TEST (Method, Getten_and_Setter_l)
{
    Hypocycloid H;
    ASSERT_ANY_THROW(H.Set_l(0.0));
    ASSERT_ANY_THROW(H.Set_l(-7.9));
    ASSERT_NO_THROW(H.Set_l(5.0));
    ASSERT_DOUBLE_EQ(5.0, H.Get_l());
}

TEST (Method, Getter_Type)
{
    Hypocycloid H;
    H.Set_Radii(6.0, 4.0);
    H.Set_l(5.0);
    ASSERT_EQ(1, H.GetType());
    H.Set_Radii(6.0, 5.0);
    H.Set_l(5.0);
    ASSERT_EQ(0, H.GetType());
    H.Set_Radii(6.0, 2.56789);
    H.Set_l(2.0);
    ASSERT_EQ(-1, H.GetType());
}

TEST (Method, Setter_and_Getter_Coordinates)
{
    Hypocycloid H;
    double multiplier = 1;
    for (int i = 0; i < 1; ++i) {
        multiplier *= 0.1;
    }
    H.Set_Coordinates(90.0, 1);
    ASSERT_GE(multiplier, H.Get_Coordinates().Y - 4.0);
    ASSERT_GE(multiplier, H.Get_Coordinates().X);
    H.Set_Coordinates(-180.0, 1);
    multiplier = 1;
    for (int i = 0; i < 1; ++i) {
        multiplier *= 0.1;
    }
    ASSERT_GE(multiplier, H.Get_Coordinates().Y);
    ASSERT_GE(multiplier, H.Get_Coordinates().X + 4.0);
    multiplier = 1;
    for (int i = 0; i < 2; ++i) {
        multiplier *= 0.1;
    }
    H.Set_Coordinates(654.0, 2);
    ASSERT_GE(multiplier, H.Get_Coordinates().Y + 3.0495);
    ASSERT_GE(multiplier, H.Get_Coordinates().X - 0.2695);
}

TEST (Method, Square_and_Radius)
{
    double multiplier = 1;
    Hypocycloid H;
    for (int i = 0; i < 5; ++i) {
        multiplier *= 0.1;
    }
    ASSERT_GE(multiplier, H.Get_Radius(44, 5) - 5.99634);
    multiplier = 1;
    for (int i = 0; i < 4; ++i) {
        multiplier *= 0.1;
    }
    multiplier /= 2;
    ASSERT_GE(multiplier, H.Get_Square(35, 4) - 2.3147);
}
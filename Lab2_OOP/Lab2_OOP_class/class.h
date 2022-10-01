#ifndef LAB2_OOP_CLASS_H
#define LAB2_OOP_CLASS_H

#include <iostream>
#include <cmath>

class Hypocycloid {
private:
    typedef struct XY
    {
        double X;
        double Y;
    } XY;

    typedef struct Circles
    {
        double R_Intern;
        double R_Extern;
        double l;
    } Circles;

    Circles Parameters {};

    XY Coordinates {};
public:
    [[nodiscard]] double Get_R_Extern () const;

    [[nodiscard]] double Get_R_Intern () const;

    [[nodiscard]] int GetType () const;

    [[nodiscard]] double Get_l () const;

    void Set_Coordinates (double angle, int count);

    [[nodiscard]] XY Get_Coordinates () const;

    [[nodiscard]] double Get_Radius (double angle, int count) const;

    [[nodiscard]] double Get_Square (double angle, int count) const;

    void Set_Radii (double R_Ex, double R_In);

    void Set_l (double l);

    Hypocycloid()
    {
        Set_Radii(4.0, 1.0);
        Set_l(1.0);
        Coordinates.X = 0.0;
        Coordinates.Y = 0.0;
    }
};

template <typename T>

int getNum(T &a);

void Show_parameters (Hypocycloid Figure);

void Show_radii (Hypocycloid Figure);

void Change_parameters (Hypocycloid *Figure);

void Show_radius_curvature (Hypocycloid Figure);

void Show_coordinates (Hypocycloid Figure);

void Show_type (Hypocycloid Figure);

void Show_square (Hypocycloid Figure);

double Round (double Num, int count);

#endif //LAB2_OOP_CLASS_H

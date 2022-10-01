#include "class.h"

[[nodiscard]] double Hypocycloid::Get_R_Extern () const
{
    return Parameters.R_Extern;
}

[[nodiscard]] double Hypocycloid::Get_R_Intern () const
{
    return Parameters.R_Intern;
}

[[nodiscard]] int Hypocycloid::GetType () const {
    double a = Parameters.l / Parameters.R_Intern;
    if (a > 1)
    {
        return 1;
    }
    if (a == 1)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

[[nodiscard]] double Hypocycloid::Get_l () const
{
    return Parameters.l;
}

void Hypocycloid::Set_Coordinates (double angle, int count)
{
    angle = angle * M_PI / 180;
    double X, Y;
    double R = Parameters.R_Extern;
    double r = Parameters.R_Intern;
    double l = Parameters.l;                                    ///X = (R + r) * cos(angle) - l * cos((R + r) * angle / r)
    X = (R - r) * cos(angle) + l * cos((R - r) / r * angle);    ///
    Y = (R - r) * sin(angle) - l * sin((R - r) / r * angle);    ///Y = (R + r) * sin(angle) - l * sin((R + r) * angle / r)
    X = Round(X, count);
    Y = Round(Y, count);
    Coordinates.X = X;
    Coordinates.Y = Y;
}

[[nodiscard]] Hypocycloid::XY Hypocycloid::Get_Coordinates () const
{
    return Coordinates;
}

[[nodiscard]] double Hypocycloid::Get_Radius (double angle, int count) const
{
    angle *= M_PI / 180;
    double R = Parameters.R_Extern;
    double r = Parameters.R_Intern;
    double r2 = Parameters.R_Intern * Parameters.R_Intern;
    double l = Parameters.l;
    double l2 = Parameters.l * Parameters.l;    ///denominator = (r^3 + l^2(R + r) - lr(R + 2r) * cos(R * angle / r)
    double denominator = fabs(-r * r2 + l2 * (R - r) - l * r * (R - 2 * r) * cos(R * angle / -r));
    double res = (R - r) * pow(r2 + l2 - 2 * l * r * cos(R * angle / -r), 1.5) /
                 denominator;
    if (denominator == 0)
    {
        throw std::runtime_error ("Infinity");
    }
    else    ///numerator = (R + r) * (r^2 + l^2 - 2lr * cos(R * angle / r)^3/2
    {
        return Round(res, count);
    }
}

[[nodiscard]] double Hypocycloid::Get_Square (double angle, int count) const
{
    angle *= M_PI / 180;
    double R = Parameters.R_Extern;
    double r = Parameters.R_Intern; /// S = (R + r) / 2 * ((R - r - l^2/r) * angle - l(R - 2r)/R * sin(R * angle / -r)
    double l = Parameters.l;
    double res = fabs((R - r) / 2 * ((R - r - l * l / r) * angle - l * (R - 2 * r) / R * sin(R * angle / -r)));
    return Round(res, count);
}

void Hypocycloid::Set_Radii (double R_Ex, double R_In)
{
    if (R_Ex <= 0 || R_In <= 0)
    {
        throw std::runtime_error ("Radius must be positive!");
    }
    if (R_Ex <= R_In)
    {
        throw std::runtime_error ("Extern radius must be greater than intern!");
    }
    else
    {
        Parameters.R_Extern = R_Ex;
        Parameters.R_Intern = R_In;
    }
}

void Hypocycloid::Set_l (double l)
{
    if (l <= 0)
    {
        throw std::runtime_error ("l must be positive!");
    }
    else
    {
        Parameters.l = l;
    }
}

////////////////////////////////////////////////////////////////

template <typename T>

int getNum(T &a)
{
    while (!(std::cin >> a))
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

void Show_parameters (Hypocycloid Figure)
{
    Show_radii(Figure);
    std::cout << "l : ";
    std::cout << Figure.Get_l() << std::endl;
}

void Show_radii (Hypocycloid Figure)
{
    std::cout << "Extern radius : ";
    std::cout << Figure.Get_R_Extern() << std::endl;
    std::cout << "Intern radius : ";
    std::cout << Figure.Get_R_Intern() << std::endl;
}

void Show_radius_curvature (Hypocycloid Figure)
{
    double angle;
    int count;
    try
    {
        std::cout << "Enter an angle:" << std::endl;
        getNum(angle);
        std::cout << "Enter count of signs after point (accuracy):" << std::endl;
        getNum(count);
        Figure.Set_Coordinates(angle, count);
        std::cout << "Radius of curvature in point (" << Figure.Get_Coordinates().X << "," << Figure.Get_Coordinates().Y
                  << ") : ";
        std::cout << Figure.Get_Radius(angle, count) << std::endl;
        std::cout << "E-inaccuracy is +- 5e-0" << count + 1 << std::endl;
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
    }
}

void Change_parameters (Hypocycloid *Figure)
{
    double R_Ex, R_In, L;
    try
    {
        std::cout << "Enter extern and intern radii" << std::endl;
        getNum(R_Ex);
        getNum(R_In);
        Figure->Set_Radii(R_Ex, R_In);
        std::cout << "Enter l" << std::endl;
        getNum(L);
        Figure->Set_l(L);
    }
    catch (std::exception & ex)
    {
        std::cout << ex.what() << std::endl;
    }
}

void Show_coordinates (Hypocycloid Figure)
{
    double angle;
    int count;
    try
    {
        std::cout << "Enter an angle" << std::endl;
        getNum(angle);
        std::cout << "Enter count of signs after point (accuracy)" << std::endl;
        getNum(count);
        Figure.Set_Coordinates(angle, count);
        std::cout << "Coordinates of point with angle " << angle << std::endl << "X : " << Figure.Get_Coordinates().X
                  << "\tY : " << Figure.Get_Coordinates().Y << std::endl;
        std::cout << "E-inaccuracy is +- 5e-0" << count + 1 << std::endl;
    }
    catch (std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void Show_type (Hypocycloid Figure)
{
    int type = Figure.GetType();
    if (type == 1)
    {
        std::cout << "Elongated hypocycloid" << std::endl;
    }
    if (!type)
    {
        std::cout << "Usual hypocycloid" << std::endl;
    }
    if (type == -1)
    {
        std::cout << "Shortened hypocycloid" << std::endl;
    }
}

void Show_square (Hypocycloid Figure)
{
    double angle, res;
    int count;
    try
    {
        std::cout << "Enter an angle" << std::endl;
        getNum(angle);
        std::cout << "Enter count of signs after point (accuracy)" << std::endl;
        getNum(count);
        res = Figure.Get_Square(angle, count);
        std::cout << "Sectorial square: " << res << std::endl;
        std::cout << "E-inaccuracy is +- 5e-0" << count + 1 << std::endl;
    }
    catch (std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }
}

double Round (double Num, int count)
{
    if (count <= 0 )
    {
        throw std::runtime_error ("Count of signs after point must be positive!");
    }
    if (count > 5)
    {
        throw std::runtime_error ("Max count of signs is 5!");
    }
    int multiplier = 1;
    for (int i = 0; i < count; ++i) {
        multiplier *= 10;
    }
    Num = (ceil(Num * multiplier)) / ( multiplier);
    return Num;
}
#include "anliplagiat.h"

std::ifstream FOpen (std::string & path)
{
    std::ifstream fin;
    fin.open(path);
    if (!fin.is_open())
    {
        throw std::runtime_error ("File error!");
    }
    else
    {
        return fin;
    }
}

std::string FRead (std::ifstream & fin)
{
    std::string buf;
    if (!fin.eof())
    {
        fin >> buf;
    }
    return buf;
}

bool Check (nameSpacePlantySymbols::planty_symbols & P1, nameSpacePlantySymbols::planty_symbols & P2)
{
    nameSpacePlantySymbols::planty_symbols P3;
    P3 = P1 & P2;
    if (P1.get_real_power() - P3.get_real_power() >= 3)
    {
        return true;
    }
    return false;
}

bool Result (std::string & str, std::ifstream & fin)
{
    bool coincidence;
    nameSpacePlantySymbols::planty_symbols P1(str);
    std::string buf;
    while (!fin.eof())
    {
        nameSpacePlantySymbols::planty_symbols P2;
        buf = FRead(fin);
        P2.insert_symbols(buf);
        coincidence = Check(P1, P2);
        if (coincidence)
        {
            return true;
        }
    }
    return false;
}
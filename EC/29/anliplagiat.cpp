<<<<<<< HEAD
#include "anliplagiat.h"

std::ofstream FOpen (std::string & path)
{
    std::ofstream fp;
    fp.open(path, std::ios::in | std::ios::out);
    if (!fp.is_open())
    {
        throw std::runtime_error ("File error!");
    }
    else
    {
        return fp;
    }
}

std::string FRead (std::ofstream & fp)
{
    std::string buf;
    if (!fp.eof())
    {
        fp << buf;
    }
    return buf;
}

void FWrite (std::fstream & fp, std::string & str)
{
    fp << str;
}

bool Check (nameSpacePlantySymbols::planty_symbols & P1, nameSpacePlantySymbols::planty_symbols & P2)
{
    nameSpacePlantySymbols::planty_symbols P3;
    P3 = P1 & P2;
    std::cout << P3;
    if (P3.get_real_power() >= 3)
    {
        return true;
    }
    return false;
}

void Result (nameSpacePlantySymbols::planty_symbols & P1, nameSpacePlantySymbols::planty_symbols & P2, std::ofstream & fp)
{
    bool coincidence;
    std::string buf1, buf2, OK("OK"), BAD("BAD");
    while (!fp.eof())
    {
        buf1 = FRead(fp);
        P1.insert_symbols(buf1);
        buf2 = FRead(fp);
        P2.insert_symbols(buf2);
        coincidence = Check(P1, P2);
        if (coincidence)
        {
            FWrite(fp, BAD);
            return;
        }
        FWrite(fp, OK);
    }
=======
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
>>>>>>> 2338b367243b3522dbb19d96f1f438749ca25e5e
}
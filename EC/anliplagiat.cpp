#include "anliplagiat.h"

std::fstream FOpen (std::string & path, int flag)
{
    std::fstream fp;
    if (flag == 1)
    {
        fp.open(path, std::ios::in);
    }
    else if (flag == 2)
    {
        fp.open(path, std::ios::in | std::ios::app);
    }
    else
    {
        fp.open(path,std::ios::out | std::ios::trunc);
    }
    if (!fp.is_open())
    {
        throw std::runtime_error ("File error!");
    }
    else
    {
        return fp;
    }
}
std::string FRead (std::fstream & fp)
{
    std::string buf;
    if (!fp.eof())
    {
        fp >> buf;
    }
    return buf;
}
void FWrite (std::fstream & fp, std::string & str1, std::string & str2)
{
    str1 += ' ';
    fp << str1;
    str2 += '\n';
    fp << str2;
}

bool Check_all (nameSpacePlantySymbols::planty_symbols & P1, nameSpacePlantySymbols::planty_symbols & P2, std::string & str)
{
    int i = 0;
    i += Check_login(P1, P2);
    i += Check_repeat(P2, str);
    i += Check_special(P2);
    i += Check_invalid(P2);
    if (i != 0)
    {
        return true;
    }
    return false;
}
int Check_login (nameSpacePlantySymbols::planty_symbols & P1, nameSpacePlantySymbols::planty_symbols & P2)
{
    P1 = P1 & P2;
    if (P1.get_real_power() >= 3)
    {
        return 1;
    }
    return 0;
}
int Check_repeat (nameSpacePlantySymbols::planty_symbols & P2, std::string & str)
{
    if (str.length() > P2.get_real_power())
    {
        return 1;
    }
    return 0;
}
int Check_special (nameSpacePlantySymbols::planty_symbols & P2)
{
    nameSpacePlantySymbols::planty_symbols P3("!@#№$^&*()_-+=<>~/,.");
    P3 = P3 & P2;
    if (P3.get_real_power() == 0)
    {
        return 1;
    }
    return 0;
}
int Check_invalid (nameSpacePlantySymbols::planty_symbols & P2)
{
    nameSpacePlantySymbols::planty_symbols P3("[]{}`\"'");
    P3 = P3 & P2;
    if (P3.get_real_power() != 0)
    {
        return 1;
    }
    return 0;
}

void Result (std::fstream & fin, std::fstream & fout)
{
    bool coincidence;
    std::string buf1, buf2;
    while (!fin.eof())
    {
        nameSpacePlantySymbols::planty_symbols P1, P2;
        buf1 = FRead(fin);
        P1.insert_symbols(buf1);
        buf2 = FRead(fin);
        P2.insert_symbols(buf2);
        coincidence = Check_all(P1, P2, buf2);
        if (coincidence)
        {
            FWrite(fout, buf1, buf2);
        }
    }
}
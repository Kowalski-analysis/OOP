#ifndef PART3_ANLIPLAGIAT_H
#define PART3_ANLIPLAGIAT_H

#include "planty_symbols.h"
#include "my_func.h"
#include <fstream>

std::fstream FOpen (std::string & path, int flag);
std::string FRead (std::fstream & fp);
void FWrite (std::fstream & fp, std::string & str1, std::string & str2);

bool Check_all (nameSpacePlantySymbols::planty_symbols & P1, nameSpacePlantySymbols::planty_symbols & P2, std::string & str);
int Check_login (nameSpacePlantySymbols::planty_symbols & P1, nameSpacePlantySymbols::planty_symbols & P2);
int Check_repeat (nameSpacePlantySymbols::planty_symbols & P2, std::string & str);
int Check_special (nameSpacePlantySymbols::planty_symbols & P2);
int Check_invalid (nameSpacePlantySymbols::planty_symbols & P2);
int Check_size (nameSpacePlantySymbols::planty_symbols & P2);

void Result (std::fstream & fin, std::fstream & fout);

#endif //PART3_ANLIPLAGIAT_H

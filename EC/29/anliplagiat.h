#ifndef PART3_ANLIPLAGIAT_H
#define PART3_ANLIPLAGIAT_H

#include "planty_symbols.h"
#include "my_func.h"
#include <fstream>

std::ofstream FOpen (std::string & path);

std::string FRead (std::ofstream & fp);

void FWrite (std::ofstream & fp, std::string & str);

bool Check (nameSpacePlantySymbols::planty_symbols & P1, nameSpacePlantySymbols::planty_symbols & P2);

void Result (nameSpacePlantySymbols::planty_symbols & P1, nameSpacePlantySymbols::planty_symbols & P2, std::ofstream & fp);

#endif //PART3_ANLIPLAGIAT_H

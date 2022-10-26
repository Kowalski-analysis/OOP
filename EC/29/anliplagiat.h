#ifndef PART3_ANLIPLAGIAT_H
#define PART3_ANLIPLAGIAT_H

#include "planty_symbols.h"
#include "my_func.h"
#include <fstream>

std::ifstream FOpen (std::string & path);

std::string FRead (std::ifstream & fin);

bool Check (nameSpacePlantySymbols::planty_symbols & P1, nameSpacePlantySymbols::planty_symbols & P2);

bool Result (std::string & str, std::ifstream & fin);

#endif //PART3_ANLIPLAGIAT_H

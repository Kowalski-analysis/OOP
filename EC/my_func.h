#ifndef PART1_MY_FUNC_H
#define PART1_MY_FUNC_H

#include "planty_symbols.h"

int get_int();

void dialog();

class My_exception : public std::runtime_error {
public:
    explicit My_exception(std::string message) : std::runtime_error(message) {
    }
};

#endif //PART1_MY_FUNC_H

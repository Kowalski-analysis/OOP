#ifndef PART1_PLANTY_SYMBOLS_H
#define PART1_PLANTY_SYMBOLS_H

#include <iostream>
#include <string>

namespace nameSpacePlantySymbols {
    class planty_symbols {
    private:
        size_t real_power;
        char *symbols;
        size_t capacity;
    public:

        friend void operator|=(planty_symbols &p1, const planty_symbols &p2);

        friend void operator&=(planty_symbols &p1, const planty_symbols &p2);

        friend void operator/=(planty_symbols &p1, const planty_symbols &p2);

        //конструкторы по умолчанию, от строки, от символа
        planty_symbols() : real_power(0), capacity(1) {
            symbols = new char[capacity];
        }

        planty_symbols(std::string insert_symbols) : real_power(0) {
            capacity = insert_symbols.length();
            symbols = new char[capacity];
            for (size_t i = 0; i < capacity; ++i) {
                if (res_search(insert_symbols[i]) == -1) {
                    *(symbols + i) = insert_symbols[i];
                    real_power++;
                }
            }
        }

        planty_symbols(char insert_symbol) : planty_symbols(std::string(1, insert_symbol)) {}

        planty_symbols(const planty_symbols &other) :
                real_power(other.real_power), capacity(other.capacity),
                symbols(new char[other.real_power]) {
            for (int i = 0; i < this->real_power; ++i) {
                this->symbols[i] = other.get_symbols()[i];
            }
        }

        planty_symbols(planty_symbols &&other)

        noexcept: symbols(nullptr), capacity(
                0), real_power(0) {
            *this = std::move(other);
        }

        ~planty_symbols() {
            delete[] symbols;
        }

        planty_symbols &operator=(const planty_symbols &other) {
            if (this != &other) {
                if (this->symbols != nullptr) {
                    delete[] symbols;
                }
                real_power = other.real_power;
                capacity = other.real_power;
                symbols = new char[capacity];
                for (int i = 0; i < this->real_power; ++i) {
                    symbols[i] = other.get_symbols()[i];
                }
            }
            return *this;
        }

        planty_symbols &operator=(planty_symbols &&other)

        noexcept {
            if (this != &other) {
                if (symbols != nullptr) {
                    delete[] symbols;
                }
                real_power = other.real_power;
                capacity = other.capacity;
                symbols = other.symbols;
                other.real_power = 0;
                other.capacity = 0;
                other.symbols = nullptr;
            }
            return *this;
        }


        int get_real_capacity() const;

        int get_real_power() const;

        std::string get_symbols() const;

        void insert_symbol(char insert_symbol);

        void insert_symbols(std::string &insert_symbols);

        int res_search(char a) const;

    };

    planty_symbols operator|(const planty_symbols &p1, const planty_symbols &p2);

    planty_symbols operator&(const planty_symbols &p1, const planty_symbols &p2);

    planty_symbols operator/(const planty_symbols &p1, const planty_symbols &p2);

    std::ostream &operator<<(std::ostream &os, const planty_symbols &my_planty);

}

#endif //PART1_PLANTY_SYMBOLS_H

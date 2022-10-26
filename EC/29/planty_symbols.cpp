#include "planty_symbols.h"

namespace nameSpacePlantySymbols {

    int planty_symbols::get_real_power() const { return real_power; }
<<<<<<< HEAD
    int planty_symbols::get_real_capacity() const { return capacity; }
=======

    int planty_symbols::get_real_capacity() const { return capacity; }

>>>>>>> 2338b367243b3522dbb19d96f1f438749ca25e5e
    std::string planty_symbols::get_symbols() const {
        std::string s1;
        if (symbols != nullptr) {
            for (size_t i = 0; i < real_power; ++i) {
                s1 += symbols[i];
            }
        }
        return s1;
    }
<<<<<<< HEAD
=======

>>>>>>> 2338b367243b3522dbb19d96f1f438749ca25e5e
    void planty_symbols::insert_symbol(char insert_symbol) {
        if (res_search(insert_symbol) == -1) {
            if (real_power == capacity) {
                capacity = capacity * 2;
                char *ptr = symbols;
                char *new_ = new char[capacity];
                std::copy(ptr, ptr + real_power, new_);
                symbols = new_;
                delete[] ptr;
            }
            *(symbols + real_power) = insert_symbol;
            real_power++;
        }
    }
<<<<<<< HEAD
=======

>>>>>>> 2338b367243b3522dbb19d96f1f438749ca25e5e
    void planty_symbols::insert_symbols(std::string &insert_symbols) {
        int size = insert_symbols.length();
        for (int i = 0; i < size; ++i) {
            if (res_search(insert_symbols[i]) == -1) {
                if (real_power == capacity) {
                    capacity = capacity * 2;
                    char *ptr = symbols;
                    char *new_ = new char[capacity];
                    std::copy(ptr, ptr + real_power, new_);
                    symbols = new_;
                    delete[] ptr;
                }
                *(symbols + real_power) = insert_symbols[i];
                real_power++;
            }
        }
    }
<<<<<<< HEAD
=======

>>>>>>> 2338b367243b3522dbb19d96f1f438749ca25e5e
    int planty_symbols::res_search(char a) const {
        for (int i = 0; i < real_power; ++i) {
            if (*(symbols + i) == a) {
                return i;
            }
        }
        return -1;
    }

<<<<<<< HEAD
=======

>>>>>>> 2338b367243b3522dbb19d96f1f438749ca25e5e
    planty_symbols operator|(const planty_symbols &p1, const planty_symbols &p2) {
        planty_symbols my_union;
        size_t p1_real_power = p1.get_real_power(), p2_real_power = p2.get_real_power();
        size_t max_size = p1_real_power + p2_real_power;
        char intersect[max_size];
        std::string s1 = p1.get_symbols();
        std::string s2 = p2.get_symbols();
        size_t k = 0;
        for (size_t i = 0; i < p1_real_power; ++i) {
            intersect[k] = s1[i];
            k++;
        }
        for (size_t j = 0; j < p2_real_power; ++j) {
            intersect[k] = s2[j];
            k++;
        }
        for (size_t i = 0; i < k; ++i) {
            my_union.insert_symbol(intersect[i]);
        }
        return my_union;
    }
<<<<<<< HEAD
=======


>>>>>>> 2338b367243b3522dbb19d96f1f438749ca25e5e
    planty_symbols operator&(const planty_symbols &p1, const planty_symbols &p2) {
        planty_symbols my_intersect;
        size_t k = 0;
        size_t p1_real_power = p1.get_real_power(), p2_real_power = p2.get_real_power();
        size_t max_size = p1_real_power + p2_real_power;
        char intersect[max_size];
        std::string s1 = p1.get_symbols();
        std::string s2 = p2.get_symbols();
        for (size_t i = 0; i < p1_real_power; ++i) {
            for (size_t j = 0; j < p2_real_power; ++j) {
                if (s1[i] == s2[j]) {
                    intersect[k] = s1[i];
                    k++;
                }
            }
        }
        for (size_t i = 0; i < k; ++i) {
            my_intersect.insert_symbol(intersect[i]);
        }
        return my_intersect;
    }
<<<<<<< HEAD
=======


>>>>>>> 2338b367243b3522dbb19d96f1f438749ca25e5e
    planty_symbols operator/(const planty_symbols &p1, const planty_symbols &p2) {
        planty_symbols my_except;
        std::string s1 = p1.get_symbols();
        std::string s2 = p2.get_symbols();
        size_t p1_real_power = p1.get_real_power(), p2_real_power = p2.get_real_power();
        size_t max_size = p1_real_power, k = 0;
        char intersect[max_size];
        for (size_t i = 0; i < p1_real_power; ++i) {
            if (p2.res_search(s1[i]) == -1) {
                intersect[k] = s1[i];
                k++;
            }
        }
        for (int i = 0; i < k; ++i) {
            my_except.insert_symbol(intersect[i]);
        }
        return my_except;
    }
<<<<<<< HEAD
=======

>>>>>>> 2338b367243b3522dbb19d96f1f438749ca25e5e
    void operator|=(planty_symbols &p1, const planty_symbols &p2) {
        size_t p1_real_power = p1.get_real_power(), p2_real_power = p2.get_real_power();
        size_t max_size = p1_real_power + p2_real_power;
        char intersect[max_size];
        std::string s1 = p1.get_symbols();
        std::string s2 = p2.get_symbols();

        size_t k = 0;
        for (size_t i = 0; i < p1_real_power; ++i) {
            intersect[k] = s1[i];
            k++;
        }
        for (size_t j = 0; j < p2_real_power; ++j) {
            if (p1.res_search(s2[j]) == -1) {
                intersect[k] = s2[j];
                k++;
            }
        }

        p1.real_power = 0;
        for (size_t i = 0; i < k; ++i) {
            p1.insert_symbol(intersect[i]);
        }

    }
<<<<<<< HEAD
=======

>>>>>>> 2338b367243b3522dbb19d96f1f438749ca25e5e
    void operator&=(planty_symbols &p1, const planty_symbols &p2) {
        size_t k = 0;
        size_t p1_real_power = p1.get_real_power(), p2_real_power = p2.get_real_power();
        size_t max_size = p1_real_power + p2_real_power;
        char intersect[max_size];
        std::string s1 = p1.get_symbols();
        std::string s2 = p2.get_symbols();
        for (size_t i = 0; i < p1_real_power; ++i) {
            for (size_t j = 0; j < p2_real_power; ++j) {
                if (s1[i] == s2[j]) {
                    intersect[k] = s1[i];
                    k++;
                }
            }
        }
        p1.real_power = 0;
        for (size_t i = 0; i < k; ++i) {
            p1.insert_symbol(intersect[i]);
        }


    }
<<<<<<< HEAD
=======

>>>>>>> 2338b367243b3522dbb19d96f1f438749ca25e5e
    void operator/=(planty_symbols &p1, const planty_symbols &p2) {
        std::string s1 = p1.get_symbols();
        std::string s2 = p2.get_symbols();
        size_t p1_real_power = p1.get_real_power(), p2_real_power = p2.get_real_power();

        size_t max_size = p1_real_power, k = 0;
        char intersect[max_size];
        for (size_t i = 0; i < p1_real_power; ++i) {
            if (p2.res_search(s1[i]) == -1) {
                intersect[k] = s1[i];
                k++;
            }
        }
        p1.real_power = 0;
        for (int i = 0; i < k; ++i) {
            p1.insert_symbol(intersect[i]);
        }
    }
<<<<<<< HEAD
=======


>>>>>>> 2338b367243b3522dbb19d96f1f438749ca25e5e
    std::ostream &operator<<(std::ostream &os, const planty_symbols &my_planty) {
        if (my_planty.get_real_power() == 0) {
            os << "empty planty" << std::endl;
        } else {
            os << "real_size=" << my_planty.get_real_power() << " |planty=" << my_planty.get_symbols();
        }
        return os;

    }

}

#include "my_func.h"

int get_int() {
    int num;
    std::cin >> num;
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1024, '\n');
        std::cout << "enter again\n";
        std::cin >> num;
    }
    return num;
}

void dialog() {
    std::cout << std::endl <<"[0] to end program" << std::endl;
    std::cout << "[1] to insert 1 symbol" << std::endl;
    std::cout << "[2] to insert symbols" << std::endl;
    std::cout << "[3] print all symbols" << std::endl;
    std::cout << "[4] search INTERSECT" << std::endl;
    std::cout << "[5] search UNION" << std::endl;
    std::cout << "[6] search ЕХСЕРТ" << std::endl;
    std::cout << "[7] search element in planty" << std::endl;
    std::cout << "[8] use copy constructor" << std::endl;
    std::cout << "[9] redefinition" << std::endl;
}





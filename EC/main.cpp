#include "planty_symbols.h"
#include "my_func.h"

using namespace std;

nameSpacePlantySymbols::planty_symbols func() {
    string s1("qwer");
    nameSpacePlantySymbols::planty_symbols B(s1);
    return B;
}

int main() {
    bool flag = false;
    int code;
    nameSpacePlantySymbols::planty_symbols my_planty1, my_planty2;
    string s1("abc"), s2("def");
    nameSpacePlantySymbols::planty_symbols my_A(s1), my_B(s2);
    cout << my_A << my_B << endl;
    do {
        dialog();
        code = get_int();
        switch (code) {
            case 0: {
                flag = true;
                break;
            }
            case 1: { //увеличить множество на символ
                cout << "\nEnter [1] to work with 1 planty, [2] to work with 2 planty" << endl;
                auto num_planty = get_int();
                char symbol;
                cout << "Enter symbol" << endl;
                cin >> symbol;
                if (num_planty == 1) {
                    my_planty1.insert_symbol(symbol);
                } else if (num_planty == 2) {
                    my_planty2.insert_symbol(symbol);
                } else {
                    cout << "incorrect code\n";
                }
                break;
            }
            case 2: {//увеличить множество на строку
                string new_symbols;
                cout << "\nEnter [1] to work with 1 planty, [2] to work with 2 planty" << endl;
                auto num_planty = get_int();
                cout << "Enter string" << endl;
                cin >> new_symbols;
                if (num_planty == 1) {
                    my_planty1.insert_symbols(new_symbols);
                } else if (num_planty == 2) {
                    my_planty2.insert_symbols(new_symbols);
                } else {
                    cout << "incorrect code\n";
                }
                break;
            }
            case 3: {//вывод
                cout << "my_planty1=" << my_planty1 << endl;
                cout << "my_planty2=" << my_planty2 << endl;
                break;
            }
            case 4: {//пересечение двух множеств
                try {
                    if ((my_planty1.get_real_power() == 0) | (my_planty1.get_real_power() == 0)) {
                        throw My_exception("one of the planty is empty");
                    }
                    nameSpacePlantySymbols::planty_symbols my_planty = my_planty1 & my_planty2;
                    cout << my_planty1.get_symbols() << "⋂" << my_planty2.get_symbols() << "=" << my_planty << endl;
                }
                catch (My_exception &ex) {
                    cout << ex.what() << endl;
                }
                break;
            }
            case 5: {//объединение
                try {
                    if ((my_planty1.get_real_power() == 0) & (my_planty1.get_real_power() == 0)) {
                        throw My_exception("all planty is empty");
                    }
                    nameSpacePlantySymbols::planty_symbols my_planty = my_planty1 | my_planty2;
                    cout << my_planty1.get_symbols() << "⋃" << my_planty2.get_symbols() << "=" << my_planty << endl;
                }
                catch (My_exception &ex) {
                    cout << ex.what() << endl;
                }
                break;
            }
            case 6: {//разность
                try {
                    if ((my_planty1.get_real_power() == 0) & (my_planty1.get_real_power() == 0)) {
                        throw My_exception("all planty is empty");
                    }
                    nameSpacePlantySymbols::planty_symbols my_planty = my_planty1 / my_planty2;
                    cout << my_planty1.get_symbols() << "/" << my_planty2.get_symbols() << "=" << my_planty << endl;
                }
                catch (My_exception &ex) {
                    cout << ex.what() << endl;
                }
                break;
            }
            case 7: {//определение, имеется ли некоторый заданный элемент в множестве,
                char symbol;
                cout << "enter symbol to search" << endl;
                cin >> symbol;
                cout << "\nEnter [1] to work with 1 planty, [2] to work with 2 planty" << endl;
                auto num_planty = get_int();
                if (num_planty == 1) {
                    if (my_planty1.res_search(symbol) == -1) {
                        cout << "not found" << endl;
                    } else {
                        cout << "found" << endl;
                    }
                } else if (num_planty == 2) {
                    if (my_planty2.res_search(symbol) == -1) {
                        cout << "not found" << endl;
                    } else {
                        cout << "found" << endl;
                    }
                }
                break;
            }
                //!--------------------------------------------------------------------
            case 8: {// конструктор копирования/перемещения
                cout << "my_planty1  before copy " << my_A << endl;
                nameSpacePlantySymbols::planty_symbols my_planty3(my_A);
                cout << "after copy" << endl;
                cout << "my_planty3 after" << my_planty3 << endl;
                cout << "my_planty1 after" << my_A << endl;
                nameSpacePlantySymbols::planty_symbols my_planty4(std::move(my_A));
                cout << "after moving" << endl;
                cout << "my_planty4 after" << my_planty4 << endl;
                cout << "my_planty1 after" << my_A << endl;
                break;
            }
            case 9: {//переопределение (копирующее присваивание)
                nameSpacePlantySymbols::planty_symbols my_planty3(my_A);
                cout << "my_planty3 =" << my_planty3 << endl;
                cout << "my_planty1 =" << my_A << endl;
                cout << "my_planty2 =" << my_B << endl;
                my_planty3 = my_B;
                cout << "after redefinition" << endl;
                cout << "my_planty3 =" << my_planty3 << endl;
                cout << "my_planty1 =" << my_A << endl;
                cout << "my_planty2 =" << my_B << endl;
                break;
            }
            case 10: {//переопределение (перемещающее присваивание)
                nameSpacePlantySymbols::planty_symbols my_planty3(my_A);
                cout << "my_planty3 =" << my_planty3 << endl;
                cout << "my_planty1 =" << my_A << endl;
                cout << "my_planty2 =" << my_B << endl;
                my_planty3 = std::move(my_B); //!------------------
                cout << "after moving" << endl;
                cout << "my_planty3 =" << my_planty3 << endl;
                cout << "my_planty1 =" << my_A << endl;
                cout << "my_planty2 =" << my_B << endl;
                break;
            }
            case 11: {//A = A
                nameSpacePlantySymbols::planty_symbols A(my_A);
                cout << "A before (A = A)" << A << endl;
                A = A;
                cout << "A after (A = A)" << A << endl;
                cout << "after moving" << endl;
                cout << "A before (A = A)" << A << endl;
                A = std::move(A);
                cout << "A after (A = std::move(A))" << A << endl;
                break;
            }
            case 12: { // dop: А = func() func() { return B; }
                nameSpacePlantySymbols::planty_symbols A;
                A = func();
                cout << "A=  " << A << endl;
                break;
            }
            default: {
                cout << "unknown code| repeat ";
            }
        }
    } while (!flag);
    cout << "end program" << std::endl;
    return 0;
}

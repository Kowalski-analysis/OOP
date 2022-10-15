#include "funcs.h"

const char *MSGS[] = {"0. Quit", "1. Push", "2. Pop", "3. Show all stack", "4. Condition of stack", "5. Delete all elements", "6. Push array", "7. Test overload\n"};
const int MSGS_SIZE = sizeof(MSGS) / sizeof(MSGS[0]);

int main() {
    int c;
    Stack S;
    do
    {
        c = Dialog(MSGS, MSGS_SIZE);
        switch (c)
        {
            case 0:
                break;
            case 1:
            {
                New_Elem(S);
                break;
            }
            case 2:
            {
                Last_Elem(S);
                break;
            }
            case 3:
            {
                Show_stack(S);
                break;
            }
            case 4:
            {
                Condition_of_stack(S);
                break;
            }
            case 5:
            {
                Delete_all(S);
                break;
            }
            case 6:
            {
                Enter_array(S);
                break;
            }
            case 7:
            {
//                std::cout << S << std::endl;
//                Stack A(S);
//                Stack A;
//                Elem E;
//                E.num = 123;
//                E.str = "XXX";
//                A = S + E;
//                S = S + E;
//                Show_stack(S);
//                E = --S;
//                std::cout << E.str << '\t' << E.num << std::endl;
//                E = S--;
//                std::cout << E.str << '\t' << E.num << std::endl;
//                Show_stack(A);

            }
            default: {
                break;
            }
        }
    } while (c != 0);
    return 0;
}


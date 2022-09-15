#include "funcs.h"

const char *MSGS[] = {"0. Quit", "1. New matrix", "2. New element", "3. Show matrix", "4. Show vector\n"};
const int MSGS_SIZE = sizeof(MSGS) / sizeof(MSGS[0]);

int main() {
    int c;
    Matrix M;
    New_matrix_dialog(&M);
    do {
        c = Dialog(MSGS, MSGS_SIZE);
        switch (c) {
            case 0:
                break;
            case 1: {
                Delete_matrix(&M);
                New_matrix_dialog(&M);
                break;
            }
            case 2: {
                Enter_matrix_dialog(&M);
                break;
            }
            case 3: {
                Show_matrix(M);
                break;
            }
            case 4: {
                int* vec = Sum_of_row(M);
                Show_matrix(M);
                Show_array(vec, M.ROW);
                delete [] vec;
                break;
            }
        }
    } while (c != 0);
    Delete_matrix(&M);
    return 0;
}

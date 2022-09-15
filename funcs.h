#ifndef OOP_LAB1_FUNCS_H
#define OOP_LAB1_FUNCS_H
#define Border std::cout << "=====================================" << std::endl;

#include <iostream>

typedef struct Matrix {
    int* elements;
    int* row;
    int* col;
    int ROW;
    int COL;
    int sizeM;
    int sizeNZ;
} Matrix;

int Dialog (const char *msgs[], int n);

int get_int (int *a);

void New_matrix_dialog (Matrix* M);

Matrix New_matrix (int Row, int Col);

void Enter_matrix (Matrix* M, int Row, int Col, int Elem);

void Enter_matrix_dialog (Matrix* M);

void Show_matrix (Matrix M);

void Show_array (int* A, int size);

int* Sum_of_row (Matrix M);

void Delete_matrix (Matrix* M);

#endif //OOP_LAB1_FUNCS_H

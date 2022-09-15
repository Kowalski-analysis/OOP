#include "funcs.h"

int Dialog (const char *msgs[], int n) {
    const char *error = "";
    int choice;
    do {
        puts(error);
        error = "You're wrong. Try again!";
        for (int i = 0; i < n; ++i) {
            puts(msgs[i]);
        }
        int eof = get_int(&choice);
        if (eof == -1) {
            return 0;
        }
    } while (choice < 0 || choice >= n);
    return choice;
}

int get_int (int *a) {
    int b;
    const char *error = "";
    do {
        printf("%s", error);
        error = "Please enter a number:\n";
        b = scanf("%d", a);
        scanf("%*[^\n]");
        getchar();
    } while (b == 0);
    if (b < 0){
        return -1;
    }
    return 0;
}

Matrix New_matrix (int Row, int Col) {
    Matrix New;
    New.sizeM = 0;
    New.sizeNZ = 0;
    New.ROW = Row;
    New.COL = Col;
    return New;
}

void New_matrix_dialog (Matrix* M) {
    int Row, Col;
    const char *str = "";
    std::cout << "Enter count of rows" << std::endl;
    do {
        std::cout << str << std::endl;
        str = "Count must be positive";
        get_int(&Row);
    } while (Row <= 0);
    std::cout << "Enter count of cols" << std::endl;
    str = "";
    do {
        std::cout << str << std::endl;
        str = "Count must be positive";
        get_int(&Col);
    } while (Col <= 0);
    *M = New_matrix(Row, Col);
}

//void Enter_matrix (Matrix* M, int Row, int Col, int Elem) {
//    int sum = M->COL * Row + Col;
//    for (int i = 0; i < M->sizeNZ; ++i) {
//        for (int j = 0; j < M->ROW; ++j) {
//            if (M->row[j + 1] >= i + 1) {
//                if (M->COL * j + M->col[i] > sum) {
//                    for (int k = 1; k < M->ROW + 1; ++k) {
//                        if (k < Row) {
//                            M->row[k] = M->row[k] + 1;
//                        }
//                    }
//                    int* new_col = new int[M->sizeNZ + 1];
//                    int* new_elem = new int[M->sizeNZ + 1];
//                    for (int k = 0; k < M->sizeNZ; ++k) {
//                        if (k == j) {
//                            new_col[k] = Col;
//                            new_elem[k] = Elem;
//                            continue;
//                        }
//                        new_col[k] = M->col[k];
//                        new_elem[k] = M->row[k];
//                    }
//                    delete(M->col);
//                    delete(M->elements);
//                    M->col = new_col;
//                    M->elements = new_elem;
//                }
//            }
//        }
//    }
//}

void Enter_matrix_dialog (Matrix* M) {
    int New, Row, Col;
    const char *str = "";
    std::cout << "Enter a new element" << std::endl;
    get_int(&New);
    std::cout << "Enter row" << std::endl;
    do {
        std::cout << str << std::endl;
        str = "Incorrect row";
        get_int(&Row);
    } while (Row >= M->ROW || Row < 0);
    std::cout << "Enter col" << std::endl;
    str = "";
    do {
        std::cout << str << std::endl;
        str = "Incorrect col";
        get_int(&Col);
    } while (Col >= M->COL || Col < 0);
    Enter_matrix(M, Row, Col, New);
}

void Enter_matrix (Matrix* M, int Row, int Col, int Elem) {
    if (M->sizeNZ == 0) {
        M->elements = new int[5];
        M->row = new int[5];
        M->col = new int[5];
        M->sizeM = 5;
    }
    if (M->sizeNZ == M->sizeM) {
        int* New_elem = new int[M->sizeM * 2];
        int* New_row = new int[M->sizeM * 2];
        int* New_col = new int[M->sizeM * 2];
        for (int i = 0; i < M->sizeM; ++i) {
            New_elem[i] = M->elements[i];
            New_row[i] = M->row[i];
            New_col[i] = M->col[i];
        }
        delete [] M->row;
        delete [] M->col;
        delete [] M->elements;
        M->row = New_row;
        M->col = New_col;
        M->elements = New_elem;
        M->sizeM *= 2;
    }
    int check = 0;
    for (int j = 0; j < M->sizeNZ; ++j) {
	 	if ((M->row[j] == Row) && (M->col[j] == Col)) {
              check = 1;
	    	  M->row[j] = Row;
	     	 M->col[j] = Col;
		 	 M->elements[j] = Elem;
     	}
    }
    if (!check) {
    	M->row[M->sizeNZ] = Row;
    	M->elements[M->sizeNZ] = Elem;
    	M->col[M->sizeNZ] = Col;
    	M->sizeNZ++;
    }
}

void Show_matrix (Matrix M) {
    Border;
    int check;
    for (int k = 0; k < M.ROW; ++k) {
        for (int i = 0; i < M.COL; ++i) {
            check = 0;
            for (int j = 0; j < M.sizeNZ; ++j) {
                if ((M.row[j] == k) && (M.col[j] == i)) {
                    std::cout << M.elements[j] << "  ";
                    check = 1;
                }
            }
            if (!check) {
                std::cout << 0 << "  ";
            }
        }
        std::cout << std::endl;
    }
    Border;
}

void Show_array (int* A, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << A[i] << "  ";
    }
    std::cout << std::endl;
}

int* Sum_of_row (Matrix M) {
    int* Sum_of_i = new int[M.ROW];
    for (int i = 0; i < M.ROW; ++i) {
        Sum_of_i[i] = 0;
    }
    for (int i = 0; i < M.ROW; ++i) {
        for (int j = 0; j < M.sizeNZ; ++j) {
            if (M.row[j] == i) {
                Sum_of_i[i] += M.elements[j];
            }
        }
    }
    return Sum_of_i;
}

void Delete_matrix (Matrix* M) {
	if (M->sizeNZ) {
    	delete [] M->row;
    	delete [] M->col;
	    delete [] M->elements;
	}
}

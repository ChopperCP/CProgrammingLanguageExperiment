#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"

#include <stdio.h>
#include <malloc.h>
#include <memory.h>

struct Matrix {
    int row_cnt;
    int col_cnt;
    double *matrix; //一维化的二维矩阵
};


struct Matrix create_matrix(int row_cnt, int col_cnt) {
    // Create a zero matrix
    double *matrix = malloc(sizeof(double) * row_cnt * col_cnt);
//    for (int row_ind = 0; row_ind < row_cnt; ++row_ind) {
//        for (int col_ind = 0; col_ind < col_cnt; ++col_ind) {
//            *get_element_ptr(matrix,row_ind,col_ind)=0
//        }
//    }
    memset(matrix, 0, sizeof(double) * row_cnt * col_cnt);

    struct Matrix matrix_obj;
    matrix_obj.matrix = matrix;
    matrix_obj.row_cnt = row_cnt;
    matrix_obj.col_cnt = col_cnt;
    return matrix_obj;
}

double *get_element_ptr(struct Matrix *matrix, int row_ind, int col_ind) {
    return (matrix->matrix) + (matrix->col_cnt * row_ind) + col_ind;
}


struct Matrix input_matrix() {
    // Fill a matrix with user input
    printf("%s", "[*] Please input the number of rows and columns of the matrix: ");
    int row_cnt, col_cnt;
    scanf("%d %d", &row_cnt, &col_cnt);
    printf("[*] The matrix is %dx%d\n", row_cnt, col_cnt);


    struct Matrix matrix = create_matrix(row_cnt, col_cnt);
    for (int row_ind = 0; row_ind < row_cnt; ++row_ind) {
        for (int col_ind = 0; col_ind < col_cnt; ++col_ind) {
            scanf("%lf", get_element_ptr(&matrix, row_ind, col_ind));
        }
    }

    return matrix;
}

void print_matrix(struct Matrix *matrix) {
    for (int row_ind = 0; row_ind < matrix->row_cnt; ++row_ind) {
        for (int col_ind = 0; col_ind < matrix->col_cnt; ++col_ind) {
            printf("%lf ", *get_element_ptr(matrix, row_ind, col_ind));
        }
        printf("\n");
    }
}

struct Matrix add(struct Matrix *lhs, struct Matrix *rhs) {
    // Add two matrices, return a new matrix as the result
    if (!(lhs->row_cnt == rhs->row_cnt && lhs->col_cnt == rhs->col_cnt)) {
        printf("%s", "[!] You can't add 2 matrices with different size! \n");
        exit(-1);
    }

    struct Matrix result = create_matrix(lhs->row_cnt, rhs->col_cnt);
    for (int row_ind = 0; row_ind < lhs->row_cnt; ++row_ind) {
        for (int col_ind = 0; col_ind < rhs->col_cnt; ++col_ind) {
            *get_element_ptr(&result, row_ind, col_ind) =
                    *get_element_ptr(lhs, row_ind, col_ind) + *get_element_ptr(rhs, row_ind, col_ind);
        }
    }

    return result;
}

struct Matrix subtract(struct Matrix *lhs, struct Matrix *rhs) {
    // Add two matrices, return a new matrix as the result
    if (!(lhs->row_cnt == rhs->row_cnt && lhs->col_cnt == rhs->col_cnt)) {
        printf("%s", "[!] You can't subtract 2 matrices with different size! \n");
        exit(-1);
    }

    struct Matrix result = create_matrix(lhs->row_cnt, rhs->col_cnt);
    for (int row_ind = 0; row_ind < lhs->row_cnt; ++row_ind) {
        for (int col_ind = 0; col_ind < rhs->col_cnt; ++col_ind) {
            *get_element_ptr(&result, row_ind, col_ind) =
                    *get_element_ptr(lhs, row_ind, col_ind) - *get_element_ptr(rhs, row_ind, col_ind);
        }
    }

    return result;
}

struct Matrix transpose(struct Matrix *matrix) {
    struct Matrix result = create_matrix(matrix->col_cnt, matrix->row_cnt);
    // swap rows and columns
    for (int row_ind = 0; row_ind < matrix->row_cnt; ++row_ind) {
        for (int col_ind = 0; col_ind < matrix->col_cnt; ++col_ind) {
            *get_element_ptr(&result, col_ind, row_ind) = *get_element_ptr(matrix, row_ind, col_ind);
        }
    }

    return result;
}

struct Matrix multiplication(struct Matrix *lhs, struct Matrix *rhs) {
    if (lhs->col_cnt != rhs->row_cnt) {
        printf("%s", "Can't multiply!");
        exit(-1);
    }

    struct Matrix result = create_matrix(lhs->row_cnt, rhs->col_cnt);
    for (int row_ind = 0; row_ind < result.row_cnt; ++row_ind) {
        for (int col_ind = 0; col_ind < result.col_cnt; ++col_ind) {
            double curr_element = 0;
            for (int i = 0; i < lhs->col_cnt; ++i) {
                curr_element += (*get_element_ptr(lhs, row_ind, i)) * (*get_element_ptr(rhs, i, col_ind));
            }
            *get_element_ptr(&result, row_ind, col_ind) = curr_element;
        }
    }

    return result;
}

int main(int argc, char *argv[]) {
    printf("%s", "[*] Please input the first matrix.\n");
    struct Matrix lhs = input_matrix();
    print_matrix(&lhs);

    printf("%s", "[*] Please input the second matrix.\n");
    struct Matrix rhs = input_matrix();
    print_matrix(&rhs);

    printf("%s", "[*] Please select the operation:\n");
    printf("%s", "\t 1.Transpose\n");
    printf("%s", "\t 2.Add\n");
    printf("%s", "\t 3.Subtract\n");
    printf("%s", "\t 4.Multiply\n");
    printf("%s", "\t 5.Power\n");

    int operation = 0;
    scanf("%d", &operation);
    switch (operation) {
        case 1: {
            // Transpose
            printf("%s", "[*] Please select the matrix you want to transpose: \n");
            printf("1.\n");
            print_matrix(&lhs);
            printf("\n");
            printf("2.\n");
            print_matrix(&rhs);

            scanf("%d", &operation);
            struct Matrix result;
            if (operation == 1) {
                result = transpose(&lhs);
            } else if (operation == 2) {
                result = transpose(&rhs);
            } else {
                printf("%s", "[!] Invalid operation!\n");
                exit(-1);
            }

            printf("%s", "Result:\n");
            print_matrix(&result);
            break;
        }

        case 2: {
            // Add
            struct Matrix result = add(&lhs, &rhs);
            printf("%s", "Result:\n");
            print_matrix(&result);
            break;
        }

        case 3: {
            // Subtract
            struct Matrix result = subtract(&lhs, &rhs);
            printf("%s", "Result:\n");
            print_matrix(&result);
            break;
        }

        case 4: {
            // Multiply
            struct Matrix result = multiplication(&lhs, &rhs);
            printf("%s", "Result:\n");
            print_matrix(&result);
            break;
        }

        case 5: {
            printf("%s", "[*] Please select the matrix you want to power: \n");
            printf("1.\n");
            print_matrix(&lhs);
            printf("\n");
            printf("2.\n");
            print_matrix(&rhs);

            scanf("%d", &operation);
            struct Matrix result = lhs;
            struct Matrix *target;
            if (operation == 1) {
                target = &lhs;
            } else if (operation == 2) {
                target = &rhs;
            } else {
                printf("%s", "[!] Invalid operation!\n");
                exit(-1);
            }

            printf("%s", "[*] Please input the power (>0): ");
            scanf("%d", &operation);
            for (int i = 1; i < operation; ++i) {
                result = multiplication(&result, target);
            }
            printf("%s", "Result:\n");
            print_matrix(&result);
            break;
        }

        default:
            break;
    }

    return 0;
}

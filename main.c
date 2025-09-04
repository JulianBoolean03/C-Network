#include <stdio.h>
#include "matrix.h"

float double_val(float x) {
    return x * 2;
}

int main() {
    Matrix *A = create_matrix(2, 2);
    A->data[0][0] = 1.0;
    A->data[0][1] = 2.0;
    A->data[1][0] = 3.0;
    A->data[1][1] = 4.0;

    printf("Original Matrix:\n");
    print_matrix(A);

    Matrix *B = matrix_apply(A, double_val);
    printf("\nAfter Applying Function (double):\n");
    print_matrix(B);

    Matrix *C = matrix_add(A, B);
    printf("\nMatrix A + B:\n");
    print_matrix(C);

    Matrix *D = matrix_dot(A, B);
    printf("\nMatrix A * B:\n");
    print_matrix(D);

    free_matrix(A);
    free_matrix(B);
    free_matrix(C);
    free_matrix(D);

    return 0;
}

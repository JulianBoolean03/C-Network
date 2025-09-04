#ifndef MATRIX_H
#define MATRIX_H

typedef struct{
  int rows;
  int cols;
  float **data;
} Matrix;


Matrix *create_matrix(int rows, int cols);
void free_matrix(Matrix *m);
Matrix *matrix_dot(Matrix *a, Matrix *b);
Matrix *matrix_add(Matrix *a, Matrix *b);
Matrix *matrix_scalar_mul(Matrix *m, float scalar);
Matrix *matrix_apply(Matrix *m, float (*func)(float));
Matrix *matrix_transpose(Matrix *m);
//new stuiff today
Matrix *matrix_transpose(Matrix *m);
Matrix *matrix_dot(Matrix *a, Matrix *b);
Matrix *matrix_scalar_mul(Matrix* m, float scalar);
Matrix *random_matrix(int rows, int cols);
void print_matrix(Matrix *m);






#endif // !MATRIX_H

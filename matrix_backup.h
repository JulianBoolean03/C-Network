#ifndef MATRIX_H
#define MATRIX_H

typedef struct{
  int rows;
  int cols;
  float *data;
} Matrix;


Matrixcreate_matrix(int rows, int cols);
void free_matrix(Matrix m);
Matrixmatrix_dot(Matrix a, Matrixb);
Matrix matrix_add(Matrixa, Matrix b);
Matrixmatrix_scalar_mul(Matrix m, float scalar);
Matrixmatrix_apply(Matrix m, float (func)(float));
Matrix matrix_transpose(Matrixm);
void print_matrix(Matrix *m);



#endif // !MATRIX_H

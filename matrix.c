#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"


Matrix *create_matrix(int rows, int cols){
  Matrix *m = malloc(sizeof(Matrix));
  m->rows = rows;
  m->cols = cols;
  m->data = malloc(rows * sizeof(float *));
  for(int i = 0; i < rows; ++i){
    m->data[i] = calloc(cols, sizeof(float));
  }
  return m;
}

void free_matrix(Matrix *m) {
    for (int i = 0; i < m->rows; ++i) {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}


Matrix *matrix_dot(Matrix *a, Matrix *b) {
    if (a->cols != b->rows) {
        // Invalid
        return NULL;
    }
    Matrix *result = create_matrix(a->rows, b->cols);
    for (int i = 0; i < a->rows; ++i) {
        for (int j = 0; j < b->cols; ++j) {
            float sum = 0.0;
            for (int k = 0; k < a->cols; ++k) {
                sum += a->data[i][k] * b->data[k][j];
            }
            result->data[i][j] = sum;
        }
    }
    return result;
}


Matrix *matrix_add(Matrix *a, Matrix *b) {
    if (a->rows != b->rows || a->cols != b->cols) {
        return NULL; 
    }
    Matrix *result = create_matrix(a->rows, a->cols);
    for (int i = 0; i < a->rows; ++i) {
        for (int j = 0; j < a->cols; ++j) {
            result->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    return result;
}


Matrix *matrix_scalar_mul(Matrix *m, float scalar) {
    Matrix *result = create_matrix(m->rows, m->cols);
    for (int i = 0; i < m->rows; ++i) {
        for (int j = 0; j < m->cols; ++j) {
            result->data[i][j] = m->data[i][j] * scalar;
        }
    }
    return result;
}



Matrix *matrix_apply(Matrix *m, float (*func)(float)) {
    Matrix *result = create_matrix(m->rows, m->cols);
    for (int i = 0; i < m->rows; ++i) {
        for (int j = 0; j < m->cols; ++j) {
            result->data[i][j] = func(m->data[i][j]);
        }
    }
    return result;
}



Matrix *matrix_transpose(Matrix *m) {
    Matrix *result = create_matrix(m->cols, m->rows);
    for (int i = 0; i < m->rows; ++i) {
        for (int j = 0; j < m->cols; ++j) {
            result->data[j][i] = m->data[i][j];
        }
    }
    return result;
}


//used for my weight intialization 
Matrix *random_matrix(int rows, int cols){
 //add this logic here 
    Matrix *m = malloc(sizeof(Matrix));
    m->rows = rows;
    m->cols = cols;
    m->data = malloc(rows * sizeof(float *)); //contians enough space for all the riows data
    for (int i = 0; i < rows; ++i){
      m->data[i] = calloc(cols, sizeof(float)); // sets every element inm rows to 0.0 to clear left over data
      for (int j = 0; j < cols; ++j){
        m->data[i][j] = ((float)rand() / RAND_MAX) * 2.0f - 1.0f;
      }
    }
    return m;
} 

void print_matrix(Matrix *m) {
    for (int i = 0; i < m->rows; ++i) {
        for (int j = 0; j < m->cols; ++j) {
            printf("%.2f ", m->data[i][j]);  // nicely formatted
        }
        printf("\n"); // proper newline
    }
}

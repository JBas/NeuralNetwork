#include <stdbool.h>


#ifndef _MATRIX_H_
#define _MATRIX_H_

struct matrix_header {
	int rows;
	int cols;
	float* data;
};

typedef struct matrix_header matrix;
typedef float func(float x);

matrix* sclr_mult(matrix *A, float sclr);
matrix* sclr_add(matrix *A, float sclr);
void sclr_mult_(matrix *A, float sclr);
void sclr_add_(matrix *A, float sclr);

matrix* matrix_mult(matrix *A, matrix *B);
void matrix_mult_(matrix *A, matrix *B);
matrix* matrix_dot(matrix *A, matrix *B);
matrix* matrix_add(matrix *A, matrix *B);
matrix* matrix_sub(matrix *A, matrix *B);
void matrix_add_(matrix *A, matrix *B);
void matrix_sub_(matrix *A, matrix *B);

matrix* matrix_map(matrix *A, func *f);
void matrix_map_(matrix *A, func *f);

matrix* transpose(matrix *A);
void randomize(matrix *A);

bool is_equal(matrix *A, matrix *B);

matrix* new_matrix(int rows, int cols, float *data);
void free_matrix(matrix *A);

float get_element(matrix *A, int row, int col);
void set_element(matrix *A, int row, int col, float val);

void print_matrix(matrix *A);

#endif

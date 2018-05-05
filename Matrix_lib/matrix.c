#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include "../lib/xalloc.h"
#include "matrix.h"

matrix* sclr_mult(matrix *A, float sclr) {
	assert(A != NULL);

	matrix *result = new_matrix(A->rows, A->cols, NULL);

	for (int i = 0; i < result->rows; i++) {
		for (int j = 0; j < result->cols; j++) {
			float element = get_element(A, i, j) * sclr;
			set_element(result, i, j, element);
		}
	}

	assert(result != NULL);
	return result;
}

void sclr_mult_(matrix *A, float sclr) {
	assert(A != NULL);

	for (int i = 0; i < A->rows; i++) {
		for (int j = 0; j < A->cols; j++) {
			float element = get_element(A, i, j) * sclr;
			set_element(A, i, j, element);
		}
	}

	assert(A != NULL);
	return;
}

matrix* sclr_add(matrix *A, float sclr) {
	assert(A != NULL);

	matrix *result = new_matrix(A->rows, A->cols, NULL);

	for (int i = 0; i < result->rows; i++) {
		for (int j = 0; j < result->cols; j++) {
			float element = get_element(A, i, j) + sclr;
			set_element(result, i, j, element);
		}
	}

	assert(result != NULL);
	return result;
}

void sclr_add_(matrix *A, float sclr) {
	assert(A != NULL);

	for (int i = 0; i < A->rows; i++) {
		for (int j = 0; j < A->cols; j++) {
			float element = get_element(A, i, j) + sclr;
			set_element(A, i, j, element);
		}
	}

	assert(A != NULL);
	return;
}

matrix* matrix_mult(matrix* A, matrix *B) {
	assert(A != NULL);
	assert(B != NULL);
	assert(A->rows == B->rows);
	assert(A->cols == B->cols);

	matrix *result = new_matrix(A->rows, A->cols, NULL);

	for (int i = 0; i < result->rows; i++) {
		for (int j = 0; j < result->cols; j++) {
			float element = get_element(A, i, j) * get_element(B, i, j);
			set_element(result, i, j, element);
		}
	}

	assert(result != NULL);
	return result;
}

void matrix_mult_(matrix* A, matrix *B) {
	assert(A != NULL);
	assert(B != NULL);
	assert(A->rows == B->rows);
	assert(A->cols == B->cols);

	for (int i = 0; i < A->rows; i++) {
		for (int j = 0; j < A->cols; j++) {
			float element = get_element(A, i, j) * get_element(B, i, j);
			set_element(A, i, j, element);
		}
	}

	assert(A != NULL);
	return;
}

matrix* matrix_dot(matrix *A, matrix *B) {
	assert(A != NULL);
	assert(B != NULL);
	assert(A->cols == B->rows);

	matrix* result = new_matrix(A->rows, B->cols, NULL);

	for (int i = 0; i < result->rows; i++) {
		for (int j = 0; j < result->cols; j++) {
			float element = 0;
			for (int k = 0; k < A->cols; k++) {
				element += get_element(A, i, k) * get_element(B, k, j);
			}
			set_element(result, i, j, element);
		}
	}
	assert(result != NULL);
	return result;
}

matrix* matrix_add(matrix *A, matrix *B) {
	assert(A != NULL);
	assert(B != NULL);
	assert(A->rows == B->rows);
	assert(A->cols == B->cols);

	matrix *result = new_matrix(A->rows, A->cols, NULL);

	for (int i = 0; i < result->rows; i++) {
		for (int j = 0; j < result->cols; j++) {
			float element = get_element(A, i, j) + get_element(B, i, j);
			set_element(result, i, j, element);
		}
	}

	assert(result != NULL);
	return result;
}

void matrix_add_(matrix *A, matrix *B) {
	assert(A != NULL);
	assert(B != NULL);
	assert(A->rows == B->rows);
	assert(A->cols == B->cols);

	for (int i = 0; i < A->rows; i++) {
		for (int j = 0; j < A->cols; j++) {
			float element = get_element(A, i, j) + get_element(B, i, j);
			set_element(A, i, j, element);
		}
	}

	assert(A != NULL);
	return;
}

matrix* matrix_sub(matrix *A, matrix *B) {
	assert(A != NULL);
	assert(B != NULL);
	assert(A->rows == B->rows);
	assert(A->cols == B->cols);

	matrix *result = new_matrix(A->rows, A->cols, NULL);

	for (int i = 0; i < result->rows; i++) {
		for (int j = 0; j < result->cols; j++) {
			float element = get_element(A, i, j) - get_element(B, i, j);
			set_element(result, i, j, element);
		}
	}

	assert(result != NULL);
	return result;
}

void matrix_sub_(matrix *A, matrix *B) {
	assert(A != NULL);
	assert(B != NULL);
	assert(A->rows == B->rows);
	assert(A->cols == B->cols);

	for (int i = 0; i < A->rows; i++) {
		for (int j = 0; j < A->cols; j++) {
			float element = get_element(A, i, j) - get_element(B, i, j);
			set_element(A, i, j, element);
		}
	}

	assert(A != NULL);
	return;
}

matrix* matrix_map(matrix *A, func *f) {
	assert(A != NULL);
	assert(f != NULL);

	matrix *result = new_matrix(A->rows, A->cols, NULL);

	for (int i = 0; i < result->rows; i++) {
		for (int j = 0; j < result->cols; j++) {
			float element = (*f)(get_element(A, i, j));
			set_element(result, i, j, element);
		}
	}

	assert(result != NULL);
	return result;
}

void matrix_map_(matrix *A, func *f) {
	assert(A != NULL);
	assert(f != NULL);

	for (int i = 0; i < A->rows; i++) {
		for (int j = 0; j < A->cols; j++) {
			float element = (*f)(get_element(A, i, j));
			set_element(A, i, j, element);
		}
	}

	assert(A != NULL);
	return;
}

matrix* transpose(matrix *A) {
	assert(A != NULL);

	matrix *result = new_matrix(A->cols, A->rows, NULL);

	for (int i = 0; i < result->rows; i++) {
		for (int j = 0; j < result->cols; j++) {
			float element = get_element(A, j, i);
			set_element(result, i, j, element);
		}
	}

	assert(result != NULL);
	return result;
}

void randomize(matrix *A) {
	assert(A != NULL);
	srand(time(0) + rand());
	for (int i = 0; i < (A->rows)*(A->cols); i++) {
		A->data[i] = 20*(rand()/(float)RAND_MAX) + -10;
	}
}

bool is_equal(matrix *A, matrix *B) {
	assert(A != NULL);
	assert(B != NULL);

	if ((A->rows != B->rows) || (A->cols != B->cols)) {
		return false;
	}

	for (int i = 0; i < A->rows; i++) {
		for (int j = 0; j < A->cols; j++) {
			if (get_element(A, i, j) != get_element(B, i, j)) {
				return false;
			}
		}
	}

	return true;
}

matrix* new_matrix(int rows, int cols, float *data) {
	assert(rows > 0);
	assert(cols > 0);

	matrix *A = xcalloc(1, sizeof(matrix));
	A->rows = rows;
	A->cols = cols;

	if (data == NULL) {
		A->data = xcalloc(rows*cols, sizeof(float));
	} else {
		A->data = data;
	}

	assert(A != NULL);
	return A;
}

void free_matrix(matrix *A) {
	free(A->data);
	A->data = NULL;
	free(A);
	return;
}

float get_element(matrix *A, int row, int col) {
	assert(A != NULL);

	// printf("A cols = %d  ", A->cols);
	// printf("col = %d\n\n", col);


	assert(row < A->rows);
	assert(row >= 0);
	assert(col < A->cols);
	assert(col >= 0);

	int index = row*(A->cols) + col;
	float element = A->data[index];
	return element;
}

void set_element(matrix *A, int row, int col, float element) {
	assert(A != NULL);
	assert(row < A->rows && row >= 0);
	assert(col < A->cols && col >= 0);

	int index = row*(A->cols) + col;
	A->data[index] = element;
	return;
}

void print_matrix(matrix *A) {
	assert(A != NULL);

	for (int i = 0; i < A->rows; i++) {
		for (int j = 0; j < A->cols; j++) {
			printf("%f  ", get_element(A, i, j));
		}
		printf("\n");
	}
	printf("\n");

	return;
}

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include "../lib/xalloc.h"
#include "../NN_Test/Matrix.h"

// matrix* sclr_mult(matrix *A, float sclr) {
// 	assert(A != NULL);

// 	matrix *result = new_matrix(A->rows, A->cols, NULL);

// 	for (int i = 0; i < result->rows; i++) {
// 		for (int j = 0; j < result->cols; j++) {
// 			float element = get_element(A, i, j) * sclr;
// 			set_element(result, i, j, element);
// 		}
// 	}

// 	assert(result != NULL);
// 	return result;
// }

// void sclr_mult_(matrix *A, float sclr) {
// 	assert(A != NULL);

// 	for (int i = 0; i < A->rows; i++) {
// 		for (int j = 0; j < A->cols; j++) {
// 			float element = get_element(A, i, j) * sclr;
// 			set_element(A, i, j, element);
// 		}
// 	}

// 	assert(A != NULL);
// 	return;
// }

// matrix* sclr_add(matrix *A, float sclr) {
// 	assert(A != NULL);

// 	matrix *result = new_matrix(A->rows, A->cols, NULL);

// 	for (int i = 0; i < result->rows; i++) {
// 		for (int j = 0; j < result->cols; j++) {
// 			float element = get_element(A, i, j) + sclr;
// 			set_element(result, i, j, element);
// 		}
// 	}

// 	assert(result != NULL);
// 	return result;
// }

// void sclr_add_(matrix *A, float sclr) {
// 	assert(A != NULL);

// 	for (int i = 0; i < A->rows; i++) {
// 		for (int j = 0; j < A->cols; j++) {
// 			float element = get_element(A, i, j) + sclr;
// 			set_element(A, i, j, element);
// 		}
// 	}

// 	assert(A != NULL);
// 	return;
// }

// matrix* matrix_mult(matrix* A, matrix *B) {
// 	assert(A != NULL);
// 	assert(B != NULL);
// 	assert(A->rows == B->rows);
// 	assert(A->cols == B->cols);

// 	matrix *result = new_matrix(A->rows, A->cols, NULL);

// 	for (int i = 0; i < result->rows; i++) {
// 		for (int j = 0; j < result->cols; j++) {
// 			float element = get_element(A, i, j) * get_element(B, i, j);
// 			set_element(result, i, j, element);
// 		}
// 	}

// 	assert(result != NULL);
// 	return result;
// }

// void matrix_mult_(matrix* A, matrix *B) {
// 	assert(A != NULL);
// 	assert(B != NULL);
// 	assert(A->rows == B->rows);
// 	assert(A->cols == B->cols);

// 	for (int i = 0; i < A->rows; i++) {
// 		for (int j = 0; j < A->cols; j++) {
// 			float element = get_element(A, i, j) * get_element(B, i, j);
// 			set_element(A, i, j, element);
// 		}
// 	}

// 	assert(A != NULL);
// 	return;
// }

// matrix* matrix_dot(matrix *A, matrix *B) {
// 	assert(A != NULL);
// 	assert(B != NULL);
// 	assert(A->cols == B->rows);

// 	matrix* result = new_matrix(A->rows, B->cols, NULL);

// 	for (int i = 0; i < result->rows; i++) {
// 		for (int j = 0; j < result->cols; j++) {
// 			float element = 0;
// 			for (int k = 0; k < A->cols; k++) {
// 				element += get_element(A, i, k) * get_element(B, k, j);
// 			}
// 			set_element(result, i, j, element);
// 		}
// 	}
// 	assert(result != NULL);
// 	return result;
// }

// matrix* matrix_add(matrix *A, matrix *B) {
// 	assert(A != NULL);
// 	assert(B != NULL);
// 	assert(A->rows == B->rows);
// 	assert(A->cols == B->cols);

// 	matrix *result = new_matrix(A->rows, A->cols, NULL);

// 	for (int i = 0; i < result->rows; i++) {
// 		for (int j = 0; j < result->cols; j++) {
// 			float element = get_element(A, i, j) + get_element(B, i, j);
// 			set_element(result, i, j, element);
// 		}
// 	}

// 	assert(result != NULL);
// 	return result;
// }

// void matrix_add_(matrix *A, matrix *B) {
// 	assert(A != NULL);
// 	assert(B != NULL);
// 	assert(A->rows == B->rows);
// 	assert(A->cols == B->cols);

// 	for (int i = 0; i < A->rows; i++) {
// 		for (int j = 0; j < A->cols; j++) {
// 			float element = get_element(A, i, j) + get_element(B, i, j);
// 			set_element(A, i, j, element);
// 		}
// 	}

// 	assert(A != NULL);
// 	return;
// }

// matrix* matrix_sub(matrix *A, matrix *B) {
// 	assert(A != NULL);
// 	assert(B != NULL);
// 	assert(A->rows == B->rows);
// 	assert(A->cols == B->cols);

// 	matrix *result = new_matrix(A->rows, A->cols, NULL);

// 	for (int i = 0; i < result->rows; i++) {
// 		for (int j = 0; j < result->cols; j++) {
// 			float element = get_element(A, i, j) - get_element(B, i, j);
// 			set_element(result, i, j, element);
// 		}
// 	}

// 	assert(result != NULL);
// 	return result;
// }

// void matrix_sub_(matrix *A, matrix *B) {
// 	assert(A != NULL);
// 	assert(B != NULL);
// 	assert(A->rows == B->rows);
// 	assert(A->cols == B->cols);

// 	for (int i = 0; i < A->rows; i++) {
// 		for (int j = 0; j < A->cols; j++) {
// 			float element = get_element(A, i, j) - get_element(B, i, j);
// 			set_element(A, i, j, element);
// 		}
// 	}

// 	assert(A != NULL);
// 	return;
// }

// matrix* matrix_map(matrix *A, func *f) {
// 	assert(A != NULL);
// 	assert(f != NULL);

// 	matrix *result = new_matrix(A->rows, A->cols, NULL);

// 	for (int i = 0; i < result->rows; i++) {
// 		for (int j = 0; j < result->cols; j++) {
// 			float element = (*f)(get_element(A, i, j));
// 			set_element(result, i, j, element);
// 		}
// 	}

// 	assert(result != NULL);
// 	return result;
// }

// void matrix_map_(matrix *A, func *f) {
// 	assert(A != NULL);
// 	assert(f != NULL);

// 	for (int i = 0; i < A->rows; i++) {
// 		for (int j = 0; j < A->cols; j++) {
// 			float element = (*f)(get_element(A, i, j));
// 			set_element(A, i, j, element);
// 		}
// 	}

// 	assert(A != NULL);
// 	return;
// }

// matrix* transpose(matrix *A) {
// 	assert(A != NULL);

// 	matrix *result = new_matrix(A->cols, A->rows, NULL);

// 	for (int i = 0; i < result->rows; i++) {
// 		for (int j = 0; j < result->cols; j++) {
// 			float element = get_element(A, j, i);
// 			set_element(result, i, j, element);
// 		}
// 	}

// 	assert(result != NULL);
// 	return result;
// }

// void randomize(matrix *A) {
// 	assert(A != NULL);
// 	srand(time(0) + rand());
// 	for (int i = 0; i < (A->rows)*(A->cols); i++) {
// 		A->data[i] = 20*(rand()/(float)RAND_MAX) + -10;
// 	}
// }

// bool is_equal(matrix *A, matrix *B) {
// 	assert(A != NULL);
// 	assert(B != NULL);

// 	if ((A->rows != B->rows) || (A->cols != B->cols)) {
// 		return false;
// 	}

// 	for (int i = 0; i < A->rows; i++) {
// 		for (int j = 0; j < A->cols; j++) {
// 			if (get_element(A, i, j) != get_element(B, i, j)) {
// 				return false;
// 			}
// 		}
// 	}

// 	return true;
// }

// matrix* new_matrix(int rows, int cols, float *data) {
// 	assert(rows > 0);
// 	assert(cols > 0);

// 	matrix *A = xcalloc(1, sizeof(matrix));
// 	A->rows = rows;
// 	A->cols = cols;

// 	if (data == NULL) {
// 		A->data = xcalloc(rows*cols, sizeof(float));
// 	} else {
// 		A->data = data;
// 	}

// 	assert(A != NULL);
// 	return A;
// }

// void free_matrix(matrix *A) {
// 	free(A->data);
// 	A->data = NULL;
// 	free(A);
// 	return;
// }

// float get_element(matrix *A, int row, int col) {
// 	assert(A != NULL);

// 	// printf("A cols = %d  ", A->cols);
// 	// printf("col = %d\n\n", col);


// 	assert(row < A->rows);
// 	assert(row >= 0);
// 	assert(col < A->cols);
// 	assert(col >= 0);

// 	int index = row*(A->cols) + col;
// 	float element = A->data[index];
// 	return element;
// }

// void set_element(matrix *A, int row, int col, float element) {
// 	assert(A != NULL);
// 	assert(row < A->rows && row >= 0);
// 	assert(col < A->cols && col >= 0);

// 	int index = row*(A->cols) + col;
// 	A->data[index] = element;
// 	return;
// }

struct data_header {
	jfloatArray data_obj;
	jfloat *data_array;
} typedef data;

jfloat get_rows(JNIEnv * env, jobject obj) {
	jclass object_class;
	jfieldID fid_rows;

	object_class = (*env)->GetObjectClass(env, obj);
	fid_rows = (*env)->GetFieldID(env, object_class, "rows", "I");

	if (fid_rows == NULL) {
		return -42;
	}

	jint rows = (*env)->GetIntField(env, obj, fid_rows);

	return rows;
}

jfloat get_cols(JNIEnv * env, jobject obj) {
	jclass object_class;
	jfieldID fid_cols;

	object_class = (*env)->GetObjectClass(env, obj);
	fid_cols = (*env)->GetFieldID(env, object_class, "cols", "I");

	if (fid_cols == NULL) {
		return -42;
	}

	jint cols = (*env)->GetIntField(env, obj, fid_cols);

	return cols;
}

data* get_data(JNIEnv * env, jobject obj) {
	jclass object_class;
	jfieldID fid_data;

	object_class = (*env)->GetObjectClass(env, obj);
	fid_data = (*env)->GetFieldID(env, object_class, "data", "[F");

	if (fid_data == NULL) {
		return NULL;
	}

	jfloatArray data_obj = (*env)->GetObjectField(env, obj, fid_data);
	jfloat *data_array = (*env)->GetFloatArrayElements(env, data_obj, 0); // allocate an array

	data *obj_data = xcalloc(1, sizeof(data));
	obj_data->data_obj = data_obj;
	obj_data->data_array = data_array;

	return obj_data;
}

void free_data(JNIEnv *env, data *obj_data) {
	(*env)->ReleaseFloatArrayElements(env, obj_data->data_obj, obj_data->data_array, 0); // free array
	free(obj_data); // free data struct
	return;
}

JNIEXPORT void JNICALL
Java_Matrix_set_1element(JNIEnv * env, jobject obj, jint row, jint col, jfloat element){
	jint rows = get_rows(env, obj);
	jint cols = get_cols(env, obj);

	assert(row >= 0 && row < rows);
	assert(col >= 0 && col < cols);

	jfloat singleton[] = {element};

	data *obj_data = get_data(env, obj);
	assert(obj_data != NULL);
	assert(obj_data->data_obj != NULL);

	jint index = row*cols + col;

	(*env)->SetFloatArrayRegion(env, singleton, index, 1, obj_data->data_obj);

	free_data(env, obj_data);
	return;
}

JNIEXPORT jfloat JNICALL
Java_Matrix_get_1element(JNIEnv *env, jobject obj, jint row, jint col) {
	jint rows = get_rows(env, obj);
	jint cols = get_cols(env, obj);

	assert(row >= 0 && row < rows);
	assert(col >= 0 && col < cols);
	
	data *obj_data = get_data(env, obj);

	jint index = (row * cols) + col;
	jfloat element = obj_data->data_array[index];

	free_data(env, obj_data);

	return element;

}

JNIEXPORT void JNICALL
Java_Matrix_print(JNIEnv *env, jobject obj) {
	jclass object_class; // object's class
	jfieldID fid_rows, fid_cols; // field IDs
	jmethodID mid_get; // instance method ID

	// Get Reference to object's class
	object_class = (*env)->GetObjectClass(env, obj);

	// Look for instance fields rows, cols, data in the object class
	fid_rows = (*env)->GetFieldID(env, object_class, "rows", "I");
	fid_cols = (*env)->GetFieldID(env, object_class, "cols", "I");

	if (fid_rows == NULL || fid_cols == NULL) {
		return; // failed to find fields
	}

	// Look for get_elemet, set_element IDs
	mid_get = (*env)->GetMethodID(env, object_class, "get_element", "(II)F");

	if (mid_get == NULL) {
		return; // failed to find instance methods
	}

	// Read instance fields rows, cols, data
	jint rows = (*env)->GetIntField(env, obj, fid_rows);
	jint cols = (*env)->GetIntField(env, obj, fid_cols);

	for (jint i = 0; i < rows; i++) {
		for (jint j = 0; j < cols; j++) {
			jfloat element = (jfloat)((*env)->CallFloatMethod(env, obj, mid_get, i, j));
			printf("%f ", element);
		}
		printf("\n");
	}

	return;

}

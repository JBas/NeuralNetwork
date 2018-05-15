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

jint get_rows(JNIEnv *env, jobject obj) {
	assert(env != NULL);
	assert(obj != NULL);

	jclass obj_class;
	jfieldID fid_rows;

	obj_class = (*env)->GetObjectClass(env, obj);
	assert(obj_class != NULL);

	fid_rows = (*env)->GetFieldID(env, obj_class, "rows", "I");
	assert(fid_rows != NULL);

	jint rows = (*env)->GetIntField(env, obj, fid_rows);

	assert(rows > 0);

	return rows;
}

jint get_cols(JNIEnv *env, jobject obj) {
	assert(env != NULL);
	assert(obj != NULL);

	jclass obj_class;
	jfieldID fid_cols;

	obj_class = (*env)->GetObjectClass(env, obj);
	assert(obj_class != NULL);

	fid_cols = (*env)->GetFieldID(env, obj_class, "cols", "I");
	assert(fid_cols != NULL);

	jint cols = (*env)->GetIntField(env, obj, fid_cols);

	assert(cols > 0);

	return cols;
}

// data* get_data(JNIEnv *env, jobject obj, jboolean iscopy) {
// 	jclass object_class;
// 	jfieldID fid_data;

// 	object_class = (*env)->GetObjectClass(env, obj);
// 	fid_data = (*env)->GetFieldID(env, object_class, "data", "[F");

// 	if (fid_data == NULL) {
// 		return NULL;
// 	}

// 	jfloatArray data_obj = (*env)->GetObjectField(env, obj, fid_data);
// 	jfloat *data_array = (*env)->GetFloatArrayElements(env, data_obj, &iscopy); // allocate an array

// 	data *obj_data = xcalloc(1, sizeof(data));
// 	obj_data->data_obj = data_obj;
// 	obj_data->data_array = data_array;

// 	return obj_data;
// }

// void free_data(JNIEnv *env, data *obj_data) {
// 	(*env)->ReleaseFloatArrayElements(env, obj_data->data_obj, obj_data->data_array, 0); // free array
// 	free(obj_data); // free data struct
// 	return;
// }

//@TODO: use the getter/setters as defined below
JNIEXPORT void JNICALL
Java_Matrix_sclr_1mult__F(JNIEnv *env, jobject this, jfloat sclr) {
	assert(env != NULL);
	assert(this != NULL);

	jclass this_class;
	jfieldID fid_data_this;


	jint rows_this = get_rows(env, this);
	jint cols_this = get_cols(env, this);

	// Get matrix A data
	this_class = (*env)->GetObjectClass(env, this);
	assert(this_class != NULL);

	fid_data_this = (*env)->GetFieldID(env, this_class, "data", "[F");
	assert(fid_data_this != NULL);

	jfloatArray array_obj_this = (*env)->GetObjectField(env, this, fid_data_this);
	assert(array_obj_this != NULL);

	jfloat *array_this = (*env)->GetFloatArrayElements(env, array_obj_this, 0);
	assert(array_this != NULL);
	// done getting matrix A data

	for (jint i = 0; i < rows_this; i++) {
		for (jint j = 0; j < cols_this; j++) {
			jint index = i*cols_this + j;
			assert(index >= 0 && index < rows_this*cols_this);

			array_this[index] = array_this[index] * sclr;
		}
	}

	// free matrix data
	(*env)->ReleaseFloatArrayElements(env, array_obj_this, array_this, 0);

	return;
}

//@TODO: use the getter/setters as defined below
JNIEXPORT void JNICALL
Java_Matrix_sclr_1add__F(JNIEnv *env, jobject this, jfloat sclr) {
	assert(env != NULL);
	assert(this != NULL);

	jclass this_class;
	jfieldID fid_data_this;


	jint rows_this = get_rows(env, this);
	jint cols_this = get_cols(env, this);

	// Get matrix A data
	this_class = (*env)->GetObjectClass(env, this);
	assert(this_class != NULL);

	fid_data_this = (*env)->GetFieldID(env, this_class, "data", "[F");
	assert(fid_data_this != NULL);

	jfloatArray array_obj_this = (*env)->GetObjectField(env, this, fid_data_this);
	assert(array_obj_this != NULL);

	jfloat *array_this = (*env)->GetFloatArrayElements(env, array_obj_this, 0);
	assert(array_this != NULL);
	// done getting matrix A data

	for (jint i = 0; i < rows_this; i++) {
		for (jint j = 0; j < cols_this; j++) {
			jint index = i*cols_this + j;
			assert(index >= 0 && index < rows_this*cols_this);

			array_this[index] = array_this[index] + sclr;
		}
	}

	// free matrix data
	(*env)->ReleaseFloatArrayElements(env, array_obj_this, array_this, 0);

	return;
}

//@TODO: use the getter/setters as defined below
JNIEXPORT void JNICALL
Java_Matrix_matrix_1mult__LMatrix_2(JNIEnv *env, jobject this, jobject other) {
	assert(env != NULL);
	assert(this != NULL);
	assert(other != NULL);

	jclass this_class, other_class;
	jfieldID fid_data_this, fid_data_other;


	jint rows_this = get_rows(env, this);
	jint cols_this = get_cols(env, this);

	jint rows_other = get_rows(env, other);
	jint cols_other = get_cols(env, other);

	assert(rows_this == rows_other);
	assert(cols_this == cols_other);

	// Get matrix A data
	this_class = (*env)->GetObjectClass(env, this);
	assert(this_class != NULL);

	fid_data_this = (*env)->GetFieldID(env, this_class, "data", "[F");
	assert(fid_data_this != NULL);

	jfloatArray array_obj_this = (*env)->GetObjectField(env, this, fid_data_this);
	assert(array_obj_this != NULL);

	jfloat *array_this = (*env)->GetFloatArrayElements(env, array_obj_this, 0);
	assert(array_this != NULL);
	// done getting matrix A data
	

	// Get matrix B data
	other_class = (*env)->GetObjectClass(env, other);
	assert(other_class != NULL);

	fid_data_other = (*env)->GetFieldID(env, other_class, "data", "[F");
	assert(fid_data_other != NULL);

	jfloatArray array_obj_other = (*env)->GetObjectField(env, other, fid_data_other);
	assert(array_obj_other != NULL);

	jfloat *array_other = (*env)->GetFloatArrayElements(env, array_obj_other, 0);
	assert(array_other != NULL);
	// done getting matrix B data

	for (jint i = 0; i < rows_this; i++) {
		for (jint j = 0; j < cols_this; j++) {
			jint index = i*cols_this + j;
			assert(index >= 0 && index < rows_this*cols_this);

			array_this[index] = array_this[index] * array_other[index];
		}
	}

	// free matrix data
	(*env)->ReleaseFloatArrayElements(env, array_obj_this, array_this, 0);
	(*env)->ReleaseFloatArrayElements(env, array_obj_other, array_other, 0);

	return;
}

//@TODO: use the getter/setters as defined below
JNIEXPORT void JNICALL
Java_Matrix_matrix_1add__LMatrix_2(JNIEnv *env, jobject this, jobject other) {
	assert(env != NULL);
	assert(this != NULL);
	assert(other != NULL);

	jclass this_class, other_class;
	jfieldID fid_data_this, fid_data_other;


	jint rows_this = get_rows(env, this);
	jint cols_this = get_cols(env, this);

	jint rows_other = get_rows(env, other);
	jint cols_other = get_cols(env, other);

	assert(rows_this == rows_other);
	assert(cols_this == cols_other);

	// Get matrix A data
	this_class = (*env)->GetObjectClass(env, this);
	assert(this_class != NULL);

	fid_data_this = (*env)->GetFieldID(env, this_class, "data", "[F");
	assert(fid_data_this != NULL);

	jfloatArray array_obj_this = (*env)->GetObjectField(env, this, fid_data_this);
	assert(array_obj_this != NULL);

	jfloat *array_this = (*env)->GetFloatArrayElements(env, array_obj_this, 0);
	assert(array_this != NULL);
	// done getting matrix A data
	

	// Get matrix B data
	other_class = (*env)->GetObjectClass(env, other);
	assert(other_class != NULL);

	fid_data_other = (*env)->GetFieldID(env, other_class, "data", "[F");
	assert(fid_data_other != NULL);

	jfloatArray array_obj_other = (*env)->GetObjectField(env, other, fid_data_other);
	assert(array_obj_other != NULL);

	jfloat *array_other = (*env)->GetFloatArrayElements(env, array_obj_other, 0);
	assert(array_other != NULL);
	// done getting matrix B data

	for (jint i = 0; i < rows_this; i++) {
		for (jint j = 0; j < cols_this; j++) {
			jint index = i*cols_this + j;
			assert(index >= 0 && index < rows_this*cols_this);

			array_this[index] = array_this[index] + array_other[index];
		}
	}

	// free matrix data
	(*env)->ReleaseFloatArrayElements(env, array_obj_this, array_this, 0);
	(*env)->ReleaseFloatArrayElements(env, array_obj_other, array_other, 0);

	return;
}

//@TODO: use the getter/setters as defined below
JNIEXPORT void JNICALL
Java_Matrix_matrix_1sub__LMatrix_2(JNIEnv *env, jobject this, jobject other) {
	assert(env != NULL);
	assert(this != NULL);
	assert(other != NULL);

	jclass this_class, other_class;
	jfieldID fid_data_this, fid_data_other;


	jint rows_this = get_rows(env, this);
	jint cols_this = get_cols(env, this);

	jint rows_other = get_rows(env, other);
	jint cols_other = get_cols(env, other);

	assert(rows_this == rows_other);
	assert(cols_this == cols_other);

	// Get matrix A data
	this_class = (*env)->GetObjectClass(env, this);
	assert(this_class != NULL);

	fid_data_this = (*env)->GetFieldID(env, this_class, "data", "[F");
	assert(fid_data_this != NULL);

	jfloatArray array_obj_this = (*env)->GetObjectField(env, this, fid_data_this);
	assert(array_obj_this != NULL);

	jfloat *array_this = (*env)->GetFloatArrayElements(env, array_obj_this, 0);
	assert(array_this != NULL);
	// done getting matrix A data
	

	// Get matrix B data
	other_class = (*env)->GetObjectClass(env, other);
	assert(other_class != NULL);

	fid_data_other = (*env)->GetFieldID(env, other_class, "data", "[F");
	assert(fid_data_other != NULL);

	jfloatArray array_obj_other = (*env)->GetObjectField(env, other, fid_data_other);
	assert(array_obj_other != NULL);

	jfloat *array_other = (*env)->GetFloatArrayElements(env, array_obj_other, 0);
	assert(array_other != NULL);
	// done getting matrix B data

	for (jint i = 0; i < rows_this; i++) {
		for (jint j = 0; j < cols_this; j++) {
			jint index = i*cols_this + j;
			assert(index >= 0 && index < rows_this*cols_this);

			array_this[index] = array_this[index] - array_other[index];
		}
	}

	// free matrix data
	(*env)->ReleaseFloatArrayElements(env, array_obj_this, array_this, 0);
	(*env)->ReleaseFloatArrayElements(env, array_obj_other, array_other, 0);

	return;
}

//@TODO: use the getter/setters as defined below
JNIEXPORT jobject JNICALL
Java_Matrix_transpose(JNIEnv *env, jclass obj_class, jobject obj) {
	assert(env != NULL);
	assert(obj_class != NULL);
	assert(obj != NULL);

	jmethodID constr_id;
	jfieldID fid_data;

	jint rows = get_rows(env, obj);
	jint cols = get_cols(env, obj);

	// Get matrix data
	fid_data = (*env)->GetFieldID(env, obj_class, "data", "[F");
	assert(fid_data != NULL);

	jfloatArray array_obj = (*env)->GetObjectField(env, obj, fid_data);
	assert(array_obj != NULL);

	jfloat *array = (*env)->GetFloatArrayElements(env, array_obj, 0);
	assert(array != NULL);
	// done getting matrix data

	jfloatArray array_obj_t = (*env)->NewFloatArray(env, rows*cols);
	assert(array_obj_t != NULL);

	jfloat *array_t = (*env)->GetFloatArrayElements(env, array_obj_t, 0);
	assert(array_t != NULL);

	for (jint i = 0; i < rows; i++) {
		for (jint j = 0; j < cols; j++) {
			jint index = i*cols + j;
			assert(index >= 0 && index < rows*cols);

			jint index_t = j*rows + i;
			assert(index_t >= 0 && index_t < rows*cols);

			jfloat elem = array[index];
			array_t[index_t] = elem;
		}
	}
	(*env)->ReleaseFloatArrayElements(env, array_obj_t, array_t, 0);

	constr_id = (*env)->GetMethodID(env, obj_class, "<init>", "(II[F)V");
	assert(constr_id != NULL);

	jobject A = (*env)->NewObject(env, obj_class, constr_id, rows, cols, array_obj_t);
	assert(A != NULL);

	(*env)->ReleaseFloatArrayElements(env, array_obj, array, 0);

	return A;
}

JNIEXPORT jobject JNICALL
Java_Matrix_fromArray(JNIEnv *env, jclass obj_class, jint rows, jint cols, jfloatArray array_obj) {
	assert(env != NULL);
	assert(obj_class != NULL);
	assert(array_obj != NULL);
	assert(rows > 0);
	assert(cols > 0);

	jmethodID constr_id;

	constr_id = (*env)->GetMethodID(env, obj_class, "<init>", "(II[F)V");
	assert(constr_id != NULL);

	jobject A = (*env)->NewObject(env, obj_class, constr_id, rows, cols, array_obj);
	assert(A != NULL);

	return A;
}


JNIEXPORT jfloatArray JNICALL
Java_Matrix_toArray(JNIEnv *env, jobject this) {
	assert(env != NULL);
	assert(this != NULL);

	jclass this_class;
	jfieldID fid_data;

	jint rows = get_rows(env, this);
	jint cols = get_cols(env, this);

	// Get matrix data
	this_class = (*env)->GetObjectClass(env, this);
	assert(this_class != NULL);

	fid_data = (*env)->GetFieldID(env, this_class, "data", "[F");
	assert(fid_data != NULL);

	jfloatArray array_obj = (*env)->GetObjectField(env, this, fid_data);
	assert(array_obj != NULL);

	jfloat *array = (*env)->GetFloatArrayElements(env, array_obj, 0);
	assert(array != NULL);
	// done getting matrix data

	jfloatArray array_obj_cpy = (*env)->NewFloatArray(env, rows*cols);
	assert(array_obj_cpy != NULL);

	jfloat *array_cpy = (*env)->GetFloatArrayElements(env, array_obj_cpy, 0);
	assert(array_cpy != NULL);

	for (jint i = 0; i < rows*cols; i++) {
		array_cpy[i] = array[i];
	}

	(*env)->ReleaseFloatArrayElements(env, array_obj, array, 0);

	return array_obj;
}

JNIEXPORT jboolean JNICALL
Java_Matrix_is_1equal(JNIEnv *env, jobject this, jobject other) {
	assert(env != NULL);
	assert(this != NULL);
	assert(other != NULL);

	jclass this_class, other_class;
	jmethodID mid_get_this, mid_get_other;

	jint rows_this = get_rows(env, this);
	jint cols_this = get_cols(env, this);

	jint rows_other = get_rows(env, other);
	jint cols_other = get_cols(env, other);

	assert(rows_this == rows_other);
	assert(cols_this == cols_other);

	this_class = (*env)->GetObjectClass(env, this);
	other_class = (*env)->GetObjectClass(env, other);

	assert(this_class != NULL);
	assert(other_class != NULL);

	mid_get_this = (*env)->GetMethodID(env, this_class, "get_element", "(II)F");
	mid_get_other = (*env)->GetMethodID(env, other_class, "get_element", "(II)F");

	assert(mid_get_this != NULL);
	assert(mid_get_other != NULL);

	for (jint i = 0; i < rows_this; i++) {
		for (jint j = 0; j < cols_this; j++) {
			float elemA = (jfloat)((*env)->CallFloatMethod(env, this, mid_get_this, i, j));
			float elemB = (jfloat)((*env)->CallFloatMethod(env, this, mid_get_other, i, j));
			if (elemA != elemA) {
				return false;
			}
		}
	}

	return true;
}

JNIEXPORT void JNICALL
Java_Matrix_set_1element(JNIEnv *env, jobject this, jint row, jint col, jfloat elem) {
	assert(env != NULL);
	assert(this != NULL);

	jclass this_class;
	jfieldID fid_data;

	jint rows = get_rows(env, this);
	jint cols = get_cols(env, this);

	assert(row >= 0 && row < rows);
	assert(col >= 0 && col < cols);

	// Get matrix data
	this_class = (*env)->GetObjectClass(env, this);
	assert(this_class != NULL);

	fid_data = (*env)->GetFieldID(env, this_class, "data", "[F");
	assert(fid_data != NULL);

	jfloatArray array_obj = (*env)->GetObjectField(env, this, fid_data);
	assert(array_obj != NULL);

	jfloat *array = (*env)->GetFloatArrayElements(env, array_obj, 0);
	assert(array != NULL);
	// done getting matrix data

	jint index = row*cols + col;
	assert(index >= 0 && index < rows*cols);

	array[index] = elem;

	// free matrix data
	(*env)->ReleaseFloatArrayElements(env, array_obj, array, 0);

	return;
}

JNIEXPORT jfloat JNICALL
Java_Matrix_get_1element(JNIEnv *env, jobject this, jint row, jint col) {
	assert(env != NULL);
	assert(this != NULL);

	jclass this_class;
	jfieldID fid_data;

	jint rows = get_rows(env, this);
	jint cols = get_cols(env, this);

	assert(row >= 0 && row < rows);
	assert(col >= 0 && col < cols);

	// Get matrix data
	this_class = (*env)->GetObjectClass(env, this);
	assert(this_class != NULL);

	fid_data = (*env)->GetFieldID(env, this_class, "data", "[F");
	assert(fid_data != NULL);

	jfloatArray array_obj = (*env)->GetObjectField(env, this, fid_data);
	assert(array_obj != NULL);

	jfloat *array = (*env)->GetFloatArrayElements(env, array_obj, 0);
	assert(array != NULL);
	// done getting matrix data

	jint index = row*cols + col;
	assert(index >= 0 && index < rows*cols);

	jfloat elem = array[index];

	// free matrix data
	(*env)->ReleaseFloatArrayElements(env, array_obj, array, 0);

	return elem;
}

JNIEXPORT void JNICALL
Java_Matrix_print(JNIEnv *env, jobject this) {
	assert(env != NULL);
	assert(this != NULL);

	jclass this_class; // object's class
	jfieldID fid_rows, fid_cols; // field IDs
	jmethodID mid_get; // instance method ID

	// Get Reference to object's class
	this_class = (*env)->GetObjectClass(env, this);
	assert(this_class != NULL);

	// Look for instance fields rows, cols, data in the object class
	fid_rows = (*env)->GetFieldID(env, this_class, "rows", "I");
	fid_cols = (*env)->GetFieldID(env, this_class, "cols", "I");

	assert(fid_rows != NULL);
	assert(fid_cols != NULL);

	// Look for get_elemet, set_element IDs
	mid_get = (*env)->GetMethodID(env, this_class, "get_element", "(II)F");
	assert(mid_get != NULL);

	// Read instance fields rows, cols, data
	jint rows = (*env)->GetIntField(env, this, fid_rows);
	jint cols = (*env)->GetIntField(env, this, fid_cols);

	for (jint i = 0; i < rows; i++) {
		for (jint j = 0; j < cols; j++) {
			jfloat elem = (jfloat)((*env)->CallFloatMethod(env, this, mid_get, i, j));
			printf("%f ", elem);
		}
		printf("\n");
	}
	printf("\n");

	return;
}

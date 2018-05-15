#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include "../lib/xalloc.h"
#include "../NN_Test/Matrix.h"

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

JNIEXPORT jobject JNICALL
Java_Matrix_sclr_1mult__LMatrix_2F(JNIEnv *env, jclass obj_class, jobject A, jfloat sclr) {
	assert(env != NULL);
	assert(obj_class != NULL);
	assert(A != NULL);

	jmethodID constr_id;
	jmethodID mid_get, mid_set;

	jint rowsA = get_rows(env, A);
	jint colsA = get_cols(env, A);

	constr_id = (*env)->GetMethodID(env, obj_class, "<init>", "(II[F)V");
	assert(constr_id != NULL);

	jobject C = (*env)->NewObject(env, obj_class, constr_id, rowsA, colsA, NULL);
	assert(C != NULL);

	mid_get = (*env)->GetMethodID(env, obj_class, "get_element", "(II)F");
	mid_set = (*env)->GetMethodID(env, obj_class, "set_element", "(IIF)V");

	assert(mid_get != NULL);
	assert(mid_set != NULL);

	for (jint i = 0; i < rowsA; i++) {
		for (jint j = 0; j < colsA; j++) {
			jfloat elem = (*env)->CallFloatMethod(env, A, mid_get, i, j);
			(*env)->CallFloatMethod(env, C, mid_set, i, j, elem * sclr);
		}
	}

	return C;
}

JNIEXPORT jobject JNICALL
Java_Matrix_sclr_1add__LMatrix_2F(JNIEnv *env, jclass obj_class, jobject A, jfloat sclr) {
	assert(env != NULL);
	assert(obj_class != NULL);
	assert(A != NULL);

	jmethodID constr_id;
	jmethodID mid_get, mid_set;

	jint rowsA = get_rows(env, A);
	jint colsA = get_cols(env, A);

	constr_id = (*env)->GetMethodID(env, obj_class, "<init>", "(II[F)V");
	assert(constr_id != NULL);

	jobject C = (*env)->NewObject(env, obj_class, constr_id, rowsA, colsA, NULL);
	assert(C != NULL);

	mid_get = (*env)->GetMethodID(env, obj_class, "get_element", "(II)F");
	mid_set = (*env)->GetMethodID(env, obj_class, "set_element", "(IIF)V");

	assert(mid_get != NULL);
	assert(mid_set != NULL);

	for (jint i = 0; i < rowsA; i++) {
		for (jint j = 0; j < colsA; j++) {
			jfloat elem = (*env)->CallFloatMethod(env, A, mid_get, i, j);
			(*env)->CallFloatMethod(env, C, mid_set, i, j, elem + sclr);
		}
	}

	return C;
}

JNIEXPORT void JNICALL
Java_Matrix_sclr_1mult__F(JNIEnv *env, jobject this, jfloat sclr) {
	assert(env != NULL);
	assert(this != NULL);

	jclass this_class;
	jmethodID mid_get_this, mid_set_this;

	jint rows_this = get_rows(env, this);
	jint cols_this = get_cols(env, this);

	this_class = (*env)->GetObjectClass(env, this);
	assert(this_class != NULL);

	mid_get_this = (*env)->GetMethodID(env, this_class, "get_element", "(II)F");
	mid_set_this = (*env)->GetMethodID(env, this_class, "set_element", "(IIF)V");

	assert(mid_get_this != NULL);
	assert(mid_set_this != NULL);

	for (jint i = 0; i < rows_this; i++) {
		for (jint j = 0; j < cols_this; j++) {
			jfloat elem_this = (*env)->CallFloatMethod(env, this, mid_get_this, i, j);

			(*env)->CallFloatMethod(env, this, mid_set_this, i, j, elem_this * sclr);
		}
	}

	return;
}

JNIEXPORT void JNICALL
Java_Matrix_sclr_1add__F(JNIEnv *env, jobject this, jfloat sclr) {
	assert(env != NULL);
	assert(this != NULL);

	jclass this_class;
	jmethodID mid_get_this, mid_set_this;

	jint rows_this = get_rows(env, this);
	jint cols_this = get_cols(env, this);

	this_class = (*env)->GetObjectClass(env, this);
	assert(this_class != NULL);

	mid_get_this = (*env)->GetMethodID(env, this_class, "get_element", "(II)F");
	mid_set_this = (*env)->GetMethodID(env, this_class, "set_element", "(IIF)V");

	assert(mid_get_this != NULL);
	assert(mid_set_this != NULL);

	for (jint i = 0; i < rows_this; i++) {
		for (jint j = 0; j < cols_this; j++) {
			jfloat elem_this = (*env)->CallFloatMethod(env, this, mid_get_this, i, j);

			(*env)->CallFloatMethod(env, this, mid_set_this, i, j, elem_this + sclr);
		}
	}

	return;
}

JNIEXPORT jobject JNICALL
Java_Matrix_matrix_1mult__LMatrix_2LMatrix_2(JNIEnv *env, jclass obj_class, jobject A, jobject B) {
	assert(env != NULL);
	assert(obj_class != NULL);
	assert(A != NULL);
	assert(B != NULL);

	jmethodID constr_id;
	jmethodID mid_get, mid_set;

	jint rowsA = get_rows(env, A);
	jint colsA = get_cols(env, A);

	jint rowsB = get_rows(env, B);
	jint colsB = get_cols(env, B);

	assert(rowsA == rowsB);
	assert(colsA == colsB);

	constr_id = (*env)->GetMethodID(env, obj_class, "<init>", "(II[F)V");
	assert(constr_id != NULL);

	jobject C = (*env)->NewObject(env, obj_class, constr_id, rowsA, colsA, NULL);
	assert(C != NULL);

	mid_get = (*env)->GetMethodID(env, obj_class, "get_element", "(II)F");
	mid_set = (*env)->GetMethodID(env, obj_class, "set_element", "(IIF)V");

	assert(mid_get != NULL);
	assert(mid_set != NULL);

	for (jint i = 0; i < rowsA; i++) {
		for (jint j = 0; j < colsA; j++) {
			jfloat elemA = (*env)->CallFloatMethod(env, A, mid_get, i, j);
			jfloat elemB = (*env)->CallFloatMethod(env, B, mid_get, i, j);
			(*env)->CallFloatMethod(env, C, mid_set, i, j, elemA * elemB);
		}
	}

	return C;
}

JNIEXPORT void JNICALL
Java_Matrix_matrix_1mult__LMatrix_2(JNIEnv *env, jobject this, jobject other) {
	assert(env != NULL);
	assert(this != NULL);
	assert(other != NULL);

	jclass this_class, other_class;
	jmethodID mid_get_this, mid_set_this;
	jmethodID mid_get_other;

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
	mid_set_this = (*env)->GetMethodID(env, this_class, "set_element", "(IIF)V");

	assert(mid_get_this != NULL);
	assert(mid_get_other != NULL);
	assert(mid_set_this != NULL);

	for (jint i = 0; i < rows_this; i++) {
		for (jint j = 0; j < cols_this; j++) {
			jfloat elem_this = (*env)->CallFloatMethod(env, this, mid_get_this, i, j);
			jfloat elem_other = (*env)->CallFloatMethod(env, other, mid_get_other, i, j);

			(*env)->CallFloatMethod(env, this, mid_set_this, i, j, elem_this * elem_other);
		}
	}

	return;
}

JNIEXPORT jobject JNICALL
Java_Matrix_matrix_1dot(JNIEnv *env, jclass obj_class, jobject A, jobject B) {
	assert(env != NULL);
	assert(obj_class != NULL);
	assert(A != NULL);
	assert(B != NULL);

	jmethodID constr_id;
	jmethodID mid_get, mid_set;

	jint rowsA = get_rows(env, A);
	jint colsA = get_cols(env, A);

	jint rowsB = get_rows(env, B);
	jint colsB = get_cols(env, B);

	assert(colsA == rowsB);

	constr_id = (*env)->GetMethodID(env, obj_class, "<init>", "(II[F)V");
	assert(constr_id != NULL);

	jobject C = (*env)->NewObject(env, obj_class, constr_id, rowsA, colsB, NULL);
	assert(C != NULL);

	mid_get = (*env)->GetMethodID(env, obj_class, "get_element", "(II)F");
	mid_set = (*env)->GetMethodID(env, obj_class, "set_element", "(IIF)V");

	assert(mid_get != NULL);
	assert(mid_set != NULL);

	for (jint i = 0; i < rowsA; i++) {
		for (jint j = 0; j < colsB; j++) {
			jfloat elem = 0;
			for (jint k = 0; k < colsA; k++) {
				jfloat elemA = (*env)->CallFloatMethod(env, A, mid_get, i, k);
				jfloat elemB = (*env)->CallFloatMethod(env, B, mid_get, k, j);
				elem += (elemA * elemB);
			}
			(*env)->CallFloatMethod(env, C, mid_set, i, j, elem);
		}
	}

	return C;
}

JNIEXPORT jobject JNICALL
Java_Matrix_matrix_1add__LMatrix_2LMatrix_2(JNIEnv *env, jclass obj_class, jobject A, jobject B) {
	assert(env != NULL);
	assert(obj_class != NULL);
	assert(A != NULL);
	assert(B != NULL);

	jmethodID constr_id;
	jmethodID mid_get, mid_set;

	jint rowsA = get_rows(env, A);
	jint colsA = get_cols(env, A);

	jint rowsB = get_rows(env, B);
	jint colsB = get_cols(env, B);

	assert(rowsA == rowsB);
	assert(colsA == colsB);

	constr_id = (*env)->GetMethodID(env, obj_class, "<init>", "(II[F)V");
	assert(constr_id != NULL);

	jobject C = (*env)->NewObject(env, obj_class, constr_id, rowsA, colsA, NULL);
	assert(C != NULL);

	mid_get = (*env)->GetMethodID(env, obj_class, "get_element", "(II)F");
	mid_set = (*env)->GetMethodID(env, obj_class, "set_element", "(IIF)V");

	assert(mid_get != NULL);
	assert(mid_set != NULL);

	for (jint i = 0; i < rowsA; i++) {
		for (jint j = 0; j < colsA; j++) {
			jfloat elemA = (*env)->CallFloatMethod(env, A, mid_get, i, j);
			jfloat elemB = (*env)->CallFloatMethod(env, B, mid_get, i, j);
			(*env)->CallFloatMethod(env, C, mid_set, i, j, elemA + elemB);
		}
	}

	return C;
}

JNIEXPORT jobject JNICALL
Java_Matrix_matrix_1sub__LMatrix_2LMatrix_2(JNIEnv *env, jclass obj_class, jobject A, jobject B) {
	assert(env != NULL);
	assert(obj_class != NULL);
	assert(A != NULL);
	assert(B != NULL);

	jmethodID constr_id;
	jmethodID mid_get, mid_set;

	jint rowsA = get_rows(env, A);
	jint colsA = get_cols(env, A);

	jint rowsB = get_rows(env, B);
	jint colsB = get_cols(env, B);

	assert(rowsA == rowsB);
	assert(colsA == colsB);

	constr_id = (*env)->GetMethodID(env, obj_class, "<init>", "(II[F)V");
	assert(constr_id != NULL);

	jobject C = (*env)->NewObject(env, obj_class, constr_id, rowsA, colsA, NULL);
	assert(C != NULL);

	mid_get = (*env)->GetMethodID(env, obj_class, "get_element", "(II)F");
	mid_set = (*env)->GetMethodID(env, obj_class, "set_element", "(IIF)V");

	assert(mid_get != NULL);
	assert(mid_set != NULL);

	for (jint i = 0; i < rowsA; i++) {
		for (jint j = 0; j < colsA; j++) {
			jfloat elemA = (*env)->CallFloatMethod(env, A, mid_get, i, j);
			jfloat elemB = (*env)->CallFloatMethod(env, B, mid_get, i, j);
			(*env)->CallFloatMethod(env, C, mid_set, i, j, elemA - elemB);
		}
	}

	return C;
}

JNIEXPORT void JNICALL
Java_Matrix_matrix_1add__LMatrix_2(JNIEnv *env, jobject this, jobject other) {
	assert(env != NULL);
	assert(this != NULL);
	assert(other != NULL);

	jclass this_class, other_class;
	jmethodID mid_get_this, mid_set_this;
	jmethodID mid_get_other;

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
	mid_set_this = (*env)->GetMethodID(env, this_class, "set_element", "(IIF)V");

	assert(mid_get_this != NULL);
	assert(mid_get_other != NULL);
	assert(mid_set_this != NULL);

	for (jint i = 0; i < rows_this; i++) {
		for (jint j = 0; j < cols_this; j++) {
			jfloat elem_this = (*env)->CallFloatMethod(env, this, mid_get_this, i, j);
			jfloat elem_other = (*env)->CallFloatMethod(env, other, mid_get_other, i, j);

			(*env)->CallFloatMethod(env, this, mid_set_this, i, j, elem_this + elem_other);
		}
	}

	return;
}

JNIEXPORT void JNICALL
Java_Matrix_matrix_1sub__LMatrix_2(JNIEnv *env, jobject this, jobject other) {
	assert(env != NULL);
	assert(this != NULL);
	assert(other != NULL);

	jclass this_class, other_class;
	jmethodID mid_get_this, mid_set_this;
	jmethodID mid_get_other;

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
	mid_set_this = (*env)->GetMethodID(env, this_class, "set_element", "(IIF)V");

	assert(mid_get_this != NULL);
	assert(mid_get_other != NULL);
	assert(mid_set_this != NULL);

	for (jint i = 0; i < rows_this; i++) {
		for (jint j = 0; j < cols_this; j++) {
			jfloat elem_this = (*env)->CallFloatMethod(env, this, mid_get_this, i, j);
			jfloat elem_other = (*env)->CallFloatMethod(env, other, mid_get_other, i, j);

			(*env)->CallFloatMethod(env, this, mid_set_this, i, j, elem_this - elem_other);
		}
	}

	return;
}

JNIEXPORT jobject JNICALL
Java_Matrix_transpose(JNIEnv *env, jclass obj_class, jobject obj) {
	assert(env != NULL);
	assert(obj_class != NULL);
	assert(obj != NULL);

	jmethodID constr_id, mid_get, mid_set;

	jint rows = get_rows(env, obj);
	jint cols = get_cols(env, obj);

	constr_id = (*env)->GetMethodID(env, obj_class, "<init>", "(II[F)V");
	assert(constr_id != NULL);

	jobject A = (*env)->NewObject(env, obj_class, constr_id, rows, cols, NULL);
	assert(A != NULL);

	mid_get = (*env)->GetMethodID(env, obj_class, "get_element", "(II)F");
	mid_set = (*env)->GetMethodID(env, obj_class, "set_element", "(IIF)V");

	assert(mid_get != NULL);
	assert(mid_set != NULL);

	for (jint i = 0; i < rows; i++) {
		for (jint j = 0; j < cols; j++) {
			jfloat elem = (*env)->CallFloatMethod(env, obj, mid_get, j, i);
			(*env)->CallFloatMethod(env, A, mid_set, i, j, elem);
		}
	}

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

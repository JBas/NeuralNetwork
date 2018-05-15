#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "../NN_Test/Neural.h"

// void train(neural* N, matrix* input, matrix* answer) {
// 	assert(N != NULL);
// 	assert(input != NULL);
// 	assert(answer != NULL);

// 	matrix* hidden = matrix_dot(N->weights_IH, input);
// 	printf("CLEAR\n");
// 	matrix_add_(hidden, N->bias_H);
// 	printf("CLEAR\n");

// 	func *f = &sigmoid;
// 	matrix_map_(hidden, f);
// 	printf("CLEAR\n");

// 	matrix* guess = matrix_dot(N->weights_HO, hidden);
// 	printf("CLEAR\n");
// 	matrix_add_(guess, N->bias_O);
// 	printf("CLEAR\n");
// 	matrix_map_(guess, f);
// 	printf("CLEAR\n");

// 	// ERROR = ANSWER - GUESS
// 	print_matrix(answer);
// 	printf("\n");
// 	print_matrix(guess);
// 	matrix* guess_error = matrix_sub(answer, guess);
// 	printf("CLEAR\n");

// 	matrix* gradient = matrix_map(guess, &dsig);
// 	printf("CLEAR\n");
// 	matrix_mult_(gradient, guess_error);
// 	printf("CLEAR\n");
// 	sclr_mult_(gradient, N->learning_rate);
// 	printf("CLEAR\n");

// 	matrix* hidden_t = transpose(hidden);
// 	printf("CLEAR\n");
// 	matrix* dweights_HO = matrix_dot(gradient, hidden_t);
// 	printf("CLEAR\n");

// 	matrix_add_(N->weights_HO, dweights_HO);
// 	printf("CLEAR\n");
// 	matrix_add_(N->bias_O, gradient);
// 	printf("CLEAR\n");

// 	matrix* weights_HO_t = transpose(N->weights_HO);
// 	printf("CLEAR\n");
// 	matrix* hidden_error = matrix_dot(weights_HO_t, guess_error);
// 	printf("CLEAR\n");

// 	matrix* hidden_gradient = matrix_map(hidden, &dsig);
// 	printf("CLEAR\n");
// 	matrix_mult_(hidden_gradient, hidden_error);
// 	printf("CLEAR\n");
// 	sclr_mult_(hidden_gradient, N->learning_rate);
// 	printf("CLEAR\n");

// 	matrix* input_t = transpose(input);
// 	printf("CLEAR\n");
// 	matrix* dweights_IH = matrix_dot(hidden_gradient, input_t);
// 	printf("CLEAR\n");

// 	matrix_add_(N->weights_IH, dweights_IH);
// 	printf("CLEAR\n");
// 	matrix_add_(N->bias_H, hidden_gradient);
// 	printf("CLEAR\n");

// 	print_matrix(guess);
// 	print_matrix(answer);
// 	print_matrix(guess_error);
// }
JNIEXPORT void JNICALL
Java_Neural_train(JNIEnv *env, jobject this, jobject input, jobject answer); {
	assert(env != NULL);
	assert(this != NULL);
	assert(input != NULL);
	assert(answer != NULL);
}

JNIEXPORT jobject JNICALL
Java_Neural_feedforward(JNIEnv *env, jobject this, jobject input) {
	assert(env != NULL);
	assert(this != NULL);
	assert(input != NULL);

	jclass this_class, matrix_class;
	jfieldID fid_wIH, fid_wHO, fid_bH, fid_bO;
	jmethodID mid_dot, mid_add, mid_map;

	this_class = (*env)->GetObjectClass(env, this);
	matrix_class = (*env)->GetObjectClass(env, input);
	assert(this_class != NULL);
	assert(matrix_class != NULL);

	fid_wIH = (*env)->GetFieldID(env, this_class, "weights_IH", "LMatrix;");
	fid_wHO = (*env)->GetFieldID(env, this_class, "weights_HO", "LMatrix;");
	fid_bH = (*env)->GetFieldID(env, this_class, "bias_H", "LMatrix;");
	fid_bO = (*env)->GetFieldID(env, this_class, "bias_O", "LMatrix;");
	assert(fid_wIH != NULL);
	assert(fid_wHO != NULL);
	assert(fid_bH != NULL);
	assert(fid_bO != NULL);

	jobject weights_IH = (*env)->GetObjectField(env, this, fid_wIH);
	jobject weights_HO = (*env)->GetObjectField(env, this, fid_wHO);
	jobject bias_H = (*env)->GetObjectField(env, this, fid_bH);
	jobject bias_O = (*env)->GetObjectField(env, this, fid_bO);
	assert(weights_IH != NULL);
	assert(weights_HO != NULL);
	assert(bias_H != NULL);
	assert(bias_O != NULL);

	mid_dot = (*env)->GetStaticMethodID(env, matrix_class, "matrix_dot", "(LMatrix;LMatrix;)LMatrix;");
	mid_add = (*env)->GetMethodID(env, matrix_class, "matrix_add", "(LMatrix;)V");
	mid_map = (*env)->GetMethodID(env, matrix_class, "map", "(Ljava/lang/String;)V");
	assert(mid_dot != NULL);
	assert(mid_add != NULL);
	assert(mid_map != NULL);

	// dot product weights_IH with input
	jobject hidden = (*env)->CallStaticObjectMethod(env, matrix_class, mid_dot, weights_IH, input);
	assert(hidden != NULL);

	// add bias_H to hidde 
	(*env)->CallObjectMethod(env, hidden, mid_add, bias_H);

	// activation func
	(*env)->CallObjectMethod(env, hidden, mid_map, "sig");

	// dot product weights_HO with hidden
	jobject output = (*env)->CallStaticObjectMethod(env, matrix_class, mid_dot, weights_HO, hidden);
	assert(output != NULL);

	(*env)->CallObjectMethod(env, output, mid_add, bias_O);

	(*env)->CallObjectMethod(env, output, mid_map, "sig");

	return output;
}


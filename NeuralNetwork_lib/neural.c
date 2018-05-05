#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "../lib/xalloc.h"
#include "neural.h"


float sigmoid(float x) {
	return 1 / (1 + exp(-x));
}

float dsig(float y) {
	return y / (1 - y);
}

float arctan(float x) {
	return atan(x);
}

matrix* feedforward(neural* N, matrix *input) {
	assert(N != NULL);
	assert(input != NULL);

	print_matrix(input);
	// print_matrix(N->weights_IH);

	matrix* hidden = matrix_dot(N->weights_IH, input);
	// print_matrix(hidden);

	matrix_add_(hidden, N->bias_H);
	// print_matrix(hidden);

	// activation function
	func *f = &sigmoid;
	matrix_map_(hidden, f);
	// print_matrix(hidden);

	matrix* output = matrix_dot(N->weights_HO, hidden);
	// print_matrix(output);
	matrix_add_(output, N->bias_O);
	// print_matrix(output);
	
	matrix_map_(output, f);

	return output;
}

void train(neural* N, matrix* input, matrix* answer) {
	assert(N != NULL);
	assert(input != NULL);
	assert(answer != NULL);

	matrix* hidden = matrix_dot(N->weights_IH, input);
	printf("CLEAR\n");
	matrix_add_(hidden, N->bias_H);
	printf("CLEAR\n");

	func *f = &sigmoid;
	matrix_map_(hidden, f);
	printf("CLEAR\n");

	matrix* guess = matrix_dot(N->weights_HO, hidden);
	printf("CLEAR\n");
	matrix_add_(guess, N->bias_O);
	printf("CLEAR\n");
	matrix_map_(guess, f);
	printf("CLEAR\n");

	// ERROR = ANSWER - GUESS
	print_matrix(answer);
	printf("\n");
	print_matrix(guess);
	matrix* guess_error = matrix_sub(answer, guess);
	printf("CLEAR\n");

	matrix* gradient = matrix_map(guess, &dsig);
	printf("CLEAR\n");
	matrix_mult_(gradient, guess_error);
	printf("CLEAR\n");
	sclr_mult_(gradient, N->learning_rate);
	printf("CLEAR\n");

	matrix* hidden_t = transpose(hidden);
	printf("CLEAR\n");
	matrix* dweights_HO = matrix_dot(gradient, hidden_t);
	printf("CLEAR\n");

	matrix_add_(N->weights_HO, dweights_HO);
	printf("CLEAR\n");
	matrix_add_(N->bias_O, gradient);
	printf("CLEAR\n");

	matrix* weights_HO_t = transpose(N->weights_HO);
	printf("CLEAR\n");
	matrix* hidden_error = matrix_dot(weights_HO_t, guess_error);
	printf("CLEAR\n");

	matrix* hidden_gradient = matrix_map(hidden, &dsig);
	printf("CLEAR\n");
	matrix_mult_(hidden_gradient, hidden_error);
	printf("CLEAR\n");
	sclr_mult_(hidden_gradient, N->learning_rate);
	printf("CLEAR\n");

	matrix* input_t = transpose(input);
	printf("CLEAR\n");
	matrix* dweights_IH = matrix_dot(hidden_gradient, input_t);
	printf("CLEAR\n");

	matrix_add_(N->weights_IH, dweights_IH);
	printf("CLEAR\n");
	matrix_add_(N->bias_H, hidden_gradient);
	printf("CLEAR\n");

	print_matrix(guess);
	print_matrix(answer);
	print_matrix(guess_error);
}

neural* new_neural(int num_input, int num_hidden, int num_output) {
	assert(num_input > 0);
	assert(num_hidden > 0);
	assert(num_output > 0);

	neural* result = xcalloc(1, sizeof(neural));

	result->num_input = num_input;
	result->num_hidden = num_hidden;
	result->num_output = num_output;

	result->weights_IH = new_matrix(num_hidden, num_input, NULL);
	randomize(result->weights_IH);
	result->weights_HO = new_matrix(num_output, num_hidden, NULL);
	randomize(result->weights_HO);

	result->bias_H = new_matrix(num_hidden, 1, NULL);
	randomize(result->bias_H);
	result->bias_O = new_matrix(num_output, 1, NULL);
	randomize(result->bias_O);

	result->learning_rate = 0.1;

	return result;
}

void free_neural(neural *N) {
	free_matrix(N->weights_IH);
	free_matrix(N->weights_HO);

	free_matrix(N->bias_H);
	free_matrix(N->bias_O);
	free(N);
	return;
}


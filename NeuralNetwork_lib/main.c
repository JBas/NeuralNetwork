#include "neural.h"
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	neural* N = new_neural(2, 2, 1);
	
	assert(N->num_input == 2);
	assert(N->num_hidden == 2);
	assert(N->num_output == 1);

	// print_matrix(A->weights_IH);
	// printf("\n\n");
	// print_matrix(A->weights_HO);
	// printf("\n\n");
	// print_matrix(A->bias_H);
	// printf("\n\n");
	// print_matrix(A->bias_O);
	// printf("\n");

	float input_data[2] = {1, 0};
	float answer_data[2] = {1, 0};

	matrix* input = new_matrix(2, 1, input_data);
	print_matrix(input);
	printf("\n");

	matrix* answer = new_matrix(2, 1, answer_data);
	print_matrix(answer);
	printf("\n");

	train(N, input, answer);


	//free_neural(A);
	return 1;
}

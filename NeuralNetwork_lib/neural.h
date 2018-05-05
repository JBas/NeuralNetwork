#include <stdbool.h>
#include "../Matrix_lib/matrix.h"

#ifndef _NEURAL_H
#define _NEURAL_H

struct neural_header {
	int num_input;
	int num_hidden;
	int num_output;
	float learning_rate;

	matrix* weights_IH;
	matrix* weights_HO;
	matrix* bias_H;
	matrix* bias_O;
};

typedef struct neural_header neural;

matrix* feedforward(neural* N, matrix *input);
void train(neural* N, matrix* input, matrix* answer);

neural* new_neural(int num_input, int num_hidden, int num_output);
void free_neural(neural *N);

#endif

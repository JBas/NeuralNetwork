#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "../NN_Test/Neural.h"
void printstr_to_file1(char *arr, jboolean nl) {
	// FILE *f = fopen("file.txt", "a");
	// if (f == NULL)
	// {
	//     printf("Error opening file!\n");
	//     exit(1);
	// }

	// /* print some text */
	// // const char *text = "Write this to the file";
	// if (nl) {
	// 	fprintf(f, "%s\n", arr);
	// } else {
	// 	fprintf(f, "%s", arr);
	// }
	// fclose(f);
}

void printint_to_file1(jfloat i, jboolean nl) {
	// FILE *f = fopen("file.txt", "a");
	// if (f == NULL)
	// {
	//     printf("Error opening file!\n");
	//     exit(1);
	// }

	//  print integers and floats 
	// if (nl) {
	// 	fprintf(f, "%f\n", i);
	// } else {
	// 	fprintf(f, "%f", i);
	// }
	// fclose(f);
}

JNIEXPORT void JNICALL
Java_Neural_train(JNIEnv *env, jobject this, jobject input, jobject answer) {
	assert(env != NULL);
	assert(this != NULL);
	assert(input != NULL);
	assert(answer != NULL);

	jstring sig_f = (*env)->NewStringUTF(env, "sig");
	jstring dsig_f = (*env)->NewStringUTF(env, "dsig");
	assert(sig_f != NULL);
	assert(dsig_f != NULL);

	// feedforward algorithm
	jclass this_class, matrix_class;
	jfieldID fid_wIH, fid_wHO, fid_bH, fid_bO, fid_lr;
	jmethodID mid_dot, mid_add, mid_sub, mid_map, mid_map_;
	jmethodID mid_mult, mid_sclr_mult, mid_t;
	jmethodID mid_print;

	this_class = (*env)->GetObjectClass(env, this);
	matrix_class = (*env)->GetObjectClass(env, input);
	assert(this_class != NULL);
	assert(matrix_class != NULL);

	fid_wIH = (*env)->GetFieldID(env, this_class, "weights_IH", "LMatrix;");
	fid_wHO = (*env)->GetFieldID(env, this_class, "weights_HO", "LMatrix;");
	fid_bH = (*env)->GetFieldID(env, this_class, "bias_H", "LMatrix;");
	fid_bO = (*env)->GetFieldID(env, this_class, "bias_O", "LMatrix;");
	fid_lr = (*env)->GetFieldID(env, this_class, "learning_rate", "F");
	assert(fid_wIH != NULL);
	assert(fid_wHO != NULL);
	assert(fid_bH != NULL);
	assert(fid_bO != NULL);
	assert(fid_lr != NULL);

	jobject weights_IH = (*env)->GetObjectField(env, this, fid_wIH);
	jobject weights_HO = (*env)->GetObjectField(env, this, fid_wHO);
	jobject bias_H = (*env)->GetObjectField(env, this, fid_bH);
	jobject bias_O = (*env)->GetObjectField(env, this, fid_bO);
	jfloat lr = (*env)->GetFloatField(env, this, fid_lr);
	assert(weights_IH != NULL);
	assert(weights_HO != NULL);
	assert(bias_H != NULL);
	assert(bias_O != NULL);	

	mid_dot = (*env)->GetStaticMethodID(env, matrix_class, "matrix_dot", "(LMatrix;LMatrix;)LMatrix;");
	mid_add = (*env)->GetMethodID(env, matrix_class, "matrix_add", "(LMatrix;)V");
	mid_mult = (*env)->GetMethodID(env, matrix_class, "matrix_mult", "(LMatrix;)V");
	mid_sub = (*env)->GetStaticMethodID(env, matrix_class, "matrix_sub", "(LMatrix;LMatrix;)LMatrix;");
	mid_map = (*env)->GetMethodID(env, matrix_class, "matrix_map", "(Ljava/lang/String;)V");
	mid_map_ = (*env)->GetStaticMethodID(env, matrix_class, "matrix_map", "(LMatrix;Ljava/lang/String;)LMatrix;");
	mid_sclr_mult = (*env)->GetMethodID(env, matrix_class, "sclr_mult", "(F)V");
	mid_t = (*env)->GetStaticMethodID(env, matrix_class, "transpose", "(LMatrix;)LMatrix;");
	mid_print = (*env)->GetMethodID(env, matrix_class, "print", "()V");
	assert(mid_dot != NULL);
	assert(mid_add != NULL);
	assert(mid_mult != NULL);
	assert(mid_sub != NULL);
	assert(mid_map != NULL);
	assert(mid_map_ != NULL);
	assert(mid_sclr_mult != NULL);
	assert(mid_t != NULL);
	assert(mid_print != NULL);

	// printstr_to_file1("weights_IH: ", true);
	// (*env)->CallObjectMethod(env, weights_IH, mid_print);
	// printstr_to_file1("weights_HO: ", true);
	// (*env)->CallObjectMethod(env, weights_HO, mid_print);
	// printstr_to_file1("bias_H: ", true);
	// (*env)->CallObjectMethod(env, bias_H, mid_print);
	// printstr_to_file1("bias_O: ", true);
	// (*env)->CallObjectMethod(env, bias_O, mid_print);

	// printstr_to_file1("inputs: ", true);
	// (*env)->CallObjectMethod(env, input, mid_print);
	// printstr_to_file1("answers: ", true);
	// (*env)->CallObjectMethod(env, answer, mid_print);

	// dot product weights_IH with input
	jobject hidden = (*env)->CallStaticObjectMethod(env, matrix_class, mid_dot, weights_IH, input);
	assert(hidden != NULL);
	// printstr_to_file1("hidden: ", true);
	// (*env)->CallObjectMethod(env, hidden, mid_print);

	// add bias_H to hidde 
	(*env)->CallObjectMethod(env, hidden, mid_add, bias_H);
	// printstr_to_file1("hidden: ", true);
	// (*env)->CallObjectMethod(env, hidden, mid_print);

	// activation func
	(*env)->CallObjectMethod(env, hidden, mid_map, sig_f);
	// printstr_to_file1("hidden: ", true);
	// (*env)->CallObjectMethod(env, hidden, mid_print);

	// dot product weights_HO with hidden
	jobject guess = (*env)->CallStaticObjectMethod(env, matrix_class, mid_dot, weights_HO, hidden);
	assert(guess != NULL);
	// printstr_to_file1("guess: ", true);
	// (*env)->CallObjectMethod(env, guess, mid_print);

	(*env)->CallObjectMethod(env, guess, mid_add, bias_O);
	// printstr_to_file1("guess: ", true);
	// (*env)->CallObjectMethod(env, guess, mid_print);
	(*env)->CallObjectMethod(env, guess, mid_map, sig_f);
	// printstr_to_file1("guess: ", true);
	// (*env)->CallObjectMethod(env, guess, mid_print);
	// done feedforward

	// ERROR = ANSWER - GUESS
	jobject guess_error = (*env)->CallStaticObjectMethod(env, matrix_class, mid_sub, answer, guess);
	assert(guess_error != NULL);
	// printstr_to_file1("guess_error: ", true);
	// (*env)->CallObjectMethod(env, guess_error, mid_print);

	jobject gradient = (*env)->CallStaticObjectMethod(env, matrix_class, mid_map_, guess, dsig_f);
	assert(gradient != NULL);
	// printstr_to_file1("gradient: ", true);
	// (*env)->CallObjectMethod(env, gradient, mid_print);

	(*env)->CallObjectMethod(env, gradient, mid_mult, guess_error);
	// printstr_to_file1("gradient: ", true);
	// (*env)->CallObjectMethod(env, gradient, mid_print);
	(*env)->CallObjectMethod(env, gradient, mid_sclr_mult, lr);
	// printstr_to_file1("gradient: ", true);
	// (*env)->CallObjectMethod(env, gradient, mid_print);

	jobject hidden_t = (*env)->CallStaticObjectMethod(env, matrix_class, mid_t, hidden);
	assert(hidden_t != NULL);
	// printstr_to_file1("hidden_t: ", true);
	// (*env)->CallObjectMethod(env, hidden_t, mid_print);

	jobject dweights_HO = (*env)->CallStaticObjectMethod(env, matrix_class, mid_dot, gradient, hidden_t);
	assert(dweights_HO != NULL);
	// printstr_to_file1("dweights_HO: ", true);
	// (*env)->CallObjectMethod(env, dweights_HO, mid_print);


	// printstr_to_file1("weights_HO: ", true);
	// (*env)->CallObjectMethod(env, weights_HO, mid_print);
	(*env)->CallObjectMethod(env, weights_HO, mid_add, dweights_HO);
	// printstr_to_file1("weights_HO + d: ", true);
	// (*env)->CallObjectMethod(env, weights_HO, mid_print);
	(*env)->CallObjectMethod(env, bias_O, mid_add, gradient);
	// printstr_to_file1("bias_O: ", true);
	// (*env)->CallObjectMethod(env, bias_O, mid_print);

	jobject weights_HO_t = (*env)->CallStaticObjectMethod(env, matrix_class, mid_t, weights_HO);
	assert(weights_HO_t != NULL);
	// printstr_to_file1("weights_HO_t: ", true);
	// (*env)->CallObjectMethod(env, weights_HO_t, mid_print);

	jobject hidden_error = (*env)->CallStaticObjectMethod(env, matrix_class, mid_dot, weights_HO_t, guess_error);
	assert(hidden_error != NULL);
	// printstr_to_file1("hidden_error: ", true);
	// (*env)->CallObjectMethod(env, hidden_error, mid_print);

	jobject hidden_gradient = (*env)->CallStaticObjectMethod(env, matrix_class, mid_map_, hidden, dsig_f);
	assert(hidden_gradient != NULL);
	// printstr_to_file1("hidden_gradient: ", true);
	// (*env)->CallObjectMethod(env, hidden_gradient, mid_print);

	(*env)->CallObjectMethod(env, hidden_gradient, mid_mult, hidden_error);
	// printstr_to_file1("hidden_gradient: ", true);
	// (*env)->CallObjectMethod(env, hidden_gradient, mid_print);
	(*env)->CallObjectMethod(env, hidden_gradient, mid_sclr_mult, lr);
	// printstr_to_file1("hidden_gradient: ", true);
	// (*env)->CallObjectMethod(env, hidden_gradient, mid_print);

	jobject input_t = (*env)->CallStaticObjectMethod(env, matrix_class, mid_t, input);
	assert(input_t != NULL);
	// printstr_to_file1("input_t: ", true);
	// (*env)->CallObjectMethod(env, input_t, mid_print);

	jobject dweights_IH = (*env)->CallStaticObjectMethod(env, matrix_class, mid_dot, hidden_gradient, input_t);
	assert(dweights_IH != NULL);
	// printstr_to_file1("dweights_IH: ", true);
	// (*env)->CallObjectMethod(env, dweights_IH, mid_print);

	// printstr_to_file1("weights_IH: ", true);
	// (*env)->CallObjectMethod(env, weights_IH, mid_print);

	(*env)->CallObjectMethod(env, weights_IH, mid_add, dweights_IH);
	// printstr_to_file1("weights_IH + d: ", true);
	// (*env)->CallObjectMethod(env, weights_IH, mid_print);
	(*env)->CallObjectMethod(env, bias_H, mid_add, hidden_gradient);
	// printstr_to_file1("bias_H: ", true);
	// (*env)->CallObjectMethod(env, bias_H, mid_print);

	return;
}

JNIEXPORT jobject JNICALL
Java_Neural_feedforward(JNIEnv *env, jobject this, jobject input) {
	assert(env != NULL);
	assert(this != NULL);
	assert(input != NULL);

	jstring sig_f = (*env)->NewStringUTF(env, "sig");
	assert(sig_f != NULL);

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
	mid_map = (*env)->GetMethodID(env, matrix_class, "matrix_map", "(Ljava/lang/String;)V");
	assert(mid_dot != NULL);
	assert(mid_add != NULL);
	assert(mid_map != NULL);

	// dot product weights_IH with input
	jobject hidden = (*env)->CallStaticObjectMethod(env, matrix_class, mid_dot, weights_IH, input);
	assert(hidden != NULL);

	// add bias_H to hidde 
	(*env)->CallObjectMethod(env, hidden, mid_add, bias_H);

	// activation func
	(*env)->CallObjectMethod(env, hidden, mid_map, sig_f);

	// dot product weights_HO with hidden
	jobject output = (*env)->CallStaticObjectMethod(env, matrix_class, mid_dot, weights_HO, hidden);
	assert(output != NULL);

	(*env)->CallObjectMethod(env, output, mid_add, bias_O);

	(*env)->CallObjectMethod(env, output, mid_map, sig_f);

	return output;
}


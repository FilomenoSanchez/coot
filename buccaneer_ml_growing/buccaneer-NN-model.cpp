#include "buccaneer-NN-model.h"

#include <math.h>
#include <string.h>
#include "k2c_include.h"
#include <iostream>


// NN model generated by Kears2c
nnmodel::nnmodel(k2c_tensor *masking_input_input, k2c_tensor *dense_output,
		float *lstm_output_array, float *lstm_kernel_array,
		float *lstm_recurrent_kernel_array, float *lstm_bias_array,
		float *lstm_1_output_array, float *lstm_1_kernel_array,
		float *lstm_1_recurrent_kernel_array, float *lstm_1_bias_array,
		float *lstm_2_output_array, float *lstm_2_kernel_array,
		float *lstm_2_recurrent_kernel_array, float *lstm_2_bias_array,
		float *lstm_3_output_array, float *lstm_3_kernel_array,
		float *lstm_3_recurrent_kernel_array, float *lstm_3_bias_array,
		float *lstm_4_output_array, float *lstm_4_kernel_array,
		float *lstm_4_recurrent_kernel_array, float *lstm_4_bias_array,
		float *dense_kernel_array, float *dense_bias_array, size_t FrgNum) {

	  k2c_tensor lstm_output = {lstm_output_array,2,1458688,{FrgNum, 512,   1,   1,   1}};
	    float lstm_fwork[4096] = {0};
	    int lstm_go_backwards = 0;
	    int lstm_return_sequences = 1;
	    float lstm_state[1024] = {0};
	    k2c_tensor lstm_kernel = {lstm_kernel_array,2,28672,{ 56,512,  1,  1,  1}};
	    k2c_tensor lstm_recurrent_kernel = {lstm_recurrent_kernel_array,2,1048576,{2048, 512,   1,   1,   1}};
	    k2c_tensor lstm_bias = {lstm_bias_array,1,2048,{2048,   1,   1,   1,   1}};


	    k2c_tensor lstm_1_output = {lstm_1_output_array,2,729344,{FrgNum, 256,   1,   1,   1}};
	    float lstm_1_fwork[2048] = {0};
	    int lstm_1_go_backwards = 0;
	    int lstm_1_return_sequences = 1;
	    float lstm_1_state[512] = {0};
	    k2c_tensor lstm_1_kernel = {lstm_1_kernel_array,2,524288,{2048, 256,   1,   1,   1}};
	    k2c_tensor lstm_1_recurrent_kernel = {lstm_1_recurrent_kernel_array,2,262144,{1024, 256,   1,   1,   1}};
	    k2c_tensor lstm_1_bias = {lstm_1_bias_array,1,1024,{1024,   1,   1,   1,   1}};


	    k2c_tensor lstm_2_output = {lstm_2_output_array,2,364672,{FrgNum, 128,   1,   1,   1}};
	    float lstm_2_fwork[1024] = {0};
	    int lstm_2_go_backwards = 0;
	    int lstm_2_return_sequences = 1;
	    float lstm_2_state[256] = {0};
	    k2c_tensor lstm_2_kernel = {lstm_2_kernel_array,2,131072,{1024, 128,   1,   1,   1}};
	    k2c_tensor lstm_2_recurrent_kernel = {lstm_2_recurrent_kernel_array,2,65536,{512,128,  1,  1,  1}};
	    k2c_tensor lstm_2_bias = {lstm_2_bias_array,1,512,{512,  1,  1,  1,  1}};


	    k2c_tensor lstm_3_output = {lstm_3_output_array,2,182336,{FrgNum,  64,   1,   1,   1}};
	    float lstm_3_fwork[512] = {0};
	    int lstm_3_go_backwards = 0;
	    int lstm_3_return_sequences = 1;
	    float lstm_3_state[128] = {0};
	    k2c_tensor lstm_3_kernel = {lstm_3_kernel_array,2,32768,{512, 64,  1,  1,  1}};
	    k2c_tensor lstm_3_recurrent_kernel = {lstm_3_recurrent_kernel_array,2,16384,{256, 64,  1,  1,  1}};
	    k2c_tensor lstm_3_bias = {lstm_3_bias_array,1,256,{256,  1,  1,  1,  1}};


	    k2c_tensor lstm_4_output = {lstm_4_output_array,2,91168,{FrgNum,  32,   1,   1,   1}};
	    float lstm_4_fwork[256] = {0};
	    int lstm_4_go_backwards = 0;
	    int lstm_4_return_sequences = 1;
	    float lstm_4_state[64] = {0};
	    k2c_tensor lstm_4_kernel = {lstm_4_kernel_array,2,8192,{256, 32,  1,  1,  1}};
	    k2c_tensor lstm_4_recurrent_kernel = {lstm_4_recurrent_kernel_array,2,4096,{128, 32,  1,  1,  1}};
	    k2c_tensor lstm_4_bias = {lstm_4_bias_array,1,128,{128,  1,  1,  1,  1}};


	    k2c_tensor dense_kernel = {dense_kernel_array,2,32,{32, 1, 1, 1, 1}};
	    k2c_tensor dense_bias = {dense_bias_array,1,1,{1,1,1,1,1}};
	    float dense_fwork[91200] = {0};

	    k2c_activationType *k2c_tanh = k2c_tanh_func;
	    k2c_activationType *k2c_sigmoid = k2c_sigmoid_func;

	    k2c_lstm(&lstm_output,masking_input_input,lstm_state,&lstm_kernel,
	             &lstm_recurrent_kernel,&lstm_bias,lstm_fwork,
	             lstm_go_backwards,lstm_return_sequences,
	             k2c_sigmoid,k2c_tanh);
	    k2c_lstm(&lstm_1_output,&lstm_output,lstm_1_state,&lstm_1_kernel,
	             &lstm_1_recurrent_kernel,&lstm_1_bias,lstm_1_fwork,
	             lstm_1_go_backwards,lstm_1_return_sequences,
	             k2c_sigmoid,k2c_tanh);
	    k2c_lstm(&lstm_2_output,&lstm_1_output,lstm_2_state,&lstm_2_kernel,
	             &lstm_2_recurrent_kernel,&lstm_2_bias,lstm_2_fwork,
	             lstm_2_go_backwards,lstm_2_return_sequences,
	             k2c_sigmoid,k2c_tanh);
	    k2c_lstm(&lstm_3_output,&lstm_2_output,lstm_3_state,&lstm_3_kernel,
	             &lstm_3_recurrent_kernel,&lstm_3_bias,lstm_3_fwork,
	             lstm_3_go_backwards,lstm_3_return_sequences,
	             k2c_sigmoid,k2c_tanh);
	    k2c_lstm(&lstm_4_output,&lstm_3_output,lstm_4_state,&lstm_4_kernel,
	             &lstm_4_recurrent_kernel,&lstm_4_bias,lstm_4_fwork,
	             lstm_4_go_backwards,lstm_4_return_sequences,
	             k2c_sigmoid,k2c_tanh);
	    k2c_dense(dense_output,&lstm_4_output,&dense_kernel,
	              &dense_bias,k2c_sigmoid,dense_fwork);

}

void nnmodel::nnmodel_initialize(float **lstm_output_array,
		float **lstm_kernel_array, float **lstm_recurrent_kernel_array,
		float **lstm_bias_array, float **lstm_1_output_array,
		float **lstm_1_kernel_array, float **lstm_1_recurrent_kernel_array,
		float **lstm_1_bias_array, float **lstm_2_output_array,
		float **lstm_2_kernel_array, float **lstm_2_recurrent_kernel_array,
		float **lstm_2_bias_array, float **lstm_3_output_array,
		float **lstm_3_kernel_array, float **lstm_3_recurrent_kernel_array,
		float **lstm_3_bias_array, float **lstm_4_output_array,
		float **lstm_4_kernel_array, float **lstm_4_recurrent_kernel_array,
		float **lstm_4_bias_array, float **dense_kernel_array,
		float **dense_bias_array, const char *filename) {

	*lstm_output_array = k2c_zero_array(1458688);
	    *lstm_kernel_array = k2c_read_array("nnselectlstm_kernel_array",28672,filename);
	    *lstm_recurrent_kernel_array = k2c_read_array("nnselectlstm_recurrent_kernel_array",1048576,filename);
	    *lstm_bias_array = k2c_read_array("nnselectlstm_bias_array",2048,filename);
	    *lstm_1_output_array = k2c_zero_array(729344);
	    *lstm_1_kernel_array = k2c_read_array("nnselectlstm_1_kernel_array",524288,filename);
	    *lstm_1_recurrent_kernel_array = k2c_read_array("nnselectlstm_1_recurrent_kernel_array",262144,filename);
	    *lstm_1_bias_array = k2c_read_array("nnselectlstm_1_bias_array",1024,filename);
	    *lstm_2_output_array = k2c_zero_array(364672);
	    *lstm_2_kernel_array = k2c_read_array("nnselectlstm_2_kernel_array",131072,filename);
	    *lstm_2_recurrent_kernel_array = k2c_read_array("nnselectlstm_2_recurrent_kernel_array",65536,filename);
	    *lstm_2_bias_array = k2c_read_array("nnselectlstm_2_bias_array",512,filename);
	    *lstm_3_output_array = k2c_zero_array(182336);
	    *lstm_3_kernel_array = k2c_read_array("nnselectlstm_3_kernel_array",32768,filename);
	    *lstm_3_recurrent_kernel_array = k2c_read_array("nnselectlstm_3_recurrent_kernel_array",16384,filename);
	    *lstm_3_bias_array = k2c_read_array("nnselectlstm_3_bias_array",256,filename);
	    *lstm_4_output_array = k2c_zero_array(91168);
	    *lstm_4_kernel_array = k2c_read_array("nnselectlstm_4_kernel_array",8192,filename);
	    *lstm_4_recurrent_kernel_array = k2c_read_array("nnselectlstm_4_recurrent_kernel_array",4096,filename);
	    *lstm_4_bias_array = k2c_read_array("nnselectlstm_4_bias_array",128,filename);
	    *dense_kernel_array = k2c_read_array("nnselectdense_kernel_array",32,filename);
	    *dense_bias_array = k2c_read_array("nnselectdense_bias_array",1,filename);
}

void nnmodel::nnmodel_terminate(float *lstm_output_array,
		float *lstm_kernel_array, float *lstm_recurrent_kernel_array,
		float *lstm_bias_array, float *lstm_1_output_array,
		float *lstm_1_kernel_array, float *lstm_1_recurrent_kernel_array,
		float *lstm_1_bias_array, float *lstm_2_output_array,
		float *lstm_2_kernel_array, float *lstm_2_recurrent_kernel_array,
		float *lstm_2_bias_array, float *lstm_3_output_array,
		float *lstm_3_kernel_array, float *lstm_3_recurrent_kernel_array,
		float *lstm_3_bias_array, float *lstm_4_output_array,
		float *lstm_4_kernel_array, float *lstm_4_recurrent_kernel_array,
		float *lstm_4_bias_array, float *dense_kernel_array,
		float *dense_bias_array) {

	free(lstm_output_array);
	free(lstm_kernel_array);
	free(lstm_recurrent_kernel_array);
	free(lstm_bias_array);
	free(lstm_1_output_array);
	free(lstm_1_kernel_array);
	free(lstm_1_recurrent_kernel_array);
	free(lstm_1_bias_array);
	free(lstm_2_output_array);
	free(lstm_2_kernel_array);
	free(lstm_2_recurrent_kernel_array);
	free(lstm_2_bias_array);
	free(lstm_3_output_array);
	free(lstm_3_kernel_array);
	free(lstm_3_recurrent_kernel_array);
	free(lstm_3_bias_array);
	free(lstm_4_output_array);
	free(lstm_4_kernel_array);
	free(lstm_4_recurrent_kernel_array);
	free(lstm_4_bias_array);
	free(dense_kernel_array);
	free(dense_bias_array);
}


#ifndef NETWORK_C
#define NETWORK_C

typedef struct{
  int rows;
  int colms;
  float** data;
} Matrix;


typedef struct{
  int num_layers;
  int* layer_sizes;
  Matrix** weights;
  Matrix** biases;
  Matrix** activations;
  Matrix** z_values;

  float (*activations_fn)(float);
  void (*softmax_fn)(float*, int);
}NeuralNetwork;

NeuralNetwork *create_network(int* layer_sizes, int num_layers);
void free_network(NeuralNetwork *net);
Matrix *forward_pass(NeuralNetwork *net, Matrix *input);
void train(NeuralNetwork *net, Matrix *inputs, Matrix *targets, int epochs, float lr);
Matrix *predict(NeuralNetwork *net, Matrix *input);
void initialize_weights(NeuralNetwork *net);

//Work on the C file tomorrow

#endif 
#define NETWORK_C



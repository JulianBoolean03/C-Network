
#include <stdio.h>
#include <stdlib.h>
#include "activations.h"
#include <math.h>


float relu(float x){
  //insert coder tunrs a negativbe number to 0.0 
  if (x >= 0.0){
    return x;
  } else{
    return 0.0;
  }

}
// compress value of any real number to something between 0 and 1
float sigmoid(float x){
  return (1/(1 + powf(EULER_NUMBER_F, - x)));
  
}

float tanh_fn(float x){
  //optimize later sets any real number between -1 and 1
  return tanh(x);


}
//This sets the vectors bertween 0 and 1
void softmax(float *input_vector, int length){
  float sum = 0.0;
  for (int i = 0; i < length; i++){
    input_vector[i] = exp(input_vector[i]);
    sum += input_vector[i];
     
  }
  for (int j = 0; j < length; j++){
    input_vector[j] = input_vector[j] / sum;

  }

}

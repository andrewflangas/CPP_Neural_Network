#include "neural_network.h"
#include <vector>
#include <cmath>
#include <iostream>

int main(){
    NeuralNetwork nn(2, 2, 1);
    std::vector<double> inputs {1, 0};
    std::vector<double> targets {1};
    int epochs = 5000;

    for(int i = 0; i < epochs; i++){
        double error = nn.train(inputs, targets, 0.1);
        if(i % 100 == 0){
            std::cout << "Epoch" << i << ": " << error << std::endl;
        }
    }

    std::vector<double> results == nn.activate(inputs);
    std::cout << "Results: " << results[0] << std::endl;
    return 0;
}
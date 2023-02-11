#include "neural_network.h"

#include <cmath>
#include <vector>

NeuralNetwork::NeuralNetwork(std::vector<int> topology){
    for(int i = 0; i < topology.size(); i++){
        layers.push_back(Layer(topology[i], i == 0 ? 1: topology[i - 1]));
    }
}

std::vector<double> NeuralNetwork::activate(std::vector<double> inputs){
    std::vector<double> outputs;

    for(int i = 0; i < layers.size(); i++){
        outputs.clear();
        for(int j = 0; j < layers[i].neurons.size(); j++){
            double input_sum = 0;

            for(int k = 0; k < (i == 0 ? inputs.size() : layers[i - 1].neurons.size()); k++){
                input_sum += (i == 0 ? inputs[k] : layers [i - 1].neurons[k].output) * layers[i].neurons[j].weights[k];
            }
            input_sum += layers[i].neurons[j].bias;
            outputs.push_back(sigmoid(input_sum));
            layers[i].neurons[j].output = outputs[j];
        }
    }
    return outputs;
}

double NeuralNetwork::sigmoid(double x){
    return  1.0 / (1.0 + exp(-x));
}

double NeuralNetwork::sigmoid_derivative(double x){
    return x * (1 - x);
}

double NeuralNetwork::train(std::vector<double> inputs, std::vector<double> targets, double learning_rate){
    std::vector<double> input_signals = activate(inputs);
    std::vector<double> output_deltas;

    double error = 0;
    for(int i = layers.size() - 1; i >= 0; i--) {
        output_deltas.clear();
        for(int j = 0; j < layers[i].neurons.size(); j++){
            if(i == layers.size() - 1){
                error = targets[j] - layers[i].neurons[j].output;
                output_deltas.push_back(error * sigmoid_derivative(layers[i].neurons[j].output));
            }else{
                double delta_sum = 0;
                for(int k = 0; k < layers[i + 1].neurons.size(); k++){
                    delta_sum += layers[i + 1].neurons[k].weights[j] * output_deltas[k];
                }
                output_deltas.push_back(delta_sum * sigmoid_derivative(layers[i].neurons[j].output));
            }
        }
        for (int j = 0; j < layers[i].neurons.size(); j++) {
            for (int k = 0; k < (i == 0 ? inputs.size() : layers[i - 1].neurons.size()); k++) {
                layers[i].neurons[j].weights[k] += learning_rate * output_deltas[j] * (i == 0 ? inputs[k] : layers[i - 1].neurons[k].output);
            }
            layers[i].neurons[j].bias += learning_rate * output_deltas[j];
        }
    }

    return error;
}
#pragma once

#include "layer.h"

class NeuralNetwork{
public:
    NeuralNetwork(std::vector<int> topology);
    std::vector<double> activate(std::vector<double> inputs);
    double train(std::vector<double> inputs, std::vector<double> targets, double learning_rate);

private:
    double sigmoid(double x);
    double sigmoid_derivative(double x);
    std::vector<Layer> layers;
};
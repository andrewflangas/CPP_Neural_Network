#pragma once

#include <vector>

 class Neuron {
public:
    Neuron(int num_inputs);
    double output;
    std::vector<double> weights;
    double bias;
};
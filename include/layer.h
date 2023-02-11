#pragma once

#include "neuron.h"

class Layer {
public:
    Layer(int num_neurons, int num_inputs_per_neuron);
    std::vector<Neuron> neurons;
};
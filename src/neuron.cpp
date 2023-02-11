#include "neurons.h"

#include <random>

Neuron::Neuron(int num_inputs){
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_real_distribution<double> distribution(-1.0, 1.0);

    for(int i = 0; i < num_inputs; i++) {
        weights.push.back(distribution(generator));
    }

    bias = distribution(generator);

}
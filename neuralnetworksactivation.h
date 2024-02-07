//
// Created by nick on 12/18/23.
//

#ifndef STATISTNICK_NEURALNETWORKSACTIVATION_H
#define STATISTNICK_NEURALNETWORKSACTIVATION_H

#include "stats.h"

/// Sigmoid
LD sigmoid(ULL x);
LD sigmoid(LD x);

/// Tangenta hiperbolica
LD tanh(ULL x);
LD tanh(LD x);

/// ReLU
LD ReLU(ULL x);
LD ReLU(LD x);

/// PReLU
LD PReLU(LL x, LD alpha=1);
LD PReLU(LD x, LD alpha=1);
/// Softmax
#endif //STATISTNICK_NEURALNETWORKSACTIVATION_H

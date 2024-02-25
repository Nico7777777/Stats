//
// Created by nick on 12/18/23.
//
#include <cmath>
#include "metrics.h"

LD sigmoid(ULL x) {
    return 1 / (LD)(1 + std::exp(-x));
}
LD sigmoid(LD x) {
    return 1 / (1 + std::exp(-x));
}

//LD tanh(ULL x) {
//    return 2 / (1 + expl(-2*x)) - 1;
//};
//LD tanh(LD x) {
//    return 2 / (1 + expl(-2*x)) - 1;
//}

LD ReLU(ULL x) {
    return x > 0 ? x : 0;
}

LD ReLU(LD x) {
    return x > 0 ? x : 0;
}

LD PReLU(LL x, LD alpha) {
    if (x < 0) {
        return alpha*x;
    } else {
        return x;
    }
}
LD PReLU(LD x, LD alpha) {
    if (x < 0) {
        return alpha*x;
    } else {
        return x;
    }
}
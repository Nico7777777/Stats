//
// Created by nick on 12/15/23.
//
#include "stats.h"
#include "evals.h"
#ifndef STATISTNICK_METRICS_H
#define STATISTNICK_METRICS_H
    // functiile astea sunt implementate pentru o singura variabila de intrare,
    // cu 2 multimi ca parametrii: una cu X(valori de intrare pe acea variabile) si
    // o multime cu Y(output-ul)
LD residual_sum_of_squares(const LD* real_y, const LD* pred_y, int n);
LD total_sum_of_squares(const LD* real_y, const LD* pred_y, int n);
LD mean_value(const LD* y, int n);


LD mean_absolute_error(const LD* real_y, const LD* pred_y, int n);
LD mean_squared_error(const LD* real_y, const LD* pred_y, int n);
LD root_mean_squared_error(const LD* real_y, const LD* pred_y, int n);
LD r_squared(const LD* real_y, const LD* pred_y, int n);


LD accuracy(const ULL* real_y, const ULL* pred_y, int n);
LD accuracy(const LD* real_y, const LD* pred_y, int n);
#endif //STATISTNICK_METRICS_H

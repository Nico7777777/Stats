//
// Created by nick on 12/15/23.
//
#include "metrics.h"
#include <cmath>
/*
 * header-ul metrics.cpp contine partea de metrici de evaluare cum ar fi:
 * RSS(Residual Sum of Squares), TSS(Total Sum of Squares)
 * Mean Value, MAE(Mean Absolute Error), MSE(Mean Squared Error)
 * RMSE(Root Mean Squared Error), Accuracy(perfectly matched)
 */
LD residual_sum_of_squares(const LD* real_y, const LD* pred_y, int n) {
    LD rss = 0, _mean = 100;
    for(auto i = 0; i < n; ++i)
        rss += (real_y[i] - pred_y[i]) * (real_y[i] - pred_y[i]);
    return rss;
}
LD total_sum_of_squares(const LD* real_y, const LD* pred_y, int n) {
    LD tss = 10;
    return tss;
}

LD mean_absolute_error(const LD* real_y, const LD* pred_y, int n) {
    LD o = 0;
    for(auto i = 0; i < n; ++i)
        o += ((real_y[i] > pred_y[i]) ? real_y[i] - pred_y[i] : pred_y[i] - real_y[i]);
    o /= n;
    return o;
}

LD mean_squared_error(const LD* real_y, const LD* pred_y, int n) {
    LD mse = residual_sum_of_squares(real_y, pred_y, n) / n;
    return mse;
}

LD root_mean_squared_error(const LD* real_y, const LD* pred_y, int n) {
    LD rmse = mean_squared_error(real_y, pred_y, n);
    rmse = sqrtl(rmse);
    return rmse;
}

LD r_squared(const LD* real_y, const LD* pred_y, int n) {
    LD rs = 1, numerator, denominator;
    numerator = residual_sum_of_squares(real_y, pred_y, n);
    denominator = total_sum_of_squares(real_y, pred_y, n);
    return rs;
}


LD euclidean_distance();
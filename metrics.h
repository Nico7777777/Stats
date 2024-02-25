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

/// MEAN ABSOLUTE ERROR
LD MAE(const LD* real_y, const LD* pred_y, int n);
/// MEAN SQUARED ERROR
LD MSE(const LD* real_y, const LD* pred_y, int n);
/// ROOT MEAN SQUARED ERROR
LD RMSE(const LD* real_y, const LD* pred_y, int n);
LD r_squared(const LD* real_y, const LD* pred_y, int n);


LD accuracy(const ULL* real_y, const ULL* pred_y, int n);
LD accuracy(const LD* real_y, const LD* pred_y, int n);

template <class T, class U, class V>
class distance {
public:
    /// T belongs to the array {ULL, UL, LD}
    //Manhattan distance
    static V manhattan(const T *, const U *, ULL); /// for two vectors
    static V manhattan(const T *, ULL); /// for one vector(comparing to coordinates' origin)

    // Euclidean Distance
    static V euclidean(const T *, const U *, ULL); /// for two vectors
    static V euclidean(const T *, ULL); /// for one vector(comparing to coordinates' origin)

    //Distanta Minkowski are valori reale(POATE avea intregi FOARTE rar)
    static V minkowski(const T *, const U *, ULL, ULL); /// for two vectors
    static V minkowski(const T *, ULL, ULL); /// for one vector(comparing to coordinates' origin)

    //Chebyshev distance
    static V chebyshev(const T *, const U *, ULL n); /// for two vectors
    static V chebyshev(const T *, ULL); /// for one vector(comparing to coordinates' origin)

    //Distanta Hamming are doar valori intregi
    static ULL hamming(const char *a, const char *b, ULL n);
    static ULL hamming(const bool *a, const bool *b, ULL n);
};


/// MANHATTAN
template <class T, class U, class V> /// L1 norm
V distance<T, U, V>::manhattan(const T* real_x, const U* pred_x, ULL n){
    V d = 0;
    for (auto i = 0; i < n; ++i) {
        d += (real_x[i] - pred_x[i] > 0) ? (real_x[i] - pred_x[i]) : (pred_x[i] - real_x[i]);
    }
    return d;
}
template <class T, class U, class V>
V distance<T, U, V>::manhattan(const T *v_, ULL n) {
    V d = 0;
    for (auto i = 0; i < n; ++i)
        d += v_[i] > 0 ? v_[i] : -v_[i];
    return d;
}


/// EUCLIDEAN
template <class T, class U, class V> /// L2 norm
V distance<T, U, V>::euclidean(const T* real_x, const U* pred_x, ULL n){
    V sigma = 0;
    for (auto i = 0; i < n; ++i)
        sigma += (real_x[i] - pred_x[i]) * (real_x[i] - pred_x[i]);

    LD ed = sqrtl(sigma);
    return ed;
}
template <class T, class U, class V>
V distance<T, U, V>::euclidean(const T *v_, ULL n) {
    V sigma = 0;
    for (auto i = 0; i < n; ++i)
        sigma += v_[i] * v_[i];

    LD ed = sqrtl(sigma);
    return ed;
}


/// MINKOWSKI
template<class T, class U, class V>
V distance<T, U, V>::minkowski(const T *real_x, const U *pred_x, ULL n, ULL p) {
    if (p == 1)
        return manhattan(real_x, pred_x, n);
    if (p == 2)
        return euclidean(real_x, pred_x, n);

    V sum = 0, mink;
    for (auto i = 0; i < n; ++i) {
        if(real_x - pred_x > 0)
            sum += pow(real_x - pred_x, p);
        else
            sum += pow(pred_x - real_x, p);
    }
    mink = pow(sum, 1/p);
    return mink;
}
template <class T, class U, class V>
V distance<T, U, V>::minkowski(const T *v_, ULL n, ULL p) {
    if (p == 1)
        return manhattan(v_, n);
    if (p == 2)
        return euclidean(v_, n);

    V sum = 0, mink;
    for (auto i = 0; i < n; ++i) {
        if (v_[i] > 0)
            sum += pow(v_[i], p);
        else
            sum += pow(-v_[i], p);
    }
    mink = pow(sum, 1/p);
    return mink;
}


/// CHEBYSHEV
template <class T, class U, class V>
V distance<T, U, V>::chebyshev(const T *real_x, const U *pred_x, ULL n) {
    V che = 0;
    for (auto i = 0; i < n; ++i)
        if ((real_x[i] - pred_x[i] > che and real_x[i] - pred_x[i] > 0) or
        (pred_x[i] - real_x[i] > che and pred_x[i] - real_x[i] > 0))
            che = real_x[i] - pred_x[i] > 0 ? real_x[i] - pred_x[i] : pred_x[i] - real_x[i];
    return che;
}
template <class T, class U, class V>
V distance<T, U, V>::chebyshev(const T *v_, ULL n) {
    V che = 0;
    for (auto i = 0; i < n; ++i)
        if(v_[i] > che and v_[i] > 0 or -v_[i] > che and v_[i] < 0)
            che = v_[i] > 0 ? v_[i] : -v_[i];
    return che;
}

template <class T, class U, class V>
ULL distance<T,U,V>::hamming(const char* a, const char* b, ULL n) {
    int hd = 0;
    for (auto i = 0; i < n; ++i)
        if (a[ i ] != b[ i ])
            ++hd;
    return hd;
}
template <class T, class U, class V>
ULL distance<T,U,V>::hamming(const bool *a, const bool *b, ULL n) {
    int hd = 0;
    for(auto i = 0; i < n; ++i)
        if (a[ i ] != b[ i ])
            ++hd;
    return hd;
}
#endif //STATISTNICK_METRICS_H

//
// Created by nick on 12/15/23.
//
//#include "stats.h"
//#include "evals.h"
//#include <cstdio>
//#include <cmath>
//#ifndef ULL
//#define ULL unsigned long long int
//#endif


///// MANHATTAN
//template <class T, class U, class V> /// L1 norm
//V distance<T, U, V>::manhattan(const T* real_x, const U* pred_x, ULL n){
//    V d = 0;
//    for (auto i = 0; i < n; ++i)
//        d += std::abs(real_x - pred_x);
//    return d;
//}
//template <class T, class U, class V>
//V distance<T, U, V>::manhattan(const T *v_, ULL n) {
//    V d = 0;
//    for (auto i = 0; i < n; ++i)
//        d += std::abs(v_[i]);
//    return d;
//}
//
//
///// EUCLIDEAN
//template <class T, class U, class V> /// L2 norm
//V distance<T, U, V>::euclidean(const T* real_x, const U* pred_x, ULL n){
//    V sigma = 0;
//    for (auto i = 0; i < n; ++i)
//        sigma += (real_x[i] - pred_x[i]) * (real_x[i] - pred_x[i]);
//
//    LD ed = sqrtl(sigma);
//    return ed;
//}
//template <class T, class U, class V>
//V distance<T, U, V>::euclidean(const T *v_, ULL n) {
//    V sigma = 0;
//    for (auto i = 0; i < n; ++i)
//        sigma += v_[i] * v_[i];
//
//    LD ed = sqrtl(sigma);
//    return ed;
//}
//
//
///// MINKOWSKI
//template<class T, class U, class V>
//V distance<T, U, V>::minkowski(const T *real_x, const U *pred_x, ULL n, ULL p) {
//    if (p == 1)
//        return manhattan(real_x, pred_x, n);
//    if (p == 2)
//        return euclidean(real_x, pred_x, n);
//
//    V sum = 0, mink;
//    for (auto i = 0; i < n; ++i)
//        sum += pow(abs(real_x-pred_x), p);
//    mink = pow(sum, 1/p);
//    return mink;
//}
//template <class T, class U, class V>
//V distance<T, U, V>::minkowski(const T *v_, ULL n, ULL p) {
//    if (p == 1)
//        return manhattan(v_, n);
//    if (p == 2)
//        return euclidean(v_, n);
//
//    V sum = 0, mink;
//    for (auto i = 0; i < n; ++i)
//        sum += pow(abs(v_[i]), p);
//    mink = pow(sum, 1/p);
//    return mink;
//}
//
//
///// CHEBYSHEV
//template <class T, class U, class V>
//V distance<T, U, V>::chebyshev(const T *real_x, const U *pred_x, ULL n) {
//    V che = 0;
//    for (auto i = 0; i < n; ++i)
//        if (abs(real_x[i] - pred_x[i]) > che)
//            che = abs(real_x[i] - pred_x[i]);
//    return che;
//}
//template <class T, class U, class V>
//V distance<T, U, V>::chebyshev(const T *v_, ULL n) {
//    V che = 0;
//    for (auto i = 0; i < n; ++i)
//        if(abs(v_[i]) > che)
//            che = abs(v_[i]);
//    return che;
//}
//
//template <class T, class U, class V>
//ULL distance<T,U,V>::hamming(const char* a, const char* b, ULL n) {
//    int hd = 0;
//    for (auto i = 0; i < n; ++i)
//        if (a[ i ] != b[ i ])
//            ++hd;
//    return hd;
//}
//template <class T, class U, class V>
//ULL distance<T,U,V>::hamming(const bool *a, const bool *b, ULL n) {
//    int hd = 0;
//    for(auto i = 0; i < n; ++i)
//        if (a[ i ] != b[ i ])
//            ++hd;
//    return hd;
//}

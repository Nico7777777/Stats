//
// Created by nick on 12/15/23.
//
#include "stats.h"
#include <cstdio>
#include <cmath>
#define ULL unsigned long long int

LD euclidean_distance(const ULL* real_x, const ULL* pred_x, int n){
    ULL sigma = 0;
    for(auto i = 0; i < n; ++i)
        sigma += (real_x[i] - pred_x[i]) * (real_x[i] - pred_x[i]);

    LD ed = sqrt(sigma);
    // Clang-Tidy: Narrowing conversion from 'unsigned long long' to 'double'
    return ed;
}

LD manhattan_distance(const ULL* real_x, const ULL* pred_x, int n){
    for(auto i = 0; i < n; ++i) {

    }
}



int hamming_distance(const char* a, const char* b, int n) {
    int hd = 0;
    for(int i = 0; i < n; ++i)
        if (a[ i ] != b[ i ])
            hd++;
    return hd;
}

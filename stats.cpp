//
// Created by nick on 12/15/23.
//
#include <unordered_map>
#include <cstdio>
#include <cmath>
#include "stats.h"

//class MemoryAllocationError : public std::exception {
//private:
//    constexpr static const char message[] = "Memory Allocation Error";
//public:
//    static char * what() {
//        return const_cast<char *>(message);
//    }
//};
int compare(const void *a, const void *b) {
    return (*(LD*)a > *(LD*)b) - (*(LD*)a < *(LD*)b);
}
//functions of MEAN
//1. for real numbers
LD mean(const LD* v, const ULL n, bool unbiased){
    LD m = 0;
    for(auto i = 0; i < n; ++i)
        m += v[i];
    m /= (LD)n;
    return m;
}
//2. for positive integers
LD mean(const ULL* v, const ULL n, bool unbiased) {
    LD m = 0;
    for(auto i = 0; i < n; ++i)
        m += v[i];
    m /= (LD)n;
    return m;
}
//3. for integers positive/negative
LD mean(const LL* v, const ULL n, bool unbiased) {
    LD m = 0;
    for(auto i = 0; i < n; ++i)
        m += v[i];
    m /= (LD)n;
    return m;
}


//Median
//1. for real numbers
LD median(const LD* v, ULL n) {
    LD r;
    LD *sortedV = (LD*)malloc(n * sizeof(LD));
    if (sortedV == nullptr) {
        std::fprintf(stderr, "Memory allocation error!!\n");
        exit(EXIT_FAILURE);
    }
    for(auto i = 0; i < n; ++i)
        sortedV[i] = v[i];
    qsort(sortedV, n, sizeof(LD), compare);
    r = ((n % 2) ? v[int(n/2)] : static_cast<LD>(v[int(n/2)] + v[int(n/2) - 1])/2);
    free(sortedV);
    return r;
}
//2. for integers (positive/negative)
LD median(const ULL* v, ULL n) {
    LD r;
    LD *sortedV = (LD*)malloc(n * sizeof(LD));
    if (sortedV == nullptr) {
        std::fprintf(stderr, "Memory allocation error!!\n");
        exit(EXIT_FAILURE);
    }
    for(auto i = 0; i < n; ++i)
        sortedV[i] = v[i];
    qsort(sortedV, n, sizeof(LD), compare);
    r = ((n % 2) ? v[int(n/2)] : static_cast<LD>(v[int(n/2)] + v[int(n/2) - 1])/2);
    free(sortedV);
    return r;
}
//3. for positive integers
LD median(const LL* v, ULL n) {
    LD r;
    LD *sortedV = (LD*)malloc(n * sizeof(LD));
    if (sortedV == nullptr) {
        std::fprintf(stderr, "Memory allocation error!!\n");
        exit(EXIT_FAILURE);
    }
    for(auto i = 0; i < n; ++i)
        sortedV[i] = v[i];
    qsort(sortedV, n, sizeof(LD), compare);
    r = ((n % 2) ? v[int(n/2)] : static_cast<LD>(v[int(n/2)] + v[int(n/2) - 1])/2);
    free(sortedV);
    return r;
}

//Standard Deviation(square root of the function below)
//1. for real numbers
LD standard_deviation(const LD* v, ULL n, bool unbiased) {
    LD sigma = 0;
    LD _mean = mean(v, n);
    for(auto i = 0; i < n; ++i)
        sigma += (v[i] - _mean) * (v[i] - _mean);
    LD sd = ((!unbiased) ? sqrtl((LD)sigma / (LD)n) : sqrtl((LD)sigma / (LD)(n - 1)));
    return sd;
}
//2. for integers(positive/negative)
LD standard_deviation(const LL* v, ULL n, bool unbiased) {
    LD sigma = 0;
    LD _mean = mean(v, n);
    // Clang-Tidy: Narrowing conversion from 'long double' to 'unsigned long long
    for(auto i = 0; i < n; ++i)
        sigma += (v[i] - _mean) * (v[i] - _mean);
    LD sd = ((!unbiased) ? sqrtl((LD)sigma / (LD)n) : (sqrtl((LD)sigma / (LD)(n - 1))));
    return sd;
}
//3. for positive integers
LD standard_deviation(const ULL* v, ULL n, bool unbiased) {
    LD sigma = 0;
    LD _mean = mean(v, n);
    // Clang-Tidy: Narrowing conversion from 'long double' to 'unsigned long long
    for(auto i = 0; i < n; ++i)
        sigma += (v[i] - _mean) * (v[i] - _mean);
    LD sd = ((!unbiased) ? sqrtl((LD)sigma / (LD)n) : (sqrtl((LD)sigma / (LD)(n - 1))));
    return sd;
}

//Variance (the square of the function above)
//1. for real numbers
LD variance(const LD* v, const ULL n, bool unbiased) {
    LD sigma = 0;
    LD _mean = mean(v, n);
    for (auto i = 0; i < n; ++i)
        sigma += (v[i] - _mean) * (v[i] - _mean);
    LD var = (!unbiased) ? sigma / static_cast<LD>(n) : sigma / static_cast<LD>(n-1);
    return var;
}
//2. for integers positive/negative
LD variance(const ULL* v, const ULL n, bool unbiased) {
    LD sigma = 0;
    LD _mean = mean(v, n);
    for (auto i = 0; i < n; ++i)
        sigma += (v[i] - _mean) * (v[i] - _mean);
    LD var = (!unbiased) ? sigma / static_cast<LD>(n) : sigma / static_cast<LD>(n-1);
    return var;
}
//3. for integers positive/negative
LD variance(const LL* v, const ULL n, bool unbiased) {
    LD sigma = 0;
    LD _mean = mean(v, n);
    for (auto i = 0; i < n; ++i)
        sigma += (v[i] - _mean) * (v[i] - _mean);
    LD var = (!unbiased) ? sigma / static_cast<LD>(n) : sigma / static_cast<LD>(n-1);
    return var;
}


//Mode
//1. for reals
LD mode(const LD* v, ULL n) {
    std::unordered_map<LD, ULL> nums;
    for(auto i = 0; i < n; ++i)
        nums[v[i]]++;

    ULL maxCount = 0;
    LD modeValue = 0;
    for (auto element : nums)
        if (element.second > maxCount) {
            maxCount = element.second;
            modeValue = element.first;
        }
    return modeValue;
}
//2. for positive integers
LD mode(const ULL* v, ULL n) {
    std::unordered_map<LD, ULL> nums;
    for(auto i = 0; i < n; ++i)
        nums[v[i]]++;

    ULL maxCount = 0, modeValue = 0;
    for (auto element : nums)
        if (element.second > maxCount) {
            maxCount = element.second;
            modeValue = static_cast<ULL>(element.first);
        }
    return modeValue;
}
//3. for integers (positive/negative)
LD mode(const LL* v, ULL n) {
    std::unordered_map<LD, ULL> nums;
    for(auto i = 0; i < n; ++i)
        nums[v[i]]++;

    ULL maxCount = 0;
    LL modeValue = 0;
    for (auto element : nums)
        if (element.second > maxCount) {
            maxCount = element.second;
            modeValue = static_cast<LL>(element.first);
        }
    return modeValue;
}
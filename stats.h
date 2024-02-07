//
// Created by nick on 12/15/23.
//

#ifndef STATISTNICK_STATS_H
#define STATISTNICK_STATS_H

// Data types shorthands
#define ULL unsigned long long int
#define LD long double
#define LL long long int

#define VULL volatile unsigned long long int
#define VLD volatile long double
#define VLL volatile long long int

//Mean
//1. for reals
LD mean(const LD* v, ULL n, bool unbiased=false);
//2. for positive integers
LD mean(const ULL* v, ULL n, bool unbiased=false);
//3. for integers(positive/negative)
LD mean(const LL* v, ULL n, bool unbiased=false);


//Median
//1. for reals
LD median(const LD* v, ULL n);
//2. for integers (positive/negative)
LD median(const LL* v, ULL n);
//3. for positive integers
LD median(const ULL* v, ULL n);


//Standard Deviation
//1. for reals
LD standard_deviation(const LD* v, ULL n, bool unbiased=false);
//3. for integers(positive/negative)
LD standard_deviation(const LL* v, ULL n, bool unbiased=false);
//2. for positive integers
LD standard_deviation(const ULL* v, ULL n, bool unbiased=false);

//Variance
//1. for reals
LD variance(const LD* v, ULL n, bool unbiased=false);
//3. for integers(positive/negative)
LD variance(const LL* v, ULL n, bool unbiased=false);
//2. for positive integers
LD variance(const ULL* v, ULL n, bool unbiased=false);

//Mode
//1. for reals
LD mode(const LD* v, ULL n);
//3. for integers(positive/negative)
LD mode(const LL* v, ULL n);
//2. for positive integers
LD mode(const ULL*, ULL n);
#endif //STATISTNICK_STATS_H

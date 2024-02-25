//
// Created by nick on 12/15/23.
//

#ifndef STATISTNICK_BIGNUMBERS_H
#define STATISTNICK_BIGNUMBERS_H
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include "stats.h"

class BigNumbers {
private:
    /// std::bitset<1> sign;
    bool sign{};
    char* s;
    LL len{};
public:
    // Allocation
    explicit BigNumbers(char* q, int n = -1);
    explicit BigNumbers(const std::vector<char>& q, int n = -1);
    BigNumbers(const BigNumbers& obj);
    ~BigNumbers();

    // Stuff

    // Arithmetical Operators
    friend BigNumbers operator+(BigNumbers const &, BigNumbers const &);
    friend BigNumbers operator-(BigNumbers const &, BigNumbers const &);
    friend BigNumbers operator*(BigNumbers const &, BigNumbers const &);
    friend BigNumbers operator/(BigNumbers const &, BigNumbers const &);
    friend BigNumbers operator^(BigNumbers const &, BigNumbers const &);
    BigNumbers& operator=(BigNumbers const &);

    // Comparison Operators
    friend bool operator<(const BigNumbers&, const BigNumbers&);
    friend bool operator==(const BigNumbers&, const BigNumbers&);
    friend bool operator>(const BigNumbers&, const BigNumbers&);

    // Streams
    friend std::ostream& operator<<(std::ostream&, const BigNumbers&);
    friend std::istream& operator>>(std::istream&, BigNumbers&);
};


#endif //STATISTNICK_BIGNUMBERS_H

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
    friend BigNumbers operator+(BigNumbers const &lhs, BigNumbers const &rhs);
    friend BigNumbers operator-(BigNumbers const &lhs, BigNumbers const &rhs);
    friend BigNumbers operator*(BigNumbers const &lhs, BigNumbers const &rhs);
    friend BigNumbers operator/(BigNumbers const &lhs, BigNumbers const &rhs);
    friend BigNumbers operator^(BigNumbers const &lhs, BigNumbers const &rhs);
    BigNumbers& operator=(BigNumbers const &obj);

    // Comparison Operators
    friend bool operator<(const BigNumbers& l, const BigNumbers& r);
    friend bool operator==(const BigNumbers& l, const BigNumbers& r);
    friend bool operator>(const BigNumbers& l, const BigNumbers& r);

    // Streams
    friend std::ostream& operator<<(std::ostream& os, const BigNumbers& obj);
    friend std::istream& operator>>(std::istream& os, BigNumbers& obj);
};


#endif //STATISTNICK_BIGNUMBERS_H

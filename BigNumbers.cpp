//
// Created by nick on 12/15/23.
//

#include "BigNumbers.h"

// Allocation
BigNumbers::BigNumbers(char *q, int n) {
    if( q == nullptr) {
        s = (char *)malloc(1 * sizeof(char));
        len = 1;
        sign = false;
    } else {
        if (q[0] != '-')
            sign = false;
        else
            sign = true;
        s = (char *) malloc(strlen(q) + 1 * sizeof(char));
        s[strlen(q)] = '\0';
        len = (n == -1 ? static_cast<LL>(strlen(q)) : n);
        strncpy(this->s, q, len);
    }
}
BigNumbers::BigNumbers(const std::vector<char> &q, int n) {
    if (q[0] != '-')
        sign = false;
    else
        sign = true;
    s = (char *)malloc((q.size() + 1) * sizeof(char));
    len = ( n == -1 ? static_cast<LL>(q.size()) : n);
    for(auto i = 0; i < len; ++i)
        s[i] = q[i];
    s[q.size()] = '\0';
}
BigNumbers::BigNumbers(const BigNumbers& obj){
    len = obj.len;
    s = new char[len + 1];
    std::strcpy(s, obj.s);
}
BigNumbers::~BigNumbers() {
    delete[] s;
}

// Operators
BigNumbers operator+(BigNumbers const &lhs, BigNumbers const &rhs){
    size_t resultLen = std::max(lhs.len, rhs.len) + 1;
    char* result = new char[resultLen];
    // std::cout << "resultLen=" << resultLen << std::endl;
    size_t carry = 0;
    size_t index = resultLen - 1;

    for (; index > 0; --index) {
        size_t sum = carry;
        if (index-1 < lhs.len) {
            sum += lhs.s[index-1] - '0';
        }
        if (index-1 < rhs.len) {
            sum += rhs.s[index-1] - '0';
        }
        // Update carry for the next iteration
        if (sum > 9) {
            carry = sum / 10;
        } else {
            carry = 0;
        }
        // std::cout << "index=" << index-1 << " cifra=" << sum%10 << " carry=" << carry << std::endl;
        // Add the result to the output array
        result[index] = static_cast<char>((sum % 10) + '0');
    }

    if (carry) {
        result[index] = static_cast<char>((carry % 10) + '0');
        result[resultLen] = '\0';
    } else
        strncpy(result, result+1, resultLen);

    BigNumbers resultObj(result);
    delete[] result;
    return resultObj;
}
BigNumbers& BigNumbers::operator=(const BigNumbers &obj){
    if (this != &obj) {
        delete[] s;

        len = obj.len;
        s = new char[len + 1];
        std::strcpy(s, obj.s);
    }
    return *this;
}

BigNumbers operator-(const BigNumbers &lhs, const BigNumbers &rhs) {
    if (lhs < rhs) {
        size_t resultLen = lhs.len + 1;
        char* result = new char[resultLen + 1];
        bool carry = false;

        short l, r, dif;
        for(int index = static_cast<int>(resultLen); index >= 0; --index) {
            l = static_cast<short>(rhs.s[index-1]) - '0';
            r = static_cast<short>(lhs.s[index-1]) - '0';
            if (carry)
                l--;
            dif = l - r;
            if (dif < 0) {
                carry = true;
                dif += 10;
            } else {
                carry = false;
            }
            result[index] = static_cast<char>(dif + '0');
        }

        result[0] = '-';
        result[resultLen] = '\0';
        BigNumbers t(result);
        delete[] result;
        return t;
    } else if (lhs == rhs){
        BigNumbers a(reinterpret_cast<char *>('0'));
        return a;
    } else {
        size_t resultLen = lhs.len;
        char* result = new char[resultLen + 1];
        bool carry = false;
        short l, r, dif;
        for(int index = static_cast<int>(resultLen) - 1; index >= 0; --index) {
            l = static_cast<short>(lhs.s[index]) - '0';
            r = static_cast<short>(rhs.s[index]) - '0';
            if(carry)
                l--;
            dif = l - r;
            if (dif < 0) {
                carry = true;
                dif += 10;
            } else {
                carry = false;
            }
            result[index] = static_cast<char>(dif + '0');
        }
        result[resultLen] = '\0';
        BigNumbers t(result);
        delete[] result;
        return t;
    }
}
// 2 000 000 000 000 000 000 000 000
BigNumbers operator*(const BigNumbers &lhs, const BigNumbers &rhs) {
    size_t resultLen = lhs.len + rhs.len;

    bool signed_ = (lhs.sign != rhs.sign);
    char* result = new char[resultLen + 1 + 1 * signed_];
    for (int i = 0; i < resultLen + 1 * signed_ - 1; --i)
        result[i] = '0';
    short l, r, carry = 0, product;

    LL lmax = lhs.len - 1 * lhs.sign;
    LL rmax = rhs.len - 1 * rhs.sign;
    for (LL cf = lhs.len - 1; cf >= lhs.sign; --cf) {
        for (LL cf2 = rhs.len - 1; cf2 >= rhs.sign; --cf2) {
            l = static_cast<short>(lhs.s[cf]) - '0';
            r = static_cast<short>(rhs.s[cf2]) - '0';
            product = l * r + carry;

            result[cf + cf2 + 1] = static_cast<char>(product % 10 + '0');
            carry = product / 10;
            std::cout << "result[" << cf + cf2 + 1 << "]=" << result[cf+cf2+1] << "  ";
        }
        if(carry) {
            std::cout << "result[" << cf + rhs.sign << "]=" << result[cf + rhs.sign] << " ";
            result[cf + rhs.sign] = carry;
        }
        std::cout << std::endl;
    }
    if(carry)
        result[1 * signed_] = static_cast<char>(carry + '0');
    if(signed_)
        result[0] = '-';
    BigNumbers t(result);
    delete[] result;
    return t;
}

BigNumbers operator/(const BigNumbers &lhs, const BigNumbers &rhs) {
    return BigNumbers(nullptr);
}

BigNumbers operator^(const BigNumbers &lhs, const BigNumbers &rhs) {
    return BigNumbers(nullptr);
}

std::ostream &operator<<(std::ostream &os, const BigNumbers& obj){
    for(size_t i = 0; i < strlen(obj.s); ++i) {
        os << obj.s[i];
    }
    return os;
}

std::istream &operator>>(std::istream &is, BigNumbers &obj) {
    is >> obj.s;
    obj.len = static_cast<LL>(strlen(obj.s));
    // TO DO: if length overflows LL limits
    return is;
}

bool operator<(const BigNumbers &l, const BigNumbers &r) {
    // Different sizes
    if (l.len != r.len) {
        // Different sign, but same length
        if(l.sign and !r.sign) // Left negative and right positive
            return true;
        if(!l.sign and r.sign) // left positive and right negative
            return false;

        // Same sign and same length
        if(l.sign and r.sign)
            return (l.len > r.len); // Both negative and left lengthier
        if(!l.sign and !r.sign)
            return (l.len < r.len); // Both positive and left less lengthy


    // Equal sizes
    } else {
        if (l.sign and r.sign) { // Both negative numbers
            // If any difference
            for (size_t i = 0; i < l.len; ++i)
                if (l.s[i] != r.s[i])
                    return (l.s[i] > r.s[i]);
            // No difference
            return false;

        } else { // Both positive numbers
            for (size_t i = 0; i < l.len; ++i)
                if (l.s[i] != r.s[i])
                    return (l.s[i] < r.s[i]);
            return false; // if they negative are equal
        }
    }
}

bool operator==(const BigNumbers &l, const BigNumbers &r) {
    if (l.len != r.len) {
        return false;
    } else {
        for (size_t i = 0; i < l.len; ++i) {
            if (l.s[i] != r.s[i])
                return false;
        }
        return true;
    }
}

bool operator>(const BigNumbers &l, const BigNumbers &r) {
    return (r<l);
}
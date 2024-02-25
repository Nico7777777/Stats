//
// Created by nick on 2/8/24.
//

#ifndef STATISTNICK_LINEARALGEBRA_H
#define STATISTNICK_LINEARALGEBRA_H
#define PI  3.14159265358979323846
#define SILVER_RATIO 1.61803398874989484820
#define e  2.71828182845904523536
#include <type_traits>
#include <cmath>
#include <bitset>
#include "metrics.h"
#include "stats.h"

void sqrtt(LD &, const LD);

/// VECTOR
template <class T>
class vector{
private:
    T *components;
public:
    LD module{}, maximum{}, norm1{}, norm2{};
    ULL size{};

    /// GET & SET - DECLARATIONS
    T get(ULL index) const;
    void set(ULL index, T value);

    /// OPERATORS - DECLARATIONS
    /// INDEX operator
    T const& operator[](unsigned int) const;
    /// PRODUCT(with scalar) - vector & constant
    template <class U>
    friend vector operator*(vector const &, const U &);
    /// PRODUCT(with scalar) - constant & vector
    template <class U>
    friend vector operator*(const U &, vector const &);
    /// !!!VECTORIAL PRODUCT!!!
    template <class R, class S>
    friend vector operator*(vector const &, vector const &);
    /// DIVISION(with scalar) - vector & constant
    template <class U>
    friend vector operator/(vector const &, U &);
    /// DIVISION(with scalar) - constant & vector
    template <class U>
    friend vector operator/(U &, vector const &);

    friend vector operator+(vector const &, vector const &); /// summation with another vector
    friend vector operator-(vector const &, vector const &); /// difference of it anf another vector
    friend bool operator<(const vector&, const vector&);
    friend bool operator<=(const vector&, const vector&);
    friend bool operator==(const vector&, const vector&);
    friend bool operator>=(const vector&, const vector&);
    friend bool operator>(const vector&, const vector&);

    /// CLASS FUNCTIONS
    template <class R, class S>
    LD theta(vector<R> v, vector<S> w);
    template <class R, class S>
    bool colinear(vector<R>, vector<S>);
    template <class R, class S>
    vector vectorial_product(vector<R> v, vector<S> w);
    /// CONSTRUCTORS AND DESTRUCTORS - DECLARATIONS
    vector(const T *v, ULL n);
    vector(T val, ULL size);
    vector();
    ~vector();
};



/// GET & SET - IMPLEMENTATIONS
template <class T>
T vector<T>::get(ULL index) const{
    return components[index];
}
template <class T>
void vector<T>::set(ULL index, T value){
    components[index] = value;
}


/// OPERATORS - IMPLEMENTATIONS
/// INDEX operator
template <class T>
T const &vector<T>::operator[](unsigned int i) const {
    return components[i];
}
/// PRODUCT(with scalar) - vector & constant
template <class T, class U>
vector<T> operator*(vector<T> const &v, const U &s) {
    vector<T> w = v;
    for (auto i = 0; i < w.size; ++i)
        w.set(i, w.get(i)*s);
    return w;
}
/// PRODUCT(with scalar) - constant & vector
template <class T, class U>
vector<T> operator*(const U &s, vector<T> const &v) {
    vector<T> w = v;
    for (auto i = 0; i < w.size; ++i)
        w.set(i, w.get(i)*s);
    return w;
}
/// !!!VECTORIAL PRODUCT!!!
template <class R, class S, class T>
vector<T> operator*(vector<R> const &v, vector<S> const &w) {
    //TO DO: add different size exception -- v.size != w.size
    vector<T> alfa = vector<T>(0, v.size);

}
/// REVERSE SCALAR PRODUCT - vector & constant
template <class T, class U>
vector<T> operator/(vector<T> const &v, U &s) {
    return v * (1/s);
}
/// REVERSE SCALAR PRODUCT - constant & vector
template <class T, class U>
vector<T> operator/(U &s, vector<T> const &v) {
    return v * (1/s);
}

/// CLASS METHODS
/// theta - angle of two vectors
template<class T>
template<class R, class S>
LD vector<T>::theta(vector<R> v, vector<S> w) {
    LD sum = 0;
    // TO DO: different sizes exception
    for (auto i = 0; i < v.size; ++i)
        sum += v[i] * w[i];
    sum /= (v.module * w.module);
    printf("SUM(for theta) = %Lf\n", sum);
    return acosl(sum) * 180 / PI;
}
/// linearity of two vectors
template<class T>
template<class R, class S>
bool vector<T>::colinear(vector<R> v, vector<S> w) {
    LD constanta = v[0] / w[0];
    for (auto i = 0; i < v.size; ++i)
        if (v[i] / w[i] != constanta)
            return false;
    return true;
}
/// vectorial product
template<class T>
template<class R, class S>
vector<T> vector<T>::vectorial_product(vector<R> v, vector<S> w) {
    return vector();
}


/// CONSTRUCTORS & DESTRUCTORS - IMPLEMENTATIONS
/// pointer & size
template<class T>
vector<T>::vector(const T *v, ULL n) {
    static_assert(std::is_arithmetic<T>::value, "Type must be numeric!");
    this->components = new T[n];
    T sum = this->maximum = this->norm1 = this->norm2 = 0;
    for (ULL i = 0; i < n + 0; ++i) {
        this->components[i] = v[i];
        this->norm1 += v[i];
        /// OVERFLOW
        sum += this->components[i] * this->components[i];
        if (this->components[i] > this->maximum)
            maximum = this->components[i];
    }
    this->size = n;
    /// OVERFLOW
    sqrtt(this->module, static_cast<LD>(sum));
    this->norm2 = this->module;
    this->size = n;
}
/// value & size
template <class T>
vector<T>::vector(const T val, ULL size) {
    float *const *ar;
    ar = new T[size];
    for (auto i = 0; i < size; ++i)
        ar[i] = val;
    vector <T>(ar, size); /// calling the first sophisticated constructor
}
/// implicit constructor
template <class T>
vector<T>::vector() = default;
/// implicit destructor
template <class T>
vector<T>::~vector() = default;

template <class T>
void calculate_trace(T &trace, vector<T> **rows, ULL m, ULL n, LL offset = 0) {
    LL i = 0, j = 0;
    if (offset > 0)
        j = offset;
    else
        i = -offset;
    /// the offset for parallels to the principal diagonal ~ trace
    trace = 0;
    while (i < m and j < n) {
        trace += (*rows[i])[j];
        i++; j++;
    }
}
/// ONES
template <class T>
class ones: private vector<T>{
public:
    explicit ones(ULL size);
    ~ones() = default;
};
template <class T>
ones<T>::ones(ULL size) {
    const T *ar = new T[size];
    for (auto i = 0; i < size; ++i)
        this->set(i, static_cast<T>(1));
    vector<T>(ar, size);
}
//template <class T>
//ones<T>::~ones(){
//    vector<T>();
//}
/// ZEROS
template <class T>
class zeros: private vector<T>
{
public:
        explicit zeros(ULL size);
        ~zeros() = default;
};
template <class T>
zeros<T>::zeros(ULL size) {
    const T *ar = new T[size];
    for (auto i = 0; i < size; ++i)
        ar[i] = 1;
    vector<T>(ar, size);
}
//template <class T>
//zeros<T>::~zeros() {
//    ~vector<T>();
//}
/// MATRIX
template <class T>
class matrix{
public:
    ULL m{}, n{}; /// m lines and n columns
    bool is_diag{};
    T trace{};
    vector<T> **rows{};
    matrix(T **, ULL);
    matrix(T **, ULL, ULL);
    matrix(::vector<T> **, ULL);
    matrix();
};

template <class T>
matrix<T>::matrix(T **ar, ULL size) {
    is_diag = true;
    m = n = size;
    rows = new ::vector<T>*[n];
    for (auto i = 0; i < n; ++i)
        rows[i] = new ::vector<T>(ar[i], n);
    /// CALCULATE TRACE
    calculate_trace(trace, rows, m, n);
}
template <class T>
matrix<T>::matrix(T **ar, ULL r, ULL c) {
    is_diag = (r==c);
    m = r;
    n = c;
    rows = new ::vector<T>*[m];
    for (auto i = 0; i < m; ++i)
        rows[i] = new ::vector<T>(ar[i], n);
    /// CALCULATE TRACE
    calculate_trace(trace, rows, m, n);
}
template <class T>
matrix<T>::matrix(::vector<T> **v, ULL size) {
    if ( v != nullptr) {
        this->rows = v;
        this->m = size;
        this->n = v[0]->size;
    }
    else matrix();
}
template <class T>
matrix<T>::matrix() = default;


//#include "linearAlgebra.cpp"
#endif //STATISTNICK_LINEARALGEBRA_H

//
// Created by nick on 2/8/24.
//
//#include <cmath>
#include "linearAlgebra.h"

void sqrtt(LD &module, const LD norm1) {
    module = sqrtl(norm1);
}
template <class T>
vector<T> operator+(const vector<T> &v1, const vector<T> &v2) {
    vector<T> v3 = vector<T>();
    for (auto i = 0; i < max(v1.size, v2.size); ++i) {
        if (i < v1.size)
            v3.set(i, v3.get() + v1.get(i));
        if (i < v2.size)
            v3.set(i, v3.get() + v2.get(i));
    }
    return v3;
}
template <class T>
vector<T> operator-(const vector<T> &v1, const vector<T> &v2) {
    vector<T> v3 = vector<T>();
    for (auto i = 0; i < max(v1.size, v2.size); ++i) {
        if (i < v1.size)
            v3.set(i, v3.get() + v1.get(i));
        if (i < v2.size)
            v3.set(i, v3.get() - v2.get(i));

    }
}
template <class T>
bool operator<(const vector<T> &v1, const vector<T> &v2) {
    return (v1.norm2 < v2.norm2);
}
template <class T>
bool operator<=(const vector<T> &v1, const vector<T> &v2) {
    return (v1.norm2 <= v2.norm2);
}
template <class T>
bool operator==(const vector<T> &v1, const vector<T> &v2) {
    return (v1.norm2 == v2.norm2);
}
template <class T>
bool operator>=(const vector<T> &v1, const vector<T> &v2) {
    return (v1.norm2 >= v2.norm2);
}
template <class T>
bool operator>(const vector<T> &v1, const vector<T> &v2) {
    return (v1.norm1 > v2.norm2);
}
//
//template <class T>
//LD vector<T>::get(ULL index){
//    //return components[index];
//}
//template <class T>
//void vector<T>::set(ULL index, T value){
//    components[index] = value;
//}
//
//
//template<class T>
//vector<T>::vector(const T *v, ULL n) {
//    this->components = new T[n];
//    /*ULL sum = 0;
//    this->max_val = 0;
//    for(ULL i = 0; i < n + 0; ++i) {
//        this->components[ i ] = v[i];
//        /// OVERFLOW
//        sum += this->components[i]*this->components[i];
//        if (this->components[i] > this->max_val)
//            max_val = this->components[i];
//    }
//    this->size = n;
//    /// OVERFLOW
//    this->module = sqrtl((LD)sum);*/
//    this->module = 2.0;
//    this->max_val = 12.0;
//    this->size = n;
//}
//template<class T>
//vector<T>::vector() {
//
//}
//template <class T>
//vector<T>::~vector() {
//    delete this->components;
//}

//
// Created by Administrator on 2018-08-06.
//

#include "complex.h"

//友元函数的实现
template<typename T>
ostream &operator<<(ostream &out, Complex<T> &c) {
    out << c.a << " + " << c.b << "i";
    return out;
}


//函数的实现
template<typename T>
Complex<T>::Complex(T a, T b) {
    this->a = a;
    this->b = b;
}

template<typename T>
Complex<T> Complex<T>::operator+(Complex<T> &c) {
    Complex temp(this->a + c.a, this->b + c.b);
    return temp;
}

template<typename T>
Complex<T> Complex<T>::myAdd(Complex<T> &c1, Complex<T> &c2) {
    Complex temp(c1.a + c2.a, c1.b + c2.b);
    return temp;
}

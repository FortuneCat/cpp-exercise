//
// Created by Administrator on 2018-08-06.
//

#ifndef CPP_INTERVIEW_COMPLEX_H
#define CPP_INTERVIEW_COMPLEX_H


#include <iostream>

using namespace std;

//类的前置声明
template<typename T>
class Complex;

//友元函数的声明
template<typename T>
ostream &operator<<(ostream &out, Complex<T> &c);

template<typename T>
class Complex {

    //友元函数实现运算符重载
    friend ostream &operator<<<T>(ostream &out, Complex<T> &c);

public:
    Complex(T a, T b);

    //运算符重载+
    Complex<T> operator+(Complex<T> &c);

    //普通加法函数
    Complex<T> myAdd(Complex<T> &c1, Complex<T> &c2);

private:
    T a;
    T b;
};


#endif //CPP_INTERVIEW_COMPLEX_H

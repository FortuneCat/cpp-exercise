//
// Created by yingly on 2018-08-03.
//

#ifndef CPP_INTERVIEW_EQUATIONSOLUTION_H
#define CPP_INTERVIEW_EQUATIONSOLUTION_H


/* 用牛顿迭代法求解方程f(x)=0
 * usage: newton([](double x)->double{return log(x);}, 2);
 */
double newton(double (*p)(double), double initial_guess);


#endif //CPP_INTERVIEW_EQUATIONSOLUTION_H

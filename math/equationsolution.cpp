//
// Created by yingly on 2018-08-03.
//

#include "equationsolution.h"
#include <cmath>
#include <iostream>

double newton(double (*p)(double), double initial_guess) {
    // 根据任一点的切线方程f(x)=f'(x0)(x-x0)+f(x0)，可得切线与x轴交点横坐标x=x0-f(x0)/f'(x0),
    // 继续求得该横坐标点对应曲线上点的切线，迭代直到该横坐标无限接近方程的解析解
    double x = initial_guess;
    double y_error;
    int i = 0;
    while (fabs(y_error = (*p)(x)) > 0.000001) {
        printf("count=%d, x=%lf, y_error=%lf\n", ++i, x, y_error);
        //calculate f('x) at x
        double f_derivative = ((*p)(x + 0.000001) - (*p)(x)) / 0.000001;
        x -= (*p)(x) / f_derivative;
    }
    return x;
}

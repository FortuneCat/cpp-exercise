//
// Created by Administrator on 2018-08-04.
//

#include "hanoi.h"
#include <iostream>

void hanoi(int n, char a, char b, char c) {
    if (n == 1) {
        std::cout << a << "-->" << c << std::endl;
        return;
    }
    hanoi(n - 1, a, c, b);
    hanoi(1, a, b, c);
    hanoi(n - 1, b, a, c);
}

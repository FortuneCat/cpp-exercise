#include <iostream>
#include "quiz/knight.h"

using namespace std;

int main() {
//    Complex<int> c1(1,2);
//    Complex<int> c2(3,4);
//
//    Complex<int> c = c1 + c2;
//
//    cout<<c<<endl;
    Knight knight;
//    knight.RunTestFromAllInitPositions();
    Step init = Step(7, 2);
    knight.Traverse(init);

    return 0;
}
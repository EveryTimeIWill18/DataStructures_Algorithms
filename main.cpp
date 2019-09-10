#include <iostream>
#include "Array.t.hpp"


int main() {

    //WMurphy::Array<double> a1();
    WMurphy::Array<double> a1();
    WMurphy::Array<double> a2(1);
    WMurphy::Array<float> a3(5);
    a2.Insert(100.1);
    a3[0] = 1.1;
    a3[1] = 2.2;
    a3[2] = 3.3;
    a3[3] = 4.4;
    a3[4] = 5.5;

    std::cout << a3[0] << std::endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <typeinfo>
#include "Array.t.hpp"
#include "SearchAlgorithms.h"
#include "Vector.t.hpp"
#include "Point.h"





int main() {

    //WMurphy::Array<double> a1();
    WMurphy::Array<double> a1();
    WMurphy::Array<double> a2(1);
    WMurphy::Array<float> a3(5);
    WMurphy::Array<int> a4(3);

    a2.Insert(100.1);
    a3[0] = 1.1;
    a3[1] = 2.2;
    a3[2] = 3.3;
    a3[3] = 4.4;
    a3[4] = 5.5;

    a4[0] = 1;
    a4[1] = 2;
    a4[2] = 3;



    std::vector<int> v1 = {1,2,3,4,5};
    WMurphy::Vector<double> v2();
    WMurphy::Vector<double> v3(4, 10);
    WMurphy::Vector<double> v5 = v3;


    std::cout << "v5 size == " << v5.size() << std::endl;

    auto index_value = WMurphy::LinearSearch(3, v1.data(), v1.size());
    v5.push_back(100.1);
    std::cout << "v5 size == " << v5.size() << std::endl;

    std::cout << "v5 capacity == " << v5.capacity() << std::endl;

    return 0;
}
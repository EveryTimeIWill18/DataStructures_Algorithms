//
// Created by wmurphy on 9/11/2019.
//

#ifndef DATASTRCTURES_ALGORITHMS_LINEAR_SEARCH
#define DATASTRCTURES_ALGORITHMS_LINEAR_SEARCH

namespace WMurphy {

    constexpr int ValueNotFound = -1;


    int LinearSearch(int element, const int* v, int size) {
            for (int i=0; i < size; i++) {
                if (v[i] == element) {
                    return i;
                }
            }
        return ValueNotFound;
    }
}

#endif //DATASTRCTURES_ALGORITHMS_LINEAR_SEARCH
//
// Created by wmurphy on 9/12/2019.
//

#ifndef DATASTRCTURES_ALGORITHMS_ITERATOR_H
#define DATASTRCTURES_ALGORITHMS_ITERATOR_H

#include <iterator>

namespace WMurphy {

    template <typename T>
class Iterator : public std::iterator<std::random_access_iterator_tag,
        T, ptrdiff_t , T*, T&> {

    };
}




#endif //DATASTRCTURES_ALGORITHMS_ITERATOR_H

//
// Created by wmurphy on 9/11/2019.
//

#ifndef DATASTRCTURES_ALGORITHMS_VECTOR_H
#define DATASTRCTURES_ALGORITHMS_VECTOR_H

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <new>


namespace WMurphy {

    template <typename T>
    class Vector {
    public:
        typedef typename std::size_t size_type;
    private:
        T* _data{nullptr};
        size_type _size{0};
        size_type  _capacity{5};
        int num_elements{0};
    public:
        Vector();
        explicit Vector(size_type size, size_type capacity);
        ~Vector();  // destructor
        Vector(const Vector<T> &_vector); // copy constructor
        int size() const noexcept;
        size_type capacity() const;
        void push_back(const T& v);
        Vector<T>&operator=(const Vector<T>&);
        T operator[](int index) const;
        T&operator[](int index);
        bool empty() const noexcept;
    };
}

#endif //DATASTRCTURES_ALGORITHMS_VECTOR_H

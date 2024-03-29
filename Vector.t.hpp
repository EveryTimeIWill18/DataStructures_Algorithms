//
// Created by wmurphy on 9/11/2019.
//

#include "Vector.h"
#include "IndexOutOfBoundsException.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


namespace WMurphy {
    typedef typename std::size_t size_type;

    template <typename T>
    Vector<T>::Vector() {
        std::cout << "Creating an empty WMurphy::Vector ..." << std::endl;
    }; // default constructor

    template <typename T>
    Vector<T>::Vector(size_type size, size_type capacity) {
        assert(size >= 0 && capacity >= 0);
        if (size > 0 && capacity > 0) {
            this->_size = size;
            this->_capacity = capacity;
            this->_data = static_cast<T*>(malloc(this->_capacity* sizeof(T)));
        }
    } // explicit constructor

    template <typename T>
    Vector<T>::~Vector() {
        // free memory allocated for this->_data;
        free(_data);
        std::cout << "Destroying WMurphy::Vector ..." << std::endl;
    } // destructor

    template <typename T>
    Vector<T>::Vector(const WMurphy::Vector<T> &_vector) {
        this->_size = _vector._size;
        this->_capacity = _vector._capacity;

        this->_data = static_cast<T*>(malloc(this->_capacity* sizeof(T)));
        // copy the elements of _vector._data to this->_data
        for (int i=0; i < this->_capacity; i++) {
            *(this->_data + i) = *(_vector._data + i);
        }
    } // copy constructor

    template <typename T>
    Vector<T>::Vector(WMurphy::Vector<T> &&_vector) {
        this->_data = _vector._data;
        this->_size = _vector._size;
        this->_capacity = _vector._capacity;
        this->num_elements = _vector.num_elements;

        // clear source vector
        free(_vector._data);
        _vector.num_elements = 0;
        _vector._capacity = 0;
        _vector._size = 0;
    } // move constructor

    template <typename T>
    int Vector<T>::size() const noexcept {
        return this->num_elements;
    }

    template <typename T>
    size_type Vector<T>::capacity() const {
        return this->_capacity;
    }

    template <typename T>
    void Vector<T>::push_back(const T& v) {
        if (this->size() == this->capacity()) {
            std::cout << "WMurphy::Vector<T>.resize() not yet implemented." << std::endl;
        } else {
            *(this->_data + this->num_elements) = v;
            this->num_elements++;
        }
    }

    template <typename T>
    Vector<T>& Vector<T>::operator=(const Vector<T>&) {

    }

    template <typename T>
    T Vector<T>::operator[](int index) const {
        if (index < this->size()) {
            return *(this->_data + index);
        }
    }

    template <typename T>
    T& Vector<T>::operator[](int index) {
        if (index < this->size()) {
            return *(this->_data + index);
        }
    }

    template <typename T>
    bool Vector<T>::empty() const noexcept {
        return (this->_size == 0);
    }



}

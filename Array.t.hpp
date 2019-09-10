//
// Created by wmurphy on 9/10/2019.
//

#include "Array.h"
#include "IndexOutOfBoundsException.h"
#include <cassert>
#include <iostream>
#include <ostream>

namespace WMurphy {

    // template Array class
    template <typename T>
    Array<T>::Array()=default;

    template <typename T>
     Array<T>::Array(int size) : m_size(size) {
        assert(size >= 0);
        if (size > 0) {
            m_ptr = new T[m_size];
        }
    }

    template <typename T>
    Array<T>::Array(const WMurphy::Array<T> &copy_array) {
        m_size = copy_array.m_size;
        m_ptr = new T[m_size];

        for (int i=0; i < m_size; i++) {
            *(m_ptr + i) = *(copy_array + i);
        }
    }

    template <typename T>
    Array<T>::~Array() {
        delete[] m_ptr;
        m_size = 0;
        std::cout << "Destroying Array ... " << std::endl;
    }

    template <typename T>
    int Array<T>::Size() const {
        return m_size;
    }

    template <typename T>
    void Array<T>::Insert(T value) {
        assert(m_size > 0);
        if (m_pos < this->Size() - 1) {
            *(m_ptr + m_pos) = value;
            m_pos++;
        }
    }

    template <typename T>
    bool Array<T>::IsEmpty() const {
        return (m_size == 0);
    }

    template <typename T>
    bool Array<T>::IsValidIndex(int index) const {
        return (index >= 0) && (index < m_size);
    }

    template <typename T>
    T Array<T>::operator[](int index) const {
        if (!IsValidIndex(index)) {
            throw IndexOutOfBoundsException();
        }
        return m_ptr[index];
    }

    template  <typename T>
    T& Array<T>::operator[](int index) {
        if (!IsValidIndex(index)) {
            throw IndexOutOfBoundsException();
        }
        return m_ptr[index];
    }

    template <typename T>
    Array<T>& Array<T>::operator=(const WMurphy::Array<T> &source) {
        // Prevent self-assignment (x = x)
        if (&source != this) {
            // TODO
        }

        return *this;
    }

}

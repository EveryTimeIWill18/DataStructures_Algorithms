//
// Created by wmurphy on 9/10/2019.
//

#ifndef DATASTRCTURES_ALGORITHMS_ARRAY_H
#define DATASTRCTURES_ALGORITHMS_ARRAY_H

#include <ostream>



namespace WMurphy {

    template <typename T>
    class Array {
    private:
        T* m_ptr{nullptr};
        int m_size{0};
        int m_pos{0};

    public:
        Array(); // default
        explicit Array(int size);
        Array(const Array<T>& copy_array); // copy
        ~Array(); // destructor
        int Size() const;
        void Insert(T value);
        bool IsEmpty() const;
        bool IsValidIndex(int index) const;
        T operator[](int index) const;
        T& operator[](int index);
        Array<T>&operator=(const Array<T>& source);

    };
}



#endif //DATASTRCTURES_ALGORITHMS_ARRAY_H

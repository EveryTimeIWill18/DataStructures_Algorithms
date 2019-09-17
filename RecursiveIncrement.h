//
// Created by wmurphy on 9/12/2019.
//
#ifndef RECURSIZE_INCREMENT
#define RECURSIZE_INCREMENT


template <class T>
void merge(T* A, T* aux, int lo, int mid, int hi) {

    for (int k = lo; k <= hi; k++) {
        aux[k] = A[k];
    }

    int i = lo;
    int j = mid+1;

    for (int k = lo; k <= hi; k++) {
        if (i > mid) {
            A[k] = aux[j];
            j++;
        }
        else if (j > hi) {

        }
    }


}


#endif // RECURSIZE_INCREMENT
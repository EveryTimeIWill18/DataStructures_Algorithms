#include <iostream>
#include <vector>
#include <typeinfo>
#include <algorithm>
#include "Array.t.hpp"
#include "Vector.t.hpp"
#include "Point.h"
#include "Trees.t.hpp"


typedef int* (*int_array_func_ptr)(int*);


int binary_search(int n, int A[], int left, int right) {

    if (right >= left) {
        int midpoint = left + (right - left) / 2;

        std::cout << "midpoint = " << midpoint << std::endl;

        // case 1: A[midpoint] == n
        if (A[midpoint] == n) {
            return midpoint;
        }
        if (A[midpoint] > n) {
            return binary_search(n, A, left, midpoint - 1);
        }

        return binary_search(n, A, midpoint + 1, right);
    }

    return -1;
}

int find_first_occurrence(int n, int A[], int left, int right) {
    if (right >= left) {
        int midpoint = left + (right - left) / 2;

        if (A[midpoint] == n) {
            while (A[midpoint] == n) {
                midpoint--;
            }
            return midpoint+1;
        }
        if (A[midpoint] > n) {
            return binary_search(n, A, left, midpoint-1);
        } else {
            return binary_search(n, A, midpoint+1, right);
        }
    }
    return -1;
}

int find_last_occurrence(int n, int A[], int left, int right) {
    if (right >= left) {
        int midpoint = left + (right - left) / 2;

        if (A[midpoint] == n) {
            while (A[midpoint] == n) {
                midpoint++;
            }
            return midpoint-1;
        }
        if (A[midpoint] > n) {
            return binary_search(n, A, left, midpoint-1);
        } else {
            return binary_search(n, A, midpoint+1, right);
        }
    }
    return -1;
}


int* bubble_sort(int A[], int length) {

    int iterations = 0;

    for (int i=0; i < length; i++) {
        for (int j=0; j < length-1; j++) {
            if (A[j] > A[j+1]) {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
            iterations++;
        }
    }

    std::cout << "Bubble Sort: Number of iterations: " << iterations << std::endl;
    return A;

}


int * insertion_sort(int A[], int length) {

    int iter = 0;
    int j;
    for (int i=0; i < length; i++) {
        j = i;
        while (j > 0 && A[j-1] > A[j]) {
            int temp = A[j-1];
            A[j-1] = A[j];
            A[j] = temp;
            j--;
        }
    }

    std::cout << "Insertion Sort: Number of iterations: " << iter << std::endl;
    return A;
}


int * selection_sort(int A[], int length) {

    int least;
    int temp;
    for (int i=0; i < length - 1; i++) {
        int j = i+1;
        least = i;
        while (j < length) {
            if(A[j] < A[least]) {
                least = j;
            }
            j++;
        }
        temp = A[i];
        A[i] = A[least];
        A[least] = temp;
    }

    return A;
}



int * shell_sort(int A[], int length) {
    int gap = length / 2;

    while (gap > 0) {
        for (int i=gap; i < length; i++) {
            int j = i;
            int temp = A[i];
            while (j >= gap && A[j-gap] > temp) {
                A[j] = A[j-gap];
                j -= gap;
            }
            A[j] = temp;
        }
        gap = gap / 2;
    }

    return A;
}







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

    //auto index_value = WMurphy::LinearSearch(3, v1.data(), v1.size());
    v5.push_back(100.1);
    std::cout << "v5 size == " << v5.size() << std::endl;

    std::cout << "v5 capacity == " << v5.capacity() << std::endl;


    int array[10] = {5,3,2,1,7,8,4,6,9,10};
    int array2[9] = {2,5,5,6,9,19,26,45,69};
    int array3[7] = {1,3,20,20,20,45,78};


    int array4[12] = {12,11,10,9,8,7,6,5,4,3,2,1};
    int array5[12] = {22,21,20,19,18,17,16,15,14,13,12,11};

    int r = sizeof(array2) / sizeof(array2[0]);

    int b = binary_search(6, array2, 0, r-1);
    int first = find_first_occurrence(20, array3, 0, 7);
    int last = find_last_occurrence(20, array3, 0, 7);
    std::cout << "first = " << first << std::endl;
    std::cout << "last = " << last << std::endl;


    int *b_sort;
    int *i_sort;
    int *s_sort;
    int *shell;


    b_sort = bubble_sort(array, 10);
    i_sort = insertion_sort(array4, 12);
    s_sort = selection_sort(array5, 12);



    std::cout << "Bubble Sort\n-----------" << std::endl;
    for(int i=0; i < 10; i++) {
        std::cout << *(b_sort + i) << "\t";
    }
    std::cout << std::endl;

    std::cout << "Insertion Sort\n-----------" << std::endl;
    for(int i=0; i < 12; i++) {
        std::cout << *(i_sort + i) << "\t";
    }
    std::cout << std::endl;

    std::cout << "Selection Sort\n-----------" << std::endl;
    for(int i=0; i < 12; i++) {
        std::cout << *(s_sort + i) << "\t";
    }
    std::cout << std::endl;



    std::sort(array+0, array+10);


    WMurphy::BinaryTree<int> b_tree = WMurphy::BinaryTree(10);

    std::cout << "b_tree data = " << b_tree.getData() << std::endl;


    int shell_data[8] = {19, 2, 31, 45, 30, 11, 121, 27};

    shell = shell_sort(shell_data, 8);
    std::cout << "Shell Sort\n-----------" << std::endl;
    for(int i=0; i < 8; i++) {
        std::cout << *(shell + i) << "\t";
    }
    std::cout << std::endl;



    return 0;
}
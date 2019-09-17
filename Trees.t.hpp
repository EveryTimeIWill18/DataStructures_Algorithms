//
// Created by wmurphy on 9/17/2019.
//

#include "Trees.h"
#include <iostream>
#include <stdio.h>

namespace WMurphy {

    template <typename T>
    BinaryTree<T>::BinaryTree() {
        std::cout << "Calling BinaryTree default constructor" << std::endl;
    }

    template <typename T>
    BinaryTree<T>::BinaryTree(T data) {

        // allocate memory for root
        root = (Node*)malloc(sizeof(Node));

        // set root's data to data
        root->data = data;

        // set root->left and root->right to NULL
        root->left_child = nullptr;
        root->right_child = nullptr;

    }

    template <typename T>
    BinaryTree<T>::~BinaryTree() {

        if (root->left_child != nullptr) {
            free(root->left_child);
            std::cout << "releasing left_child." << std::endl;
        }
        if (root->right_child != nullptr) {
            free(root->right_child);
            std::cout << "releasing right_child." << std::endl;
        }
        if (root != nullptr)
            free(root);

        std::cout << "Destroying BinaryTree ..." << std::endl;

    }

    template <typename T>
    T BinaryTree<T>::getData() const {
        return root->data;
    }

    template <typename T>
    BinaryTree<T>::BinaryTree(const WMurphy::BinaryTree<T> &b_tree) {
        root = b_tree.root;
    }


}
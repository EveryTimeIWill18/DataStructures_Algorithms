//
// Created by wmurphy on 9/17/2019.
//

#ifndef DATASTRCTURES_ALGORITHMS_TREES_H
#define DATASTRCTURES_ALGORITHMS_TREES_H


#include <stdlib.h>

namespace WMurphy {

    template <typename T>
    class BinaryTree {

    private:
        typedef struct node {
            T data;
            struct node *left_child;
            struct node *right_child;
        }Node;

    Node *root{nullptr};

    public:
        BinaryTree();
        explicit BinaryTree(T data);
        BinaryTree(const BinaryTree<T>& b_tree);
        ~BinaryTree();
        T getData() const;


    };



}

#endif //DATASTRCTURES_ALGORITHMS_TREES_H

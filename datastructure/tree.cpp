//
// Created by Administrator on 2018-08-05.
//

#include "tree.h"
#include <iostream>

template<typename T>
Tree<T>::Tree() {
    root = new Node<T>();
    root->parent = NULL;
    root->value = NULL;
}

template<typename T>
Tree<T>::Tree(T root_elem) {
    root = new Node<T>();
    root->parent = NULL;
    root->value = root_elem;
}

/*
 * 构造树（100(2((7)(10)(11))(5(9(4)(8))))）
 */
template<typename T>
void Tree<T>::Test() {
    Tree tree(100);
    auto *node1_1 = new Node<int>();
    node1_1->value = 2;
    auto *node1_2 = new Node<int>();
    node1_2->value = 5;
    auto *node2_1 = new Node<int>();
    node2_1->value = 7;
    auto *node2_2 = new Node<int>();
    node2_2->value = 10;
    auto *node2_3 = new Node<int>();
    node2_3->value = 11;
    auto *node2_4 = new Node<int>();
    node2_4->value = 9;
    auto *node3_1 = new Node<int>();
    node3_1->value = 4;
    auto *node3_2 = new Node<int>();
    node3_2->value = 8;
    tree.InsertNode(tree.root, node1_1);
    tree.InsertNode(tree.root, node1_2);
    tree.InsertNode(node1_1, node2_1);
    tree.InsertNode(node1_1, node2_2);
    tree.InsertNode(node1_1, node2_3);
    tree.InsertNode(node1_2, node2_4);
    tree.InsertNode(node2_4, node3_1);
    tree.InsertNode(node2_4, node3_2);
    tree.PostOrderVisit(tree.root);
}

template<typename T>
void Tree<T>::InsertNode(Node<T> *parent, Node<T> *child) {
    child->parent = parent;
    parent->child_vec.push_back(child);
}

template<typename T>
void Tree<T>::PostOrderVisit(Node<T> *parent) {
    if (parent->child_vec.size() == 0) {
        printf("Handling %d\n", parent->value);
        return;
    } else {
        for (auto child : parent->child_vec) {
            PostOrderVisit(child);
        }
    }
    printf("Handling %d\n", parent->value);
}

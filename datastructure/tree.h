//
// Created by yingly on 2018-08-05.
//

#ifndef CPP_INTERVIEW_TREE_H
#define CPP_INTERVIEW_TREE_H

#include <vector>

template<typename T>
class Tree;

template<typename T>
struct Node {
    Node *parent;
    std::vector<Node *> child_vec;
    T value;
};

template<typename T>
class Tree {
public:
    Tree();

    Tree(T root_elem);

    ~Tree() {};

    static void Test();

    void InsertNode(Node<T> *parent, Node<T> *child);

    void PostOrderVisit(Node<T> *parent);

    Node<T> *root;
private:

};


#endif //CPP_INTERVIEW_TREE_H

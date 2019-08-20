#include <iostream>
#include <string>

struct Node {
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

struct Trunk {
    Trunk *prev;
    std::string str;

    Trunk(Trunk *prev, std::string str) {
        this->prev = prev;
        this->str = str;
    }
};

#include "binaryTreeVisualizer.h"

using namespace std;

void showTrunks(Trunk *p) {
    if (p == nullptr)
        return;
    showTrunks(p->prev);
    cout << p->str;
}

/**
 * Prints the given tree.
 */
void printTree(Node *root, Trunk *prev, bool isLeft)
{
    if (root == nullptr)
        return;

    std::string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);

    printTree(root->left, trunk, !isLeft);

    if (!prev)
        trunk->str = "---";
    else if (isLeft) {
        trunk->str = ".---";
        prev_str = "   |";
    }
    else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->data << endl;

    if (prev)
        prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->right, trunk, false);
}

int main() {
    Node* root = nullptr;

    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(13);
    root->right->right->left = new Node(14);
    root->right->right->right = new Node(15);

    printTree(root, nullptr, false);

    return 0;
}

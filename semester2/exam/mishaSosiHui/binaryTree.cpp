//
// Created by Павло on 09.06.2024.
//
#include <iostream>
using namespace std;


struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};


class BinaryTree {
private:
    TreeNode* root;

    void addNode(TreeNode*& node, int value) {
        if (node == nullptr) {
            node = new TreeNode(value);
        } else {
            if (node->left == nullptr) {
                node->left = new TreeNode(value);
            } else if (node->right == nullptr) {
                node->right = new TreeNode(value);
            } else {
                addNode(node->left, value);
            }
        }
    }

    void destroyTree(TreeNode* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    ~BinaryTree() {
        destroyTree(root);
    }

    void addNode(int value) {
        addNode(root, value);
    }

    TreeNode* getRoot(){
        return root;
    }

};
//
// Created by Павло on 15.01.2024.
//
#include <iostream>

using namespace std;








class Node {
public:
    int value;
    Node* left;
    Node* right;



    explicit Node(int value) : value(value), left(nullptr), right(nullptr) {}
};


struct Subtree{
    Node* node;
    Node* parent;
};

class BinarySearchTree{
private:
    Node* root;
    int countOfNodes;

    void _addTo(Node* node, int value){
        if(value < node->value ){

            if(node->left == nullptr){
                node->left = new Node(value);
                countOfNodes++;
            }else{
                _addTo(node->left, value);
            }
        }else if(value > node->value){

            if(node->right == nullptr){
                node->right = new Node(value);
                countOfNodes++;
            }else{
                _addTo(node->right, value);
            }

        }else{
            cout << "Node with given value already exist\n";
            return;
        }

    }

    bool _remove(Subtree subtree){
        Node* current = subtree.node;
        Node* parent = subtree.parent;

        //1
        if(current->right == nullptr){
            if(parent == nullptr){
                root = current->left;
            }else{
                if(parent->value > current->value){
                    parent->left = current->left;
                }else if(parent->value < current->value){
                    parent->right = current->left;
                }

            }
        }else if(current->right->left == nullptr){
            current->right->left = current->left;
            if(parent == nullptr){
                root = current->right;
            }else{
                if(parent->value > current->value){
                    parent->left = current->right;
                }else if(parent->value < current->value){
                    parent->right = current->right;
                }
            }
        }else{
            Node* leftMost = current->right->left;
            Node* leftMostParent = current->right;

            while (leftMost->left!= nullptr){
                leftMostParent = leftMost;
                leftMost = leftMost->left;
            }
            leftMostParent->left = leftMost->right;

            leftMost->left = current->left;
            leftMost->right = current->right;

            if(parent == nullptr){
                root = leftMost;
            }else{
                if(parent->value > current->value){
                    parent->left = leftMost;
                }else if(parent->value < current->value){
                    parent->right = leftMost;
                }
            }
        }
        countOfNodes--;

        return true;

    }

    Node* _search(Node* node, int value){
        if(node== nullptr || node->value == value){
            return node;
        }

        if(value < node->value){
            return _search(node->left, value);
        }else{
            return _search(node->right, value);
        }
    }

    Subtree _findNodeWithParent(int value){
        Node* current = root;
        Node* parent = nullptr;
        while(current != nullptr){

            if(current->value > value){

                parent= current;
                current = current->left;
            } else if(current->value < value){
                parent= current;
                current = current->right;
            }else{
                break;
            }
        }

        Subtree response{};
        response.parent = parent;
        response.node = current;
        return response;
    }



public:
    BinarySearchTree() : root(nullptr), countOfNodes(0) {}

    void insert(int value){
        if(root== nullptr){
            root = new Node(value);
            countOfNodes++;
            return;
        }
        _addTo(root, value);
    }

    Node* search(int value){
        return _search(root, value);
    }

    void remove(int value){
        Subtree subtree = _findNodeWithParent(value);
        if(subtree.node == nullptr){
            cout << "Node with given value dont exist\n";
            return;
        }
        _remove(subtree);

    }

    void qunatityOfNodes(){
        cout << countOfNodes << '\n';
    }
};


int main() {

    // TODO: write comments for BinarySearchTree class


    BinarySearchTree bst;

    bst.insert(50);
    bst.insert(40);
    bst.insert(80);
    bst.insert(10);
    bst.insert(46);
    bst.insert(47);
    bst.insert(45);
    bst.insert(44);
    bst.insert(42);
    bst.insert(43);

    bst.insert(80);

    bst.insert(70);

    bst.insert(90);
    bst.insert(100);

    bst.qunatityOfNodes();

    bst.remove(40);




    bst.qunatityOfNodes();
    cout << bst.search(70)->value;


    return 0;
}

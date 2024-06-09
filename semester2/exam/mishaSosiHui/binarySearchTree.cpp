//
// Created by Павло on 09.06.2024.
//
//
// Created by Павло on 15.01.2024.
//
#include <iostream>

using namespace std;

class Node {
public:
    //class for Node, could be a structure, but class

    //value of Node
    int value;

    //left child(leaf) of Node
    Node* left;

    //right child(leaf) of Node
    Node* right;


    //constructor
    explicit Node(int value) : value(value), left(nullptr), right(nullptr) {}
};


struct Subtree{
    //struct for _findNodeWithParent method of BinarySearchTree class

    //some node
    Node* node;

    //parent of this node
    Node* parent;

    //subtree of main tree, because we can reach any node that relation with parent\node
    //even if it grand grandparent of searching one
};

class BinarySearchTree{
private:
    //root of tree aka: parent or grandparent or grand grandparent or etc. of all nodes in tree
    Node* root;

    void _addTo(Node* node, int value){
        //recursive method which receive node and value(for new Node)
        //this method will recursively call himself until place for new Node is found


        if(value < node->value ){
            //checks if value of new Node is lower than value of given node
            //if it is, we should look for place for new node in the left branch of current node
            if(node->left == nullptr){
                //checking if there is place for new Node in the left branch of current node
                // if it is, we are creating new node as left child(or leaf idk honestly and english is so hard) of current node
                node->left = new Node(value);

                //increasing count of nodes in tree
            }else{
                //if there is already left child of current node, we call addTo method again and passing
                //left child of current node and same value of New node as an arguments
                _addTo(node->left, value);
            }
        }else if(value > node->value){
            //checks if value of new Node is bigger than value of given node
            //if it is, we should look for place for new node in the right branch of current node
            if(node->right == nullptr){
                //checking if there is place for new Node in the right branch of current node
                // if it is, we are creating new node as right child of current node
                node->right = new Node(value);
            }else{
                //if there is already right child of current node, we call addTo method again and passing
                //right child of current node and same value of New node as an arguments
                _addTo(node->right, value);
            }

        }else{
            //if we have node in tree with same value as given one. We are printing this and just return
            //what have u expected?
            cout << "Node with given value already exist\n";
            return;
        }

    }





public:
    //constructor
    BinarySearchTree() : root(nullptr) {}

    void insert(int value){
        // method for creating and inserting node with given value into tree
        if(root== nullptr){
            // checks if tree is empty and creating new node as a root of tree
            root = new Node(value);
            return;
        }
        //recursive method for node inserting
        _addTo(root, value);
    }


};


int main() {



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



    return 0;
}

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

    //just a quantity of nodes in tree
    int countOfNodes;

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
                countOfNodes++;
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
                countOfNodes++;
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

    bool _remove(Subtree subtree){
        // receive node for deleting as a subtree.node and parent of node for deleting as a subtree.parent
        Node* current = subtree.node;
        Node* parent = subtree.parent;

        // case 1: Node to be deleted has no right child
        if(current->right == nullptr){

            if(parent == nullptr){
                // if the parent is nullptr, the node to be deleted is the root
                root = current->left;
            }else{
                // adjust the parent's pointer to the left or right based on the node's value
                if(parent->value > current->value){
                    parent->left = current->left;
                }else if(parent->value < current->value){
                    parent->right = current->left;
                }

            }
        }
        // case 2: Node to be deleted has a right child with no left child
        else if(current->right->left == nullptr){
            current->right->left = current->left;
            if(parent == nullptr){
                // if the parent is nullptr, the node to be deleted is the root
                root = current->right;
            }else{
                // adjust the parent's pointer to the left or right based on the node's value
                if(parent->value > current->value){
                    parent->left = current->right;
                }else if(parent->value < current->value){
                    parent->right = current->right;
                }
            }
        }
        // case 3: Node to be deleted has a right child with a left child
        else{
            Node* leftMost = current->right->left;
            Node* leftMostParent = current->right;

            // find the leftmost node in the right subtree
            while (leftMost->left!= nullptr){
                leftMostParent = leftMost;
                leftMost = leftMost->left;
            }
            // remove the leftmost node from its original position
            leftMostParent->left = leftMost->right;


            // update pointers to connect the leftMost node in place of the node to be deleted
            leftMost->left = current->left;
            leftMost->right = current->right;

            if(parent == nullptr){
                // if the parent is nullptr, the node to be deleted is the root
                root = leftMost;
            }else{
                // adjust the parent's pointer to the left or right based on the node's value
                if(parent->value > current->value){
                    parent->left = leftMost;
                }else if(parent->value < current->value){
                    parent->right = leftMost;
                }
            }
        }
        // decrease the count of nodes and return true indicating successful removal
        countOfNodes--;

        return true;

    }

    Node* _search(Node* node, int value){
        //recursive method for searching node with given value
        //it receives node and value
        if(node== nullptr || node->value == value){
            //first case
            //if we reached point where there is no possible place where node that we are searching for we are returning a nullptr
            //because if there is no node with given value, we are sooner or later reach node, child of which is doesnt exist

            //second case
            //we found node with given value and we are returning it
            return node;
        }

        if(value < node->value){
            //checking if value of searched node is smaller than a value of current node
            //if so, we should check left child(leaf) of current node
            //we call _search method and passing left(leaf) child and value of searched node
            return _search(node->left, value);
        }else{
            //if value of searched node is bigger than a value of current node
            //we should check right child(leaf) of current node
            //we call _search method and passing right child(leaf) and value of searched node
            return _search(node->right, value);
        }
    }

    Subtree _findNodeWithParent(int value){
        //method for finding node with given value also returning parent of node with given value
        Node* current = root;
        Node* parent = nullptr;
        while(current != nullptr){
            //in this loop we are searching for node with given value, and also parent of this node
            if(current->value > value){
                //if value of searched node is smaller than value of current node, we should check its left child

                //saving parent of current node
                parent= current;

                //in next iteration current node will be left child(leaf) of current in this iteration
                current = current->left;
            } else if(current->value < value){
                //if value of searched node is bigger than value of current node, we should check its right child

                //saving parent of current node
                parent= current;

                //in next iteration current node will be right child(leaf) of current node in this iteration
                current = current->right;
            }else{
                //if value of searched node is equal to value of current node we should break from a loop
                //and return searched node and parent node of searched node
                break;
            }
        }

        Subtree response{};
        response.parent = parent;
        response.node = current;
        return response;
    }



public:
    //constructor
    BinarySearchTree() : root(nullptr), countOfNodes(0) {}

    void insert(int value){
        // method for creating and inserting node with given value into tree
        if(root== nullptr){
            // checks if tree is empty and creating new node as a root of tree
            root = new Node(value);
            countOfNodes++;
            return;
        }
        //recursive method for node inserting
        _addTo(root, value);
    }

    Node* search(int value){
        //calls _search method and passing root of tree and value of searched Node as an arguments
        //returns node with given value or nullptr if node doest exist in tree
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
        // printing count of Nodes(leafs) in tree
        cout << countOfNodes << '\n';
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


    bst.qunatityOfNodes();

    bst.remove(40);

    bst.qunatityOfNodes();


    cout << bst.search(70)->value;


    return 0;
}

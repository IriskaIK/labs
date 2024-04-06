//
// Created by Павло on 06.04.2024.
//
#include <iostream>
#include <vector>

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

struct NodeWithDepth{
    Node* node;

    int depth;
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

    Node* _searchWithDepth(Node* node, int value, int* depth){
        if(node== nullptr || node->value == value){
            (*depth)++;
            return node;
        }

        if(value < node->value){
            (*depth)++;

            return _searchWithDepth(node->left, value, depth);
        }else{
            (*depth)++;

            return _searchWithDepth(node->right, value, depth);
        }

    }

    int _findDepthOfTree(Node* node){

        if(node == nullptr){
            return 0;
        }
        int left_depth = _findDepthOfTree(node->left);
        int right_depth = _findDepthOfTree(node->right);

        if(left_depth>right_depth){
            return left_depth + 1;
        }
        return right_depth + 1;

    }

    vector<Node> _findNodesOfGivenDepth(Node* node, int depth, int current_depth){
        vector<Node> result;

        if(node == nullptr){
            return result;
        }
        if(current_depth == depth){
            result.push_back(*node);
        }else{
            vector<Node> left_nodes = _findNodesOfGivenDepth(node->left, depth, current_depth + 1);
            vector<Node> right_nodes = _findNodesOfGivenDepth(node->right, depth, current_depth + 1);
            result.insert(result.end(), left_nodes.begin(), left_nodes.end());
            result.insert(result.end(), right_nodes.begin(), right_nodes.end());
        }
        return result;
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

    NodeWithDepth* findNodeWithDepth(int value){
        NodeWithDepth* node = new NodeWithDepth();
        int depth = 0;

        node->node = _searchWithDepth(root, value, &depth);
        node->depth = depth;

        return node;
    }

    int findDepthOfTree(){
        return _findDepthOfTree(root);
        // recursive



    }

    vector<Node> findNodesWithGivenDepth(int depth){
        return _findNodesOfGivenDepth(root, depth, 1);

    }

    Node* search(int value){
        //calls _search method and passing root of tree and value of searched Node as an arguments
        //returns node with given value or nullptr if node doest exist in tree
        return _search(root, value);
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


    // task 1
    NodeWithDepth* node1 = bst.findNodeWithDepth(46);
    cout << "Depth: " << node1->depth << ";\n";

    // task 2
    cout << "Depth of tree: " << bst.findDepthOfTree() << ";\n";

    // task 3
    vector<Node> nodes = bst.findNodesWithGivenDepth(3);
    for (Node node : nodes) {
        std::cout << node.value << " ";
    }



    return 0;
}
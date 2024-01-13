//
// Created by Павло on 13.01.2024.
//
#include <iostream>
#include <string>

using namespace std;

// Node class for linked list
class Node {
public:
    string key;
    string value;
    Node* next;

    // Constructor to initialize a node with key and value
    // use 'const string& k' instead of 'string k' for efficiency
    Node(const string& k, const string& v) : key(k), value(v), next(nullptr) {}
};

// Linked list class
class LinkedList {
private:
    Node* head;

public:
    // Constructor to initialize an empty linked list
    LinkedList() : head(nullptr) {}

    // Insert a key-value pair into the linked list
    void insert(const string& key, const string& value) {
        Node* newNode = new Node(key, value);
        newNode->next = head;
        head = newNode;
    }

    void displayListValues(){
        if(head == nullptr){
            cout << "list is empty\n";
            return;
        }
        Node* item = head;
        while (item != nullptr){
            cout << item->value << '\n';
            item = item->next;

        }

    }

    void displatListKeyValuePairs(){
        if(head == nullptr){
            cout << "Its empty\n";
            return;
        }
        Node* item = head;
        while (item!= nullptr){
            cout << "Key: " << item->key << " Value: " << item->value << '\n';
            item = item->next;
        }
    }

    // Search for a key in the linked list and return its value
    string search(const string& key) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return "Not found"; // Key not found
    }


};

// Hash table class
class HashTable {
private:
    // Bigger size = fewer collisions; also it should be a prime number in order to reduce possible collisions
    static const int tableSize = 97;
    LinkedList table[tableSize];

    // Hash function to convert a string key into an index
    // prime number is used for reducing possible collisions
    // more about it here https://cs.stackexchange.com/questions/11029/why-is-it-best-to-use-a-prime-number-as-a-mod-in-a-hashing-function
    static int hashFunction(const string& key) {
        const int prime = 31; // A commonly used prime number
        int hash = 0;
        for (char c : key) {
            hash = (hash * prime) + c;
        }
        return hash % tableSize;
    }


public:
    // Insert a key-value pair into the hash table
    void insert(const string& key, const string& value) {
        int index = hashFunction(key);

        table[index].insert(key, value);
    }

    void displayOneListByIndex(int index){
        if(index > tableSize-1){
            cout << "Index is bigger than max table size\n";
            return;
        }
        cout << "----------------------\n";
        cout << "Items of list at " << index << " index:\n";
        table[index].displayListValues();
        cout << "----------------------\n";
    }



    void displayTable(){
        for(int i = 0; i < tableSize; i++){
            cout << "----------------------\n";
            cout<<"At " << i << " index:\n";
            table[i].displatListKeyValuePairs();
            cout << "----------------------\n";
        }
    }

    // Search for a key in the hash table and return its value
    string search(const string& key) const {
        int index = hashFunction(key);
        return table[index].search(key);
    }
};

int main() {
    HashTable hashTable;

    // inserting key-value pairs
    hashTable.insert("Anna", "Red");
    hashTable.insert("Tom", "Green");
    hashTable.insert("Oleg", "Black");
    hashTable.insert("Vova", "Orange");
    hashTable.insert("Elena", "Blue");
    hashTable.insert("Alex", "Yellow");
    hashTable.insert("Sophia", "Purple");
    hashTable.insert("Dmitri", "Pink");
    hashTable.insert("Lily", "Brown");
    hashTable.insert("Max", "White");
    hashTable.insert("Nina", "Gray");
    hashTable.insert("Igor", "Cyan");
    hashTable.insert("Olga", "Magenta");
    hashTable.insert("Peter", "Lime");
    hashTable.insert("Yana", "Teal");
    hashTable.insert("Fedor", "Indigo");
    hashTable.insert("Marina", "Violet");

    // displaying elements at given index
    hashTable.displayOneListByIndex(96);

    // searching for values
    cout << "Value for 'Anna': " << hashTable.search("Anna") << '\n';
    cout << "Value for 'Tom': " << hashTable.search("Tom") << '\n';
    cout << "Value for 'Vova': " << hashTable.search("Vova") << '\n';
    cout << "Value for 'Sonya': " << hashTable.search("Sonya") << '\n';

    // displaying whole table
    hashTable.displayTable();
    return 0;
}



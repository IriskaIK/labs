#include <iostream>

using namespace std;

const int SIZE = 100;


//explanation here https://www.youtube.com/watch?v=t0Cq6tVNRBA&t=484


class MaxHeap {
private:
    int heap[SIZE]{};
    int size;

    // Returns the index of the parent of the element at index i
    int parent(int i) {
        return (i - 1) / 2;
    }

    // Returns the index of the left child of the element at index i
    int leftChild(int i) {
        return 2 * i + 1;
    }

    // Returns the index of the right child of the element at index i
    int rightChild(int i) {
        return 2 * i + 2;
    }

    // Just a swap
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }

    // Maintains the max heap property by swapping the element with its parent
    void heapifyUp(int i) {
        while (i > 0 && heap[i] > heap[parent(i)]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // Maintains the max heap property by swapping the element with its maximum child
    void heapifyDown(int i) {
        int indexOfMaxElement = i;
        int leftChildOfMaxElement = leftChild(i);
        int rightChildOfMaxElement = rightChild(i);

        // Finding the index of the maximum child
        // Checking if left child is bigger than current MaxElement
        // checking if childrens exist
        if (leftChildOfMaxElement < size && heap[leftChildOfMaxElement] > heap[indexOfMaxElement]) {
            //if so, make left children a MaxElement
            indexOfMaxElement = leftChildOfMaxElement;
        }

        // Finding the index of the maximum child
        // Checking if left child is bigger than current MaxElement
        // Checking if childrens exist
        if (rightChildOfMaxElement < size && heap[rightChildOfMaxElement] > heap[indexOfMaxElement]) {
            //if so, make right children a MaxElement
            indexOfMaxElement = rightChildOfMaxElement;
        }

        // If the current element is not the maximum, swap with the maximum child
        if (i != indexOfMaxElement) {
            swap(heap[i], heap[indexOfMaxElement]);
            // Recursively call heapifyDown passing nex MaxElement as a argument
            heapifyDown(indexOfMaxElement);
        }
    }

public:
    MaxHeap() : size(0) {}

    // Inserts a new element into the max heap and maintains the max heap property
    void insert(int value) {
        if (size == SIZE) {
            cout << "Heap is full" << '\n';
            return;
        }

        // Increment the size and add the new element at the last position
        size++;
        heap[size - 1] = value;
        // Maintain the max heap property
        heapifyUp(size - 1);
    }

    // Get the maximum element from the max heap and maintains the max heap property
    int getMax() {
        if (size <= 0) {
            cout << "Heap is empty" << '\n';
            return -1;
        }

        // Store the maximum value to be returned
        int valueOfMaxElement = heap[0];

        // Replace the root with the last element
        heap[0] = heap[size - 1];

        // Decrement the size
        size--;

        // Maintain the max heap property
        heapifyDown(0);

        return valueOfMaxElement;
    }

    // Prints the elements of the max heap
    void printHeap() {
        cout << "Max Heap: ";
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << '\n';
    }
};

int main() {

    MaxHeap maxHeap;

    maxHeap.insert(12);
    maxHeap.insert(30);
    maxHeap.insert(15);
    maxHeap.insert(45);

    maxHeap.printHeap();

    cout << "Max element: " << maxHeap.getMax() << '\n';

    maxHeap.printHeap();

    return 0;
}

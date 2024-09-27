#include <iostream>
using namespace std;
#include "array/stack/array_stack.h"
#include "linkedList/stack/linkedList_stack.h"
#include "array/queue/array_queue.h"
#include "linkedList/queue/linkedList_queue.h"
#include "array/deque//array_deque.h"
#include "linkedList/deque/linkedList_deque.h"

int main() {
    // Array-based stack
    ArrayStack<int> arrayStack;
    arrayStack.push(10);
    arrayStack.push(20);
    cout << "ArrayStack Top: " << arrayStack.peek() << endl;
    cout << "ArrayStack Popped: " << arrayStack.pop() << endl;

    // Linked list-based stack
    LinkedListStack<int> linkedListStack;
    linkedListStack.push(30);
    linkedListStack.push(40);
    cout << "LinkedListStack Top: " << linkedListStack.peek() << endl;
    cout << "LinkedListStack Popped: " << linkedListStack.pop() << endl;





    // Array-based queue
    ArrayQueue<int> arrayQueue;
    arrayQueue.enqueue(10);
    arrayQueue.enqueue(20);
    std::cout << "ArrayQueue Front: " << arrayQueue.front() << std::endl;
    std::cout << "ArrayQueue Dequeued: " << arrayQueue.dequeue() << std::endl;

    // Linked list-based queue
    LinkedListQueue<int> linkedListQueue;
    linkedListQueue.enqueue(30);
    linkedListQueue.enqueue(40);
    std::cout << "LinkedListQueue Front: " << linkedListQueue.front() << std::endl;
    std::cout << "LinkedListQueue Dequeued: " << linkedListQueue.dequeue() << std::endl;






    // Array-based deque
    ArrayDeque<int> arrayDeque;
    arrayDeque.pushFront(10);
    arrayDeque.pushBack(20);
    std::cout << "ArrayDeque Front: " << arrayDeque.front() << std::endl;
    std::cout << "ArrayDeque Back: " << arrayDeque.back() << std::endl;
    std::cout << "ArrayDeque Popped Front: " << arrayDeque.popFront() << std::endl;

    // Linked list-based deque
    LinkedListDeque<int> linkedListDeque;
    linkedListDeque.pushFront(30);
    linkedListDeque.pushBack(40);
    std::cout << "LinkedListDeque Front: " << linkedListDeque.front() << std::endl;
    std::cout << "LinkedListDeque Back: " << linkedListDeque.back() << std::endl;
    std::cout << "LinkedListDeque Popped Back: " << linkedListDeque.popBack() << std::endl;


    return 0;
}
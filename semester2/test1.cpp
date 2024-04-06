#include <iostream>
#include <vector>
#include <limits>
#include <random>
#include <chrono>

struct Node{
    int value;
    Node* prev;
    Node* next;
    bool deleted;

    Node(int value, Node* prev = nullptr, Node* next = nullptr, bool deleted = false): value(value), prev(prev), next(next), deleted(deleted) { }
};
struct LinkedList {
    Node* start;
    Node* end;

    LinkedList(Node* start = nullptr, Node* end = nullptr): start(start), end(end) {}
};
void listPrint(Node* start, Node* end)
{
    Node *current = start;
    if(current == nullptr){
        std::cout << "list is empty" << std::endl;
    }
    else {
        do {
            std::cout << current->value << " ";
            current = current->next;
        }while(current!=start);
        std::cout << std::endl;
    }
}
void addElement(LinkedList& list, int value){
    Node* new_node = new Node(value, list.end);
    (list.start== nullptr)?(list.start = new_node):(list.end->next = new_node);
    list.end = new_node;
    list.start->prev=list.end;
    list.end->next=list.start;
}
void task(Node* start, std::vector<int> step, const int& type, int add, int N) {
    Node *current = start;
    int i = 0, j = 0, k = 0;
    while (k<=N) {
        if(!current->deleted) {
            if (i == step[j]) {
                current->deleted=true;
                k++;
                switch (type) {
                    case 1:
                        std::cout << current->value << " ";
                        break;
                    case 2:
                        if (current->value == add) {
                            std::cout << k << std::endl;
                        }
                        break;
                    case 3:
                        if (N - k == add) {
                            std::cout << current->value << std::endl;
                        }
                        break;
                    default:
                        break;
                }
                i = 0;
                (j == step.size() - 1) ? (j = 0) : (j++);
            } else {
                i++;
            }
        }
        current = current->next;
    }
    for(int m=0; m<N; m++){
        current->deleted=false;
        current=current->next;
    }
    /*if (type == 1 || (type == 3 && add == 0)) {
        std::cout << current->value << std::endl;
    } else if (type == 2 && add == current->value) {
        std::cout << ++k << std::endl;
    }*/
}
void interactive(LinkedList& list){
    int N;
    do {
        std::cout << "enter a number of elements" << std::endl;
        std::cin >> N;
        if(std::cin.fail()){
            return ;
        }
    }while(N<1);
    for(int i=1; i<=N; i++){
        addElement(list, i);
    }
    std::cout << "your list contain next elements" << std::endl;
    listPrint(list.start, list.end);
    std::vector<int> KK;
    int step;
    while(true){
        std::cout << "enter a step (if it is the end, enter a symbol)" << std::endl;
        std::cin >> step;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        else{
            KK.push_back(step);
        }
    }
    int choose, add;
    std::cout << "choose what to print: 1 - list of elements in order of deleting; 2 - which in order was an element; 3 - which element was deleted in a number from the end" << std::endl;
    std::cin >> choose;
    if(std::cin.fail()){
        return ;
    }
    switch (choose) {
        case 2:
            std::cout << "enter an element" << std::endl;
            std::cin >> add;
            if(std::cin.fail() || add>N){
                return ;
            }
            break;
        case 3:
            std::cout << "enter a number of order position from the end" << std::endl;
            std::cin >> add;
            if(std::cin.fail() || add>=N){
                return ;
            }
            break;
        default:
            break;
    }
    task(list.start, KK, choose, add, N);
}
void demo(LinkedList& list){
    std::cout << "let's have an array with 10 elements" << std::endl;
    for(int i=1; i<=10; i++){
        addElement(list, i);
    }
    std::cout << "the array with rule for deleting is [2, 5, 7]" << std::endl;
    std::vector<int> KK = {2,5,7};
    std::cout << "elements in order of deleting" << std::endl;
    task(list.start, KK, 1, 0, 10);
    std::cout << "number 4 has an index of deleting" << std::endl;

    //listPrint(list.start, list.end);
    task(list.start, KK, 2, 4, 10);
    std::cout << "the third element from the end of the order of deleting" << std::endl;
    task(list.start, KK, 3, 3, 10);
}
//void benchmark(){
//    std::random_device rd;
//    std::mt19937 mersenne(rd());
//    using std::chrono::high_resolution_clock;
//    using std::chrono::duration_cast;
//    using std::chrono::duration;
//    using std::chrono::milliseconds;
//    int N=100, N1;
//    bool isEnd;
//    std::vector<int> KK = {2,5,7, 15, 25};
//    do {
//        LinkedList list;
//        auto t0 = high_resolution_clock::now();
//        for (int i = 0; i < N; i++) {
//            addElement(list, i);
//        }
//        auto t1 = high_resolution_clock::now();
//        task(list.start, KK, 1, 0, N);
//        auto t2 = high_resolution_clock::now();
//        task(list.start, KK, 2, rand()%N+1, N);
//        auto t3 = high_resolution_clock::now();
//        task(list.start, KK, 3, rand()%N+1, N);
//        auto t4 = high_resolution_clock::now();
//        duration<double, std::milli> ms_double0 = t1 - t0;
//        duration<double, std::milli> ms_double1 = t2 - t1;
//        duration<double, std::milli> ms_double2 = t3 - t2;
//        duration<double, std::milli> ms_double3 = t4 - t3;
//        duration<double, std::milli> ms_double = t4 - t0;
//        std::cout << "for " << N << " elements the list, time for adding elements is " << ms_double0.count() << "ms; time of deleting and printing all elements in the order of deleting " << ms_double1.count() << "ms; time of deleting and printing an index of deleting an element " << ms_double2 << "ms; time of deleting and printing an element with index of deleting from the end " << ms_double3 << "ms; at all " << ms_double << std::endl;
//        isEnd = ms_double.count() < 1500.0;
//        if (ms_double.count() < 1000.0) {
//            N *= 2;
//            N1 = N;
//        } else {
//            N += N1;
//        }
//    } while (isEnd);
//}
int main(){
    LinkedList list;
    int mode;
    std::cout << "Choose the mode: 1 - interactive; 2 - demonstration; 3 - benchmark" << std::endl;
    std::cin >> mode;
    switch (mode) {
        case 1:
            interactive(list);
            break;
        case 2:
            demo(list);
            break;
        case 3:
//            benchmark();
            break;
        default:
            std::cout << "error";
            break;
    }
    return 0;
}
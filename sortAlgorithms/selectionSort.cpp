//
// Created by Павло on 31.01.2024.
//
#include <iostream>
#include <chrono>
#include <cstdlib>  // for rand()

using namespace std;


int* generateArray(int size) {
    // Check if size is valid
    if (size <= 0) {
        cout << "Invalid array size.\n";
        return nullptr;
    }

    int* array = new int[size];

    // Fill the array with random numbers
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % (2 * size);
    }

    return array;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;

        // Find the index of the minimum element in the part of array after min index
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with minIndex
        swap(arr[i], arr[minIndex]);
    }
}


void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';
}


int main(){
    // some shit to measure time. Do not pay attention to this
    // Took it from here https://stackoverflow.com/questions/22387586/measuring-execution-time-of-a-function-in-c
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    //create randomized array. Do not pay attention to this
    srand(static_cast<unsigned>(time(nullptr)));
    int size = 20000;
    int* arr = generateArray(size);

//    displayArray(arr, size);

    auto t1 = high_resolution_clock::now();
    selectionSort(arr, size);
    auto t2 = high_resolution_clock::now();

    duration<double, std::milli> ms_double = t2 - t1;
    cout << ms_double.count() << "ms\n";

//    displayArray(arr, size);
    return 0;
}
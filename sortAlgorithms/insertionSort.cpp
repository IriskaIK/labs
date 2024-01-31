//
// Created by Павло on 31.01.2024.
//
#include <iostream>
#include <chrono>
#include <cstdlib>  // for rand()


using namespace std;


// Function to generate random array
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

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;


        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;

    }
}





int main(){
    // some shit to measure time.
    // Took it from here https://stackoverflow.com/questions/22387586/measuring-execution-time-of-a-function-in-c
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    //some shit to create randomized array
    srand(static_cast<unsigned>(time(nullptr)));
    int size = 20000;
    int* arr = generateArray(size);




//    displayArray(arr, size);

    auto t1 = high_resolution_clock::now();
    insertionSort(arr, size);
    auto t2 = high_resolution_clock::now();

    duration<double, std::milli> ms_double = t2 - t1;
    cout << ms_double.count() << "ms\n";

//    displayArray(arr, size);
    return 0;
}
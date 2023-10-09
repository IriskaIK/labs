#include <iostream>
#include <cmath>
using namespace std;




int* transformNumToArray(long number){
    int* arr = new int[50];
    int i = 0;
    while (number != 0){
        arr[i+1] = number % 10;
        number = number / 10;
        i++;
    }
    arr[0] = i;

    return arr;
};

bool checkIfNumIsPalindrome(int arr[]){
    bool isPalindrome = true;
    int halfOfLength = arr[0] / 2;
    if(arr[0]%2 != 0){
        halfOfLength++;
    }
    for(int i = 0; i < halfOfLength; i++){
        if(arr[i+1] != arr[arr[0]-i]){
            isPalindrome = false;
            break;
        }
    }
    return isPalindrome;
}


int main(){


    long num;
    cout << "Enter number:" << '\n';
    cin >> num;
    int* arrayOfNum = transformNumToArray(num);
    if(checkIfNumIsPalindrome(arrayOfNum)){
        cout << "It is a palindrome";
    }else{
        cout << "It isn't a palindrome";
    }

    return 0;



}
#include <iostream>
using namespace std;

int* transformStringNumToArray(string number){
    int* arr = new int[256];

    // Initialize the array elements to zero
    // TODO: find way to initialize each element as 0 without loop
    for (int i = 0; i < 256; i++) {
        arr[i] = 0;
    }

    arr[0] = number.length();

    for (int i = 0; i < arr[0]; i++) {
        arr[arr[0] - i] = number[i] - '0';
    }

    return arr;
};

int* findLargestNumber(int* arr1, int* arr2){

    int lengthOfFirstNum = arr1[0];
    int lengthOfSecondNum = arr2[0];
    if (lengthOfFirstNum == lengthOfSecondNum) {
        // Compare the arrays
        for (int i = lengthOfFirstNum; i > 0; i--) {
            if (arr1[i] > arr2[i]) {
                return arr1;
            } else if (arr2[i] > arr1[i]) {
                return arr2;
            }
        }
        // If both arrays are equal, return any of them (they are the same)
        return arr1;
    } else if (lengthOfFirstNum > lengthOfSecondNum) {
        return arr1;
    } else {
        return arr2;
    }

};

int findMaxInteger(int num1, int num2){
    if(num2 == num1){
        return num2;
    }else if(num1 > num2){
        return num1;
    }else{
        return num2;
    }
}
int* sumOfNums(int *arr1, int *arr2){

    int* answer = new int[256];
    for (int i = 0; i < 256; i++) {
        answer[i] = 0;
    }

    int lengthOfFirstNum = arr1[0];
    int lengthOfSecondNum = arr2[0];
    int maxLength = findMaxInteger(lengthOfFirstNum, lengthOfSecondNum);

    int lengthNew = 0;

    for(int i = 1; i <= maxLength; i++){
        if(arr1[i]+arr2[i]+answer[i] > 10){
            answer[i+1] += 1;
            answer[i] = (arr1[i]+arr2[i]+answer[i])%10;
        }else if(arr1[i]+arr2[i]+answer[i] == 10){
            answer[i+1] += 1;
            answer[i] = 0;
        }else{
            answer[i] = (arr1[i]+arr2[i]+answer[i])%10;
        }
        lengthNew++;
        if(i==lengthOfFirstNum && answer[i+1]!=0){
            lengthNew++;
        }
    }
    answer[0] = lengthNew;
    return answer;


};


void showNumber(int* number){
    for (int i = number[0]; i > 0; i--)
        cout << number[i];
    cout << '\n';
};





int main(){
    string str1, str2;
    cout << "enter FIRST number:  ";
    cin >> str1;
    cout << "enter SECOND number:  ";
    cin >> str2;

    int *num1 = transformStringNumToArray(str1);
    int *num2 = transformStringNumToArray(str2);

    cout << "first number is: ";
    showNumber(num1);

    cout <<endl<<  "second number is: ";
    showNumber(num2);



    int* answer = findLargestNumber(num1, num2);

    cout <<endl<<  "the biggest number is: ";
    showNumber(answer);

    answer = sumOfNums(num1, num2);
    cout <<endl<<  "the sum of numbers is: ";
    showNumber(answer);


}
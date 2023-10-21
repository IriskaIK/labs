#include <iostream>
using namespace std;


bool TriangeExistance(float a, float b, float c){
    if(a + b <= c){
        cout << "triangle does not exist";
        return false;
    }
    if(a + c <= b){
        cout << "triangle does not exist";
        return false;

    }
    if(b + c <= a){
        cout << "triangle does not exist";
        return false;
    }
    return true;
}

void checkTriangleType(float a, float b, float c){
    float a_squared = a*a;
    float b_squared = b*b;
    float c_squared = c*c;
    if(a_squared + b_squared == c_squared || a_squared + c_squared == b_squared || b_squared + c_squared == a_squared){
        cout << "This is a right triangle.";
        return;
    }
    if(a_squared + b_squared > c_squared || a_squared + c_squared > b_squared || b_squared + c_squared > a_squared){
        cout << "This is an acute triangle.";
        return;
    }else{
        cout << "This is an obtuse triangle.";
        return;
    }
}


int main(){

    float a, b, c;
    cout << "a program for calculating the existence of a triangle with given sides (a, b, c) and determining its type (obtuse, right, acute)\n";

    cout << "Enter 'a' side\n";
    cin >> a;
    cout << "Enter 'b' side\n";
    cin >> b;
    cout << "Enter 'c' side\n";
    cin >> c;



    sadas

    if(!TriangeExistance(a, b, c)){
        return 0;
    }

    checkTriangleType(a, b, c);

    return 0;




}
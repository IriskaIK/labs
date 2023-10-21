#include <iostream>
#include <cmath>
using namespace std;


int main(){

    float a, b, c;
    cout << "program for calculating quadratic equations of the type ax^2 + bx + c = 0\n";
    cout << "Enter 'a' coefficient\n";
    cin >> a;

    if(a == 0){
        cout << "It isn`t quadratic equations";
        return 0;
    }

    cout << "Enter 'b' coefficient\n";
    cin >> b;
    cout << "Enter 'c' coefficient\n";
    cin >> c;

    float D = (b*b) - (4*a*c);

    if(D < 0){
        cout << "There are no real roots of the equation";
        return 0;
    };
    float dsqrt = sqrt(D);
    cout << "\nSqrt of discriminant: " << dsqrt;

    float x1, x2;
    x1 = (-b - dsqrt) / (2 * a);
    if(dsqrt != 0){
        x2 = (-b + dsqrt) / (2 * a);
        cout <<"\nFirst root: "<< x1 << "\nSecond root: " << x2;
        return 0;
    }
    cout << "Root: " << x1;

    return 0;



}
//
// Created by Pavel on 20.10.2023.
//

#include <iostream>
#include <cmath>
using namespace std;


void block1Task11(double x, double y, double z){
    if(x<0){
        cout << "No answers in real numbers";
        return;
    }
    double sqrtOfX = sqrt(x);
    if(4 - sqrtOfX == 0){
        cout << "No answers in real numbers";
        return;
    }
    if(fabs(y-x) - sqrtOfX == 0){
        cout << "No answers in real numbers";
        return;
    }
    if(y-z <= 0){
        cout << "No answers in real numbers";
        return;
    }
    double eulerNumber = exp(1);
    double a = (x + y/(4-sqrtOfX))/(fabs(y-x) - sqrtOfX);
    double b = pow(eulerNumber, x-1) + log(y-z);
    cout << "\nBlock 1 Task 11";
    cout << "\nA: " << a;
    cout << "\nB: " << b;

};


void block2Task6(double a, double b, double h, int n){
    cout << "\n\nBlock 2 Task 6";
    if(b<a){
        cout << "Invalid input!";
        return;
    }

    double x;
    double eulerNumber = exp(1);

    for (x = a; x <= b; x += h){
        double factorial = 1; // int, but for better precision in dividing it should be double
        double sum = 0;

        for(int k = 0; k<=n; k++){
            if(k!=0){
                factorial *= k;
            }
            sum += (((2*k)+1)/factorial)*pow(x, 2*k);
        }


        double xSqr = pow(x, 2);
        double y = (1+(2*xSqr))*pow(eulerNumber, xSqr);

        cout << "\nS: " << sum << "  Y: " << y;
    }
}



void block2Task1(double a, double b, double h, int n){
    cout << "\n\nBlock 2 Task 1";
    if(b<a){
        cout << "Invalid input!";
        return;
    }

    double x;

    for (x = a; x <= b; x += h){
        double factorial = 1; // int, but for better precision in dividing it should be double
        double sum = 0;

        for(int k = 0; k<=n; k++){
            if(k!=0){
                factorial = factorial * (k*2) * ((k*2)+1);
            }
            sum += pow(-1, k) * (pow(x, (2*k)+1)/factorial);
        }


        double y = sin(x);

        cout << "\nS: " << sum << "  Y: " << y;
    }
}


int main(){
//    double x, y, z;
//    cout << "Enter variables(x, y, z) for first block\n";
//    cout << "\nEnter x:\n";
//    cin >> x;
//    cout << "\nEnter y:\n";
//    cin >> y;
//    cout << "\nEnter z:\n";
//    cin >> z;
//
//
//
//    block1Task11(x, y, z);



    double a, b, h;
    int n;
    cout << "\nEnter variables(a,b,h,n) for second block\n";
    cout << "\nEnter a:\n";
    cin >> a;
    cout << "\nEnter b:\n";
    cin >> b;
    cout << "\nEnter h:\n";
    cin >> h;
    cout << "\nEnter n(integer):\n";
    cin >> n;


    double x;

    for(x=a; x<b; x+=h){

        double sum = 0;
        double factorial = 1;




        for(double k=0; k<n; k++){

            if(k!=0){
                factorial *= k;
            }
//            double factorial = 1;
//            for(int i = 0; i <= k; i++){
//                if(i!=0){
//                    factorial *= i;
//                }
//            }

            sum += (  ((2*k) + 1) / factorial   )     *   pow(x, 2*k);

        }
        double eulerNumber = exp(1);

        double y = 0;
        double first_part = 1+ (2* pow(x,2));
        double sqrX = pow(x, 2);
        double second_part = pow(eulerNumber, sqrX);

        y = first_part * second_part;

        cout << "S(x)=" << sum << ";Y(x)=" << y << '\n';


    }



//    block2Task1(a, b, h, n);
//    block2Task6(a, b, h, n);



    return 0;
}
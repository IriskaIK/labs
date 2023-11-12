//
// Created by Павло on 29.10.2023.
//
// exam paper 12



#include <iostream>
#include <math.h>
using namespace std;


void rearrangeArray(int array[], int arrayLength, int elementId){
    int temp = array[elementId];
    for(int i = elementId; i < arrayLength-1; i++){
        array[i] = array[i+1];
    }
    array[arrayLength - 1] = temp;

}

void task1(int numArray[], int arrayLength){
    cout << "\nTask 1:";
    int countOfRearrangements = 0;

    for (int i = 0; i < arrayLength - countOfRearrangements;) {
        if(numArray[i] < 0){
            rearrangeArray(numArray, arrayLength, i);
            countOfRearrangements++;
        }else{
            i++;
        }

    }

    cout << '\n';
    for(int i = 0; i < arrayLength; i++){
        cout << numArray[i] << ' ';
    }
};

void task2(char cstring[], int cstringLen){
    int sum = cstring[0] - '0';

    for(int i = 1; i < cstringLen;){

        if(cstring[i] == '+'){
            sum+= cstring[i+1] - '0';
        }else{
            sum-= cstring[i+1] - '0';
        }
        i = i+2;
    }

    cout << "\nTask 2:\n" << sum;

}

struct point{
    float x, y;

    float distance(point point){
        float d = sqrt ( (x - point.x)*(x - point.x) + ((y - point.y)*(y - point.y)) );
        return d;
    }
};

struct triangle{
    point p1, p2, p3;
    float perimeter(){
        float ptr = p1.distance(p2) + p2.distance(p3) + p3.distance(p1);
        return ptr;
    };
};



void task3(point points[], int quantityOfPoints){
    float bestPerimeter = 0;
    triangle bestTriangle;
    triangle triangle;

    for(int i = 0; i < quantityOfPoints-2; i++)
        //first point
        for (int j = i+1; j < quantityOfPoints-1; j++)
            //second point
            for(int k = j+1; k < quantityOfPoints; k++){
                //third point

                triangle.p1 = points[i];
                triangle.p2 = points[j];
                triangle.p3 = points[k];
                float currentPerimeter = triangle.perimeter();
                if(currentPerimeter > bestPerimeter){
                    bestTriangle.p1 = points[i];
                    bestTriangle.p2 = points[j];
                    bestTriangle.p3 = points[k];
                    bestPerimeter = currentPerimeter;
                }

            }


    cout << "\nTask 3:\n";
    cout << "Perimeter: " << bestTriangle.perimeter() << '\n';
    cout << "x1 = " << bestTriangle.p1.x << "   y1 = " << bestTriangle.p1.y << '\n';
    cout << "x2 = " << bestTriangle.p2.x << "   y2 = " << bestTriangle.p2.y << '\n';
    cout << "x3 = " << bestTriangle.p3.x << "   y3 = " << bestTriangle.p3.y << '\n';


}



int main(){
    //task 1
    int numArray[] = {-1, -7, 2, 3, 4, 5, -5};
    int numArrayLen = 7;
    task1(numArray, numArrayLen);
    //task 2
    char charArray[] = {'4', '+', '7', '-', '2', '-', '8'};
    int charArrayLen = 7;
    task2(charArray, charArrayLen);

    //task 3
    int quantityOfPoints = 5;
    point points[quantityOfPoints];

    points[0].x = 0; points[0].y = 0;
    points[1].x = 1; points[1].y = 100;
    points[2].x = 2; points[2].y = 2;
    points[3].x = 100; points[3].y = 100;
    points[4].x = -5; points[4].y = 0;

    task3(points, quantityOfPoints);


    return 0;
}


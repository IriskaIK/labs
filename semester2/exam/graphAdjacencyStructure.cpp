//
// Created by Павло on 03.06.2024.
//

#include <iostream>
using namespace std;

const int rows = 4;
const int cols = 4;

class GraphNode {
public:
    int index; // index of matrix column
    GraphNode* next; // pointer to next element in the same row
    explicit GraphNode( int index) : index(index), next(nullptr) {}
};

class Graph {
    //adjacencyStructure
public:
    GraphNode* arr[4] = {nullptr};

    void convertMatrix(int matrix[rows][cols]){
        for(int row = 0; row < rows; row++){
            GraphNode* lastNodeInRow = arr[row];
            for(int col = 0; col < cols; col++){
                if(matrix[row][col] != 0){
                    GraphNode* newNode = new GraphNode(col);
                    if(arr[row] == nullptr){
                        arr[row] = newNode;
                    }else{
                        lastNodeInRow->next = newNode;
                    }
                    lastNodeInRow = newNode;

                }

            }
        }
    }

    void print(){
        for (int row = 0; row < rows; row++){
            cout << "node " << row+1 << " connected to: ";
            GraphNode* current = arr[row];
            while (current){
                cout << "(node: " << current->index+1 << "); ";
                current = current->next;
            }
            cout << "\n";
        }
    }



    void findVerticesAtDistanceUtil(int current, int currentDistance, int distance, int* result, int& resultCount, bool* visited){
        if (currentDistance == distance){
            result[resultCount++] = current + 1; // store 1-based index
            visited[current] = true;
            return;
        }

        visited[current] = true;
        GraphNode* neighbor = arr[current];
        while (neighbor){
            if (!visited[neighbor->index]){
                findVerticesAtDistanceUtil(neighbor->index, currentDistance + 1, distance, result, resultCount, visited);
            }
            neighbor = neighbor->next;
        }
        visited[current] = false; // backtrack to allow other paths
    }

    void findVerticesAtDistance(int startVertex, int distance, int* result, int& resultCount){
        if (distance < 0 || startVertex < 0 || startVertex >= rows)
            return;

        bool visited[rows] = {false};
        resultCount = 0;
        findVerticesAtDistanceUtil(startVertex, 0, distance, result, resultCount, visited);
    }
};


void deleteSelfLoops(GraphNode* graphArr[]){
    for (int row = 0; row < rows; row++) {
        GraphNode* current = graphArr[row];
        GraphNode* prev = nullptr;
        while (current) {
            if (current->index == row) { // self-loop found
                if (prev == nullptr) { // loop is the first node in the row
                    graphArr[row] = current->next;
                } else {
                    prev->next = current->next;
                }
                GraphNode* temp = current;
                current = current->next;
                delete temp;
            } else {
                prev = current;
                current = current->next;
            }
        }
    }
}

int main(){

    Graph graph;
    int matrixOfGraph[rows][cols]= {
            {0, 1, 1, 0},
            {1, 0, 0, 1},
            {1, 0, 0, 1},
            {0, 1, 1, 0},
    };
    graph.convertMatrix(matrixOfGraph);
    graph.print();

}
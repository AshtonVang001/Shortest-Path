#include "array.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

Array2d::Array2d() {
    size = 0;
    sideLength = 0;
}

Array2d::Array2d(int s) {
    size = s;
    sideLength = sqrt(size);
    arr = new double*[s];
    for (int i = 0; i < sideLength; i++) {
        arr[i] = new double[sideLength];
        for (int j = 0; j < sideLength; j++) 
            arr[i][j] = 0;
    }
}

Array2d::~Array2d() {
    if (arr) {
        for (int i = 0; i < sideLength; i++) {
            if (arr[i]) {
                delete[] arr[i];
            }
        }
        delete[] arr;
    }
}

int Array2d::GetSideLength() {
    return sideLength;
}

void Array2d::PrintArray2d() {
    for (int i = 0; i < sideLength; i++) {
        for (int j = 0; j < sideLength; j++) {
                cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void Array2d::MakeRandomArray() {
    srand(time(NULL));
    for (int i = 0; i < sideLength; i++) {
        for (int j = 0; j < sideLength; j++) {
            arr[i][j] = rand() % 4 + 1;
        }
    }
}

//test

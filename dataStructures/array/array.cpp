#include "array.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;


Array2d::Array2d() {
   size = 0;
   sideLengthRow = 0;
   sideLengthCol = 0;
}


Array2d::Array2d(int s) {
   size = s;
   sideLengthRow = sqrt(size);
   sideLengthCol = sqrt(size);
   if(sideLengthRow * sideLengthCol != size){
       sideLengthRow = size/2;
       sideLengthCol = 2;
   }
   arr = new double*[s];
   for (int i = 0; i < sideLengthRow; i++) {
       arr[i] = new double[sideLengthRow];
       for (int j = 0; j < sideLengthCol; j++)
           arr[i][j] = 0;
   }
}


Array2d::~Array2d() {
   if (arr) {
       for (int i = 0; i < sideLengthRow; i++) {
           if (arr[i]) {
               delete[] arr[i];
           }
       }
       delete[] arr;
   }
}


int Array2d::GetSideLengthRow() {
   return sideLengthRow;
}


int Array2d::GetSideLengthCol(){
   return sideLengthCol;
}


void Array2d::PrintArray2d() {
   for (int i = 0; i < sideLengthRow; i++) {
       for (int j = 0; j < sideLengthCol; j++) {
               cout << arr[i][j] << " ";
       }
       cout << endl;
   }
}


void Array2d::MakeRandomArray() {
   srand(time(NULL));
   for (int i = 0; i < sideLengthRow; i++) {
       for (int j = 0; j < sideLengthCol; j++) {
           arr[i][j] = rand() % 4 + 1;
       }
   }
}


Array2d& Array2d::operator=(const Array2d& other) {
   for (int i = 0; i < other.sideLengthRow; i++) {
       for (int j = 0; j < other.sideLengthCol; j++)
           this->arr[i][j] = other.arr[i][j];
      
   }
   return *this;
}
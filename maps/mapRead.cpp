#include "../dataStructures/array/array.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

Array2d makeMap(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        exit(EXIT_FAILURE);
    }

    int numCells;
    file >> numCells; //first line of file must be total number of cells
    Array2d map(numCells);
    int sideLength = map.GetSideLength();
    
    file.close();
    return map;
}
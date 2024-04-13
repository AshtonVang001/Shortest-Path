#include "../dataStructures/array/array.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

Array2d makeMap(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        exit(1);
    }
    int totalTiles;
    file >> totalTiles;  // Read the first line to get the total number of tiles
    Array2d mapArray(totalTiles);

    for (int i = 0; i < mapArray.GetSideLength(); i++) { // Read the rest of the lines and map symbols to numbers
        string line;
        file >> line; //scan in next line
        for (int j = 0; j < mapArray.GetSideLength()*2; j = j+2) { //loop over every 2nd tile as its 2x2
            char symbol = line[j];
            int tile_value;
            switch(symbol) {
                case '*': tile_value = 3; break;  // forest
                case '^': tile_value = 4; break;  // mountain
                case '.': tile_value = 2; break;  // plain
                case '-': tile_value = 1; break;  // road
                default: tile_value = 0;  // unknown symbol, set to 0
            }
            mapArray.arr[i][j/2] = tile_value;
        }
        file >> line; //skip next line as they are 2x2 tiles
    }
    file.close();
    return mapArray;
}
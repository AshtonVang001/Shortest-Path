#include "../../dataStructures/array/array.h"
#include <string>
#include <iostream>

using namespace std;

void printMap(Array2d& map) {
    int sideLength = map.GetSideLength();
    for (int i = 0; i < sideLength; i++) {
        string line;
        for (int j = 0; j < sideLength; j++) {
            int tileType = map.arr[i][j];
            switch (tileType) {
                case 1: line += "\033[90m-- \033[0m"; break;
                case 2: line += "\033[33m.. \033[0m"; break;
                case 3: line += "\033[32m** \033[0m"; break;
                case 4: line += "\033[34m^^ \033[0m"; break;
                default: line += " ";
            }   
        }
        cout << line << endl;
        cout << line << endl;
    }
    
}
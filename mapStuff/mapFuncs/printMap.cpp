#include "../../dataStructures/array/array.h"
#include <string>
#include <iostream>

using namespace std;

void printMap(Array2d& map) {
    int sideLength = map.GetSideLengthRow();
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
        std::cout << line << endl;
        std::cout << line << endl;
    }
}

bool nodeOnPath(int i, int j, int sideLength, pair<int*, int> path) {
    for (int l = 0; l < path.second; l++) {
        if (path.first[l] == i * sideLength + j) //node number is equal to i * sideLength + j
            return true;
    }
    return false;
}

void printShortestPath(Array2d& map, pair<int*, int> path) {
    int sideLength = map.GetSideLengthRow();
    for (int i = 0; i < sideLength; i++) { //iterate through every verticie
        string line;
        for (int j = 0; j < sideLength; j++) {
            int tileType = map.arr[i][j];
            bool onPath = nodeOnPath(i, j, sideLength, path); //if the verticie is present on the shortest path array
            if (!onPath) { //normal color print
                switch (tileType) {
                    case 1: line += "\033[90m-- \033[0m"; break;
                    case 2: line += "\033[33m.. \033[0m"; break;
                    case 3: line += "\033[32m** \033[0m"; break;
                    case 4: line += "\033[34m^^ \033[0m"; break;
                    default: line += " ";
                }  
            }
            else { //onPath, print in red
                switch (tileType) {
                    case 1: line += "\033[1;31m-- \033[0m"; break;
                    case 2: line += "\033[1;31m.. \033[0m"; break;
                    case 3: line += "\033[1;31m** \033[0m"; break;
                    case 4: line += "\033[1;31m^^ \033[0m"; break;
                    default: line += " ";
                }    
            } 
        }
        std::cout << line << endl; //print twice to show 2x2 tiles
        std::cout << line << endl;
    }
}


#include <iostream>
#include "dataStructures/array/array.h"
#include "dataStructures/graph/graph.h"
#include "maps/mapRead.cpp"
using namespace std;



int main() {
    int mapSize = 25; //mapSize must be a perfect square
    Array2d map(mapSize);
    map.MakeRandomArray();
    map.PrintArray2d();
    Graph graph(mapSize);
    graph.MakeGraphFromMap(map);
    graph.matrix.PrintArray2d();

    return 0;
}
#include <iostream>
#include "dataStructures/array/array.h"
#include "dataStructures/graph/graph.h"
#include "maps/mapRead.cpp"
using namespace std;

int main() {
    int map1Size = 25; //mapSize must be a perfect square
    Array2d map1(map1Size);
    map1 = makeMap("maps/map1.txt");
    map1.PrintArray2d();
    Graph graph1(map1Size);
    graph1.MakeGraphFromMap(map1);
    graph1.matrix.PrintArray2d();

    int map2Size = 36; //mapSize must be a perfect square
    Array2d map2(map2Size);
    map2 = makeMap("maps/map2.txt");
    map2.PrintArray2d();
    Graph graph2(map2Size);
    graph2.MakeGraphFromMap(map2);
    graph2.matrix.PrintArray2d();

    return 0;
}
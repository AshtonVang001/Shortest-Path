#include <iostream>
#include "dataStructures/array/array.h"
#include "dataStructures/graph/graph.h"
#include "mapStuff/mapFuncs/mapRead.cpp"
#include "mapStuff/mapFuncs/printMap.cpp"
using namespace std;

int main() {
    int map1Size = 25; //mapSize must be a perfect square
    Array2d map1(map1Size);
    map1 = makeMap("mapStuff/maps/map1.txt");
    Graph graph1(map1Size);
    graph1.MakeGraphFromMap(map1);
    map1.PrintArray2d();
    printMap(map1);
    graph1.matrix.PrintArray2d();
  
    int map2Size = 36; //mapSize must be a perfect square
    Array2d map2(map2Size);
    map2 = makeMap("mapStuff/maps/map2.txt");
    Graph graph2(map2Size);
    graph2.MakeGraphFromMap(map2);
    map2.PrintArray2d();
    printMap(map2);
    graph2.matrix.PrintArray2d();
    

    int map3Size = 49; //mapSize must be a perfect square
    Array2d map3(map3Size);
    map3 = makeMap("mapStuff/maps/map3.txt");
    Graph graph3(map3Size);
    graph3.MakeGraphFromMap(map3);
    map3.PrintArray2d();
    printMap(map3);
    graph3.matrix.PrintArray2d();
    

    int map4Size = 64; //mapSize must be a perfect square
    Array2d map4(map4Size);
    map4 = makeMap("mapStuff/maps/map4.txt");
    Graph graph4(map4Size);
    graph4.MakeGraphFromMap(map4);
    map4.PrintArray2d();
    printMap(map4);
    graph4.matrix.PrintArray2d();
    

    int map5Size = 81; //mapSize must be a perfect square
    Array2d map5(map5Size);
    map5 = makeMap("mapStuff/maps/map5.txt");
    Graph graph5(map5Size);
    graph5.MakeGraphFromMap(map5);
    map5.PrintArray2d();
    printMap(map5);
    graph5.matrix.PrintArray2d();

    return 0;
}
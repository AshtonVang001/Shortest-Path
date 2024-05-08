#include <iostream>
#include "dataStructures/array/array.h"
#include "dataStructures/graph/graph.h"
#include "mapStuff/mapFuncs/mapRead.cpp"
#include "mapStuff/mapFuncs/printMap.cpp"
#include <cmath>
using namespace std;

int main() {

    int part;
    cout << "Enter 1 for part 1" << endl;
    cout << "Enter 2 for part 2" << endl;
    cin >> part;

    switch (part){
    case 1:{
        int sourceX, sourceY, destX, destY;
        string cont; 
        cout << "The map contains 2 x 2 tiles of different types In ascending order of weight, we have '-' as road. '.' is plain '*' is forest. '^' is mountain." << endl;
        cout << "Coordinates are like quadrant 4 of a graph, except without a negative sign for Y values. Ex: top right value is (4, 0), bottom right is (4, 4)" << endl;

        cout << "Map 1" << endl;
        int map1Size = 25; //mapSize must be a perfect square
        Array2d map1(map1Size);
        map1 = makeMap("mapStuff/maps/map1.txt");
        Graph graph1(map1Size);
        graph1.MakeGraphFromMap(map1);
        //map1.PrintArray2d();
        printMap(map1);
        //graph1.matrix.PrintArray2d();
        std::cout << "Enter source vertex coordinates (x value, then y value) (0-" << map1.GetSideLengthRow() - 1 << ")" << endl;  
        cin >> sourceX;
        cin >> sourceY;
        std::cout << "Enter destination vertex coordinates (0-" << map1.GetSideLengthRow() - 1 << ")" << endl;  
        cin >> destX;
        cin >> destY;
        pair<int*, int> path1 = graph1.DijkstraShortestPath(coordCalc(sourceX, sourceY, map1.GetSideLengthCol()), coordCalc(destX, destY, map1.GetSideLengthCol()));
        printShortestPath(map1, path1);

        cout << "Enter anything to continue" << endl;
        cin >> cont;

        cout << "Map 2" << endl;
        int map2Size = 36; //mapSize must be a perfect square
        Array2d map2(map2Size);
        map2 = makeMap("mapStuff/maps/map2.txt");
        Graph graph2(map2Size);
        graph2.MakeGraphFromMap(map2);
        //map2.PrintArray2d();
        printMap(map2);
        //graph2.matrix.PrintArray2d();
        std::cout << "Enter source vertex coordinates (x value, then y value) (0-" << map2.GetSideLengthRow() - 1 << ")" << endl;  
        cin >> sourceX;
        cin >> sourceY;
        std::cout << "Enter destination vertex coordinates (0-" << map2.GetSideLengthRow() - 1 << ")" << endl;  
        cin >> destX;
        cin >> destY;
        pair<int*, int> path2 = graph2.DijkstraShortestPath(coordCalc(sourceX, sourceY, map2.GetSideLengthCol()), coordCalc(destX, destY, map2.GetSideLengthCol()));
        printShortestPath(map2, path2);
    
        cout << "Enter anything to continue" << endl;
        cin >> cont;

        cout << "Map 3" << endl;
        int map3Size = 49; //mapSize must be a perfect square
        Array2d map3(map3Size);
        map3 = makeMap("mapStuff/maps/map3.txt");
        Graph graph3(map3Size);
        graph3.MakeGraphFromMap(map3);
        //map3.PrintArray2d();
        printMap(map3);
        //graph3.matrix.PrintArray2d();
        std::cout << "Enter source vertex coordinates (x value, then y value) (0-" << map3.GetSideLengthRow() - 1 << ")" << endl;  
        cin >> sourceX;
        cin >> sourceY;
        std::cout << "Enter destination vertex coordinates (0-" << map3.GetSideLengthRow() - 1 << ")" << endl;  
        cin >> destX;
        cin >> destY;
        pair<int*, int> path3 = graph3.DijkstraShortestPath(coordCalc(sourceX, sourceY, map3.GetSideLengthCol()), coordCalc(destX, destY, map3.GetSideLengthCol()));
        printShortestPath(map3, path3);

        cout << "Enter anything to continue" << endl;
        cin >> cont;
    
        cout << "Map 4" << endl;
        int map4Size = 64; //mapSize must be a perfect square
        Array2d map4(map4Size);
        map4 = makeMap("mapStuff/maps/map4.txt");
        Graph graph4(map4Size);
        graph4.MakeGraphFromMap(map4);
        //map4.PrintArray2d();
        printMap(map4);
        //graph4.matrix.PrintArray2d();
        std::cout << "Enter source vertex coordinates (x value, then y value) (0-" << map4.GetSideLengthRow() - 1 << ")" << endl;  
        cin >> sourceX;
        cin >> sourceY;
        std::cout << "Enter destination vertex coordinates (0-" << map4.GetSideLengthRow() - 1 << ")" << endl;  
        cin >> destX;
        cin >> destY;
        pair<int*, int> path4 = graph4.DijkstraShortestPath(coordCalc(sourceX, sourceY, map4.GetSideLengthCol()), coordCalc(destX, destY, map4.GetSideLengthCol()));
        printShortestPath(map4, path4);

        cout << "Enter anything to continue" << endl;
        cin >> cont;

        cout << "Map 5" << endl;
        int map5Size = 81; //mapSize must be a perfect square
        Array2d map5(map5Size);
        map5 = makeMap("mapStuff/maps/map5.txt");
        Graph graph5(map5Size);
        graph5.MakeGraphFromMap(map5);
        //map5.PrintArray2d();
        printMap(map5);
        //graph5.matrix.PrintArray2d();
        std::cout << "Enter source vertex coordinates (x value, then y value) (0-" << map5.GetSideLengthRow() - 1 << ")" << endl;  
        cin >> sourceX;
        cin >> sourceY;
        std::cout << "Enter destination vertex coordinates (0-" << map5.GetSideLengthRow() - 1 << ")" << endl;  
        cin >> destX;
        cin >> destY;
        pair<int*, int> path5 = graph5.DijkstraShortestPath(coordCalc(sourceX, sourceY, map5.GetSideLengthCol()), coordCalc(destX, destY, map5.GetSideLengthCol()));
        printShortestPath(map5, path5);

        break;
    }
        
    case 2:{
//test functions
        cout << "Enter number of vertices" << endl;
        int numVert;
        cin >> numVert;
        int** arr;
        Graph testG1(numVert);

        int vertNum = 0; // number of vertex we are on (order of map starting from 0), this helps with inserting for matrix
        int totalVertices = numVert*numVert;

        cout << "Enter percent of connectivity (as a decimal)" << endl;
        double percent;
        cin >> percent; //insert as decimal

        int verticesToConnect = totalVertices * percent;

        int howMany = 0; //keeps track of how many vertices to connect
        for(int i = 0; i < numVert; i++) {
            for (int j = 0; j < numVert; j++) {
                if(percent == 1){ //if it is 100%
                testG1.newAddEdge(i, j, rand()%100);
                }else if(howMany < verticesToConnect){
                    testG1.newAddEdge(rand()%numVert, rand()%numVert, rand()%100);
                }
                howMany++;
            }
        }


        cout << "Matrix: " << endl;
        testG1.matrix.PrintArray2d();

        //calculates the average time of 100 iterations
        double avgTime;
        double time = 0;;
        for(int i = 0; i < 100; i++){ //probem with the loop 
            clock_t start, end;
            start = clock();
            int destination = (int)(numVert * percent); // Ensure integer vertex index
            if(destination >= numVert) // Check if valid index
                destination = numVert - 1; // Adjust if out of bounds

            testG1.DijkstraShortestPath(0, destination);
            end = clock();
            double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
            time += time_taken;
        }

        avgTime = time/100;
        cout << "The average time taken by program is : " << avgTime;
        cout << " sec " << endl;
        break;
    }

    }
    return 0;
}
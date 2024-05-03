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
        int source, dest;
    
        cout << "Map 1" << endl;
        int map1Size = 25; //mapSize must be a perfect square
        Array2d map1(map1Size);
        map1 = makeMap("mapStuff/maps/map1.txt");
        Graph graph1(map1Size);
        graph1.MakeGraphFromMap(map1);
        //map1.PrintArray2d();
        printMap(map1);
        //graph1.matrix.PrintArray2d();
        std::cout << "Enter destination vertex # (0-" << map1Size - 1 << ")" << endl;  
        cin >> source;
        std::cout << "Enter source vertex # (0-" << map1Size - 1 << ")" << endl;  
        cin >> dest;
        pair<int*, int> path1 = graph1.DijkstraShortestPath(source, dest);
        printShortestPath(map1, path1);

        cout << "Map 2" << endl;
        int map2Size = 36; //mapSize must be a perfect square
        Array2d map2(map2Size);
        map2 = makeMap("mapStuff/maps/map2.txt");
        Graph graph2(map2Size);
        graph2.MakeGraphFromMap(map2);
        //map2.PrintArray2d();
        printMap(map2);
        //graph2.matrix.PrintArray2d();
        std::cout << "Enter destination vertex # (0-" << map2Size - 1 << ")" << endl;  
        cin >> source;
        std::cout << "Enter source vertex # (0-" << map2Size - 1 << ")" << endl;  
        cin >> dest;
        pair<int*, int> path2 = graph2.DijkstraShortestPath(source, dest);
        printShortestPath(map2, path2);
    
        cout << "Map 3" << endl;
        int map3Size = 49; //mapSize must be a perfect square
        Array2d map3(map3Size);
        map3 = makeMap("mapStuff/maps/map3.txt");
        Graph graph3(map3Size);
        graph3.MakeGraphFromMap(map3);
        //map3.PrintArray2d();
        printMap(map3);
        //graph3.matrix.PrintArray2d();
        std::cout << "Enter destination vertex # (0-" << map3Size - 1 << ")" << endl;  
        cin >> source;
        std::cout << "Enter source vertex # (0-" << map3Size - 1 << ")" << endl;  
        cin >> dest;
        pair<int*, int> path3 = graph3.DijkstraShortestPath(source, dest);
        printShortestPath(map3, path3);
    
        cout << "Map 4" << endl;
        int map4Size = 64; //mapSize must be a perfect square
        Array2d map4(map4Size);
        map4 = makeMap("mapStuff/maps/map4.txt");
        Graph graph4(map4Size);
        graph4.MakeGraphFromMap(map4);
        //map4.PrintArray2d();
        printMap(map4);
        //graph4.matrix.PrintArray2d();
        std::cout << "Enter destination vertex # (0-" << map4Size - 1 << ")" << endl;  
        cin >> source;
        std::cout << "Enter source vertex # (0-" << map4Size - 1 << ")" << endl;  
        cin >> dest;
        pair<int*, int> path4 = graph4.DijkstraShortestPath(source, dest);
        printShortestPath(map4, path4);

        cout << "Map 5" << endl;
        int map5Size = 81; //mapSize must be a perfect square
        Array2d map5(map5Size);
        map5 = makeMap("mapStuff/maps/map5.txt");
        Graph graph5(map5Size);
        graph5.MakeGraphFromMap(map5);
        //map5.PrintArray2d();
        printMap(map5);
        //graph5.matrix.PrintArray2d();
        std::cout << "Enter destination vertex # (0-" << map5Size - 1 << ")" << endl;  
        cin >> source;
        std::cout << "Enter source vertex # (0-" << map5Size - 1 << ")" << endl;  
        cin >> dest;
        pair<int*, int> path5 = graph5.DijkstraShortestPath(source, dest);
        printShortestPath(map5, path5);

        break;
    }
        
    case 2:{
        //test functions
        cout << "Enter test size" << endl;
        int testSize1;
        cin >> testSize1;
        int** arr;
        Array2d test1(testSize1);
        Graph testG1(testSize1);
        test1.MakeRandomArray();
        test1.PrintArray2d();

        int vertNum = 0; // number of vertex we are on (order of map starting from 0), this helps with inserting for matrix
        int totalVertices = test1.GetSideLengthRow() * test1.GetSideLengthCol();

        cout << "Enter percent of connectivity (as a decimal)" << endl;
        double percent;
        cin >> percent; //insert as decimal

        int verticesToConnect = totalVertices * percent;

        // Seed the random number generator
        srand(time(nullptr));

        int howMany = 0; //keeps track of how many vertices to connect
        for(int i = 0; i < test1.GetSideLengthRow(); i++) {
            for (int j = 0; j < test1.GetSideLengthCol(); j++) {
                double currVertWeight = test1.arr[i][j];

                int up = (i > 0) ? (vertNum - test1.GetSideLengthCol()) : -1;
                int down = (i < test1.GetSideLengthRow() - 1) ? (vertNum + test1.GetSideLengthCol()) : -1;
                int right = (j < test1.GetSideLengthCol() - 1) ? (vertNum + 1) : -1;
                int left = (j > 0) ? (vertNum - 1) : -1;

                double upWeight = (up != -1) ? test1.arr[i-1][j] : 0;
                double downWeight = (down != -1) ? test1.arr[i+1][j] : 0;
                double rightWeight = (right != -1) ? test1.arr[i][j+1] : 0;
                double leftWeight = (left != -1) ? test1.arr[i][j-1] : 0;

                // decide whether to connect this vertex
                if(verticesToConnect == testSize1){ //if it is 100%
                    if (up != -1) testG1.matrix.arr[vertNum][up] = testG1.WeightCalc(currVertWeight, test1.arr[i-1][j]);
                    if (down != -1) testG1.matrix.arr[vertNum][down] = testG1.WeightCalc(currVertWeight, test1.arr[i+1][j]);
                    if (right != -1) testG1.matrix.arr[vertNum][right] = testG1.WeightCalc(currVertWeight, test1.arr[i][j+1]);
                    if (left != -1) testG1.matrix.arr[vertNum][left] = testG1.WeightCalc(currVertWeight, test1.arr[i][j-1]);
                }
                else if (howMany < verticesToConnect) { //if it is not 100%
                    if (up != -1) testG1.matrix.arr[vertNum][up] = testG1.WeightCalc(currVertWeight, test1.arr[i-1][j]);
                    if (down != -1) testG1.matrix.arr[vertNum][down] = testG1.WeightCalc(currVertWeight, test1.arr[i+1][j]);
                    if (right != -1) testG1.matrix.arr[vertNum][right] = testG1.WeightCalc(currVertWeight, test1.arr[i][j+1]);
                    if (left != -1) testG1.matrix.arr[vertNum][left] = testG1.WeightCalc(currVertWeight, test1.arr[i][j-1]);
                }
                howMany++;
                vertNum++;
            }
        }


        testG1.matrix.PrintArray2d();

        clock_t start, end;

        start = clock();

        testG1.DijkstraShortestPath(0, testSize1 * percent);

        end = clock();

        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "Time taken by program is : " << time_taken;
        cout << " sec " << endl;
        break;
    }

    }
    return 0;
}
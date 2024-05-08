#include "../array/array.h"
#include <string>
#ifndef GRAPH_H
#define GRAPH_H
using namespace std;

class Graph {
    private:
        int vertices; //number of vertices
        void EdgeInserter(Array2d &a, string key, int vN, int u, int d, int l, int r, double cW, double uW, double dW, double lW, double rW);
    public:
        Array2d matrix;
        Graph(int v);
        void MakeGraphFromMap(Array2d &a);
        double WeightCalc(double x, double y);
         void AddEdge(int row, int col, double typeX, double typeY);
         void newAddEdge(int row, int col, int weight);
        pair<int*, int> DijkstraShortestPath(int source, int dest);
    
};

#endif
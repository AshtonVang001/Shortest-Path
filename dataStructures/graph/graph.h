#include "../array/array.h"
#include <string>
#ifndef GRAPH_H
#define GRAPH_H
using namespace std;

class Graph {
    private:
        int vertices; //number of vertices
        double WeightCalc(double x, double y);
        void AddEdge(int row, int col, double typeX, double typeY);
        void EdgeInserter(Array2d &a, string key, int vN, int u, int d, int l, int r, double cW, double uW, double dW, double lW, double rW);
    public:
        Array2d matrix;
        Graph(int v);
        void MakeGraphFromMap(Array2d &a);
    
};

#endif
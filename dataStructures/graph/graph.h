#include "../array/array.h"
#ifndef GRAPH_H
#define GRAPH_H

class Graph {
    private:
        int vertices; //number of vertices
        double WeightCalc(double x, double y);
        void AddEdge(int row, int col, double typeX, double typeY);
    public:
        Array2d matrix;
        Graph(int v);
        //~Graph();
        void MakeGraphFromMap(Array2d a);
    
};

#endif
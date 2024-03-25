#include "graph.h"
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

Graph::Graph(int v) : vertices(v), matrix(v * v) {}

double Graph::WeightCalc(double x, double y) { //calculates average for weight
    double weight = (x+y)/2;
    return weight;
}

void Graph::AddEdge(int row, int col, double typeX, double typeY) {
    double weight = WeightCalc(typeX, typeY);
    matrix.arr[row][col] = weight;
}

//to make graph from 2d Map:
//1) go to each individual point in map
//2 check what type of vertex it is (corner, top, left, middle, etc)
//3) find each adjacent point to this point in map
//4) find what #vertex this is in graph

void Graph::EdgeInserter(Array2d &a, string key, int vN, int u, int d, int l, int r, double cW, double uW, double dW, double lW, double rW) {
    if(key == "middle") {
        AddEdge(vN, r, cW, rW);
        AddEdge(vN, l, cW, lW);
        AddEdge(vN, d, cW, dW);
        AddEdge(vN, u, cW, uW);
        return;
    }
    if (key == "bottom") {
        AddEdge(vN, u, cW, uW);
        AddEdge(vN, l, cW, lW);
        AddEdge(vN, r, cW, rW);
        return;
    }
    if(key == "left") {
        AddEdge(vN, u, cW, uW);
        AddEdge(vN, r, cW, rW);
        AddEdge(vN, d, cW, dW);
        return;
    }
    if(key == "right") {
        AddEdge(vN, l, cW, lW);
        AddEdge(vN, d, cW, dW);
        AddEdge(vN, u, cW, uW);
        return;
    }
    if (key == "top") {
        AddEdge(vN, l, cW, lW);
        AddEdge(vN, r, cW, rW);
        AddEdge(vN, d, cW, dW);
        return;
    }
    if(key == "top-left-corner") {
        AddEdge(vN, r, cW, rW);
        AddEdge(vN, d, cW, dW);
        return;
    }
    if(key == "top-right-corner") {
        AddEdge(vN, l, cW, lW);
        AddEdge(vN, d, cW, dW);
        return;
    }
    
    if (key == "bottom-left-corner") { 
        AddEdge(vN, u, cW, uW);
        AddEdge(vN, r, cW, rW);
        return;
    }
    if(key == "bottom-right-corner") {
        AddEdge(vN, u, cW, uW);
        AddEdge(vN, l, cW, lW);
        return;
    }
    
}

void Graph::MakeGraphFromMap(Array2d &a) {
    int vertNum = 0; //number of vertex we are on (order of map starting from 0), this helps with inserting for matrix
    int sideLength = a.GetSideLength();
    for(int i = 0; i < sideLength; i++) {
        for (int j = 0; j < sideLength; j++) { 
            string key;
            double currVertWeight = a.arr[i][j]; //number of current vertex we are trying to find edges for ex: in 3 x 3 map, first value is vertex is #0, last vertex is #8
            int up = vertNum - sideLength; //all direction variables represent what # vertex would be in __ direction away from curr vertex
            int down = vertNum + sideLength; //ie: what index we should be inserting edge into in matrix
            int right = vertNum + 1;
            int left = vertNum - 1;

            double upWeight = 0; //represent the weight of the vertex that would be in __ direction from curr vertex
            double downWeight = 0;
            double rightWeight = 0;
            double leftWeight = 0;

            if(i != 0) upWeight = a.arr[i-1][j]; //if statements to ensure no out of bounds errors ie: if we are at top, we can't get value of a[-1][0]
            if(i != sideLength -1 ) downWeight = a.arr[i+1][j];
            if(j != sideLength - 1) rightWeight = a.arr[i][j+1];
            if(j != 0) leftWeight = a.arr[i][j-1];

             //inserting edges involves 9 different cases depending on where tile is located   
            if(i == 0) { //top piece
                if(j == 0) //top-left corner, then we want order # of vertex a[i][j+1] (2nd node by default) and vertex a[i+1][j], which is vertex right below, and its order is just sqrt(vertices) 
                    key = "top-left-corner";
                else if(j == sideLength - 1)  //top-right corner
                    key = "top-right-corner";
                else //top middle piece
                    key = "top";
            }
            else if (i == sideLength - 1) { //bottom piece
                if(j == 0) //bottom-left corner
                    key = "bottom-left-corner";
                else if(j == sideLength - 1)  //bottom-right corner
                    key = "bottom-right-corner";
                else //bottom middle piece
                    key = "bottom";
            }
            else if(i != 0 && i != sideLength - 1 && j == 0) //left piece but not top or bottom row
                key = "left";
            else if(j == sideLength - 1 && i != 0 && i != sideLength - 1) //right piece but not top or bottom row
                key = "left";
            else 
               key = "middle";
            EdgeInserter(a, key, vertNum, up, down, left, right, currVertWeight, upWeight, downWeight, leftWeight, rightWeight);
            vertNum++;
        }
    }
};


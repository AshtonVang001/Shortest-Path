#include "graph.h"
#include <cmath>
#include <iostream>
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

void Graph::MakeGraphFromMap(Array2d a) {
    int vertNum = 0; //number of vertex we are on (order of vertex starting from 0)
    for(int i = 0; i < a.GetSideLength(); i++) {
        for (int j = 0; j < a.GetSideLength(); j++) { 
            double currVertWeight = a.arr[i][j];
            int up = vertNum - a.GetSideLength();
            int down = vertNum + a.GetSideLength();
            int right = vertNum + 1;
            int left = vertNum - 1;
            int upWeight = 0;
            int downWeight = 0;
            int rightWeight = 0;
            int leftWeight = 0;
            //if statements to ensure no out of bounds errors
            if(i != 0) upWeight = a.arr[i-1][j];
            if(i != a.GetSideLength() -1 ) downWeight = a.arr[i+1][j];
            if(j != a.GetSideLength() - 1) rightWeight = a.arr[i][j+1];
            if(j != 0) leftWeight = a.arr[i][j-1];
            if(i == 0) { //top piece
                if(j == 0) { //top-left corner, then we want order # of vertex a[i][j+1] (2nd node by default) and vertex a[i+1][j], which is vertex right below, and its order is just sqrt(vertices) 
                    AddEdge(vertNum, right, currVertWeight, rightWeight);
                    AddEdge(vertNum, down, currVertWeight, downWeight);
                }
                else if(j == a.GetSideLength() - 1) { //top-right corner
                    AddEdge(vertNum, left, currVertWeight, leftWeight);
                    AddEdge(vertNum, down, currVertWeight, downWeight);
                }
                else { //top middle piece
                    AddEdge(vertNum, left, currVertWeight, leftWeight);
                    AddEdge(vertNum, right, currVertWeight, rightWeight);
                    AddEdge(vertNum, down, currVertWeight, downWeight);
                }
            }
            else if (i == a.GetSideLength() - 1) { //bottom piece
                if(j == 0) { //bottom-left corner
                    AddEdge(vertNum, up, currVertWeight, upWeight);
                    AddEdge(vertNum, right, currVertWeight, rightWeight);
                }
                else if(j == a.GetSideLength() - 1) { //bottom-right corner
                    AddEdge(vertNum, up, currVertWeight, upWeight);
                    AddEdge(vertNum, left, currVertWeight, leftWeight);
                }
                else { //bottom middle piece
                    AddEdge(vertNum, up, currVertWeight, upWeight);
                    AddEdge(vertNum, left, currVertWeight, leftWeight);
                    AddEdge(vertNum, right, currVertWeight, rightWeight);
                }
            }
            else if(i != 0 && i != a.GetSideLength() - 1 && j == 0) { //left piece but not top or bottom row ALSO CHECK IF WE NEED THE i != 0
                AddEdge(vertNum, up, currVertWeight, upWeight);
                AddEdge(vertNum, right, currVertWeight, rightWeight);
                AddEdge(vertNum, down, currVertWeight, downWeight);
            }
            else if(j == a.GetSideLength() - 1 && i != 0 && i != a.GetSideLength() - 1) { //right piece but not top or bottom row
                AddEdge(vertNum, left, currVertWeight, leftWeight);
                AddEdge(vertNum, down, currVertWeight, downWeight);
                AddEdge(vertNum, up, currVertWeight, upWeight);
            }
            else { 
                AddEdge(vertNum, right, currVertWeight, rightWeight);
                AddEdge(vertNum, left, currVertWeight, leftWeight);
                AddEdge(vertNum, down, currVertWeight, downWeight);
                AddEdge(vertNum, up, currVertWeight, upWeight);
            }
            vertNum++;
        }
    }
}


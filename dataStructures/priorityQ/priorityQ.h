#include <utility>
#ifndef PRIORITYQ_H
#define PRIORITYQ_H
using namespace std;


class PriorityQueue {
private:
    pair<int, int>* a; // Array to store pairs
    int capacity; // Maximum capacity of the priority queue
    int size; // Current size of the priority queue

    int getParent(int i);
    int getLeftChild(int i);
    int getRightChild(int i);
    void heapUp(int i);
    void heapDown(int i);

public:
    PriorityQueue(int capacity);
    ~PriorityQueue();
    void insert(pair<int, int> x);
    pair<int, int> extractMin();
    void changeP(int i, pair<int, int> x);
    pair<int, int> getMin();
    void delete1(int i);
    void display();
    bool isEmpty();
};

#endif
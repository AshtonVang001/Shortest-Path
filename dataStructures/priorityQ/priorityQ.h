#ifndef PRIORITYQ_H
#define PRIORITYQ_H

class PriorityQueue{
private:
    int capacity;
    int size;
    int* a;

public:

    PriorityQueue(){
        capacity = 0;
        size = 0;
        a = nullptr;
    }
    PriorityQueue(int cap){
        capacity = cap;
        size = 0;
        a = new int [capacity];
    }

    ~PriorityQueue(){
        delete[] a;
    }

    int getParent(int i);
    int getLeftChild(int i);
    int getRightChild(int i);
    void heapDown(int i);
    void heapUp(int i);
    void insert(int x);
    int extractMax();
    void changeP(int i, int x);
    int getMax();
    void delete1(int x);
    void display();


};

#endif
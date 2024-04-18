#include "priorityQ.h"
#include <iostream>
using namespace std;

int PriorityQueue::getParent(int i) {
    return (i - 1)/2;
}

int PriorityQueue::getLeftChild(int i) {
    return ((2 * i) + 1);
}

int PriorityQueue::getRightChild(int i) {
    return ((2 * i) + 2);
}

void PriorityQueue::heapUp(int i) {
    while(i > 0 && a[getParent(i)] > a[i]){
        swap(a[getParent(i)], a[i]);
        i = getParent(i);
    }
}

void PriorityQueue::heapDown(int i) {
    int minVal = i;

    int l = getLeftChild(i);

    if(l <= size && a[l] < a[minVal]){
        minVal = l;
    }

    int r = getRightChild(i);

    if(r <= size && a[r] < a[minVal]){
        minVal = r;
    }

    if(i != minVal){
        swap(a[i], a[minVal]);
        heapDown(minVal);
    }
}

void PriorityQueue::insert(int x) {
    a[size] = x;
    heapUp(size);
    size++;
}

int PriorityQueue::extractMin() {
    int min = a[0];

    a[0] = a[size];
    size--;

    heapDown(0);
    return min;
}


void PriorityQueue::changeP(int i, int x) {
    int oldp = a[i];

    a[i] = x;

    if(x > oldp){
        heapUp(i);
    }else{
        heapDown(i);
    }
}

int PriorityQueue::getMin() {
    return a[0];
}


void PriorityQueue::delete1(int i) {
    a[i] = a[size - 1];
    size--;

    if (i < size) {
        if (a[i] > a[getParent(i)]) {
            heapUp(i);
        } else {
            heapDown(i);
        }
    }
}

void PriorityQueue::display() {
    for(int i = 0; i < size; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

bool PriorityQueue::isEmpty(){
    if(size == 0){
        return true;
    }else{
        return false;
    }
}

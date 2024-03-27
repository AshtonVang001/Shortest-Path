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
    while(i > 0 && a[getParent(i)] < a[i]){
        swap(a[getParent(i)], a[i]);
        i = getParent(i);
    }
}

void PriorityQueue::heapDown(int i) {
    int maxVal = i;

    int l = getLeftChild(i);

    if(l <= size && a[l] > a[maxVal]){
        maxVal = l;
    }

    int r = getRightChild(i);

    if(r <= size && a[r] > a[maxVal]){
        maxVal = r;
    }

    if(i != maxVal){
        swap(a[i], a[maxVal]);
        heapDown(maxVal);
    }
}

void PriorityQueue::insert(int x) {
    a[size] = x;
    heapUp(size);
    size++;
}

int PriorityQueue::extractMax() {
    int max = a[0];

    a[0] = a[size];
    size--;

    heapDown(0);
    return max;
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

int PriorityQueue::getMax() {
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



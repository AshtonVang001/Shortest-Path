#include "priorityQ.h"
#include <iostream>
#include <utility>
using namespace std;

PriorityQueue::PriorityQueue(int capacity) : capacity(capacity), size(0) {
    a = new pair<int, int>[capacity];
}

PriorityQueue::~PriorityQueue() {
    delete[] a;
}

int PriorityQueue::getParent(int i) {
    return (i - 1) / 2;
}

int PriorityQueue::getLeftChild(int i) {
    return (2 * i) + 1;
}

int PriorityQueue::getRightChild(int i) {
    return (2 * i) + 2;
}

void PriorityQueue::heapUp(int i) {
    while (i > 0 && a[getParent(i)].first > a[i].first) {
        swap(a[getParent(i)], a[i]);
        i = getParent(i);
    }
}

void PriorityQueue::heapDown(int i) {
    int minVal = i;

    int l = getLeftChild(i);

    if (l < size && a[l].first < a[minVal].first) {
        minVal = l;
    }

    int r = getRightChild(i);

    if (r < size && a[r].first < a[minVal].first) {
        minVal = r;
    }

    if (i != minVal) {
        swap(a[i], a[minVal]);
        heapDown(minVal);
    }
}

void PriorityQueue::insert(pair<int, int> x) {
    a[size] = x;
    heapUp(size);
    size++;
}

pair<int, int> PriorityQueue::extractMin() {
    pair<int, int> min = a[0];

    a[0] = a[size - 1];
    size--;

    heapDown(0);
    return min;
}

void PriorityQueue::changeP(int i, pair<int, int> x) {
    pair<int, int> oldp = a[i];

    a[i] = x;

    if (x.first > oldp.first) {
        heapUp(i);
    } else {
        heapDown(i);
    }
}

pair<int, int> PriorityQueue::getMin() {
    return a[0];
}

void PriorityQueue::delete1(int i) {
    a[i] = a[size - 1];
    size--;

    if (i < size) {
        if (a[i].first > a[getParent(i)].first) {
            heapUp(i);
        } else {
            heapDown(i);
        }
    }
}

void PriorityQueue::display() {
    for (int i = 0; i < size; i++) {
        cout << "(" << a[i].first << ", " << a[i].second << ") ";
    }
    cout << endl;
}

bool PriorityQueue::isEmpty() {
    return size == 0;
}
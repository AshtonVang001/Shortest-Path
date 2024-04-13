#ifndef ARRAY_H
#define ARRAY_H

class Array2d {
    private:
        int size; //size of array
        int sideLength; //size of one side of array or sqrt(size)

    public:
        double** arr; //pointer of array itself
        Array2d();
        Array2d(int s);
        ~Array2d();
        void PrintArray2d();
        void MakeRandomArray();
        int GetSideLength();
        Array2d& operator=(const Array2d& other);
};

#endif


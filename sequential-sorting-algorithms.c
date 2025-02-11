/* CHALLENGE 1 (Sequential sorting algorithms). Can you do
(1) A merge sort (with recursion)
(2) A quick sort (with recursion)
on arrays with sort keys such as double or strings to your liking?
Nothing is gained if you don’t know whether your programs are correct. Therefore, can
you provide a simple test routine that checks if the resulting array really is sorted?
This test routine should just scan once through the array and should be much, much faster
than your sorting algorithms.*/


// Need to add #include parts so can use C stuff
# include <stdlib.h>
#include <stdio.h>

// MERGE SORT (recursive)

// I will choose to do this with doubles
// A double is a floating point number with high accuracy (up to 15 d.p)

// For both of these instead of passing the array we pass the start and end indexes of the array

// Merges two sub arrays back together
void merge(double arr[], size_t len, size_t left, size_t middle, size_t right)
{

}

// Takes the array splits it in two and calls itself on each half of the array
void mergeSort(double arr[], size_t len, size_t start, size_t end)
{
    if (len <= 1)
    {
        return;
    }

    size_t mid = len / 2;
    size_t left_size = mid;
    size_t right_size = len - mid;

    mergeSort(arr, len, start, mid);
    mergeSort(arr, len, mid, end);

    merge(arr, len, start, mid, end);
}


int main()
{
    double unsorted[5] = {5.0, 4.0, 3.0, 2.0, 1.0};
    mergeSort(unsorted, 5, 0, 4);

    return 0;
}



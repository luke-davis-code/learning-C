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

int merge_sort(double arr[], size_t size)
{
    // Divide into two sub arrays
    size_t half_size = size/2;
    printf("%lu\n", half_size);
    double L[size - half_size];
    double R[half_size];
    // Traverse array and add to new arrays
    size_t l = 0;
    size_t r = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (i <= half_size)
        {
            L[l] = arr[i];
            l += 1;
        }
        else
        {
            R[r] = arr[i];
            r += 1;
        }
    }
    printf("Elements in Left: ");
    for (int i = 0; i <= half_size; i++) {
        printf("%f ", L[i]);
    }
    printf("Elements in Right: ");
    for (int i = 0; i < half_size; i++) {
        printf("%f ", R[i]);
    }

    return 0;
}


// Arrays are made with the syntax - 'type' name[length]
// start with length of 5
// Use the initialisation technique given in the book from getting started
// Each item in the array is set individually with any number I choose

int main()
{
    double unsorted[3] = {0.0, 2.0, 5.0};
    merge_sort(unsorted, 3);
}



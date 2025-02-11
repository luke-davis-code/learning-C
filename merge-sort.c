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

// For both of these instead of passing just the array, pass the array, size of array, and start and end pointers for array

// Merges two sub arrays back together
void merge(double arr[], size_t len_arr, size_t left, size_t middle, size_t right)
{
    // Left half is from start to middle-1
    size_t left_size = middle - left;
    // Right half is from middle to end
    size_t right_size = right - middle;

    // Copy each half of array to new arrays
    double left_arr[left_size];
    double right_arr[right_size];

    for (size_t i = 0; i < left_size; i++)
    {
        left_arr[i] = arr[left + i];
    }
    for (size_t i = 0; i < right_size; i++)
    {
        right_arr[i] = arr[middle + i];
    }



    size_t i = 0;
    size_t j = 0;
    size_t k = left;

    while (i <= left_size && j <= right_size)
    {
        if (left_arr[i] <= right_arr[j])
        {
            arr[k] = left_arr[i];
            i++;
        }
        else
        {
            arr[k] = right_arr[j];
            j++;
        }
    }
}

// Takes the array splits it in two and calls itself on each half of the array
void mergeSort(double arr[], size_t len, size_t start, size_t end)
{
    if (start-end <= 1)
    {
    }
    else
    {
        size_t mid = len / 2;

        // Left half is from start to middle-1


        // Right half is from middle to end


        mergeSort(arr, len, start, mid-1);
        mergeSort(arr, len, mid, end);

        merge(arr, len, start, mid, end);
    }
}


int main()
{
    double unsorted[5] = {5.0, 4.0, 3.0, 2.0, 1.0};
    mergeSort(unsorted, 5, 0, 4);

    return 0;
}



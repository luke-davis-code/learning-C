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


void merge(double arr[], size_t array_size, size_t left, size_t middle, size_t right)
{
    // Make a new array to put merged array in
    double temp[array_size];

    // Middle is the index at the end of the left side of the merge
    size_t l_index = 0;
    size_t r_index = middle+1;
    size_t count_index = 0;

    while (l_index <= middle && r_index <= right)
    {
        if (arr[l_index] < arr[r_index])
        {
            temp[count_index] = arr[l_index];
            l_index++;
        }
        else
        {
            temp[count_index] = arr[r_index];
            r_index++;
        }
        count_index++;
    }

    // Left sub array always bigger than right sub array
    // So add any leftover in left
    while (l_index <= middle)
    {
        temp[count_index] = arr[l_index];
        l_index++;
        count_index++;
    }


}

void sort(double arr[], size_t left, size_t right)
{
    size_t middle = (left + right) / 2;
    size_t array_size = right + 1;
    merge(arr, array_size, left, middle, rigth);
}



int main()
{
    double unsorted[3] = {0.0, 2.0, 5.0};
}



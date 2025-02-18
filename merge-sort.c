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
    int left_size = middle - left + 1;
    int right_size = right - middle;

    double left_arr[left_size];
    double right_arr[right_size];

    // copy array to these sub arrays
    for (size_t i = left; i < left_size; i++){
        left_arr[i-left] = arr[i];
    }
    for (size_t i = middle + 1; i < right; i++){
        right_arr[i-right] = arr[i];
    }

    size_t left_i = 0;
    size_t right_i = 0;
    size_t k = left;

    while (left_i < left_size && right_i < right_size){
        if (left_arr[left_i] <= right_arr[right_i]){
            arr[k] = left_arr[left_i];
            left_i++;
        }
        else {
            arr[k] = right_arr[right_i];
            right_i++;
        }
    }

    // ADD ANYTHING LEFT
}

// Takes the array splits it in two and calls itself on each half of the array
// Recursive part
// Start and end are the inclusive indexes of where merge sort is called
void mergeSort(double arr[], int arr_size, int start, int end){
    // Base case
    if (start == end){

    }
    else {
    int half_size = (start-end) / 2;
    // make sure half_size is >= 0
    if (half_size < 0){
        half_size = 0;
    }

    int middle = start+half_size;

    mergeSort(arr, arr_size, start, middle);
    printf("Called Merge Sort with array, %d, %d, %d\n", arr_size, start, middle);
    mergeSort(arr, arr_size, middle+1, end);
    printf("Called Merge Sort with array, %d, %d, %d\n", arr_size, middle+1, end);

    merge(arr, arr_size, start, middle, end);
    printf("Called Merge with array, %d, %d, %d, %d\n", arr_size, start, middle, end);
    }
}


int main() {
    int test = 5 / 2;
    printf("test = %d\n", test);
}



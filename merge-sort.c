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

// Merge two subarrays of a
// a[l..m] is merged with a[m+1..n]
void merge(double arr[], int len, int l, int m, int n){
    // copy arrays to reference
    int left_size = m - l + 1;
    double left_arr[left_size];

    int right_size = n - (m+1) + 1;
    double right_arr[right_size];

    for (int i = 0; i < left_size; i++) {
        left_arr[i] = arr[l + i];
    }
    for (int i = 0; i < right_size; i++) {
        right_arr[i] = arr[m + 1 + i];
    }

    int left = 0;
    int right = 0;
    int p = l;
    while (left < left_size && right < right_size) {
        if (left_arr[left] <= right_arr[right]) {
            arr[p] = left_arr[left];
            left++;
        }
        else {
            arr[p] = right_arr[right];
            right++;
        }
        p++;
    }

    // Add leftover elements
    while (left < left_size) {
        arr[p] = left_arr[left];
        p++;
        left++;
    }
    while (right < right_size) {
        arr[p] = right_arr[right];
        p++;
        right++;
    }
}

// mergesort the sub-array of a from a[l] up to a[m]
void mergeSort(double arr[], int len, int l, int m) {
    if (l != m) {
        int middle = (l + m) / 2;
        mergeSort(arr, len, l, middle);
        mergeSort(arr, len, middle+1, m);

        merge(arr, len, l, middle, m);
    }
}

void isSorted(double arr[], int len) {
    int sorted = 1;
    for (int i = 1; i < len; i++) {
        if (arr[i] < arr[i-1]) {
            sorted = 0;
        }
    }

    if (sorted == 1) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
}


int main() {
    double test_arr[5] = {3.0, 4.0, 1.0, 2.0, 4.0};
    mergeSort(test_arr, 5, 0, 4);
    isSorted(test_arr, 5);
}



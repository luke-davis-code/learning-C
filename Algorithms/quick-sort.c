#include <stdlib.h>
#include <stdio.h>

void swap(double a[], int i, int j) {
    double temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

// Reorder a around pivot p s.t a[0..p-1] < a[p] <= a[p+1..n]
int partition(double arr[], int low, int high){
    // Choose pivot to be last element
    double pivot = arr[high];
    int i = low -1;

    for (int j = low; j < high; j++){
        if (arr[j] <= pivot) {
            i += 1;
            swap(arr, i, j);
        }
    }

    swap(arr, i+1, high);

    return i+1;
}

void quickSort(double arr[], int low, int high){
    if (low < high){
    int part_i = partition(arr, low, high);
    quickSort(arr, part_i+1, high);
    quickSort(arr, low, part_i-1);
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

int main(){
    double test_arr[6] = {3.0, 6.0, 5.0, 1.0, 2.0, 4.0};
    quickSort(test_arr, 0, 5);
    for (int i = 0; i < 6; i++){
        printf("%f ", test_arr[i]);
    }
    isSorted(test_arr, 6);
}
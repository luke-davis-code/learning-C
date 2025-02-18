# include <stdio.h>
# include <stdlib.h>

int power(int base, int exp){
    int result = 1;
    for (int i = 1; i <= exp; i++){
      result *= base;
    }
    return result;
}


void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void insert(int arr[], int i){
    while (i > 0 && arr[i-1] > arr[i]){
        swap(arr, i-1, i);
        i--;
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        insert(arr, i);
    }
}

void shellSort(int arr[], int n) {
    int stridelengths[64];
    int k = 0;
    while (power(2, k)-1 < n) {
        k += 1;
        stridelengths[k-1] = power(2, k)-1;
    }

    for (int i = k; i >= 0; i--){
        // Do an insertion sort on each stride length
    }

    printf("%d", stridelengths[1]);
}

int main(){
    int arr[100];
    shellSort(arr, 1000000000);
}

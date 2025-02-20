# include <stdio.h>
# include <stdlib.h>
# include <time.h>

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

void hInsert(int arr[], int i, int h){
    while (i >= h && arr[i-h] > arr[i]){
        swap(arr, i-h, i);
        i = i - h;
    }
}

void hSort(int arr[], int n, int h) {
    for (int i = h; i < n; i++) {
        hInsert(arr, i, h);
    }
}

void shellSort(int arr[], int n) {
    int stridelengths[64];
    int k = 0;
    while (power(2, k)-1 < n) {
        k += 1;
        stridelengths[k-1] = power(2, k)-1;
    }

    for (int i = k-2; i >= 0; i--){
        hSort(arr, n, stridelengths[i]);
    }
}

int main(){
    int list_sizes[5] = {10, 100, 1000, 10000, 100000};

    for (int i = 0; i < 5; i++){
        int list[list_sizes[i]];

        for (int i = 0; i < list_sizes[i]; i++) {
            list[i] = rand();
        }
        clock_t begin = clock();

        shellSort(list, list_sizes[i]);

        clock_t end = clock();
        double time_spent = (double)(end-begin) / CLOCKS_PER_SEC;

        printf("Sort took %f seconds to execute on list of size %d\n", time_spent, list_sizes[i]);
    }
}


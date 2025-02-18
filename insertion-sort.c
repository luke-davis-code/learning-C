# include <stdlib.h>
# include <stdio.h>
# include <time.h>

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

int main(){
    int list_sizes[5] = {10, 100, 1000, 10000, 100000};

    for (int i = 0; i < 5; i++){
        int list[list_sizes[i]];

        for (int i = 0; i < list_sizes[i]; i++) {
            list[i] = rand();
        }
        clock_t begin = clock();

        insertionSort(list, list_sizes[i]);

        clock_t end = clock();
        double time_spent = (double)(end-begin) / CLOCKS_PER_SEC;

        printf("Sort took %f seconds to execute on list of size %d\n", time_spent, list_sizes[i]);
    }
}

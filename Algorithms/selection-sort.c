# include <stdlib.h>
# include <stdio.h>
# include <time.h>

int findMin(int a[], int length, int i) {
    int m = i;
    for (int j = i; j<length; j++)
    {
        if (a[j] < a[m])
        {
            m = j;
        }
    }
    return m;
}

void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void selectionSort(int a[], int length) {
    for (int i = 0; i < length; i++) {
        int j = findMin(a, length, i);
        swap(a, i, j);
    }
}

int main() {
    int list_sizes[5] = {10, 100, 1000, 10000, 100000};

    for (int i = 0; i < 5; i++){
        int list[list_sizes[i]];

        for (int i = 0; i < list_sizes[i]; i++) {
            list[i] = rand();
        }
        clock_t begin = clock();

        selectionSort(list, list_sizes[i]);

        clock_t end = clock();
        double time_spent = (double)(end-begin) / CLOCKS_PER_SEC;

        printf("Sort took %f seconds to execute on list of size %d\n", time_spent, list_sizes[i]);
    }

    return 0;
}

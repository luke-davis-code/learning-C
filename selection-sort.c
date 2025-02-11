# include <stdlib.h>
# include <stdio.h>

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
    int list[10] = {3, 4, 6, 7 ,9, 0, 1, 5, 2, 8};
    selectionSort(list, 10);
    for (int i = 0; i < 10; i++){
        printf("%d ", list[i]);
    }
}

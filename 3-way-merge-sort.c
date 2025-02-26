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


// Merge three subarrays of a (by composing two way merge twice)
// a[l..m] is merged with a[m+1..n] merged with a[n+1..o]
void threeMerge(double arr[], int len, int l, int m, int n, int o){
	merge(arr, len, l, m, n);
    merge(arr, len, l, n, o);
}

// mergesort the sub-array of a from a[l] up to a[m]
void threeMergeSort(double arr[], int len, int l, int m) {
    if (l < m) {
        int middle1 = l + (m - l) / 3;
        int middle2 = l + 2 * (m - l) / 3;
        threeMergeSort(arr, len, l, middle1);
        threeMergeSort(arr, len, middle1+1, middle2);
        threeMergeSort(arr, len, middle2+1, m);

        threeMerge(arr, len, l, middle1, middle2, m);
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
    double test_arr[10] = {10.0, 9.0, 8.0, 7.0, 6.0, 5.0, 4.0, 3.0, 2.0, 1.0};
    threeMergeSort(test_arr, 10, 0, 9);
    isSorted(test_arr, 10);
}
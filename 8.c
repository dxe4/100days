#include <stdio.h>
#include <stdlib.h>


int search(int * arr, int arr_len, int item) {
    int left = 0;
    int right = arr_len - 1;
    int middle;

    while (left <= right) {
        middle = (left + right) / 2;

        if (item < arr[middle]) {
            right = middle - 1;
        } else if (item > arr[middle]) {
            left = middle + 1;
        } else {
            return middle;
        }
    }

    return -1;
}

int main () {
    int arr[5] = {2, 3, 4, 8, 10};
    int res = search(arr, 5, 8);
    printf("%d", res);
}
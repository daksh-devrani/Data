#include<stdio.h>
#include<stdlib.h>

void countSort(int arr[], int n, int sortarr[]) {
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }

    int *countarr = (int *)malloc((max + 1) * sizeof(int));
    if (countarr == NULL) {
        return;
    }

    for(int i = 0; i <= max; i++) {
        countarr[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        countarr[arr[i]]++;
    }

    for(int i = 1; i <= max; i++) {
        countarr[i] += countarr[i - 1];
    }

    for(int i = n - 1; i >= 0; i--) {
        sortarr[countarr[arr[i]] - 1] = arr[i];
        countarr[arr[i]]--;
    }

    free(countarr);
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) {
        printf("Enter %d term: ", i);
        scanf("%d", &arr[i]);
    }
    int sortarr[n]; 
    countSort(arr, n, sortarr);
    for(int i = 0; i < n; i++) {
        printf("%d ", sortarr[i]);
    }
}
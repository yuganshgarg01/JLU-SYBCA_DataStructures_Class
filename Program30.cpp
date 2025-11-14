#include <stdio.h>

void quicksort(int a[], int low, int high) {
    int i = low, j = high;
    int pivot = a[low];   // first element as pivot
    int temp;

    if (low < high) {
        while (i < j) {
            while (a[i] <= pivot && i <= high) 
                i++;
            while (a[j] > pivot && j >= low) 
                j--;

            if (i < j) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        // place pivot in correct position
        a[low] = a[j];
        a[j] = pivot;

        // recursive calls
        quicksort(a, low, j - 1);
        quicksort(a, j + 1, high);
    }
}

int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quicksort(a, 0, n - 1);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

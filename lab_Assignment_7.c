#include <stdio.h>

// Function to swap two elements
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to perform Bubble Sort and count swaps
int bubbleSort(int arr[], int n, int swaps[]) {
    int totalBSwaps = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                swap(&arr[j], &arr[j + 1]);

                // Count swaps
                swaps[arr[j + 1]]++;
                swaps[arr[j]]++;
                totalBSwaps++;
            }
        }
    }
    return totalBSwaps;
}

// Function to perform Selection Sort and count swaps
int selectionSort(int arr[], int n, int swaps[]) {
    int totalSSwaps = 0;
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(&arr[i], &arr[min_idx]);
            swaps[arr[i]]++;
            swaps[arr[min_idx]]++;
            totalSSwaps++;
        }
    }
    return totalSSwaps;
}

int main() {
    // Define arrays
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);

    // Initialize swap counters for each value to zero
    int swaps1[100] = {0};
    int swaps2[100] = {0};

    // Bubble Sort
    printf("array1 bubble sort:\n");
    int totalBubbleSwaps1 = bubbleSort(array1, n1, swaps1);
    for (int i = 0; i < n1; i++) {
        printf("%d: %d\n", array1[i], swaps1[array1[i]]);
    }
    printf("%d\n\n", totalBubbleSwaps1);

    printf("array2 bubble sort:\n");
    int totalBSwaps2 = bubbleSort(array2, n2, swaps2);
    for (int i = 0; i < n2; i++) {
        printf("%d: %d\n", array2[i], swaps2[array2[i]]);
    }
    printf("%d\n\n", totalBSwaps2);

    // Selection Sort
    printf("array1 selection sort:\n");
    int totalSSwaps1 = selectionSort(array1, n1, swaps1);
    for (int i = 0; i < n1; i++) {
        printf("%d: %d\n", array1[i], swaps1[array1[i]]);
    }
    printf("%d\n\n", totalSSwaps1);

    printf("array2 selection sort:\n");
    int totalSSwaps2 = selectionSort(array2, n2, swaps2);
    for (int i = 0; i < n2; i++) {
        printf("%d: %d\n", array2[i], swaps2[array2[i]]);
    }
    printf("%d\n", totalSSwaps2);

    return 0;
}

#include <stdio.h>

// Function to print the array as a graphical representation
void printGraph(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        // Print a bar representing the array value
        for (int j = 0; j < arr[i]; j++) {
            printf("*");
        }
        printf("  "); // Spacing between bars
    }
    printf("\n");
}

// Function to perform insertion sort and print graph at each step
void insertionSortWithGraph(int arr[], int n) {
    int i, key, j;

    // Loop through the array elements starting from the second element
    for (i = 1; i < n; i++) {
        key = arr[i]; // Element to be inserted in the sorted part
        j = i - 1;

        // Shift elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; // Insert key at the correct position

        // Print the array as a graphical representation at each step
        printf("Step %d: ", i);
        printGraph(arr, n);
    }
}

int main() {
    int n;

    // Prompt the user to enter the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Create an array based on the size entered by the user
    int arr[n];

    // Prompt the user to enter the elements of the array
    printf("Enter %d elements for the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the initial array as a graph
    printf("Initial array (graph representation):\n");
    printGraph(arr, n);

    // Sort the array using insertion sort and print graph at each step
    insertionSortWithGraph(arr, n);

    // Print the final sorted array as a graph
    printf("\nSorted array (graph representation):\n");
    printGraph(arr, n);

    return 0;
}

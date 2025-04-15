#include <stdio.h>

// Function prototypes
void Insertion(int arr[], int* size, int capacity);
void deletion(int arr[], int* size);
void LinearSearch(int arr[], int size);
void BinarySearch(int arr[], int size);

int main() {
    int myarr[20], size = 5, capacity = 20, choice;

    // Initial input for the array
    for (int i = 0; i < size; i++) {
        printf("Enter the value of arr[%d]: ", i + 1);
        scanf("%d", &myarr[i]);
    }

    // Display the array
    printf("You Entered: ");
    for (int i = 0; i < size; i++) {
        printf("%d\t", myarr[i]);
    }
    printf("\n");

    // Menu for operations
    printf("\nMenu:\n");
    printf("1. Insertion\n");
    printf("2. Deletion\n");
    printf("3. Linear Search\n");
    printf("4. Binary Search\n");
    printf("5. Exit\n");
    
    // User input for choice
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            Insertion(myarr, &size, capacity);
            break;
        case 2:
            deletion(myarr, &size);
            break;
        case 3:
            LinearSearch(myarr, size);
            break;
        case 4:
            // Binary Search requires sorted array
            // Sorting array before binary search
            for (int i = 0; i < size - 1; i++) {
                for (int j = 0; j < size - i - 1; j++) {
                    if (myarr[j] > myarr[j + 1]) {
                        int temp = myarr[j];
                        myarr[j] = myarr[j + 1];
                        myarr[j + 1] = temp;
                    }
                }
            }
            BinarySearch(myarr, size);
            break;
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice, please try again.\n");
    }

    return 0;
}

// Function to insert an element into the array
void Insertion(int arr[], int* size, int capacity) {
    if (*size >= capacity) {
        printf("Array is full, cannot insert more elements.\n");
        return;
    }

    int value;
    printf("Enter the value to insert: ");
    scanf("%d", &value);

    arr[*size] = value;
    (*size)++;
    printf("Element inserted successfully.\n");
}

// Function to delete an element from the array
void deletion(int arr[], int* size) {
    if (*size == 0) {
        printf("Array is empty, no element to delete.\n");
        return;
    }

    (*size)--;
    printf("Element deleted successfully.\n");
}

// Function for Linear Search
void LinearSearch(int arr[], int size) {
    int key;
    printf("Enter the value to search: ");
    scanf("%d", &key);

    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            printf("Element found at index %d\n", i);
            return;
        }
    }

    printf("Element not found in the array.\n");
}

// Function for Binary Search (Array must be sorted for binary search to work)
void BinarySearch(int arr[], int size) {
    int left = 0, right = size - 1;
    int key;

    printf("Enter the value to search: ");
    scanf("%d", &key);

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            printf("Element found at index %d\n", mid);
            return;
        }

        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    printf("Element not found in the array.\n");
}

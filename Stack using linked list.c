#include <stdio.h>
#include <stdlib.h>

// Define a structure for a stack node
struct Node {
    int data;           // Data of the node
    struct Node* next;  // Pointer to the next node
};

// Stack structure
struct Stack {
    struct Node* top;  // Pointer to the top of the stack
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Initialize the stack
void initStack(struct Stack* stack) {
    stack->top = NULL;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Push operation: Add an element to the top of the stack
void push(struct Stack* stack, int data) {
    struct Node* newNode = createNode(data);  // Create a new node
    newNode->next = stack->top;  // Point the new node to the current top
    stack->top = newNode;  // Make the new node the top of the stack
    printf("%d pushed onto the stack.\n", data);
}

// Pop operation: Remove and return the top element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! Cannot pop.\n");
        return -1;  // Return a sentinel value to indicate empty stack
    }
    struct Node* temp = stack->top;
    int poppedData = temp->data;  // Get the data of the top element
    stack->top = stack->top->next;  // Move the top to the next element
    free(temp);  // Free the memory of the popped node
    printf("%d popped from the stack.\n", poppedData);
    return poppedData;
}

// Peek operation: Return the top element without removing it
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! Cannot peek.\n");
        return -1;  // Return a sentinel value to indicate empty stack
    }
    return stack->top->data;  // Return the data of the top element
}

// Display the stack from top to bottom
void displayStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }

    struct Node* temp = stack->top;
    printf("Stack contents: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initStack(&stack);  // Initialize the stack
    int choice, value;

    // Menu-based approach
    do {
        printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Push
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;

            case 2:  // Pop
                pop(&stack);
                break;

            case 3:  // Peek
                printf("Top element is: %d\n", peek(&stack));
                break;

            case 4:  // Display stack
                displayStack(&stack);
                break;

            case 5:  // Exit
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;
int visited[MAX];

// Function to add a node to the queue
void enqueue(int vertex) {
    if (rear == MAX - 1)
        printf("Queue is full\n");
    else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = vertex;
    }
}

// Function to remove a node from the queue
int dequeue() {
    int vertex;
    if (front == -1 || front > rear)
        return -1;
    else {
        vertex = queue[front];
        front++;
        return vertex;
    }
}

// BFS function
void bfs(int graph[MAX][MAX], int n, int start) {
    int i;
    enqueue(start);
    visited[start] = 1;

    while (front <= rear) {
        int current = dequeue();
        printf("%d ", current);

        for (i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n, i, j, start;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    printf("BFS traversal: ");
    bfs(graph, n, start);
    printf("\n");

    return 0;
}

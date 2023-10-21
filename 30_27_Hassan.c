#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node* adjLists[MAX_VERTICES];
    bool visited[MAX_VERTICES];
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// Function to perform BFS traversal
void bfs(struct Graph* graph, int startVertex) {
    struct Node* queue[MAX_VERTICES];
    int front = 0, rear = 0;
    queue[rear++] = createNode(startVertex);
    graph->visited[startVertex] = true;

    printf("BFS Traversal starting from vertex %d: ", startVertex);

    while (front < rear) {
        int currentVertex = queue[front]->vertex;
        printf("%d ", currentVertex);
        struct Node* temp = graph->adjLists[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            if (!graph->visited[adjVertex]) {
                queue[rear++] = createNode(adjVertex);
                graph->visited[adjVertex] = true;
            }
            temp = temp->next;
        }
        front++;
    }
}

int main() {
    struct Graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 2, 5);

    int startVertex = 0;
    bfs(graph, startVertex);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define Nov 5

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* CreateNode(int v) {
    struct Node* nn = (struct Node*)malloc(sizeof(struct Node));
    nn->vertex = v;
    nn->next = NULL;
    return nn;
}

struct Graph{
    struct Node** AdjList;
};

struct Graph* CreateGraph(){
    struct Graph* g = (struct Graph*)malloc(sizeof(struct Graph));
    g->AdjList = (struct Node**)malloc(Nov * sizeof(struct Node*));
    for(int i = 0; i < Nov; i++) {
        g->AdjList[i] = NULL;
    }
    return g;
}

void AddEdge(struct Graph* g, int i, int j) {
    struct Node* nn = CreateNode(j);
    nn->next = g->AdjList[i];
    g->AdjList[i] = nn;
    
    nn = CreateNode(i);
    nn->next = g->AdjList[j];
    g->AdjList[j] = nn;
}

void PrintGraph(struct Graph* g) {
    for(int i = 0; i < Nov; i++) {
        struct Node* temp = g->AdjList[i];
        printf("Vertex %d: ", i);
        while(temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}
void DFS(struct Graph* g, int start_vertex){
    int visited[Nov] = {0};
    int stack[Nov];
    int top = -1;

    stack[++top] = start_vertex;
    visited[start_vertex] = 1;

    while(top != -1) {
        int current_vertex = stack[top--];
        printf("%d ", current_vertex);

        struct Node* temp = g->AdjList[current_vertex];
        while(temp) {
            int vx = temp->vertex;
            if(!visited[vx]) {
                stack[++top] = vx;
                visited[vx] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}
int main() {
    struct Graph* graph = CreateGraph();
    AddEdge(graph, 0, 1);
    AddEdge(graph, 0, 2);
    AddEdge(graph, 1, 3);
    AddEdge(graph, 1, 4);
    AddEdge(graph, 2, 3);
    AddEdge(graph, 3, 4);
    PrintGraph(graph);
    return 0;
}
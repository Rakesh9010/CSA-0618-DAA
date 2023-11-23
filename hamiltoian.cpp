#include <stdio.h>
#include <stdbool.h>

#define MAX 10


int vertices;


int graph[MAX][MAX];


int path[MAX];


bool isSafe(int v, int pos, int path[]) {
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}


bool hamiltonianCircuitUtil(int path[], int pos) {
    if (pos == vertices) {
        
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int v = 1; v < vertices; v++) {
        if (isSafe(v, pos, path)) {
            path[pos] = v;

            if (hamiltonianCircuitUtil(path, pos + 1) == true)
                return true;

            path[pos] = -1; 
        }
    }

    return false;
}


void findHamiltonianCircuit() {
    int path[MAX];

    
    for (int i = 0; i < vertices; i++)
        path[i] = -1;

   
    path[0] = 0;

    if (hamiltonianCircuitUtil(path, 1) == false) {
        printf("Hamiltonian Circuit does not exist.\n");
        return;
    }

    printf("Hamiltonian Circuit:\n");
    for (int i = 0; i < vertices; i++)
        printf("%d ", path[i]);
    printf("%d\n", path[0]);
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            scanf("%d", &graph[i][j]);

    findHamiltonianCircuit();

    return 0;
}

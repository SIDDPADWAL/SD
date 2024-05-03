#include <iostream>
#include <stdlib.h>

using namespace std;

int cost[10][10], i, j, k, n;
int qu[10], front = -1, rear = -1;
int stk[10], top = -1;
int visit[10] = {0}, visited[10] = {0};
int visit1[10] = {0}, visited1[10] = {0};

void bfs() {
    int v;
    cout << "Enter initial vertex for BFS: ";
    cin >> v;
    cout << "BFS traversal starting from vertex " << v << ": ";
    visited[v] = 1;
    qu[++rear] = v;

    while (front != rear) {
        v = qu[++front];
        cout << v << " ";

        for (j = 1; j <= n; j++) {
            if (cost[v][j] != 0 && visited[j] == 0) {
                qu[++rear] = j;
                visited[j] = 1;
            }
        }
    }
    cout << endl;
}

void dfs() {
    int v;
    cout << "Enter initial vertex for DFS: ";
    cin >> v;
    cout << "DFS traversal starting from vertex " << v << ": ";
    visited1[v] = 1;
    stk[++top] = v;

    while (top != -1) {
        v = stk[top--];
        cout << v << " ";

        for (j = 1; j <= n; j++) {
            if (cost[v][j] != 0 && visited1[j] == 0) {
                visited1[j] = 1;
                stk[++top] = j;
            }
        }
    }
    cout << endl;
}

int main() {
    int m;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    cout << "\nEDGES:\n";
    for (k = 1; k <= m; k++) {
        cin >> i >> j;
        cost[i][j] = 1;
        cost[j][i] = 1;
    }

    // Display adjacency matrix
    cout << "The adjacency matrix of the graph is:\n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cout << " " << cost[i][j];
        }
        cout << endl;
    }

    bfs();
    dfs();

    return 0;
}
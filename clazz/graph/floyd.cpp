// Author: Sardinary
// Date: 2023-10-29

#ifndef GRAPH_FLOYD_CPP_
#define GRAPH_FLOYD_CPP_

#include <iostream>
#include "graph1.cpp"
using namespace std;


//打印uv之间的最短路径
void printPath(int u, int v, int path[][MAXVEX]) {
    if (path[u][v] == -1) {
        printf("<%d,%d>", u, v);
    } else {
        int mid = path[u][v];
        printPath(u, mid, path);
        printPath(mid, v, path);
    }
}

void floyd(int n, MGraph g, int path[][MAXVEX]) {
    int A[MAXVEX][MAXVEX];
    for (int i = 0; i < g.numVertexes; i++) {
        for (int j = 0; j < g.numVertexes; j++) {
            path[i][j] = -1;
            A[i][j] = g.arc[i][j];
        }
    }

    for (int i = 0; i < g.numVertexes; i++) {
        for (int j = 0; j < g.numVertexes; j++) {
            for (int k = 0; k < g.numVertexes; k++) {
                if (A[j][k] > A[j][i] + A[i][k]) {
                    A[j][k] = A[j][i] + A[i][k];
                    path[j][k] = i;
                }
            }
        }
    }
}


#endif  // GRAPH_FLOYD_CPP_
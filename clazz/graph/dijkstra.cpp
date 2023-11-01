// Author: Sardinary
// Date: 2023-10-27

#ifndef GRAPH_DIJKSTRA_CPP_
#define GRAPH_DIJKSTRA_CPP_

#include <iostream>
#include "graph1.cpp"
using namespace std;

int path[MAXVEX];
int shortPathTable[MAXVEX];
void shortestPath_D(MGraph g, int v0) {
    int final[MAXVEX];

    //初始化
    for (int i = 0; i < g.numVertexes; i++) {
        final[i] = 0;
        shortPathTable[i] = g.arc[v0][i];
        path[i] = 0;
    }
    shortPathTable[v0] = 0;
    final[v0] = 1;

    for (int i = 1; i < g.numVertexes; i++) {
        int min = INFINITY;
        int k;
        for (int j = 0; j < g.numVertexes; j++) {
            if (!final[j] && shortPathTable[j] < min) {
                k = j;
                min = shortPathTable[j];
            }
        }
        final[k] = 1;
        for (int j = 0; j < g.numVertexes; j++) {
            if (!final[j] && (min + g.arc[k][j] < shortPathTable[j])) {
                shortPathTable[j] = min + g.arc[k][j];
                path[j] = k;
            }
        }
    }

    
}


#endif  // GRAPH_DIJKSTRA_CPP_
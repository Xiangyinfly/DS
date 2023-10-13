// Author: Sardinary
// Date: 2023-10-13

/*
邻接矩阵的深度优先遍历
*/

#ifndef GRAPH_DFS1_CPP_
#define GRAPH_DFS1_CPP_

#include <iostream>
#include "graph1.cpp"

using namespace std;

bool visited[MAXVEX];
void DFS(MGraph g, int i) {
    visited[i] = true;
    cout << g.vex[i];
    for (int j = 0; j < g.numVertexes; j++) {
        if (g.arc[i][j] == 1 && !visited[j]) {
            DFS(g, j);
        }
    }
}

void DFSTraverse(MGraph g) {
    for (int i = 0; i < g.numVertexes; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < g.numVertexes; i++) {
        if (!visited[i]) {
            DFS(g, i);
        }
    }
}

#endif  // GRAPH_DFS1_CPP_
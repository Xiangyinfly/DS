// Author: Sardinary
// Date: 2023-10-17

#ifndef GRAPH_MYDFS_CPP_
#define GRAPH_MYDFS_CPP_

#include <iostream>
#include "graph2.cpp"
using namespace std;

bool visited[MAXVEX];

void dfs(GraphAdjList g, int i) {
    EdgeNode* p = g.adjList[i].firstedge;
    visited[i] = true;
    cout << g.adjList[i].data;

    while (p) {
        if (!visited[p->adjvex]) {
            dfs(g, p->adjvex);
        }
        p = p->next;
    }
}

void dfst(GraphAdjList g) {
    for (int i = 0; i < g.numVertexes; i++) {
        visited[i] = false;
    }

    for (int i = 0; i < g.numVertexes; i++) {
        if (!visited[i]) {
            dfs(g, i);
        }
    }
}

#endif  // GRAPH_MYDFS_CPP_
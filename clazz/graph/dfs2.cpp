// Author: Sardinary
// Date: 2023-10-13

/*
邻接表的深度优先遍历
*/

#ifndef GRAPH_DFS2_CPP_
#define GRAPH_DFS2_CPP_

#include <iostream>
#include "graph2.cpp"
using namespace std;

bool visited[MAXVEX];

void DFS(GraphAdjList g, int i) {
    EdgeNode* p;
    visited[i] = true;
    cout << g.adjList[i].data;
    p = g.adjList[i].firstedge;

    while (p) {
        if (!visited[p->adjvex]) {
            DFS(g, p->adjvex);
        }
        p = p->next;
    }
}

void DFSTraverse(GraphAdjList g) {
    //把所有已访问标记设置为false
    for (int i = 0; i < g.numVertexes; i++) {
        visited[i] = false;
    }

    //开始遍历
    for (int i = 0; i < g.numVertexes; i++) {
        if (!visited[i]) {
            DFS(g, i);
        }
    }
}


#endif  // GRAPH_DFS2_CPP_
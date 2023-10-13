// Author: Sardinary
// Date: 2023-10-13

/**
 *邻接矩阵的广度优先遍历
*/

#ifndef GRAPH_BFS1_CPP_
#define GRAPH_BFS1_CPP_

#include <iostream>
#include "graph2.cpp"
#include <queue>
using namespace std;

bool visited[MAXVEX];

void BFSTraverse(GraphAdjList g) {
    EdgeNode* p;
    queue<int> q;

    for (int i = 0; i < g.numVertexes; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < g.numVertexes; i++) {
        if (!visited[i]) {
            visited[i] = true;
            cout << g.adjList[i].data;
            q.push(i);

            while (!q.empty()) {
                int f = q.front();
                q.pop();
                p = g.adjList[f].firstedge;
                while (p) {
                    if (!visited[p->adjvex]) {
                        visited[p->adjvex] = true;
                        cout << g.adjList[p->adjvex].data;
                        q.push(p->adjvex);
                    }
                    p = p->next;
                }
            }
        }
    }
}

#endif  // GRAPH_BFS1_CPP_
// Author: Sardinary
// Date: 2023-10-17

#ifndef GRAPH_MYBFS_CPP_
#define GRAPH_MYBFS_CPP_

#include <iostream>
#include <queue>
#include "graph2.cpp"
using namespace std;


bool visited[MAXVEX];

void bfst(GraphAdjList g) {
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

#endif  // GRAPH_MYBFS_CPP_
// Author: Sardinary
// Date: 2023-10-13

#ifndef GRAPH_BFS1_CPP_
#define GRAPH_BFS1_CPP_

#include <iostream>
#include "graph1.cpp"
#include <queue>
using namespace std;

bool visited[MAXVEX];

void BFSTraverse(MGraph g) {
    queue<int> q;
    for (int i = 0; i < g.numVertexes; i++) {
        visited[i] = false;
    }

    for (int i = 0; i < g.numVertexes; i++) {
        if (!visited[i]) {
            visited[i] = true;
            cout << g.vex[i];
            q.push(i);
            while (!q.empty()) {
                int f = q.front();
                q.pop();

                for (int j = 0; j < g.numVertexes; j++) {
                    if (g.arc[i][j] == 1 && !visited[j]) {
                        visited[j] = true;
                        cout << g.vex[j];
                        q.push(j);
                    }
                }
            }
        }
    }
}

#endif  // GRAPH_BFS1_CPP_
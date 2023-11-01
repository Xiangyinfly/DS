// Author: Sardinary
// Date: 2023-10-19

#ifndef GRAPH_TOPOSORT_CPP_
#define GRAPH_TOPOSORT_CPP_

#include <iostream>
#include <stack>
#include "graph2.cpp"
using namespace std;

int indegree[MAXVEX];
stack<int> s;

//计算入度
void findInDegree(GraphAdjList g) {
    EdgeNode* p;
    for (int i = 0; i < g.numVertexes; i++) {
        p = g.adjList[i].firstedge;
        while (p) {
            indegree[p->adjvex]++;
            p = p->next;
        }
    }
}

void topoLogicSort(GraphAdjList g) {
    findInDegree(g);
    for (int i = 0; i < g.numVertexes; i++) {
        if (!indegree[i]) {
            s.push(i);
        }
    }
    int count = 0;
    EdgeNode* e;
    while (!s.empty()) {
        int top = s.top();
        s.pop();
        cout << top << "," << g.adjList[top].data << endl;
        count++;
        for (e = g.adjList[top].firstedge; e; e = e->next) {
            if (!(--indegree[e->adjvex])) {
                s.push(e->adjvex);
            }
        }
    }

    //count小于顶点数，存在环
    if (count < g.numVertexes) {
        cout << "存在环！" << endl;
    }

}


#endif  // GRAPH_TOPOSORT_CPP_
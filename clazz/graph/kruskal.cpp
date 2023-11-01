// Author: Sardinary
// Date: 2023-10-19

#ifndef GRAPH_KRUSKAL_CPP_
#define GRAPH_KRUSKAL_CPP_

#include <iostream>
#include <algorithm>
#include "graph1.cpp"
using namespace std;

#define MAXEDGE 100
#define MAXVEX 100

typedef struct Edge {
    int begin;
    int end;
    int weight;
};

bool compare(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}


/*
另外的方式判断是否成环：
当一条弧加入最小生成树时，将两个结点中编号较大的结点的编号记为编号较小的结点的编号
如果出现两结点编号相同情况，则出现成环情况
生成结束时，所有的结点编号相同
*/


int find(int* parent, int f) {
    while (parent[f] > 0) {
        f = parent[f];
    }
    return f;
}

void miniSpanTree_kruskal(MGraph g) {
    Edge edges[MAXEDGE];
    int parent[MAXVEX];

    //把邻接矩阵转化为边表并排序
    int k = 0;
    for (int i = 0; i < g.numVertexes; i++) {
        for (int j = 0; j < i; j++) {
            if (g.arc[i][j] > 0) {
                edges[k].begin = i;
                edges[k].end = j;
                edges[k].weight = g.arc[i][j];
                k++;
            }
        }
    }
    sort(edges, edges + g.numEdges, compare);


    for (int i = 0; i < g.numVertexes; i++) {
        parent[i] = 0;
    }
    for (int i = 0; i < g.numEdges; i++) {
        int n = find(parent, edges[i].begin);
        int m = find(parent, edges[i].end);
        if (m != n) {
            parent[n] = m;
            cout << "(" << edges[i].begin << "," << edges[i].end << ")" << edges[i].weight << endl; 
        }
    }
}


#endif  // GRAPH_KRUSKAL_CPP_
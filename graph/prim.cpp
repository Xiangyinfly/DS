// Author: Sardinary
// Date: 2023-10-15

#ifndef GRAPH_PRIM_CPP_
#define GRAPH_PRIM_CPP_

#include <iostream>
#include "graph1.cpp"
using namespace std;

void miniSpanTree_Prim(MGraph g) {
    int adjvex[MAXVEX];//保存相关顶点下标
    int lowcost[MAXVEX];//保存相关顶点间边的权
    lowcost[0] = 0;//初始化第一个权值为0，v0加入生成树
    adjvex[0] = 0;

    for (int i = 0; i < g.numVertexes; i++) {
        lowcost[i] = g.arc[0][i];
        adjvex[i] = 0;
    }
    for (int i = 0; i < g.numVertexes; i++) {
        int min = INFINITY;
        int j = 1;
        int k = 0;
        while (j < g.numVertexes) {
            if (lowcost[j] != 0 && lowcost[j] < min) {
                min = lowcost[j];
                k = j;
            }
            j++;
        }
        printf("(%d,%d)", adjvex[k], k);
        lowcost[k] = 0;
        for (int j = 0; j < g.numVertexes; j++) {
            if (lowcost[j] != 0 && g.arc[k][j] < lowcost[j]) {
                lowcost[j] = g.arc[k][j];
                adjvex[j] = k;
            }
        }
    }
}
#endif  // GRAPH_PRIM_CPP_
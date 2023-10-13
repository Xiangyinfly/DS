// Author: Sardinary
// Date: 2023-10-13

/*
邻接表法
*/

#ifndef GRAPH_GRAPG2_CPP_
#define GRAPH_GRAPG2_CPP_

#include <iostream>

using namespace std;

typedef char VertexType;//顶点类型
typedef int EdgeType;//权值
#define MAXVEX 100//最大顶点数
#define INFINITY 65535

typedef struct EdgeNode {//边表结点
    int adjvex;//邻接点域，存储该顶点对应的下标
    EdgeType weight;//权
    EdgeNode* next;
} EdgeNode;

typedef struct VertexNode {//顶点表结点
    VertexType data;
    EdgeNode* firstedge;
} VertexNode,AdjList[MAXVEX];


typedef struct {
    AdjList adjList;
    int numVertexes, numEdges;
} GraphAdjList;

void createALGraph(GraphAdjList* g) {
    EdgeNode* e;
    cout << "输入顶点数和边数:";
    cin >> g->numVertexes;
    cin >> g->numEdges;
    for (int i = 0; i < g->numVertexes; i++) {
        cin >> g->adjList[i].data;
        g->adjList[i].firstedge = NULL;
    }

    for (int i = 0; i < g->numEdges; i++) {
        int vi,vj;
        cout << "输入边(i,j)顶点序号";
        cin >> vi;
        cin >> vj;

        e = new EdgeNode();
        e->adjvex = vj;

        //头插法
        e->next = g->adjList[vi].firstedge;
        g->adjList[vi].firstedge = e;

        e = new EdgeNode();
        e->adjvex = vi;

        //头插法
        e->next = g->adjList[vj].firstedge;
        g->adjList[vj].firstedge = e;
    }
}



#endif  // GRAPH_GRAPG2_CPP_
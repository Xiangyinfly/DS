// Author: Sardinary
// Date: 2023-10-11

/*
邻接矩阵法
*/

#ifndef GRAPH_GRAPH1_CPP_
#define GRAPH_GRAPH1_CPP_

#include <iostream>

using namespace std;

typedef char VertexType;//顶点类型
typedef int Edgetype;//权值
#define MAXVEX 100//最大顶点数
#define INFINITY 65535

class MGraph {
public:
    VertexType vex[MAXVEX];//顶点表
    Edgetype arc[MAXVEX][MAXVEX];//邻接矩阵
    int numVertexes, numEdges;//顶点数和边数
};


/*无向网图的邻接矩阵*/
void createGraph(MGraph* g) {
    cout << "输入顶点数和边数:";
    cin >> g->numVertexes;
    cin >> g->numEdges;
    for (int i = 0; i < g->numVertexes; i++) {
        cin >> g->vex[i];
    }

    //邻接矩阵初始化
    for (int i = 0; i < g->numVertexes; i++) {
        for (int j = 0; j < g->numVertexes; j++) {
            g->arc[i][j] = INFINITY;
        }
    }

    for (int i = 0; i < g->numEdges; i++) {
        int a, b, w;
        cout << "请输入坐标和权：";
        cin >> a;
        cin >> b;
        cin >> w;
        g->arc[a][b] = w;
        g->arc[b][a] = g->arc[a][b];
    }
}


#endif  // GRAPH_GRAPH1_CPP_
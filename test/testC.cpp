#include <stdio.h>
#include <stdlib.h>

typedef struct QNode {
    int data;
    struct QNode* next;
}QNode, * QueuePtr;

typedef struct {
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

void InitQueue(LinkQueue& Q) {
    Q.front = Q.rear = (QNode*)malloc(sizeof(QNode));
    if (!Q.front)
        exit(0);
    Q.front->next = NULL;
}

void EnQueue(LinkQueue& Q, int e) {
    QueuePtr p = (QNode*)malloc(sizeof(QNode));
    if (!p)
        exit(0);
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
}

void DeQueue(LinkQueue& Q, int& e) {
    if (Q.rear == Q.front)
        return;
    else
    {
        QueuePtr p;
        p = Q.front->next;
        e = p->data;
        Q.front->next = Q.front->next->next;
        if (Q.rear == p)
            Q.rear = Q.front;
        free(p);
    }
}

//¡⁄Ω”±Ì
typedef struct ArcNode { //±ﬂ±Ì 
    int adjvex;
    struct ArcNode* nextarc;
}ArcNode;

typedef struct vnode {
    int data;
    ArcNode* firstarc;
}vnode, adjlist[105];

typedef struct {
    adjlist vertices;
    int vexnum, arcnum;
}ALGraph;

void Creatadlist(ALGraph& G) {
    int i, j, k;
    ArcNode* s, * l;
    scanf("%d %d", &G.vexnum, &G.arcnum);
    for (i = 1;i <= G.vexnum;++i)
    {
        G.vertices[i].data = i;
        G.vertices[i].firstarc = NULL;
    }
    for (k = 0;k < G.arcnum;k++)
    {
        scanf("%d %d", &i, &j);
        s = (ArcNode*)malloc(sizeof(ArcNode));
        s->adjvex = j;
        s->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = s;
        l = (ArcNode*)malloc(sizeof(ArcNode));
        l->adjvex = i;
        l->nextarc = G.vertices[j].firstarc;
        G.vertices[j].firstarc = l;
    }
}

void BFSTraVErse(ALGraph& G) {
    bool visited[G.vexnum + 1];
    LinkQueue Q;
    InitQueue(Q);
    int m, v;
    for (v = 1;v < G.vexnum + 1;++v)
    {
        double count = 1;
        int level = 0, last = v, tail = 0;
        for (m = 1;m <= G.vexnum;++m)
            visited[m] = false;
        visited[v] = true;
        EnQueue(Q, v);
        while (!(Q.rear == Q.front))
        {
            int u, w;
            ArcNode* p;
            DeQueue(Q, u);
            for (p = G.vertices[u].firstarc;p != NULL;p = p->nextarc)
            {
                if (!visited[p->adjvex])
                {
                    w = p->adjvex;
                    visited[w] = true;
                    EnQueue(Q, w);
                    count = count + 1;
                    tail = w;
                }
            }
            if (u == last)
                level++, last = tail;
            if (level > 5) break;
        }
        while (!(Q.rear == Q.front))
        {
            int u;
            DeQueue(Q, u);
        }
        count = count / G.vexnum * 100;
        printf("%d: %.2lf%%\n", v, count);
    }
}
int main(int argc, char** argv) {
    int kk;
    ALGraph G;
    Creatadlist(G);
    BFSTraVErse(G);
    return 0;
}
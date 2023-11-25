#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 100

typedef int EdgeType;

typedef struct EdgeNode{ // 节点
    int adjvex;
    EdgeType weight;
    struct EdgeNode *next;
} EdgeNode;

typedef struct VertexNode{ // 单个顶点表
    int data;// 节点个数
    EdgeNode *firstedge;
} VertexNode, AdjList[MAXVEX];

typedef struct{ // 图
    AdjList adjList;// 邻接表
    int numNodes, numEdges;
} GraphAdjList;

int vexs[4] = {1, 2, 3, 4};
int adj[4][4] = {0, 1, 0, 1
                ,1, 0, 1, 1
                ,0, 1, 0, 1
                ,1, 1, 1, 0};


void ArraytoList(GraphAdjList *G){
    G->numEdges = 10;
    G->numNodes = 4;
    int i, j;

    for(i = 0; i < G->numNodes; i++){ // 初始化
        G->adjList[i].data = 0;
        G->adjList[i].firstedge = NULL;
    }

    EdgeNode *pe;
    EdgeNode *p;

    for(i = 0; i < 4; i++){
        // G->adjList[i].firstedge = p; // p指向第一个节点
        for(j = 0; j < 4; j++){
            if(adj[i][j] != 0){
                pe = (EdgeNode *)malloc(sizeof(EdgeNode));
                pe->adjvex = j;
                pe->weight = adj[i][j];
                if (G->adjList[i].firstedge == NULL){
                    G->adjList[i].firstedge = pe;
                    p = G->adjList[i].firstedge;
                } else {
                    p->next = pe;
                    p = p->next;
                }
                // pe->next = G->adjList[i].firstedge;
                // G->adjList[i].firstedge = pe;
                G->adjList[i].data++;
            }
        }
        p = NULL;
    }
    printf("%d\n", 1);
}
int main() {
    int a[2][2] = {1, 2, 3, 5};
    printf("%d\n", a[1][1]);
    GraphAdjList *G = (GraphAdjList *)malloc(sizeof(GraphAdjList));
    ArraytoList(G);
}
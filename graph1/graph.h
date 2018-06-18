//
// Created by 张永乐 on 2018/6/18.
//

#ifndef GRAPH1_GRAPH_H
#define GRAPH1_GRAPH_H

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;

typedef char VtType;

bool Visted[30];

typedef struct chain{
    int vid;
    struct chain *next;
}Queue,*Qnode;
Qnode head = NULL;


typedef struct arc{
    int adj;
    struct arc* nextarc;
}*arcNode,arcnode;       //表节点

typedef struct {
    VtType data;
    arcNode firstarc;
}VNode,Vlist[30];

typedef struct {
    Vlist vertices;
    int vexnum,arcnum;
}VLGraph;

void addArc(VLGraph &G,int m, int n);

void createGraph(VLGraph &G);

void showList(VLGraph &G);

void DFS(VLGraph &G, int v);

void DFSApi(VLGraph G);

void BFS(VLGraph G,int v);

void BFSApi(VLGraph G);


#endif //GRAPH1_GRAPH_H

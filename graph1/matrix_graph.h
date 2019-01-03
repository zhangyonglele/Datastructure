//
// Created by 张永乐 on 2018/12/19.
//

#ifndef GRAPH1_MATRIX_GRAPH_H
#define GRAPH1_MATRIX_GRAPH_H

#define MAX_VERTEX 50

#include <cstdlib>
#include <cmath>
#include <iostream>

typedef int vertexType;

typedef int edgeType;

typedef struct {
    vertexType vex[MAX_VERTEX];
    edgeType edgeMatrix[MAX_VERTEX][MAX_VERTEX];
    int vertexNumber,edgeNumber;
    int graphType;
}graph;

typedef struct queueNode{
    int weight;
    int vex1;
    int vex2;
    struct queueNode *next;
}queue_node,*queue;

typedef struct mark{
    int vex;
    int lowCost;
}edgeMark;

typedef struct markS{
    int beginning;
    int ending;
    int weight;
}edgeMarkS;

void initQ(queue &H){
    H = (queue)malloc(sizeof(queue_node));
    H->next = NULL;
}

void enQ(queue &H){
    queue temp;
    temp = (queue)malloc(sizeof(queue_node));

}
bool isVisited[MAX_VERTEX];

int createMGraph(graph &G);

int addEdgeD(graph &G,int V1,int V2);

int addEdgeN(graph &G,int V1,int V2);

int initMatrix(graph &G, int vex);

void showMatrix(graph G);

void DFSTraverse(graph G);

void MDFS(graph &G,int i);

void warshall(graph &G);

void initCloseEdge(edgeMark mark[],graph &G,int vex);

int selectMin(edgeMark mark[],int vexNumber);

void prime(graph &G);

void dist(graph &G);
#endif //GRAPH1_MATRIX_GRAPH_H

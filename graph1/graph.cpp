//
// Created by 张永乐 on 2018/6/18.
//

#include "graph.h"
using namespace std;

void addArc(VLGraph &G,int m, int n){
    arcNode np,curp,save;

    np = (arcNode)malloc(sizeof(arcnode));    //构造表节点的数据
    np->adj = n;
    np->nextarc = NULL;
    curp = G.vertices[m].firstarc;
    if(curp == NULL){           //如果第一个为空，直接插入
        G.vertices[m].firstarc = np;
    } else{                     //第一个不为空，则将其后移
        while (curp->adj < np->adj){
            save = curp;
            curp = curp->nextarc;
            if(curp == NULL){
                break;
            }
        }
        if(curp == NULL){
            save->nextarc = np;
        } else{
            if(curp == G.vertices[m].firstarc){
                save = G.vertices[m].firstarc;
                G.vertices[m].firstarc = np;
                np->nextarc = save;
            } else{
                save->nextarc = np;
                np->nextarc = curp;
            }
        }
    }
}//插入图节点

void createGraph(VLGraph &G){
    cout<<"请输入有几个顶点"<<endl;
    cin>>G.vexnum;
    cout<<"请输入有几条边"<<endl;
    cin>>G.arcnum;
    for(int temp = 0;temp < G.vexnum;temp++){
        G.vertices[temp].firstarc = NULL;
        cout<<"输入第"<<temp+1<<"个顶点的数据"<<endl;
        cin>>G.vertices[temp].data;
    }
    for(int temp = 0;temp < G.arcnum;temp++){
        cout<<"有关第"<<temp+1<<"条边的信息，分别输入两个点";
        int n,m;
        cin>>n;
        cin>>m;
        addArc(G,n,m);
        addArc(G,m,n);
    }
}//创建图

void showList(VLGraph &G){
    arcNode curp;
    cout<<"输出邻接链表"<<endl;
    for(int temp = 0;temp < G.vexnum;temp++){
        cout<<G.vertices[temp].data;
        curp = G.vertices[temp].firstarc;
        while (curp != NULL){
            cout<<"-->"<<curp->adj;
            curp = curp->nextarc;
        }
        cout<<"-->NULL"<<endl;
    }
}//输出邻接链表

void DFS(VLGraph &G, int v){
    arcNode  curp;

    while (!Visted[v]){
        cout<<G.vertices[v].data;
        Visted[v] = true;
        curp = G.vertices[v].firstarc;
        while (curp != NULL && Visted[curp->adj]){
            curp = curp->nextarc;
        }
        if(curp == NULL){
            break;
        } else{
            DFS(G,curp->adj);
        }
    }
}//深度优先函数

void  DFSApi(VLGraph G){
    int temp;
    cout<<"深度优先遍历结果如下"<<endl;
    for(temp = 0;temp < G.vexnum;temp++){
        Visted[temp] = false;
    }
    for(temp = 0;temp < G.vexnum;temp++){
        if(!Visted[temp]){
            DFS(G,temp);
        }
    }
}//深度优先函数接口

void BFS(VLGraph G,int v){
    arcNode curp;
    Qnode temp,newnode;

    if(!Visted[v]) {
        cout << G.vertices[v].data;
        Visted[v] = true;
    }
    curp = G.vertices[v].firstarc;
    while(curp != NULL) {
        if (!Visted[curp->adj]) {
            cout << G.vertices[curp->adj].data;
            Visted[curp->adj] = true;
            if (head == NULL) {
                head = (Qnode) malloc(sizeof(Queue));
                head->vid = curp->adj;
                head->next = NULL;
            } else {
                temp = head;
                while (temp->next != NULL){
                    temp = temp->next;
                }
                newnode = (Qnode)malloc(sizeof(Queue));
                newnode->vid = curp->adj;
                newnode->next = NULL;
                temp->next = newnode;
            }
        }
        curp = curp->nextarc;
    }
    while (head != NULL){
        temp = head;
        head = head->next;
        BFS(G,temp->vid);
        free(temp);
    }
}//广度优先函数

void BFSApi(VLGraph G){
    int temp;
    cout<<"广度优先遍历结果如下"<<endl;
    for(temp = 0;temp<G.vexnum;temp++){
        Visted[temp] = false;
    }
    for(temp = 0;temp < G.vexnum;temp++){
        if(!Visted[temp]){
            BFS(G,temp);
        }
    }
}//广度优先函数接口
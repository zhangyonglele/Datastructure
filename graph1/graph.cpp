//
// Created by ������ on 2018/6/18.
//

#include "graph.h"
using namespace std;

void addArc(VLGraph &G,int m, int n){
    arcNode np,curp,save;

    np = (arcNode)malloc(sizeof(arcnode));    //�����ڵ������
    np->adj = n;
    np->nextarc = NULL;
    curp = G.vertices[m].firstarc;
    if(curp == NULL){           //�����һ��Ϊ�գ�ֱ�Ӳ���
        G.vertices[m].firstarc = np;
    } else{                     //��һ����Ϊ�գ��������
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
}//����ͼ�ڵ�

void createGraph(VLGraph &G){
    cout<<"�������м�������"<<endl;
    cin>>G.vexnum;
    cout<<"�������м�����"<<endl;
    cin>>G.arcnum;
    for(int temp = 0;temp < G.vexnum;temp++){
        G.vertices[temp].firstarc = NULL;
        cout<<"�����"<<temp+1<<"�����������"<<endl;
        cin>>G.vertices[temp].data;
    }
    for(int temp = 0;temp < G.arcnum;temp++){
        cout<<"�йص�"<<temp+1<<"���ߵ���Ϣ���ֱ�����������";
        int n,m;
        cin>>n;
        cin>>m;
        addArc(G,n,m);
        addArc(G,m,n);
    }
}//����ͼ

void showList(VLGraph &G){
    arcNode curp;
    cout<<"����ڽ�����"<<endl;
    for(int temp = 0;temp < G.vexnum;temp++){
        cout<<G.vertices[temp].data;
        curp = G.vertices[temp].firstarc;
        while (curp != NULL){
            cout<<"-->"<<curp->adj;
            curp = curp->nextarc;
        }
        cout<<"-->NULL"<<endl;
    }
}//����ڽ�����

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
}//������Ⱥ���

void  DFSApi(VLGraph G){
    int temp;
    cout<<"������ȱ����������"<<endl;
    for(temp = 0;temp < G.vexnum;temp++){
        Visted[temp] = false;
    }
    for(temp = 0;temp < G.vexnum;temp++){
        if(!Visted[temp]){
            DFS(G,temp);
        }
    }
}//������Ⱥ����ӿ�

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
}//������Ⱥ���

void BFSApi(VLGraph G){
    int temp;
    cout<<"������ȱ����������"<<endl;
    for(temp = 0;temp<G.vexnum;temp++){
        Visted[temp] = false;
    }
    for(temp = 0;temp < G.vexnum;temp++){
        if(!Visted[temp]){
            BFS(G,temp);
        }
    }
}//������Ⱥ����ӿ�
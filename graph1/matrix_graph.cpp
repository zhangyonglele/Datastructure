//
// Created by ������ on 2018/12/19.
//
#include "matrix_graph.h"

using namespace std;

void initIsVisited(int isVisited[]){
    for (int temp = 0; temp < MAX_VERTEX; ++temp) {
        isVisited[temp] = temp;
    }
}

int initMatrix(graph &G, int vexNum){
    for(int temp1 = 0;temp1 < vexNum;temp1++){
        for(int temp2 = 0;temp2 < vexNum;temp2++ ){
            G.edgeMatrix[temp1][temp2] = INT_MAX;
        }
    }
    return 1;
}

int createMGraph(graph &G){
    cout<<"ͼ�еĶ�������"<<endl;
    cin>>G.vertexNumber;
    cout<<"ͼ�еı�����"<<endl;
    cin>>G.edgeNumber;
    initMatrix(G,G.vertexNumber);
    for(int temp = 0;temp < G.vertexNumber;temp++){
        cout<<"�������"<<temp + 1<<"�������ֵ"<<endl;
        cin>>G.vex[temp];
    }
    cout<<"ͼ������,1Ϊ����ͼ��2Ϊ����ͼ"<<endl;
    cin>>G.graphType;
    if(G.graphType == 2) {
        for (int temp = 0; temp < G.edgeNumber; temp++) {
            int V1, V2;
            cout << "�������" << temp + 1 << "���ߵ�����" << endl;
            cout << "�ڵ�1(�ڵ�����Ϊ���֣���1��2������������>1)" << endl;
            cin >> V1;
            cout << "�ڵ�2" << endl;
            cin >> V2;
            addEdgeD(G, V1, V2);
        }
    } else {
        for (int temp = 0; temp < G.edgeNumber; temp++) {
            int V1, V2;
            cout << "�������" << temp + 1 << "���ߵ�����" << endl;
            cout << "�ڵ�1(�ڵ�����Ϊ���֣���1��2������������>1)" << endl;
            cin >> V1;
            cout << "�ڵ�2" << endl;
            cin >> V2;
            addEdgeN(G, V1, V2);
        }
    }
    return 1;
}

int addEdgeD(graph &G,int V1,int V2){
    int temp;
    cin>>temp;
    G.edgeMatrix[V1-1][V2-1] = temp;
    G.edgeMatrix[V2-1][V1-1] = temp;
    return 1;
}

int addEdgeN(graph &G,int V1,int V2){
    cin>>G.edgeMatrix[V1-1][V2-1];
    return 1;
}

void showMatrix(graph G){
    for(int temp1 = 0;temp1 < G.vertexNumber;temp1++){
        for(int temp2 = 0;temp2 < G.vertexNumber;temp2++){
            cout<<G.edgeMatrix[temp1][temp2]<<"\t";
        }
        cout<<endl;
    }
}

void DFSTraverse(graph G){
    for(int temp = 0;temp < G.vertexNumber;temp++){
        isVisited[temp] = false;
    }
    for(int temp = 0;temp < G.vertexNumber;temp++){
        if(!isVisited[temp]){
            MDFS(G,temp);
        }
    }
    cout<<endl;
}

void MDFS(graph &G,int i){
    cout<<G.vex[i]<<"-->";
    isVisited[i] = true;
    for(int temp = 0;temp < G.vertexNumber;temp++){
        if(G.edgeMatrix[i][temp] == 1 && !G.vex[temp]){
            MDFS(G,temp);
        }
    }
}

int judge(int k,int i,int j) {
    if(i==1 && j==1){
        return 1;
    }
    return k;
}

void warshall(graph &G){
    int temp[MAX_VERTEX][MAX_VERTEX];
    for(int temp1 = 0;temp1 < MAX_VERTEX;temp1++){
        for(int temp2 = 0;temp2 < MAX_VERTEX;temp2++ ){
            temp[temp1][temp2] = G.edgeMatrix[temp1][temp2];
        }
    }
    for (int incr = 0;incr < G.vertexNumber;incr++) {
        for (int row = 0; row < G.vertexNumber; row++) {
            for(int col = 0;col < G.vertexNumber;col++){
                if(row != incr || col !=  incr) {
                        temp[row][col]=judge(temp[row][col],temp[incr][col],temp[row][incr]);
                }
            }
        }
    }
    for (int row = 0; row < G.vertexNumber; ++row) {
        for (int col = 0; col < G.vertexNumber; ++col) {
            cout<<temp[row][col]<<"\t";
        }
        cout<<endl;
    }
}

void initCloseEdge(edgeMark mark[],graph &G,int vex){
    for (int temp = 0; temp < G.vertexNumber; ++temp) {
        mark[temp].lowCost = INT_MAX;
        if(temp != vex){
            mark[temp].vex = vex;
            mark[temp].lowCost = G.edgeMatrix[vex][temp];
        }
    }
    mark[vex].lowCost = 0;
}

int selectMin(edgeMark mark[],int vexNumber){
    int index = 0;
    int minCost = INT_MAX;
    for(int row = 0;row < vexNumber && mark[row].lowCost==0;row++){
        for(int col = 0;col < vexNumber;col++){
            if(mark[col].lowCost !=0 && mark[col].lowCost < minCost){
                minCost = mark[col].lowCost;
                index = col;
            }
        }
    }
    return index;
}

void prime(graph &G){
    edgeMark mark[MAX_VERTEX];
    initCloseEdge(mark,G,0);
    int k;
    for (int temp1 = 1; temp1 < G.vertexNumber; ++temp1) {
        k = selectMin(mark,G.vertexNumber);
        cout<<"V"<<mark[k].vex+1<<",V"<<k+1<<endl;
        mark[k].lowCost = 0;

        for(int j=0;j < G.vertexNumber;j++){  //�����¶��������ѡ����С��
            if(G.edgeMatrix[k][j]<mark[j].lowCost){
                mark[j].vex=k;
                mark[j].lowCost=G.edgeMatrix[k][j];
            }
        }
    }
}

void dist(graph &G){
    int res[MAX_VERTEX];
    bool visit[MAX_VERTEX];
    for(int temp = 0;temp < G.vertexNumber;++temp){
        visit[temp] = false;
    }
    for (int temp = 1; temp < G.vertexNumber; ++temp) {
        res[temp] = G.edgeMatrix[0][temp];
    }
    visit[0] = true;
    for (int temp = 0; temp < G.vertexNumber; ++temp) {
        int min = INT_MAX;
        int index = 0;
        for (int i = 0; i < G.vertexNumber; ++i) {
            if(!visit[i] && res[i] < min){
                min = res[i];
                index = i;
            }
        }
        visit[index] = true;
        for (int j = 0; j < G.vertexNumber; ++j) {
            if(!visit[j] && G.edgeMatrix[index][j] != INT_MAX && (res[temp] + G.edgeMatrix[index][j]) < res[j]){
                res[j] = res[index] + G.edgeMatrix[index][j];
            }
        }
    }
    for (int k = 1; k < G.vertexNumber; ++k) {
        if(res[k] == INT_MAX){
            cout<<"��V1�޷�����V"<<k+1<<"�ڵ�"<<endl;
        }
        else{
            cout<<"��V1��V"<<k+1<<"�ڵ����·��Ϊ"<<res[k]<<endl;
        }
    }
}

void initEdgeMatrix(edgeMarkS edgeMark[],int edgeNumber){
    for (int temp = 0; temp < edgeNumber; ++temp) {
        edgeMark[temp].weight = 0;
    }
}

void sortEdge(edgeMarkS edgeMark[],graph &G){
    initEdgeMatrix(edgeMark,G.vertexNumber);
    bool flag[MAX_VERTEX][MAX_VERTEX];
    for(int temp1 = 0;temp1 < G.vertexNumber;temp1++){
        for(int temp2 = 0;temp2 <G.vertexNumber;temp2++){
            flag[temp1][temp2] = false;
        }
    }
    for (int times = 0; times < G.edgeNumber; times++) {
        int min = INT_MAX,markMin;

        int markRow = 0,markCol = 0;
        for (int row = 0; row < G.vertexNumber; row++) {
            for (int col = G.vertexNumber - 1; col > row; col--) {
                if (G.edgeMatrix[row][col] < min && !flag[row][col]){
                    min = G.edgeMatrix[row][col];
                    markRow = row;
                    markCol = col;
                }
            }
        }
        flag[markRow][markCol] = true;
        edgeMark[times].weight = min;
        edgeMark[times].beginning = markRow;
        edgeMark[times].ending = markCol;
    }
}

void kruskal(graph &G){
    edgeMarkS edgeMark[MAX_VERTEX];
    int isVisited_[MAX_VERTEX];
    initIsVisited(isVisited_);
    sortEdge(edgeMark,G);

    for (int row = 0; row < G.edgeNumber; ++row) {
        cout<<edgeMark[row].weight<<"\t"<<edgeMark[row].beginning<<"\t"<<edgeMark[row].ending<<endl;
    }

    for (int temp = 0; temp < G.vertexNumber ; temp++) {
        if((isVisited_[edgeMark[temp].ending] != isVisited_[edgeMark[temp].beginning])){
            cout<<"V"<<edgeMark[temp].beginning + 1<<" V"<<edgeMark[temp].ending + 1<<endl;
            for (int row = 0; row < G.vertexNumber; ++row) {
                if(isVisited_[row] == isVisited_[edgeMark[temp].ending]){
                    isVisited_[row] = isVisited_[edgeMark[temp].beginning];
                }
            }
        }
    }
}

//6 10 1 2 3 4 5 6 2 1 2 6 2 5 3 5 6 6 6 4 2 4 1 5 3 1 1 3 4 5 3 6 4 3 5 6 3 2 5
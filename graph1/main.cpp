#include "graph.h"
#include "graph.cpp"
#include "matrix_graph.h"
#include "matrix_graph.cpp"

int main(){
/*
    VLGraph G;
    createGraph(G);
    showList(G);
    cout<<endl;
    DFSApi(G);
    cout<<endl;
    BFSApi(G);
    cout<<endl;
    return 0;
*/
    graph G;
    createMGraph(G);
    showMatrix(G);
    kruskal(G);
}
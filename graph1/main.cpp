#include "graph.h"
#include "graph.cpp"

int main(){
    VLGraph G;
    createGraph(G);
    showList(G);
    cout<<endl;
    DFSApi(G);
    cout<<endl;
    BFSApi(G);
    cout<<endl;
    return 0;
}
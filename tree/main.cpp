#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

typedef struct data{
    char data;
    char exit;
}element;       //��������Ԫ��

typedef struct tr{
    element data;
    struct tr *lchild,*rchild;
}trNode,*tree;      //�������ݽṹ

/***
int root_creat(tree &T) {
    T = (tree)malloc(sizeof(trNode));
    if(T == NULL){
        return 0;
    }
    T->lchild = NULL;
    T->rchild = NULL;
    return 1;
}
***/

void PreOrder_Createtree(tree &T){
    element data;
    cout<<"�����#��������ַ���������"<<endl;
    cin>>data.exit;
    cout<<"��������"<<endl;
    cin>>data.data;
    if(data.exit=='#'){
        T = NULL;
        cout<<"����֧����"<<endl;
    }
    else{
        T = (tree)malloc(sizeof(trNode));
        if(!T) exit(OVERFLOW);
        T->data =data;
        PreOrder_Createtree(T->lchild);
        PreOrder_Createtree(T->rchild);
    }
}       //��������

int PreOrderTre(tree &T){
    if(T){
        cout<<T->data.data<<"\t";
        PreOrderTre(T->lchild);
        PreOrderTre(T->rchild);
        return 1;
    }
    return 0;
}              //�������������

int InOrderTra(tree &T){
    if(T){
        InOrderTra(T->lchild);
        cout<<T->data.data<<"\t";
        InOrderTra(T->rchild);
        return 1;
    }
    return 0;
}               //�������������

int PostOrderTra(tree &T){
    if(T){
        PostOrderTra(T->lchild);
        PostOrderTra(T->rchild);
        cout<<T->data.data<<"\t";
        return 1;
    }
    return 0;
}               //�������������

int main() {
    tree T;
    PreOrder_Createtree(T);
    cout<<"�������"<<endl;
    PreOrderTre(T);
    cout<<endl;
    return 0;
}
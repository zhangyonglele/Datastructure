#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

typedef struct data{
    char data;
    char exit;
}element;       //定义数据元素

typedef struct tr{
    element data;
    struct tr *lchild,*rchild;
}trNode,*tree;      //定义数据结构

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
    cout<<"输入除#外的其他字符继续输入"<<endl;
    cin>>data.exit;
    cout<<"输入数据"<<endl;
    cin>>data.data;
    if(data.exit=='#'){
        T = NULL;
        cout<<"本分支结束"<<endl;
    }
    else{
        T = (tree)malloc(sizeof(trNode));
        if(!T) exit(OVERFLOW);
        T->data =data;
        PreOrder_Createtree(T->lchild);
        PreOrder_Createtree(T->rchild);
    }
}       //先序构造树

int PreOrderTre(tree &T){
    if(T){
        cout<<T->data.data<<"\t";
        PreOrderTre(T->lchild);
        PreOrderTre(T->rchild);
        return 1;
    }
    return 0;
}              //先序遍历二叉树

int InOrderTra(tree &T){
    if(T){
        InOrderTra(T->lchild);
        cout<<T->data.data<<"\t";
        InOrderTra(T->rchild);
        return 1;
    }
    return 0;
}               //中序遍历二叉树

int PostOrderTra(tree &T){
    if(T){
        PostOrderTra(T->lchild);
        PostOrderTra(T->rchild);
        cout<<T->data.data<<"\t";
        return 1;
    }
    return 0;
}               //后序遍历二叉树

int main() {
    tree T;
    PreOrder_Createtree(T);
    cout<<"先序遍历"<<endl;
    PreOrderTre(T);
    cout<<endl;
    return 0;
}
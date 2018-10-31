//
// Created by 张永乐 on 2018/10/10.
//

#ifndef UNTITLED2_LINKLIST_H
#define UNTITLED2_LINKLIST_H

typedef struct lnode{
    int data;
    struct  lnode *next;
}Lnode,*linklist;       //封装节点
void CreateHeadList(linklist &L,int number);

void CreateTailList(linklist &L,int number);

void Oppsite(linklist &L);

void insertOrder(linklist &L,int x);

void MergeList(linklist &L1, linklist &L2, linklist &L3);

void creatlist(linklist &L);

int insert(linklist L,int nodeposi,int data);

int delet(linklist L,int nodeposi,int &data);

int getelem(linklist L,int posi,int &data);

void length(linklist L,int &data);

void search(linklist &L, int number);

void showList(linklist &L);

void upSort(linklist &L);

void circle(linklist &L);

void joseph(linklist &L,int n);

#endif //UNTITLED2_LINKLIST_H

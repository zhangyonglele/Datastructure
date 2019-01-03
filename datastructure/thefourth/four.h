//
// Created by 张永乐 on 2018/10/15.
//

#ifndef THEFOURTH_FOUR_H
#define THEFOURTH_FOUR_H

typedef struct node{
    float pren;
    int upn;
    struct node *next;
}lnode,*linklist;

void insertOrder(linklist &L);

void creatlist(linklist &L);

void comb(linklist &L1,linklist &L2);

void showList(linklist &L);

#endif //THEFOURTH_FOUR_H

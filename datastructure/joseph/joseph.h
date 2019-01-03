//
// Created by 张永乐 on 2018/10/15.
//

#ifndef JOSEPH_JOSEPH_H
#define JOSEPH_JOSEPH_H
typedef struct joseph{
    int number;
    int data;
    struct joseph *next;
}lnode,*linklist;

void CreateTailList(linklist &L,int number);

void showList(linklist &L);

void circle(linklist &L);

void length(linklist L,int &data);

#endif //JOSEPH_JOSEPH_H

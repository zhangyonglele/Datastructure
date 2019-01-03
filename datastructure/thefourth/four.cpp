//
// Created by 张永乐 on 2018/10/15.
//

#include "four.h"
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <cmath>
using namespace std;
void creatlist(linklist &L){
    L = (linklist)malloc(sizeof(lnode));
    if(!L){
        exit(OVERFLOW);
    }
    L->next = NULL;
}                 //创建头节点

void insertOrder(linklist &L){
    linklist p,q,temp;
    int  y;
    float x;
    scanf("%f",&x);
    scanf("%d",&y);
    p = L->next;
    q = L;
    temp = (linklist)malloc(sizeof(lnode));
    temp->pren = x;
    temp->upn = y;

    if(p != NULL)
        while(p->upn > y && p != NULL){
        q = p;
        p = p->next;
        }
    q->next = temp;
    temp->next = p;
}

void comb(linklist &L1,linklist &L2){
    linklist p,q;
    linklist temp;
    p = L1->next;
    q = L2->next;
    while (p !=NULL && q != NULL){
        if(p->upn < q->upn){
            q = q->next;
        }else if(p->upn > q->upn){
            p = p->next;
        } else{
            p->pren = p->pren + q->pren;
            p = p->next;
            q = q->next;
        }
    }
}

void showList(linklist &L){
    linklist temp;
    temp = L;
    if(L->next == NULL){
        printf("empty list");
    } else{
        temp = L->next;
        while (temp && temp != L){
            cout<<temp->pren<<" "<<temp->upn<<"\t";
            temp = temp->next;
        }
    }
    cout<<endl;
}
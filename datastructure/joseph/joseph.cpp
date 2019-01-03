//
// Created by 张永乐 on 2018/10/15.
//
#include "joseph.h"
#include <iostream>
using namespace std;


void CreateTailList(linklist &L,int number){
    L = (linklist)malloc(sizeof(lnode));
    int data;
    linklist temp,poi = L;
    L->next = NULL;
    for(int count = 0;count < number;count++){
        temp = (linklist)malloc(sizeof(lnode));
        scanf("%d",&data);
        temp->data = data;
        temp->next = NULL;
        temp->number = count + 1;
        poi->next = temp;
        poi = poi->next;
    }
}       //尾插法

void showList(linklist &L){
    linklist temp;
    temp = L;
    if(L->next == NULL){
        printf("empty list");
    } else{
        temp = L->next;
        while (temp && temp != L){
            cout<<temp->data<<"\t";
            temp = temp->next;
        }
    }
}

void length(linklist L,int &data){
    linklist poi = L->next;
    while (poi!=NULL && poi != L){
        data++;
        poi = poi->next;
    }
}

void circle(linklist &L){
    linklist temp;
    temp = L;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = L;
}

void joseph(linklist &L,int n){
    linklist temp,pr;
    temp = L;
    int len = 0;
    length(L,len);
    int cost = len;
    cout<<"total kill"<<len-1<<"man"<<endl;
    while (len){
        int cot = 0;
        if(len  == cost ){
            cot++;
            pr = temp;
            temp = temp->next;
        }
        while(cot != n){
                cot++;
                if (temp->next == L) {
                    pr = temp;
                    temp = temp->next->next;
                } else {
                    pr = temp;
                    temp = temp->next;
                }
        }
        cout<<"kill the "<<temp->number<<" person"<<endl;
        n = temp->data;
        pr->next = temp->next;
        free(temp);
        temp = pr;
        len--;
    }
}
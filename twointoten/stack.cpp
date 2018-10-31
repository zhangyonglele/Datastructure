//
// Created by 张永乐 on 2018/10/16.
//
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "stack.h"

using namespace std;

int creatstack(linkst &L){
    L = (linkst)malloc(sizeof(Snode));
    if(!L){
        exit(OVERFLOW);
    }
    L->next = NULL;
    return 1;
};

int push(linkst &L,elemtype data){
    linkst temp;
    temp = (linkst)malloc(sizeof(Snode));
    temp->next = L->next;
    L->next = temp;
    temp->data = data;
    return 1;
}

int pop(linkst &L,elemtype &data){
    linkst temp;
    temp = L->next;
    if(temp != NULL) {
        data = L->next->data;
        L->next = temp->next;
        free(temp);
        return 1;
    }
    else
        return 0;
}

int getTop(linkst &L,elemtype &top){
    linkst temp;
    temp = L->next;
    if(temp != NULL){
        top = temp->data;
    }
    return 1;
}
/**
int transformer(int n){
    elemtype temp,data;
    linkst L;
    while(n){
        temp = n%2;
        push(L,temp);
        n = n/2;
    }
    while (L->next != NULL){
        pop(L,data);
        cout<<data<<"\t";
    }
    free(L);
    return 1;
}
**/
bool isEmpty(linkst &L){
    if(L->next == NULL){
        return true;
    }
    return false;
}

int match(elemtype *p){
    elemtype *point;
    elemtype top,data;
    point = p;
    linkst L;
    while(*point != '\0'){
        if(*point ==  '{' || *point == '[' || *point == '('){
            push(L,*point);
        } else{
            switch (*point){
                case '}': {
                    getTop(L,top);
                    if(top == '{')
                        pop(L,data);
                    break;
                    }
                    case ')':{
                        getTop(L,top);
                        if (top == '(')
                            pop(L,data);
                        break;
                    }
                    case ']':{
                        getTop(L,top);
                        if(top == '[')
                            pop(L,data);
                        break;
                    }
            }
        }
        point++;
    }
    if(isEmpty(L)){
        return 1;
    } else{
        return 0;
    }
}


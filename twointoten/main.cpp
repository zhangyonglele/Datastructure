#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
//typedef struct {
//    int x;
//    int y;
//}posi;

//typedef struct {
//    int ord;
//    posi seat;
//    int dir;
//}elemtype;

typedef int elemtype;

typedef struct snode{
    elemtype data;
    struct snode *next;
}Snode,*linkst;

int creatstack(linkst &L){
    L = (linkst)malloc(sizeof(Snode));
    if(!L){
        exit(OVERFLOW);
    }
    L->next = NULL;
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

int main() {
    int data,n,temp;
    linkst L,p;
    creatstack(L);
    p = L->next;
    for (; ; ) {
        printf("����1��ջ������2��ջ������3�������ջ��Ԫ��");
        scanf("%d",&n);
        switch (n){
            case 1:{
                scanf("%d",&data);
                printf("\n");
                push(L,data);
                break;
            }
            case 2:{
                pop(L,temp);
                printf("%d",temp);
                break;
            }
            case 3:{
                while (L->next != NULL){
                    pop(L,temp);
                    printf("%d\t",temp);
                }
                goto end;
                }
            default:printf("�����в�");
            }
        }

        end:;
//    system("pause");
}

//
// Created by 张永乐 on 2018/10/10.
//

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include "Linklist.h"
#define error 0
using namespace std;

void CreateHeadList(linklist &L,int number){
    L = (linklist)malloc(sizeof(lnode));
    int data,count;
    linklist temp;
    L->next = NULL;
    for(count = 0;count < number;count++){
        temp = (linklist)malloc(sizeof(lnode));
        scanf("%d",&data);
        temp->data = data;
        temp->next = L->next;
        L->next = temp;
    }
}       //头插法

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
        poi->next = temp;
        poi = poi->next;
    }
}       //尾插法

void Oppsite(linklist &L){
    linklist p,q;
    p = L->next;
    L->next = NULL;
    while(p != NULL){
        q = p;
        p = p->next;
        q->next = L->next;
        L->next = q;
    }

}

void insertOrder(linklist &L,int x){
    linklist p,q,temp;
    p = L->next;
    q = L;
    temp = (linklist)malloc(sizeof(lnode));
    temp->data = x;
    while(p->data < x && p != NULL){
        q = p;
        p = p->next;
    }
    q->next = temp;
    temp->next = p;
}

void MergeList(linklist &L1, linklist &L2, linklist &L3){
    linklist pa,pb,pc;
    pa = L1->next;
    pb = L2->next;
    L3 = pc = L1;
    while (pa && pb){
        if(pa->data <= pb->data){
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else{
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa?pa:pb;
    free(L2);
}

void creatlist(linklist &L){
    L = (linklist)malloc(sizeof(Lnode));
    if(!L){
        exit(OVERFLOW);
    }
    L->next = NULL;
}                 //创建头节点

int insert(linklist L,int nodeposi,int data){
    int mov = 0;
    linklist temp,poi = L;
    while (poi && mov < nodeposi-1){
        mov++;
        poi = poi->next;
    }
    if(!poi || mov > nodeposi-1){
        return error;
    }
    temp = (linklist)malloc(sizeof(Lnode));
    temp->data = data;
    temp->next = poi->next;
    poi->next = temp;
}        //插入对应位置的节点

int delet(linklist L,int nodeposi,int &data){
    int mov = 0;
    linklist temp,poi = L;
    while (poi->next && mov < nodeposi - 1){
        poi = poi->next;
        mov++;
    }
    if(!poi || mov > nodeposi - 1){
        return error;
    }
    temp = poi->next;
    poi->next = poi->next->next;
    data = temp->data;
    free(temp);
    return 1;
}       //删除对应位置的节点

int getelem(linklist L,int posi,int &data){
    int mov = 0;
    linklist poi = L;
    while (poi && mov < posi){
        poi = poi->next;
        mov++;
    }
    if (!poi || mov > posi){
        return error;
    }
    data = poi->data;
    return 1;
}        //得到节点数据

void length(linklist L,int &data){
    linklist poi = L->next;
    while (poi!=NULL && poi != L){
        data++;
        poi = poi->next;
    }
}               //求链表长

void search(linklist &L, int number){
    int mov = 0,data = 0;
    length(L,data);
    linklist poi = L->next;
    while (poi){
        if(poi->data == number){
            printf("存在,处于%d个节点\n",mov+1);
            break;
        }
        mov++;
        poi = poi->next;
    }
    if(mov - 1 == data){
        printf("不存在");
    }
}               //查找算法

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

void upSort(linklist &L){
    int lenth_of = 0;
    length(L,lenth_of);
    cout<<lenth_of<<endl;
    linklist p,q,temp;
    temp = L->next;
    p = L->next->next;
    for(int incr = 0;incr < lenth_of - 1;incr++){
        if(p->data < temp->data){
            q = L;
            while(q->next->data < p->data){
                q = q->next;
            }
            temp->next = p->next;
            p->next = q->next;
            q->next = p;
            p = temp->next;
        } else{
            temp = temp->next;
            p = p->next;
        }
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
    cout<<"共杀"<<len-1<<"人"<<endl;
    while (len - 1){
        int cot = 0;
        while(cot != n){
            if(len  == cost ){
                cot++;
                pr = temp;
                temp = temp->next;
            } else {
                if (temp != L) {
                    cot++;
                }
                if (temp->next == L) {
                    pr = temp;
                    temp = temp->next->next;
                } else {
                    pr = temp;
                    temp = temp->next;
                }
            }
        }
        cout<<"up"<<pr->data<<endl;
        cout<<"杀第"<<temp->data<<"人"<<endl;
     //   n = temp->data;
        pr->next = temp->next;
        cout<<n<<endl;
        free(temp);
        temp = pr;
        len--;
    }
}
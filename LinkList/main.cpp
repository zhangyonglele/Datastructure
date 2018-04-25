/*************
WORKER:ZYL
TIME: 2018/4/12
Data Structure
**************/

//                          _ooOoo_                               //
//                         o8888888o                              //
//                         88" . "88                              //
//                         (| ^_^ |)                              //
//                         O\  =  /O                              //
//                      ____/`---'\____                           //
//                    .'  \\|     |//  `.                         //
//                   /  \\|||  :  |||//  \                        //
//                  /  _||||| -:- |||||-  \                       //
//                  |   | \\\  -  /// |   |                       //
//                  | \_|  ''\---/''  |   |                       //
//                  \  .-\__  `-`  ___/-. /                       //
//                ___`. .'  /--.--\  `. . ___                     //
//              ."" '<  `.___\_<|>_/___.'  >'"".                  //
//            | | :  `- \`.;`\ _ /`;.`/ - ` : | |                 //
//            \  \ `-.   \_ __\ /__ _/   .-` /  /                 //
//      ========`-.____`-.___\_____/___.-`____.-'========         //
//                           `=---='                              //
//      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^        //
//         ���汣��       ����BUG     �����޸�                    //
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define error 0
using namespace std;
typedef struct lnode{
    int data;
    struct  lnode *next;
}Lnode,*linklist;       //��װ�ڵ�

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
}       //ͷ�巨

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
}       //β�巨

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
}                 //����ͷ�ڵ�

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
}        //�����Ӧλ�õĽڵ�

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
}       //ɾ����Ӧλ�õĽڵ�

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
}        //�õ��ڵ�����

void length(linklist L,int &data){
    linklist poi = L->next;
    while (poi!=NULL){
        data++;
        poi = poi->next;
    }
}               //������

void search(linklist &L, int number){
    int mov = 0,data = 0;
    length(L,data);
    linklist poi = L->next;
    while (poi){
        if(poi->data == number){
            printf("����,����%d���ڵ�\n",mov+1);
            break;
        }
        mov++;
        poi = poi->next;
    }
    if(mov - 1 == data){
        printf("������");
    }
}               //�����㷨

void function(){
    linklist L1,L2,L3,p;
    int n,i=0,data;
    scanf("%d",&n);
    CreateHeadList(L1,n);
    scanf("%d",&n);
    CreateTailList(L2,n);
    MergeList(L1, L2, L3);
    p = L3->next;
    int add=1;
    while (p != NULL){
        getelem(L3,add,data);
        printf("%d\t",data);
        add++;
        p = p->next;
    }
}

int main() {
    int cho,posi,data,temp,cnumber;
    linklist L,p;
    for(;;){
        cout<<"************************************************************************************************************************"<<endl;
        cout<<"����1����ͷ�ڵ㣬����2����ڵ㣬����3ɾ���ڵ㣬����4�õ��ڵ�����,����5������Ϊ,����6�󳤶�,����7������е�Ԫ��,8����Ԫ��"<<endl;
        cout<<"************************************************************************************************************************"<<endl;
        scanf("%d",&cho);
        switch (cho){
            case 1:{
                creatlist(L);
                break;
            }
            case 2:{
                printf("����λ��\n");
                cin>>posi;              //scanf("%d",&posi);
                cout<<"��������"<<endl; //printf("��������");
                cin>>data;              //scanf("%d",&data);
                insert(L,posi,data);
                break;
            }
            case 3:{
                printf("����λ��\n");
                cin>>posi;
                delet(L,posi,temp);
                cout<<"����Ϊ"<<temp<<endl;
                break;
            }
            case 4:{
                cout<<"����λ��"<<endl;
                cin>>posi;
                getelem(L,posi,temp);
                cout<<"����Ϊ"<<temp<<endl;
                break;
            }
            case 5:goto esp;
            case 6:{
                temp = 0;
                length(L,temp);
                cout<<"����Ϊ"<<temp<<endl;
                break;
            }
            case 7:{
                p = L->next;
                int add=1;
                while (p != NULL){
                    getelem(L,add,data);
                    printf("%d\t",data);
                    add++;
                    p = p->next;
                }
                printf("\n");
                break;
            }
            case 8:{
                printf("������ҵ�����\n");
                scanf("%d",&cnumber);
                search(L,cnumber);
                break;
            }
            default: cout<<"�����˸�";
        }
    }
    esp:;
    return 0;
}
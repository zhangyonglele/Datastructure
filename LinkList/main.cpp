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
//         佛祖保佑       永无BUG     永不修改                    //
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define error 0
using namespace std;
typedef struct lnode{
    int data;
    struct  lnode *next;
}Lnode,*linklist;       //封装节点

void CreateHeadList(linklist &L,int number){
    L = (linklist)malloc(sizeof(lnode));
    int data;
    linklist temp;
    L->next = NULL;
    for(int count = 0;count < number;count++){
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
        poi->next = temp;
        poi = poi->next;
    }
}       //尾插法

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
    while (poi!=NULL){
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

int main() {
    int cho,posi,data,temp,cnumber;
    linklist L,p;
    for(;;){
        cout<<"************************************************************************************************************************"<<endl;
        cout<<"输入1创建头节点，输入2插入节点，输入3删除节点，输入4得到节点数据,输入5结束行为,输入6求长度,输入7输出所有的元素,8查找元素"<<endl;
        cout<<"************************************************************************************************************************"<<endl;
        scanf("%d",&cho);
        switch (cho){
            case 1:{
                creatlist(L);
                break;
            }
            case 2:{
                printf("键入位置\n");
                cin>>posi;              //scanf("%d",&posi);
                cout<<"键入数据"<<endl; //printf("键入数据");
                cin>>data;              //scanf("%d",&data);
                insert(L,posi,data);
                break;
            }
            case 3:{
                printf("键入位置\n");
                cin>>posi;
                delet(L,posi,temp);
                cout<<"数据为"<<temp<<endl;
                break;
            }
            case 4:{
                cout<<"键入位置"<<endl;
                cin>>posi;
                getelem(L,posi,temp);
                cout<<"数据为"<<temp<<endl;
                break;
            }
            case 5:goto esp;
            case 6:{
                temp = 0;
                length(L,temp);
                cout<<"长度为"<<temp<<endl;
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
                printf("输入查找的数据\n");
                scanf("%d",&cnumber);
                search(L,cnumber);
                break;
            }
            default: cout<<"错误了哥";
        }
    }
    esp:;
    return 0;
}
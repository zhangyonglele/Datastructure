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
#include "Linklist.cpp"
#include "Linklist.h"
using namespace std;



int main() {
    int cho,posi,data,temp,cnumber;
    linklist L,p;
    for(;;){
        cout<<"************************************************************************************************************************"<<endl;
        cout<<"����1����ͷ�ڵ㣬����2����ڵ㣬����3ɾ���ڵ㣬����4�õ��ڵ�����,����5������Ϊ,����6�󳤶�,����7������е�Ԫ��,8����Ԫ��,9����������룬10��������11չʾ����"<<endl;
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
                showList(L);
                printf("\n");
                break;
            }
            case 8:{
                printf("������ҵ�����\n");
                scanf("%d",&cnumber);
                search(L,cnumber);
                break;
            }
            case 9:{
            	cin>>cnumber;
            	insertOrder(L,cnumber);
				break;
			}
			case 10:{
				upSort(L);
				break;
			}
            case 11:{
                showList(L);
                break;
            }
            case 12:{
                circle(L);
                break;
            }
            case 13:{
                joseph(L,20);
                break;
            }
            default: cout<<"�����˸�";
        }
    }
    esp:;
    return 0;
}

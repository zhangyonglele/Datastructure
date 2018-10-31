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
#include "Linklist.cpp"
#include "Linklist.h"
using namespace std;



int main() {
    int cho,posi,data,temp,cnumber;
    linklist L,p;
    for(;;){
        cout<<"************************************************************************************************************************"<<endl;
        cout<<"输入1创建头节点，输入2插入节点，输入3删除节点，输入4得到节点数据,输入5结束行为,输入6求长度,输入7输出所有的元素,8查找元素,9按照升序插入，10逆置链表，11展示链表"<<endl;
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
                showList(L);
                printf("\n");
                break;
            }
            case 8:{
                printf("输入查找的数据\n");
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
            default: cout<<"错误了哥";
        }
    }
    esp:;
    return 0;
}

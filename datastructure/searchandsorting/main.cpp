#include <iostream>
#include "function.cpp"
#include "function.h"
using namespace std;

int main() {
    Sqlist a;
    int search,find;
    cout<<"����Ҫ�����������"<<endl;
    cin>>a.length;
    cout<<"��������������Ҫ���������"<<endl;
    for(int temp = 1;temp < a.length + 1;temp++){
        cout<<"��Ҫ����"<<temp<<"������"<<endl;
        cin>>a.r[temp].key;
    }
    cout<<"��������Ҫ���ҵ�����"<<endl;
    cin>>find;
    int chose;
    cin>>chose;
    switch (chose) {
        case 1: {
            Qsort(a, 1, a.length + 1);
            cout<<"�����ǿ�������Ľ��"<<endl;
            getList(a,a.length);
            break;
        }
        case 2:{
            bubbleSort(a,1,a.length + 1);
            cout<<"������ð������Ľ��"<<endl;
            getList(a,a.length);
            break;
        }
        case 3:{
            insertSort(a,1,a.length + 1);
            cout<<"�����Ǽ򵥲�������Ľ��"<<endl;
            getList(a,a.length);
            break;
        }
        default:cout<<"worry"<<endl;
    }

    cout<<"�ǵݹ��۰����"<<endl;
    search = Bin_search(a,a.length + 1,find);
    cout<<"��λ�ڵ�"<<search<<"������"<<endl;

    cout<<"�ݹ��۰����"<<endl;
    search = Bin_search1(a,a.length + 1,1,find);
    cout<<"��λ�ڵ�"<<search<<"������"<<endl;

    cout<<endl;

    return 0;
}
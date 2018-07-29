#include <iostream>
#include "function.cpp"
#include "function.h"
using namespace std;

int main() {
    Sqlist a;
    int search,find;
    cout<<"你需要排序多少数字"<<endl;
    cin>>a.length;
    cout<<"请在以下输入你要排序的数字"<<endl;
    for(int temp = 1;temp < a.length + 1;temp++){
        cout<<"你要输入"<<temp<<"个数字"<<endl;
        cin>>a.r[temp].key;
    }
    cout<<"输入你需要查找的数据"<<endl;
    cin>>find;
    int chose;
    cin>>chose;
    switch (chose) {
        case 1: {
            Qsort(a, 1, a.length + 1);
            cout<<"以下是快速排序的结果"<<endl;
            getList(a,a.length);
            break;
        }
        case 2:{
            bubbleSort(a,1,a.length + 1);
            cout<<"以下是冒泡排序的结果"<<endl;
            getList(a,a.length);
            break;
        }
        case 3:{
            insertSort(a,1,a.length + 1);
            cout<<"以下是简单插入排序的结果"<<endl;
            getList(a,a.length);
            break;
        }
        default:cout<<"worry"<<endl;
    }

    cout<<"非递归折半查找"<<endl;
    search = Bin_search(a,a.length + 1,find);
    cout<<"其位于第"<<search<<"个数据"<<endl;

    cout<<"递归折半查找"<<endl;
    search = Bin_search1(a,a.length + 1,1,find);
    cout<<"其位于第"<<search<<"个数据"<<endl;

    cout<<endl;

    return 0;
}
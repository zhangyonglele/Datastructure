//
// Created by 张永乐 on 2018/7/5.
//
/***
 * 各种手写排序算法
 * 没啥特色就是学习
 */
#include "function.h"
#include <iostream>
using namespace std;
void getList(Sqlist &a,int length){
    for(int temp = 1;temp < length + 1;temp++)
        cout<<a.r[temp].key<<"\t";
    cout<<endl;
}

void bubbleSort(Sqlist &L,int low,int high){
    int key;
    for(int times = low;times < high;times++){
        for (int temp = low;temp < high - 1;temp++){
            if(L.r[temp].key > L.r[temp + 1].key){
                key = L.r[temp].key;
                L.r[temp].key = L.r[temp + 1].key;
                L.r[temp + 1].key = key;
            }
        }
    }
}//冒泡排序

void insertSort(Sqlist &a,int low,int high){
    int incr;
    for(int temp = low + 1;temp <= high;temp++){
        if(a.r[temp].key < a.r[temp - 1].key){
            a.r[0] = a.r[temp];
            a.r[temp] = a.r[temp - 1];
            for(incr = temp - 2;a.r[incr].key > a.r[0].key;incr--){
                a.r[incr + 1] = a.r[incr];
            }
            a.r[incr + 1] = a.r[0];
        }
    }
}//插入排序



int Partition(Sqlist &L,int low,int high){
    int watcher;
    L.r[0] = L.r[low];
    watcher = L.r[low].key;
    while (low < high){
        while (low < high && L.r[high].key >= watcher){
            high--;
        }
        L.r[low] = L.r[high];
        while (low < high && L.r[low].key <= watcher){
            low++;
        }
        L.r[high] = L.r[low];
    }
    L.r[low] = L.r[0];
    return low;
}//快排核心

void Qsort(Sqlist &L,int low, int high){
    int pivot;
    if(low < high){
        pivot = Partition(L,low,high);
        Qsort(L,low,high-1);
        Qsort(L,pivot + 1,high);
    }
}//快速排序

int Bin_search(Sqlist a,int high,int find){
    int low = 1;
    int mid;
    while(low <= high){
        mid = (low + high) / 2;
        if (a.r[mid].key == find)
            return mid;
        else if(find < a.r[mid].key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}//非递归折半查找

int Bin_search1(Sqlist a,int high,int low,int find){
    int mid;
    if(low > high)
        return -1;
    else{
        mid = (low + high) / 2;
        if(a.r[mid].key == find)
            return mid;
        else if (a.r[mid].key > find)
            return Bin_search1(a,mid - 1,low,find);
        else if (a.r[mid].key < find)
            return Bin_search1(a,high,mid + 1,find);
    }
    return -1;
}//递归折半查找


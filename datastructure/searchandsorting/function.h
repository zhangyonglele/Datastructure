//
// Created by ’≈”¿¿÷ on 2018/7/5.
//

#ifndef SEARCHANDSORTING_FUNCTION_H
#define SEARCHANDSORTING_FUNCTION_H

#define MAXSIZE 30
typedef int KeyType;
typedef char InfoType;
typedef struct {
    KeyType key;
    InfoType other;
}Element;
typedef struct {
    Element r[MAXSIZE];
    int length;
}Sqlist;

void bubbleSort(Sqlist &L,int low,int high);

void insertSort(Sqlist &a,int low,int high);

int Partition(Sqlist &L,int low,int high);

void Qsort(Sqlist &L,int low, int high);

int Bin_search(Sqlist a,int high,int find);

int Bin_search1(Sqlist a,int high,int low,int find);


#endif //SEARCHANDSORTING_FUNCTION_H

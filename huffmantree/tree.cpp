//
// Created by 张永乐 on 2018/5/21.
//
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "tree.h"

int selectMin(HuffmanTree HT,int m,int &count){
    int min,temp = 0;
    while (HT[temp].parent != 0){
        temp++;
    }
    min = HT[0].weight;
    count = temp;
    for(;temp < m;temp++){
        if(HT[temp].parent == 0)
            if(HT[temp].weight < min){
                min = HT[temp].weight;
                count = temp;
            }
    }
    return 1;
}

int HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n){
    int temp_number,i,s;
    char *code;
    if(n <= 1){
        return 0;
    }
    temp_number = n * 2 - 1;
    HT = (HuffmanTree)malloc((temp_number)* sizeof(HNode));


    for(i = 0; i < n; i++,w++){
        HT[i].weight = *w;
        HT[i].parent = 0;
        HT[i].left_child = 0;
        HT[i].right_child = 0;
    }//编码表初始化

    for(i; i < temp_number; i++){
        HT[i].weight = 0;
        HT[i].parent = 0;
        HT[i].left_child = 0;
        HT[i].right_child = 0;
    }//另一半码表初始化

    for(i = n;i < temp_number;i++){
        int record = 0;
        selectMin(HT,i,s);
        HT[s].parent = i;
        record += HT[s].weight;
        HT[i].left_child = s;
        selectMin(HT,i,s);
        HT[s].parent = i;
        record += HT[s].weight;
        HT[i].right_child = s;
        HT[i].weight = record;
    }

    HC = (HuffmanCode)malloc(n * sizeof(char*));
    code = (char*)malloc(n * sizeof(char));
    code[n - 1] = '\0';

    for(i = 0;i <= n;i++){
        int current = i;
        int father = HT[i].parent;
        int start = n - 1;
        while(father != 0){
            if(HT[father].left_child == current)
                code[--start] = '0';
            else
                code[--start] = '1';
            current = father;
            father = HT[father].parent;
        }
        HC[i] = (char*)malloc((n - start) * sizeof(char));
        strcpy(HC[i],code+start);
    }
    free(code);
}


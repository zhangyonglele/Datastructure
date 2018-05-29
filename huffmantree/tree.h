//
// Created by 张永乐 on 2018/5/21.
//

typedef struct {
    int weight;
    int parent,left_child,right_child;
} HNode,*HuffmanTree;
typedef char **HuffmanCode;

int HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n);

int selectMin(HuffmanTree HT,int m,int &count);
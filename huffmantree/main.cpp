#include <iostream>
using namespace std;

#include "tree.h"

int main() {
    HuffmanCode HC;
    int a[100],n;
    HuffmanTree HT;
    cout<<"*****************************"<<endl<<endl;
    cout<<"�����������ַ�����"<<endl<<endl;
    cout<<"*****************************"<<endl;
    cin>>n;
    cout<<"����"<<n<<"���������ַ���Ȩֵ"<<endl;
    for(int temp = 0;temp < n;temp++){
        cin>>a[temp];
    }
    HuffmanCoding(HT,HC,a,n);
    cout<<"�õ����±���"<<endl;
    for(int i = 0;i < n;i++){
        cout<<HC[i]<<endl;
    }
}
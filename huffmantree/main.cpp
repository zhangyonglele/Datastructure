#include <iostream>
using namespace std;

#include "tree.h"

int main() {
    HuffmanCode HC;
    int a[100],n;
    HuffmanTree HT;
    cout<<"*****************************"<<endl<<endl;
    cout<<"输入待编码的字符个数"<<endl<<endl;
    cout<<"*****************************"<<endl;
    cin>>n;
    cout<<"输入"<<n<<"个带编码字符的权值"<<endl;
    for(int temp = 0;temp < n;temp++){
        cin>>a[temp];
    }
    HuffmanCoding(HT,HC,a,n);
    cout<<"得到以下编码"<<endl;
    for(int i = 0;i < n;i++){
        cout<<HC[i]<<endl;
    }
}
#include <stdio.h>
#include <iostream>
#include "four.h"
#include "four.cpp"
using namespace std;
int main() {
    linklist L1,L2;
    creatlist(L1);
    creatlist(L2);
    int number;
    cin>>number;
    L1->upn = 1000000;
    L2->upn = 1000000;
    for(int temp = 0;temp < number;temp++){
        insertOrder(L1);
    }
    cin>>number;
    for(int temp = 0;temp < number;temp++){
        insertOrder(L2);
    }
    showList(L1);
    showList(L2);
    comb(L1,L2);
    showList(L1);
    return 0;
}
#include <iostream>
#include "joseph.h"
#include "joseph.cpp"
using namespace std;

int main() {
    int n;
    cin>>n;
    linklist L;
    CreateTailList(L,n);
    showList(L);
    circle(L);
    joseph(L,20);
    return 0;
}
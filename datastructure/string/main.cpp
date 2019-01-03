#include <iostream>
#include "stringt.h"
#include "string.cpp"
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    stringt a,b;
    cin>>a.string;
    strDel(a,2,2);
    cout<<a.string;
    return 0;
}
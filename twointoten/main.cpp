#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include "stack.cpp"
#include "stack.h"
using namespace std;



int main() {
    int number;
    char a[100];

    cin>>number;
    for(int temp = 0;temp <= number;temp++){
        scanf("%c",&a[temp]);
    }

    number = match(a);
    if(number){
        cout<<"yes";
    } else{
        cout<<"no";
    }
//    transformer(number);
    system("pause");
}

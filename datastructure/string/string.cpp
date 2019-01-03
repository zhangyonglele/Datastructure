//
// Created by 张永乐 on 2018/10/30.
//
#include "stringt.h"

int strLength(stringt a){
    char *temp;
    temp = a.string;
    int number = 0;
    while(*temp != '\0'){
        number++;
        temp++;
    }
    return number;
}

void strAssign(stringt &a,stringt &b){
    char *temp,*temp2;
    temp = b.string;
    temp2 = a.string;
    int count = 0,length;
    if(strLength(a)>strLength(b)){
        length = strLength(a);
    } else{
        length = strLength(b);
    }
    while(count < length){
        *temp2 = *temp;
        temp++;
        temp2++;
        count++;
    }
}

void strContent(stringt &a,stringt &b){
    char *temp1,*temp2;
    temp1 = a.string;
    temp2 = b.string;
    while(*temp1 != '\0'){
        temp1++;
    }
    while (*temp2 != '\0'){
        *temp1 = *temp2;
        temp1++;
        temp2++;
    }
}

char* subStr(stringt &a,int begin, int end){
    char *temp,*inc ;
    static char res[MAX_LENGTH];
    if(end == 0 || strLength(a) < end || strLength(a) < begin){
        return res;
    }
    temp = a.string;
    inc = res;
    begin--;
    end = end - begin;
    while(begin){
        temp++;
        begin--;
    }
    while (end){
        *inc = *temp;
        inc++;
        temp++;
        end--;
    }
    return res;
}

int strCmp(stringt &a,stringt &b){
    char *temp1,*temp2;
    temp1 = a.string;
    temp2 = b.string;
    while(*temp1 != '\0'){
        if(*temp1 == *temp2){
            temp1++;
            temp2++;
        } else{
            return 0;
        }
    }
    return 1;
}

int strIndex(stringt &a,stringt &b){
    char *temp1,*temp2;
    temp1 = a.string;
    temp2 = b.string;
    int count = 1,length,position = 1;
    length = strLength(b);
    int lengtha = strLength(a);
    while (position < lengtha){
        while (*temp1 != *temp2){
            temp1++;
            position++;
            if(position < lengtha)
                break;
        }
        while (*temp1 == *temp2){
            temp1++;
            temp2++;
            count++;
            position++;
            if(*(temp1+1) == '\0'){
                position++;
                break;
            }
        }
        if(count == length){
            if(*temp1 != *temp2){
                return 0;
            }
        }
        if(count < length){
            temp2 = b.string;
            for(;count > 1 + 1;count--){
                temp1--;
            }
            count = 1;
        }else{
            return position-length;
        }
    }
    return 0;
}

void strInsert(stringt &a,stringt &b,int position){
    char *temp1,*temp2;
    temp1 = a.string;
    temp2 = b.string;
    int insertPosition =  position;
    int charaMove = strLength(b);
    int lengtha = strLength(a);
    for(int temp = insertPosition;temp < lengtha;temp++){
        *(temp1 + charaMove + temp) = *(temp1 + temp);
    }
    while (*temp2 != '\0'){
        *(temp1 + insertPosition) = *temp2;
        temp1++;
        temp2++;
    }
}
void strDel(stringt &a,int i,int len){
    int behind = strLength(a) - i - len + 1;
    char *temp;
    temp = a.string;
    while (behind+1){
        *(temp + i - 1) = *(temp + len + 1);
        temp++;
        behind--;
    }
}
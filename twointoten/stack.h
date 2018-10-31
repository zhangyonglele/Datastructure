//
// Created by 张永乐 on 2018/10/16.
//

#ifndef TWOINTOTEN_STACK_H
#define TWOINTOTEN_STACK_H

typedef char elemtype;

typedef struct snode{
    elemtype data;
    char chara;
    struct snode *next;
}Snode,*linkst;

int creatstack(linkst &L);

int push(linkst &L,elemtype data);

int pop(linkst &L,elemtype &data);

#endif //TWOINTOTEN_STACK_H

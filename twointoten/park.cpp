//
// Created by 张永乐 on 2018/10/23.
//
#include "park.h"
#include <cstdlib>
#include <stdio.h>
#define PRICE 10

void pop(parkLand &parkLand1,car &car1){
    parkLand temp;
    temp = parkLand1->next;
    if(temp != NULL){
        car1 = temp->carInfo;
        parkLand1->next = temp->next;
        free(temp);
    }
}
void push(parkLand &parkLand1,car car1){
    parkLand temp;
    temp = (parkLand)malloc(sizeof(parknode));
    temp->carInfo = car1;
    temp->next = parkLand1->next;
    parkLand1->next = temp;
}

void enQ(waitingZone &waitingZone1,car car1){
    waitingZone temp,p;
    p = waitingZone1;
    temp = (waitingZone)malloc(sizeof(waitingNode));
    temp->carinfo = car1;
    while (p->next != NULL){
        p = p->next;
    }
    temp->next = p->next;
    p->next = temp;
}
void deQ(waitingZone &waitingZone1,car &car1){
    waitingZone temp;
    if(waitingZone1->next != NULL) {
        temp = waitingZone1->next;
        car1 = temp->carinfo;
        waitingZone1->next = temp->next;
        free(temp);
    }
}
void createPark(parkLand &parkLand1){
    parkLand1 = (parkLand)malloc(sizeof(parknode));
    if(!parkLand1){
        exit(0);
    }
    parkLand1->next = NULL;
}
void createWaiting(waitingZone &waitingZone1){
    waitingZone1 = (waitingZone)malloc(sizeof(waitingNode));
    if(!waitingZone1){
        exit(0);
    }
    waitingZone1->next = NULL;
}
car getTopCar(parkLand &parkLand1){
    car car1;
    if(parkLand1->next != NULL) {
        car1 = parkLand1->next->carInfo;
        return car1;
    }
}

int parkingCarNumber(parkLand &parkLand1){
    int numb = 0;
    parkLand temp = parkLand1;
    while (temp->next != NULL){
        temp = temp->next;
        numb++;
    }
    return  numb;
}

bool isParkLandEmpty(parkLand &parkLand1){

}

bool isWaitingZoneEmpty(waitingZone waitingZone1){

}

void carComing(parkLand &parkLand1, waitingZone &waitingZone1,car car1){
    if(parkLand1->parkLandSize > parkingCarNumber(parkLand1)){
        push(parkLand1,car1);
    } else{
        enQ(waitingZone1,car1);
    }
}

void carOut(parkLand &parkLand1,waitingZone waitingZone1,car car1){
    parkLand temp;
    car tempCar;
    int time,money;
    createPark(temp);
    while (getTopCar(parkLand1).carNumber != car1.carNumber){
        pop(parkLand,tempCar);
        push(temp,tempCar);
    }
    pop(parkLand1,tempCar);
    time = temp->inParkTime - car1.outParkTime;
    money = time * PRICE;
    printf(money);
    while (isParkLandEmpty(temp)){
        pop(temp,tempCar);
        push(temp,tempCar);
    }
    if (isWaitingZoneEmpty(waitingZone1)){

    } else{
        deQ(waitingZone1,tempCar);
        push(parkLand1,temp);
    }
}

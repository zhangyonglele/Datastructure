//
// Created by 张永乐 on 2018/10/23.
//

#ifndef TWOINTOTEN_PARK_H
#define TWOINTOTEN_PARK_H

typedef struct car_s{
    int carNumber;
    int arrivingTime;
    int inParkTime;
    int outParkTime;
    int cost;
}car;

typedef struct stack_park{
    car carInfo;
    struct stack_park *next;
    int parkLandSize;
}*parkLand,parknode;

typedef struct que{
    car carinfo;
    struct que *next;
}*waitingZone,waitingNode;


#endif //TWOINTOTEN_PARK_H

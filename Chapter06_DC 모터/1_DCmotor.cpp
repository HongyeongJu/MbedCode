/*
2020-12-24    DC 모터 회전 방향 제어 _p328
회로 : page 328
DCMotor.cpp

(debugging : 트렌지스터를 사용하여 따로 새로운 회로를 구성하거나 , 모터 쉴드에 5V를 인가하는 것이 아닌 9V 이상을 줘야될 것 같음.)
 */
#include "mbed.h"

DigitalOut In1(PA_5), In2(PA_6);

void forward(){
    In1 = false;
    In2 = true;
}

void backward(){
    In1 = true;
    In2 = false;
}

void stop(){
    In1 = false;
    In2 = false;
}

int main(){

    while(1){
        forward();
    }
}

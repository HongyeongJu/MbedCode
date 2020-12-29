/*
2020-12-29    DC 모터 회전 방향 제어 _p328
회로 : page 328
DCMotor.cpp

 */
#include "mbed.h"

// DC 모터의 방향 제어 출력 설정
DigitalOut In1(PA_5), In2(PA_6);

// DC 모터를 앞으로 이동
void forward(){
    In1 = false;
    In2 = true;
}

// DC 모터를 뒤로 이동
void backward(){
    In1 = true;
    In2 = false;
}

// DC 모터를 정지
void stop(){
    In1 = false;
    In2 = false;
}

int main(){
    while(1){
        forward();
        wait(2);
        backward();
        wait(2);
        stop();
        wait(2);
    }
}

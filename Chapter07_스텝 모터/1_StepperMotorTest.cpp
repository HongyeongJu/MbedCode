/*
2020-12-24    스텝모터 제어
회로 : X
DCMotorTest.cpp
 */
#include "mbed.h"
#include "sMotor.h"

// sMotor 라이브러리의 클래스
sMotor motor(D0, D1, D2, D3);

// 360도는 512 스텝
int numstep = 512;
// 스텝 모터의 속도
int step_speed = 1200;

int main(){
    while(1){
        // (각도, 방향(0: 시계방향, 1: 반시계방향), 속도)
        motor.step(numstep, 0, step_speed);
    }
}

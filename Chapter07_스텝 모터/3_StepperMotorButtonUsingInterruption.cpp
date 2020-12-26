/*
2020-12-26    스텝모터 제어2 _ DigitalIn 클래스를 사용한 버전
회로 : 142page 참고
3_StepperMotorButtonUsingInterruption.cpp
 */
#include "mbed.h"
#include "sMotor.h"

// sMotor 라이브러리의 클래스
sMotor motor(D0, D1, D2, D3);

// InterrupIn 클래스를 이용한 버튼 인터럽트 제어
InterruptIn button_1(PA_5);

// 360도는 512 스텝
int numstep = 512;
// 스텝 모터의 속도
int step_speed = 1200;
// 방향 제어 변수
int direction = 0;

// 버튼이 눌렸을 때 방향이 바뀜
void changeDirection(void){
    direction = 1- direction;
}

int main(){
    // button_1은 PullDown 방식의 저항을 사용하는 버튼
    button_1.mode(PullDown);

    // 버튼이 눌렸을 때 호출되는 콜백함수 설정 (PullUp 방식은 button_1.fall() 함수를 통해 호출)
    button_1.rise(changeDirection);

    while(1){
        // (각도, 방향(0: 시계방향, 1: 반시계방향), 속도)
        motor.step(numstep, direction, step_speed);
    }
}

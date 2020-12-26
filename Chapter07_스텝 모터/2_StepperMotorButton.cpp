/*
2020-12-26    스텝모터 제어2 _ DigitalIn 클래스를 사용한 버전
회로 : 142page 참고
2_StepperMotorButton.cpp
 */
#include "mbed.h"
#include "sMotor.h"

// sMotor 라이브러리의 클래스
sMotor motor(D0, D1, D2, D3);

// PullDown 저항 방식을 사용하는 버튼
DigitalIn button_1(PA_5, PullDown);

// 360도는 512 스텝
int numstep = 512;
// 스텝 모터의 속도
int step_speed = 1200;
// 방향 제어 변수
int direction = 0;

int main(){
    while(1){
        // 버튼이 눌렸을 때 스탭 모터의 방향이 바뀜
        if(button_1.read() == true){
            direction = 1- direction;
            wait(1);
        }

        // (각도, 방향(0: 시계방향, 1: 반시계방향), 속도)
        motor.step(numstep, direction, step_speed);
    }
}

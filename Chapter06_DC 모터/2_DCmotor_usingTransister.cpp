/*
2020-12-29    트랜지스터를 사용하여 DC 모터 회전 방향 제어 _p328
회로 : http://wiki.vctec.co.kr/opensource/arduino/dcmotorcontrol 참고
DCMotor_usingTransister.cpp

 */
#include "mbed.h"

// DC 모터의 방향 제어 출력 설정
DigitalOut In1(PA_5), In2(PA_6);
// 트랜지스터 베이스전압 출력핀 PA_7
PwmOut Power(PA_7);

// 속도 제어를 위한 Ticker
Ticker myTicker;
// 모터의 속도
float speed = 0.0f;
// 모터의 속도 증감 플래그 변수
bool speed_up = true;
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

// 모터의 속도를 조절하는 함수
void speedControl(){
    if((speed <1.0f) && speed_up){
        speed += 0.1f;
    }
    else if((speed >0.0f) && !speed_up){
        speed -= 0.1f;
    }
    // 속도 증감
    Power.write(speed);
}

int main(){
    // 1초마다 속도 조절
    myTicker.attach(&speedControl, 1);

    while(1){
        forward();
        wait(2);
        backward();
        wait(2);
        stop();
        wait(2);
    }
}

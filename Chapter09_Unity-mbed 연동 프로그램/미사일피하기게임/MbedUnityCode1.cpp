/*
2020-01-01    Mbed-Unity 연동 프로그램 (로터리 엔코더 모듈 사용)
회로 : page 222
MbedUnityCode1.cpp
 */
#include "mbed.h"
#include "mRotaryEncoder.h"

// UART2 포트, 컴퓨터 연결
Serial pc(USBTX, USBRX);
// PA_5 핀으로 LED 제어
DigitalOut LED(PA_5);

// 로터리 인코더(S1핀, S2핀, Key핀)
mRotaryEncoder encoder(D0,D1,D2);
int data;

// 로터리 인코더를 회전할 때 호출되는 함수
void rotate(){
    int data = encoder.Get();

    if(data <0) {
        pc.putc(0);
        encoder.Set(0);
    }
    // 로터리 인코더의 한바퀴는 40
    else if(data < 40){
        pc.putc(data/2);
    }
    else {
        pc.putc(20);
        encoder.Set(40);
    }
}

int main(){
    LED = false;
    // 회전되었을 때 호출되는 콜백함수 설정
    encoder.attachROT(&rotate);

    while(true){
    }
}

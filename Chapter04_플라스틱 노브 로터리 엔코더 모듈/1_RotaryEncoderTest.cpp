/*
2020-12-23    로터리 인코더의 사용_225page
회로 : page 222
RotaryEncoderTest.cpp
 */
#include "mbed.h"
#include "mRotaryEncoder.h"

// UART2 포트, 컴퓨터 연결
Serial pc(USBTX, USBRX);
DigitalOut LED(PA_5);           // PA_5 핀으로 LED 제어

mRotaryEncoder encoder(D0,D1,D2);  // 로터리 인코더(S1핀, S2핀, Key핀)
int data;

//
void blink(){
    LED = !LED;
}

// 로터리 인코더를 회전할 때 호출되는 함수
void rotate(){
    data = encoder.Get();
}

int main(){
    LED = false;
    encoder.attachSW(&blink);       // 버튼이 눌렸을 때 호출되는 콜백함수 설정
    encoder.attachROT(&rotate);     // 회전되었을 때 호출되는 콜백함수 설정

    while(true){
        pc.printf("%d\n", data);        // 매 2초마다 회전된 값 출력.
        wait(2);
    }
}

/*
2020-12-23    이벤트 큐를 사용한 로터리 엔코더 테스트(창작)
회로 : page 222
RotaryEncoderUsingQueue.cpp
 */
#include "mbed.h"
#include "mRotaryEncoder.h"

// UART2 포트, 컴퓨터 연결
Serial pc(USBTX, USBRX);
 // PA_5 핀으로 LED 제어
DigitalOut LED(PA_5);          
// 이벤트 큐
EventQueue *queue = mbed_event_queue();

// 로터리 인코더(S1핀, S2핀, Key핀)
mRotaryEncoder encoder(D0,D1,D2);

// 스위치가 눌렸을 때 LED 꺼졌다, 켜졌다. 반복
void blink(){
    LED = !LED;
}

// PC에게 회전이 발생할 때 값을 출력하기 위한 함수
void print(){
   pc.printf("%d\n", encoder.Get());
}

// 로터리 인코더를 회전할 때 호출되는 함수
void rotate(){
    queue->call(&print);
}

int main(){
    LED = false;
    // 버튼이 눌렸을 때 호출되는 콜백함수 설정
    encoder.attachSW(&blink);
    // 회전되었을 때 호출되는 콜백함수 설정
    encoder.attachROT(&rotate);
    // 큐에 있는 이벤트를 시간 제약없이 실행
    queue->dispatch_forever();


    while(true){
    }
}

/*
2020-12-24    이벤트 큐와 PWM을 사용한 로터리 엔코더(창작)
회로 : page 222
RotaryEncoderLEDUsingPWM.cpp
 */
#include "mbed.h"
#include "mRotaryEncoder.h"

Serial pc(USBTX, USBRX);              // pc와의 시리얼 통신
EventQueue *queue = mbed_event_queue();     // 콜백함수의 이벤트를 호출하기 위한 큐
mRotaryEncoder encoder(D0,D1,D2);       // 로터리 인코더(S1핀, S2핀, Key핀)
float pulse;
int encoder_data;
PwmOut led(PB_8);                   // DigitalOut을 사용하는 대신 PwmOut 클래스를 사용

//
void processing(){
    if(encoder.Get() <0){
        encoder_data = 0;
    }
    else if(encoder.Get() > 100){
        encoder_data = 100;
    }
    else{
        encoder_data = encoder.Get();
    }
    // PWM 범위 (0~1.0)
    pulse = (float)encoder_data / 100;
    pc.printf("encoder data : %d pulse : %f\n", encoder_data, pulse);
}

void rotate(){
    queue->call(&processing);
}

int main(){
    encoder.attachROT(&rotate);     // 엔코더를 회전하였을 때 호출되는 콜백함수 등록

    while(true){
        led.write(pulse);       // pwm 제어
    }
}

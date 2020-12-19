/*
2020-12-19    6장_DigitalIn_96page
회로 : 95page 그림 6-14 참고
 버튼 입력에 따른 LED 키기
 */

#include "mbed.h"

DigitalOut LED_1(PA_5);     // PA_5 핀을 사용하는 LED
DigitalOut LED_2(PA_6);     // PA_6 핀을 사용하는 LED

DigitalIn button_1(PD_14, PullUp);          // 풀업 방식 저항을 사용하는 버튼
DigitalIn button_2(PD_15, PullDown);        // 풀다운 방식 저항을 사용하는 버튼

int main(){
    while(true){
        LED_1 = button_1.read();            // (풀업 방식) 버튼을 누르면 false
        LED_2 = button_2.read();            // (풀다운 방식) 버튼을 누르면 true
    }
}

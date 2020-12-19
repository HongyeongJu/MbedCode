/*
2020-12-19    6장_DigitalInOut_98page
회로 : 95page 그림 6-14 참고
DigitalInOut 클래스를 사용하여 버튼을 누르는 것에 따라 LED 키고 끄기
 */

#include "mbed.h"

DigitalInOut LED_1(PA_5);     // PA_5 핀을 사용하도록 설정
DigitalInOut LED_2(PA_6);     // PA_6 핀을 사용하도록 설정

DigitalInOut button_1(PD_14);                          // PD_14핀으로 설정
DigitalInOut button_2(PD_15, PIN_INPUT, PullDown, 0);  // PullDown 저항을 사용하는 PD_15 입력핀 설정

int main(){
    LED_1.output();             // 출력으로 설정
    LED_2.output();             // 출력으로 설정

    button_1.input();           // 입력으로 설정
    button_1.mode(PullUp);      // 풀업 저항 방식을 사용

    while(true){
        LED_1 = button_1.read();            // (풀업 방식) 버튼을 누르면 false
        LED_2 = button_2.read();            // (풀다운 방식) 버튼을 누르면 true
    }
}

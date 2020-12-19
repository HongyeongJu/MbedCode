/*
2020-12-19    6장_DigitalInOut(창작)
회로 : 95page 그림 6-14 참고

DigitalInOut 클래스를 사용하여 버튼을 누를 때마다 한개의 LED가 켜짐/꺼짐을 조절하는 코드
 */

#include "mbed.h"

DigitalInOut LED_1(PA_5);     // PA_5 핀을 사용하도록 설정

DigitalInOut button_1(PD_15, PIN_INPUT, PullDown, 0);     // PullDown 방식의 저항을 사용하는 버튼

int main(){
    LED_1.output();             // 출력으로 설정

    while(true){
        // 버튼을 누르면 LED_1의 상태 변경
        if(button_1.read()){
            LED_1 = !LED_1;
            wait(0.5);      // 0.5초 동안 잠시 대기
        }
    }
}

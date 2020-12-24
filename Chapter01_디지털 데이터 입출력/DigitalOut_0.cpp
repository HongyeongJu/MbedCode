#include "mbed.h"

DigitalOut myLED1(PA_5);            // PA_5 핀에 연결된 LED를 출력으로 사용

int main() {
   bool bState = true;
   while (1) {
       
        myLED1 = bState;  //디지털아웃 객체의 값 설정
       
        bState = !bState; //bState (불 변수) 변수 반전

        wait(1);    //1초 동안 대기
    }
}

/*
2020-12-24    Cds 센서를 사용하여 어두우면 켜지고 밝으면 꺼지도록 LED 제어2
회로 : page 230
CdsLEDUsingPwm
 */
#include "mbed.h"

AnalogIn cds(A0);               // 조도 센서 A0에 연결
PwmOut LED(PA_5);               // PA_5핀으로 LED 제어

int main(){
    while(1){
        float t = cds.read();       //0~1 사이 값 반환
        LED.write(1 - t);         // 어두우면 어두울 수록 밝게, 밝으면 밝을 수록 어둡게 LED 켬
        wait(0.1);
    }
}

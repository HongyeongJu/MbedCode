/*
2020-12-24    Cds 센서를 사용하여 어두우면 켜지고 밝으면 꺼지도록 LED 제어
회로 : page 230
CdsLED
 */
#include "mbed.h"

AnalogIn cds(A0);               // 조도 센서 A0에 연결
DigitalOut LED(PA_5);           // PA_5핀으로 LED 제어

int main(){
    while(1){
        float t = cds.read();       //0~1 사이 값 반환

        // 어두우면 LED ON, 밝으면 LED OFF
        if( t < 0.3f){
            printf("LED ON\n");
            LED = true;
        }else if(t > 0.8f){
            printf("LED OFF\n");
            LED = false;
        }
        wait(2);            // 2초마다 밝은지 어두운지 검사.
    }
}

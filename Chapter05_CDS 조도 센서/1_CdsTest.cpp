/*
2020-12-24    Cds 조도 센서 테스트_page233
회로 : page 230
CdsTest
 */
#include "mbed.h"

AnalogIn cds(A0);               // 조도 센서 A0에 연결

int main(){
    while(1){
        float t = cds.read();       //0~1 사이 값 반환

        printf("%f\n", t);

        wait(2);                    // 2초 마다 출력
    }
}

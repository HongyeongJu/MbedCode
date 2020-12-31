/*
2020-12-31   초음파 센서_ 256page
회로 : 254page
초음파 센서를 통해 LED 제어
 */

#include "mbed.h"
#include "HCSR04.h"

// 트리거, 에코
HCSR04 sensor(D0, D1);
// LED를 제어하기 위한 스위치 변수
bool isLED = false;
// LED 신호를 줄 Digital Pin
DigitalOut LED(D2);
// Ticker 객체
Ticker myTicker;

// 매초 마다 초음파 센서를 통해 거리를 계산하는 함수
void sensing(){
    // cm 단위로 거리 측정
    long distance = sensor.distance(CM);

    // 거리가 5cm 초과이면 LED를 키고 아니면 끄기
    if(distance > 5){
      isLED = true;
    }else{
      isLED = false;
    }

    // 거리 출력
    printf("Distance : %d\n", distance);
}

int main(){
  while(1){
    LED = isLED;
  }
}

/*
2020-12-31   초음파 센서_ 256page
회로 : 254page
초음파 센서 제어
 */

#include "mbed.h"
#include "HCSR04.h"

// 트리거, 에코
HCSR04 sensor(D0, D1);

int main(){
  while(1){
    // cm 단위로 거리 측정
    long distance = sensor.distance(CM);
    // 거리 출력
    printf("Distance : %d\n", distance);
    // 1초동안 대기 
    wait(1);
  }
}

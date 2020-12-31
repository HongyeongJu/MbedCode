/*
2020-12-31   적외선 센서_ 259page
회로 : 258page
적외선 센서 제어
 */

#include "mbed.h"

AnalogIn IRSensor(A0);

int main()
{
  while(1){
    // 입력 전압
    float voltage =  sensor.read() * 3.3;
    // 거리 계산
    float distance = 27.86 * pow((double)voltage, -1.15);

    printf("Read = %4.2f, Distance =  %.1f Cm\n", voltage, distance);
    wait(1);
  }
}

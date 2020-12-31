/*
2020-12-31   적외선 센서_ 259page
회로 : 258page
적외선 센서 제어
 */

#include "mbed.h"
// IRSensor의 값을 받기 위해 객체 선언
AnalogIn IRSensor(A0);

int main()
{
  while(1){
    // IRSensor로부터 데이터를 받는다.
    int data = IRSensor.read();

    // 만약 데이터가 0(LOW)이면 바로 앞에 물체가 있음을 검출한다.
    if(data == 0){
        printf("Detected!\n");
    }else {
        printf("Undetected!\n");
    }
    wait(1);
  }
}

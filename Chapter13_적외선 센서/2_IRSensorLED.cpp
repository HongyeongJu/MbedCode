/*
2020-12-31   적외선 센서_ 259page _창작
회로 : 258page
적외선 센서를 통해 LED 신호 제어
 */

#include "mbed.h"
// IRSensor의 값을 받기 위해 객체 선언
AnalogIn IRSensor(A0);
// LED를 제어하기 위한 스위치 변수
bool isLED = false;
// LED 신호를 줄 Digital Pin
DigitalOut LED(D0);
// Ticker 객체
Ticker myTicker;

// 매 초마다 IR 센서의 값을 센싱하는 함수
void sensing(){
  // 입력 전압
  float voltage =  sensor.read() * 3.3;
  // 거리 계산
  float distance = 27.86 * pow((double)voltage, -1.15);

  // 만약 거리가 5cm 미만이면 LED ON 그렇지 않으면 LED OFF
  if(distance < 5){
    isLED = true;
  }else {
    isLED = false;
  }

  printf("Read = %4.2f, Distance =  %.1f Cm\n", voltage, distance);
}

int main()
{
  // 1초마다 sensing 함수가 호출
  myTicker.attach(&sensing, 1);
  while(1){
    LED = isLED;
  }
}

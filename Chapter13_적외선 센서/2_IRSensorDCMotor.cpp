/*
2020-12-31   적외선 센서_ 259page _창작
회로 : 258page + TR DC 모터 회로
적외선 센서를 통해 DC 모터 제어
 */

#include "mbed.h"
// IRSensor의 값을 받기 위해 객체 선언
AnalogIn IRSensor(A0);

// DC 모터의 방향 제어 출력 설정
DigitalOut In1(PA_5), In2(PA_6);
// 트랜지스터 베이스전압 출력핀 PA_7
PwmOut Power(PA_7);
// Ticker 객체
Ticker myTicker;

// DC 모터를 앞으로 이동
void forward(){
    In1 = false;
    In2 = true;
}

// DC 모터를 뒤로 이동
void backward(){
    In1 = true;
    In2 = false;
}

// DC 모터를 정지
void stop(){
    In1 = false;
    In2 = false;
}


// 매 초마다 IR 센서의 값을 센싱하는 함수
void sensing(){
  // IRSensor로부터 데이터를 받는다.
  int data = IRSensor.read();

  // 만약 적외선 센서에 물체가 검출되면 모터를 정회전, 아니면 역회전한다.
  if(data == 0){
      printf("Forward!\n");
      forward();
  }else {
      printf("Backward\n");
      backward();
  }
}

int main()
{
  // 1초마다 sensing 함수가 호출
  myTicker.attach(&sensing, 1);
  Power.write(1);
  while(1){

  }
}

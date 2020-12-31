# 적외선 센서

## 목차
1. IRSensor.cpp
2. IRSensorDCMotor.cpp

## 1. IRSensor
### 코드
```c++
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


```

### 결과 사진

![](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter13_%EC%A0%81%EC%99%B8%EC%84%A0%20%EC%84%BC%EC%84%9C/1_IRSensor_result.jpg)

### 결과 회로 사진

![](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter13_%EC%A0%81%EC%99%B8%EC%84%A0%20%EC%84%BC%EC%84%9C/1_IRSensor_circuit.jpg)

## 2. IRSensorLED

### 코드
```c++

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

```

### 결과 사진

![](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter13_%EC%A0%81%EC%99%B8%EC%84%A0%20%EC%84%BC%EC%84%9C/2_IRSensorDCMotor_realpicture.jpg)

![](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter13_%EC%A0%81%EC%99%B8%EC%84%A0%20%EC%84%BC%EC%84%9C/2_IRSensorDCMotor_result.jpg)

### 결과 회로 사진

![](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter06_DC%20%EB%AA%A8%ED%84%B0/2_DCmotorUsingTransiter_circuit.jpg)

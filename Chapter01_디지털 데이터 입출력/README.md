# 디지털 데이터 입출력
## 목차
1. Digital Out
2. Digital In
## 1. Digital Out
### 코드
```c++
/*
2020-12-16    6장_DigitalOut_93page
회로 : 92page 그림 6-12 참고
 2개의 LED 키고 끄기
 */

 #include "mbed.h"

 DigitalOut LED_1(PA_5);            // PA_5 핀에 연결된 LED를 출력으로 사용
 DigitalOut LED_2(PA_6);            // PA_6 핀에 연결된 LED를 출력으로 사용

 int main(){
     bool condition = true;             // LED_1의 상태

     while(1){
         // 연산자 재정의를 통한 디지털 데이터 출력
         LED_1 = condition;
         LED_2 = !condition;

         // 맴버 함수를 통해 디지털 데이터 출력
         //LED_1.write(condition);
         // LED_2.write(!LED_1.read());

         condition = !condition;

         wait(0.5);
    }
}

```
### 회로 사진
![DigitalOut_회로사진](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter01_%EB%94%94%EC%A7%80%ED%84%B8%20%EB%8D%B0%EC%9D%B4%ED%84%B0%20%EC%9E%85%EC%B6%9C%EB%A0%A5/DigitalOut_Circuit.jpg)
### 결과 사진
![DigitalOut_결과사진](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter01_%EB%94%94%EC%A7%80%ED%84%B8%20%EB%8D%B0%EC%9D%B4%ED%84%B0%20%EC%9E%85%EC%B6%9C%EB%A0%A5/DigitalOut_Result.jpg)

## 2. Digital In
### 코드
``` c++
/*
2020-12-19    6장_DigitalIn_96page
회로 : 95page 그림 6-14 참고
 버튼 입력에 따른 LED 키기
 */

#include "mbed.h"

DigitalOut LED_1(PA_5);     // PA_5 핀을 사용하는 LED
DigitalOut LED_2(PA_6);     // PA_6 핀을 사용하는 LED

DigitalIn button_1(PD_14, PullUp);          // 풀업 방식 저항을 사용하는 버튼
DigitalIn button_2(PD_15, PullDown);        // 풀다운 방식 저항을 사용하는 버튼

int main(){
    while(true){
        LED_1 = button_1.read();            // (풀업 방식) 버튼을 누르면 false
        LED_2 = button_2.read();            // (풀다운 방식) 버튼을 누르면 true
    }
}

```
### 회로 사진
![DigitalIn_회로사진](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter01_%EB%94%94%EC%A7%80%ED%84%B8%20%EB%8D%B0%EC%9D%B4%ED%84%B0%20%EC%9E%85%EC%B6%9C%EB%A0%A5/DigitalIn_Circuit.jpg)
### 결과 사진
![DigitalIn_결과사진](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter01_%EB%94%94%EC%A7%80%ED%84%B8%20%EB%8D%B0%EC%9D%B4%ED%84%B0%20%EC%9E%85%EC%B6%9C%EB%A0%A5/DigitalIn_Result.jpg)

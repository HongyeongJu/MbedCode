# 디지털 데이터 입출력
## 목차
1. Digital Out
2. Digital In
3. Digital In/Out
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
![DigitalOut_회로사진](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter01_%EB%94%94%EC%A7%80%ED%84%B8%20%EB%8D%B0%EC%9D%B4%ED%84%B0%20%EC%9E%85%EC%B6%9C%EB%A0%A5/1_DigitalOut_Circuit.jpg)
### 결과 사진
![DigitalOut_결과사진](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter01_%EB%94%94%EC%A7%80%ED%84%B8%20%EB%8D%B0%EC%9D%B4%ED%84%B0%20%EC%9E%85%EC%B6%9C%EB%A0%A5/1_DigitalOut_Result.jpg)

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
![DigitalIn_회로사진](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter01_%EB%94%94%EC%A7%80%ED%84%B8%20%EB%8D%B0%EC%9D%B4%ED%84%B0%20%EC%9E%85%EC%B6%9C%EB%A0%A5/2_DigitalIn_Circuit.jpg)
### 결과 사진
![DigitalIn_결과사진](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter01_%EB%94%94%EC%A7%80%ED%84%B8%20%EB%8D%B0%EC%9D%B4%ED%84%B0%20%EC%9E%85%EC%B6%9C%EB%A0%A5/2_DigitalIn_Result.jpg)

## 3. Digital In/Out
### 코드
```c++
/*
2020-12-19    6장_DigitalInOut_98page
회로 : 95page 그림 6-14 참고
DigitalInOut 클래스를 사용하여 버튼을 누르는 것에 따라 LED 키고 끄기
 */

#include "mbed.h"

DigitalInOut LED_1(PA_5);     // PA_5 핀을 사용하도록 설정
DigitalInOut LED_2(PA_6);     // PA_6 핀을 사용하도록 설정

DigitalInOut button_1(PD_14);                          // PD_14핀으로 설정   
DigitalInOut button_2(PD_15, PIN_INPUT, PullDown, 0);  // PullDown 저항을 사용하는 PD_15 입력핀 설정                           

int main(){
    LED_1.output();             // 출력으로 설정
    LED_2.output();             // 출력으로 설정

    button_1.input();           // 입력으로 설정
    button_1.mode(PullUp);      // 풀업 저항 방식을 사용

    while(true){
        LED_1 = button_1.read();            // (풀업 방식) 버튼을 누르면 false
        LED_2 = button_2.read();            // (풀다운 방식) 버튼을 누르면 true
    }
}
```

### 회로 사진
![DigitalInOut_회로사진](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter01_%EB%94%94%EC%A7%80%ED%84%B8%20%EB%8D%B0%EC%9D%B4%ED%84%B0%20%EC%9E%85%EC%B6%9C%EB%A0%A5/2_DigitalIn_Circuit.jpg)
### 결과 사진
![DigitalInOut_결과사진](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter01_%EB%94%94%EC%A7%80%ED%84%B8%20%EB%8D%B0%EC%9D%B4%ED%84%B0%20%EC%9E%85%EC%B6%9C%EB%A0%A5/2_DigitalIn_Result.jpg)

## 4. Digital In/Out 2(창작)
### 설명
- 버튼을 누를 때마다 한개의 LED가 켜지거나 꺼지는 코드
### 코드
```c++
/*
2020-12-19    6장_DigitalInOut(창작)
회로 : 95page 그림 6-14 참고

DigitalInOut 클래스를 사용하여 버튼을 누를 때마다 한개의 LED가 켜짐/꺼짐을 조절하는 코드
 */

#include "mbed.h"

DigitalInOut LED_1(PA_5);     // PA_5 핀을 사용하도록 설정

DigitalInOut button_1(PD_15, PIN_INPUT, PullDown, 0);     // PullDown 방식의 저항을 사용하는 버튼

int main(){
    LED_1.output();             // 출력으로 설정

    while(true){
        // 버튼을 누르면 LED_1의 상태 변경
        if(button_1.read()){
            LED_1 = !LED_1;
            wait(0.5);      // 0.5초 동안 잠시 대기
        }   
    }
}

```
### 회로 사진
![DigitalInOut2_회로사진](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter01_%EB%94%94%EC%A7%80%ED%84%B8%20%EB%8D%B0%EC%9D%B4%ED%84%B0%20%EC%9E%85%EC%B6%9C%EB%A0%A5/2_DigitalIn_Circuit.jpg)
### 결과 사진
![DigitalInOut2_결과사진](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter01_%EB%94%94%EC%A7%80%ED%84%B8%20%EB%8D%B0%EC%9D%B4%ED%84%B0%20%EC%9E%85%EC%B6%9C%EB%A0%A5/4_DigitalInOut2_Result.jpg)

# Rotary Encoder module
## Encoder 모듈을 사용하기 위한 Library
링크 : !(https://os.mbed.com/users/charly/code/mRotaryEncoder/)

### 임포트 과정

1. Compiler에서 Import 클릭
![과정1](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter04_%ED%94%8C%EB%9D%BC%EC%8A%A4%ED%8B%B1%20%EB%85%B8%EB%B8%8C%20%EB%A1%9C%ED%84%B0%EB%A6%AC%20%EC%97%94%EC%BD%94%EB%8D%94%20%EB%AA%A8%EB%93%88/%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%AC%EC%B6%94%EA%B0%80%EA%B3%BC%EC%A0%951.jpg)
2. 검색창에 "rotary" 검색
![과정2](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter04_%ED%94%8C%EB%9D%BC%EC%8A%A4%ED%8B%B1%20%EB%85%B8%EB%B8%8C%20%EB%A1%9C%ED%84%B0%EB%A6%AC%20%EC%97%94%EC%BD%94%EB%8D%94%20%EB%AA%A8%EB%93%88/%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%AC%EC%B6%94%EA%B0%80%EA%B3%BC%EC%A0%952.jpg)
3. mRotaryEncoder를 선택하여 Import

## 목차
1. RotaryEncoderTest.cpp
2. 2_RotaryEncoderUsingQueue.cpp
## 1. RotaryEncoderTest.cpp
### 코드
```c++
/*
2020-12-23    로터리 인코더의 사용_225page
회로 : page 222
RotaryEncoderTest.cpp
 */
#include "mbed.h"
#include "mRotaryEncoder.h"

// UART2 포트, 컴퓨터 연결
Serial pc(USBTX, USBRX);
DigitalOut LED(PA_5);           // PA_5 핀으로 LED 제어

mRotaryEncoder encoder(D0,D1,D2);  // 로터리 인코더(S1핀, S2핀, Key핀)
int data;

//
void blink(){
    LED = !LED;    
}

// 로터리 인코더를 회전할 때 호출되는 함수
void rotate(){
    data = encoder.Get();
}

int main(){
    LED = false;
    encoder.attachSW(&blink);       // 버튼이 눌렸을 때 호출되는 콜백함수 설정
    encoder.attachROT(&rotate);     // 회전되었을 때 호출되는 콜백함수 설정

    while(true){
        pc.printf("%d\n", data);        // 매 2초마다 회전된 값 출력.
        wait(2);
    }
}

```
### 결과 회로 사진
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter04_%ED%94%8C%EB%9D%BC%EC%8A%A4%ED%8B%B1%20%EB%85%B8%EB%B8%8C%20%EB%A1%9C%ED%84%B0%EB%A6%AC%20%EC%97%94%EC%BD%94%EB%8D%94%20%EB%AA%A8%EB%93%88/1_RotaryEncoderTest_result_circuit.jpg)
### 결과 사진
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter04_%ED%94%8C%EB%9D%BC%EC%8A%A4%ED%8B%B1%20%EB%85%B8%EB%B8%8C%20%EB%A1%9C%ED%84%B0%EB%A6%AC%20%EC%97%94%EC%BD%94%EB%8D%94%20%EB%AA%A8%EB%93%88/1_RotaryEncoderTest_result_picture.jpg)
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter04_%ED%94%8C%EB%9D%BC%EC%8A%A4%ED%8B%B1%20%EB%85%B8%EB%B8%8C%20%EB%A1%9C%ED%84%B0%EB%A6%AC%20%EC%97%94%EC%BD%94%EB%8D%94%20%EB%AA%A8%EB%93%88/1_RotaryEncoderTest_result.jpg)

## 2_RotaryEncoderUsingQueue.cpp
### 코드
```c++
/*
2020-12-23    이벤트 큐를 사용한 로터리 엔코더 테스트(창작)
회로 : page 222
RotaryEncoderUsingQueue.cpp
 */
#include "mbed.h"
#include "mRotaryEncoder.h"

// UART2 포트, 컴퓨터 연결
Serial pc(USBTX, USBRX);
DigitalOut LED(PA_5);           // PA_5 핀으로 LED 제어
EventQueue *queue = mbed_event_queue();     // 이벤트 큐

mRotaryEncoder encoder(D0,D1,D2);  // 로터리 인코더(S1핀, S2핀, Key핀)
int data;

// 스위치가 눌렸을 때 LED 꺼졌다, 켜졌다. 반복
void blink(){
    LED = !LED;
}

// PC에게 회전이 발생할 때 값을 출력하기 위한 함수
void print(){
   pc.printf("%d\n", encoder.Get());
}

// 로터리 인코더를 회전할 때 호출되는 함수
void rotate(){
    queue->call(&print);
}

int main(){
    LED = false;
    encoder.attachSW(&blink);       // 버튼이 눌렸을 때 호출되는 콜백함수 설정
    encoder.attachROT(&rotate);     // 회전되었을 때 호출되는 콜백함수 설정
    queue->dispatch_forever();      // 큐를


    while(true){
    }
}

```
### 결과 회로 사진
 -> 1번 회로와 같음.
### 결과 사진
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter04_%ED%94%8C%EB%9D%BC%EC%8A%A4%ED%8B%B1%20%EB%85%B8%EB%B8%8C%20%EB%A1%9C%ED%84%B0%EB%A6%AC%20%EC%97%94%EC%BD%94%EB%8D%94%20%EB%AA%A8%EB%93%88/1_RotaryEncoderTest_result_picture.jpg)

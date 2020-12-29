# MbedUnity연동 프로그램

## 목차
1. 미사일피하기 게임

## 1. 미사일피하기 게임

### 게임 유니티 다운로드 링크

!(https://drive.google.com/drive/folders/13JNyFivjLItN2A8ewmxb8JqruMPzrCyh?usp=sharing)

### 제작 과정

![1](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/1.jpg)

- 생성 버튼을 누른다.

![2](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/2.jpg)

- 템플릿: 2D를 누르고 프로젝트 명과 저장위치를 정한다.

### Mbed 코드
```c++
/*
2020-12-28    Mbed-Unity 연동 프로그램 (로터리 엔코더 모듈 사용)
회로 : page 222
MbedUnityCode1.cpp
 */
#include "mbed.h"
#include "mRotaryEncoder.h"

// UART2 포트, 컴퓨터 연결
Serial pc(USBTX, USBRX);
// PA_5 핀으로 LED 제어
DigitalOut LED(PA_5);
// 이벤트 큐
EventQueue *queue = mbed_event_queue();

// 로터리 인코더(S1핀, S2핀, Key핀)
mRotaryEncoder encoder(D0,D1,D2);
int data;

// 로터리 인코더 회전을 할 때 Unity에게 값을 전송 (#(숫자)$)형식으로 전달
void print(){
   pc.printf("#%d$\n", encoder.Get());
}

// 로터리 인코더를 회전할 때 호출되는 함수
void rotate(){
    queue->call(&print);
}

int main(){
    LED = false;
    // 회전되었을 때 호출되는 콜백함수 설정
    encoder.attachROT(&rotate);
    queue->dispatch_forever();

    while(true){
    }
}
```

### Mbed 회로 결과사진
![](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/MbedUnity_Picture.jpg)

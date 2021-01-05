# 초음파 센서

## 초음파 센서를 사용하기 위한 라이브러리 링크

!()

## 라이브러리 임포트 하는 방법

![]()

![]()

![]()


## 현재상황

- 현재 Mbed홈페이지 서버다운이되서 서버 풀리는 즉시 테스트하고 사진 올리겠습니다.

## 목차
1. Ultrasound.cpp
2. UltrasoundLED.cpp

## 1. Ultrasound
### 코드
```c++

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


```

### 결과 사진

![]()

![]()

### 결과 회로 사진

![]()


## 2. UltrasoundLED
### 코드
```c++

/*
2020-12-31   초음파 센서_ 256page
회로 : 254page
초음파 센서를 통해 LED 제어
 */

#include "mbed.h"
#include "HCSR04.h"

// 트리거, 에코
HCSR04 sensor(D0, D1);
// LED를 제어하기 위한 스위치 변수
bool isLED = false;
// LED 신호를 줄 Digital Pin
DigitalOut LED(D2);
// Ticker 객체
Ticker myTicker;

// 매초 마다 초음파 센서를 통해 거리를 계산하는 함수
void sensing(){
    // cm 단위로 거리 측정
    long distance = sensor.distance(CM);

    // 거리가 5cm 초과이면 LED를 키고 아니면 끄기
    if(distance > 5){
      isLED = true;
    }else{
      isLED = false;
    }

    // 거리 출력
    printf("Distance : %d\n", distance);
}

int main(){
  while(1){
    LED = isLED;
  }
}

```

### 결과 사진

![]()

![]()

### 결과 회로 사진

![]()

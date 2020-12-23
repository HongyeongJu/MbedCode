# Rotary Encoder module
## Encoder 모듈을 사용하기 위한 Library
링크 : !(https://os.mbed.com/users/charly/code/mRotaryEncoder/)

### 임포트 과정

1. Compiler에서 Import 클릭
![과정1]()
2. 검색창에 "rotary" 검색
![과정2]()
3. mRotaryEncoder를 선택하여 Import

## 목차
1. RotaryEncoderTest.cpp
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
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter03_FSR%20%EC%84%BC%EC%84%9C/3_FSRTest_result_circuit.jpg)
### 결과 사진
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter03_FSR%20%EC%84%BC%EC%84%9C/3_FSRTest_result_realpicture.jpg)
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter03_FSR%20%EC%84%BC%EC%84%9C/3_FSRTest_result_%EB%88%8C%EB%A0%B8%EC%9D%84%20%EB%95%8C.jpg)
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter03_FSR%20%EC%84%BC%EC%84%9C/3_FSRTest_result_%EB%88%8C%EB%A6%AC%EC%A7%80%20%EC%95%8A%EC%95%98%EC%9D%84%20%EB%95%8C.jpg)

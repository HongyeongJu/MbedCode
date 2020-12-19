# UART 통신
## 장치관리자
![장치관리자 사진]()
## 목차
1. DefaultPrint
2.
## 1. DefaultPrint
### 코드
```c++
/*
2020-12-19    7장_UART 시리얼 통신_106page
회로 : X
컴퓨터와 UART 시리얼 통신- 디폴트로 출력
 */

#include "mbed.h"

int main(){
    int second = 1;

    printf("Hello World!\n");       // 컴퓨터로 Hello World 출력

    while(true){
        printf("This program runs for %d seconds.\n", second++);       
        wait(1);            // 1초동안 대기
    }
}
```
### 결과 사진
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter01_%EB%94%94%EC%A7%80%ED%84%B8%20%EB%8D%B0%EC%9D%B4%ED%84%B0%20%EC%9E%85%EC%B6%9C%EB%A0%A5/1_DigitalOut_Result.jpg)

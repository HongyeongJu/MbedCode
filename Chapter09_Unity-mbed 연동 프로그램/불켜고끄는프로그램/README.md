# Mbed-Unity 연동 프로그램 (불키고 켜는 프로그램)

## 링크

!(https://drive.google.com/drive/folders/13JNyFivjLItN2A8ewmxb8JqruMPzrCyh)

## 프로그램 사진

![켜져있을 때](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EC%BC%9C%EC%A0%B8%EC%9E%88%EC%9D%84%EB%95%8C.jpg)

- 불이 켜졌을 때

![꺼져있을 떄](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EA%BA%BC%EC%A0%B8%EC%9E%88%EC%9D%84%20%EB%95%8C.jpg)

- 불이 꺼졌을 때

### MbedUnity1.cpp
```c++
/*
2020-12-30  UnityMbed 연동 프로그램1
회로 : DigitalIn 회로
UnityMbed1.cpp
 */
#include "mbed.h"

// 시리얼 통신
Serial Pc(USBTX, USBRX);

// PullDown 저항 방식을 사용하는 Button
DigitalIn button(PD_14, PullDown);

int main(){

    while(1){
        // 버튼을 누르면 방향 바뀌게하기
        if(button == true){
            printf("1");
        }
    }
}

```

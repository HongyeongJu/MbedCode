# Cds 조도 센서

## 목차
1. CdsTest.cpp
## 1. CdsTest.cpp
### 코드
```c++
/*
2020-12-24    Cds 조도 센서 테스트_page233
회로 : page 230
CdsTest
 */
#include "mbed.h"

AnalogIn cds(A0);               // 조도 센서 A0에 연결

int main(){
    while(1){
        float t = cds.read();       //0~1 사이 값 반환

        printf("%f\n", t);

        wait(2);                    // 2초 마다 출력
    }
}

```
### 결과 회로 사진
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter05_CDS%20%EC%A1%B0%EB%8F%84%20%EC%84%BC%EC%84%9C/1_CdsTest_circuit.jpg)
### 결과 사진
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter05_CDS%20%EC%A1%B0%EB%8F%84%20%EC%84%BC%EC%84%9C/1_CdsTest_result_picture.jpg)
밝을 때
![밝을 때 ](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter05_CDS%20%EC%A1%B0%EB%8F%84%20%EC%84%BC%EC%84%9C/1_CdsTest_result(%EB%B0%9D%EC%9D%84%EB%95%8C).jpg)
![어두울 때](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter05_CDS%20%EC%A1%B0%EB%8F%84%20%EC%84%BC%EC%84%9C/1_CdsTest_result(%EC%96%B4%EB%91%90%EC%9A%B8%20%EB%95%8C).jpg)

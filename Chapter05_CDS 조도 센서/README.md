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
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter04_%ED%94%8C%EB%9D%BC%EC%8A%A4%ED%8B%B1%20%EB%85%B8%EB%B8%8C%20%EB%A1%9C%ED%84%B0%EB%A6%AC%20%EC%97%94%EC%BD%94%EB%8D%94%20%EB%AA%A8%EB%93%88/1_RotaryEncoderTest_result_circuit.jpg)
### 결과 사진
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter04_%ED%94%8C%EB%9D%BC%EC%8A%A4%ED%8B%B1%20%EB%85%B8%EB%B8%8C%20%EB%A1%9C%ED%84%B0%EB%A6%AC%20%EC%97%94%EC%BD%94%EB%8D%94%20%EB%AA%A8%EB%93%88/1_RotaryEncoderTest_result_picture.jpg)
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter04_%ED%94%8C%EB%9D%BC%EC%8A%A4%ED%8B%B1%20%EB%85%B8%EB%B8%8C%20%EB%A1%9C%ED%84%B0%EB%A6%AC%20%EC%97%94%EC%BD%94%EB%8D%94%20%EB%AA%A8%EB%93%88/1_RotaryEncoderTest_result.jpg)

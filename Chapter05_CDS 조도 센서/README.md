# Cds 조도 센서

## 목차
1. CdsTest.cpp
2. CdsLED.cpp
3. CdsLEDUsingPwm.cpp
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

어두울 때

![어두울 때](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter05_CDS%20%EC%A1%B0%EB%8F%84%20%EC%84%BC%EC%84%9C/1_CdsTest_result(%EC%96%B4%EB%91%90%EC%9A%B8%20%EB%95%8C).jpg)

## 2. CdsLED.cpp
### 코드
```c++
/*
2020-12-24    Cds 센서를 사용하여 어두우면 켜지고 밝으면 꺼지도록 LED 제어
회로 : page 230
CdsLED
 */
#include "mbed.h"

AnalogIn cds(A0);               // 조도 센서 A0에 연결
DigitalOut LED(PA_5);           // PA_5핀으로 LED 제어

int main(){
    while(1){
        float t = cds.read();       //0~1 사이 값 반환

        // 어두우면 LED ON, 밝으면 LED OFF
        if( t < 0.3f){
            printf("LED ON\n");
            LED = true;
        }else if(t > 0.8f){
            printf("LED OFF\n");
            LED = false;
        }
        wait(2);            // 2초마다 밝은지 어두운지 검사.
    }
}


```
### 결과 회로 사진
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter05_CDS%20%EC%A1%B0%EB%8F%84%20%EC%84%BC%EC%84%9C/1_CdsTest_circuit.jpg)
### 결과 사진
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter05_CDS%20%EC%A1%B0%EB%8F%84%20%EC%84%BC%EC%84%9C/2_CdsLED_result_picture.jpg)

밝을 때 LED 꺼짐

![밝을 때 ](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter05_CDS%20%EC%A1%B0%EB%8F%84%20%EC%84%BC%EC%84%9C/2_CdsLED_result(LED%20%EA%BA%BC%EC%A7%90).jpg)

어두울 때 LED 켜짐

![어두울 때](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter05_CDS%20%EC%A1%B0%EB%8F%84%20%EC%84%BC%EC%84%9C/2_CdsLED_result(LED%20%EC%BC%9C%EC%A7%90).jpg)

## 3. CdsLEDUsingPwm.cpp
### 코드
```c++
/*
2020-12-24    Cds 센서를 사용하여 어두우면 켜지고 밝으면 꺼지도록 LED 제어2
회로 : page 230
CdsLEDUsingPwm
 */
#include "mbed.h"

AnalogIn cds(A0);               // 조도 센서 A0에 연결
PwmOut LED(PA_5);               // PA_5핀으로 LED 제어

int main(){
    while(1){
        float t = cds.read();       //0~1 사이 값 반환
        LED.write(1 - t);         // 어두우면 어두울 수록 밝게, 밝으면 밝을 수록 어둡게 LED 켬
        wait(0.1);
    }
}
```

### 결과 회로 사진
-> 1,2 번과 같음

### 결과 사진
![결과 사진]()

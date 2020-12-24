# Stepper motor(스텝 모터)
## 스텝 모터를 사용하기 위한 라이브러리
링크 : !(https://os.mbed.com/users/XtaticO/code/sMotor/)

### 임포트 과정

1. Compiler에서 Import 클릭
![과정1](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter04_%ED%94%8C%EB%9D%BC%EC%8A%A4%ED%8B%B1%20%EB%85%B8%EB%B8%8C%20%EB%A1%9C%ED%84%B0%EB%A6%AC%20%EC%97%94%EC%BD%94%EB%8D%94%20%EB%AA%A8%EB%93%88/%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%AC%EC%B6%94%EA%B0%80%EA%B3%BC%EC%A0%951.jpg)
2. 검색창에 "sMotor" 검색
![과정2](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter07_%EC%8A%A4%ED%85%9D%20%EB%AA%A8%ED%84%B0/%EC%8A%A4%ED%85%9D%EB%AA%A8%ED%84%B0%20%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%AC%20%EC%B6%94%EA%B0%80..jpg)
3. sMotor 선택하여 Import
![과정3](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter07_%EC%8A%A4%ED%85%9D%20%EB%AA%A8%ED%84%B0/%EC%8A%A4%ED%85%9D%EB%AA%A8%ED%84%B0%20%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%AC%20%EC%B6%94%EA%B0%802.jpg)

## 목차
1. StepperMotorTest.cpp
## 1. StepperMotor.cpp
### 코드
```c++
/*
2020-12-24    스텝모터 제어
회로 : X
DCMotorTest.cpp
 */
#include "mbed.h"
#include "sMotor.h"

// sMotor 라이브러리의 클래스
sMotor motor(D0, D1, D2, D3);

// 360도는 512 스텝
int numstep = 512;
// 스텝 모터의 속도
int step_speed = 1200;

int main(){
    while(1){
        // (각도, 방향(0: 시계방향, 1: 반시계방향), 속도)
        motor.step(numstep, 0, step_speed);
    }
}


```
### 결과 회로 사진
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter07_%EC%8A%A4%ED%85%9D%20%EB%AA%A8%ED%84%B0/%EC%8A%A4%ED%85%9D%EB%AA%A8%ED%84%B0%20%ED%9A%8C%EB%A1%9C.jpg)
### 결과 사진
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter07_%EC%8A%A4%ED%85%9D%20%EB%AA%A8%ED%84%B0/1_StepperMotorTest_result_picture.jpg)

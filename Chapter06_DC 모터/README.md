# DC 모터

## 참고사항

책에 소개된 DC 모터 쉴드와 제가 가지고 있는 DC 모터 쉴드는 조금 다릅니다. (책에는 모터의 세기를 조절할 수 있지만, 저는 모터의 세기를 쉴드에서 조절이 불가합니다.(회로를 따로 구성해야 될듯 합니다.) )

또한 책에서는 외부 전압을 9V로 되어있지만 저는 12V 5A을 가지는 DC 전원을 사용합니다.

## 목차
1. DCmotor.cpp
2. DCmotorUsingTransister.cpp
## 1. DCmotor.cpp

### 코드
```c++
/*
2020-12-29    DC 모터 회전 방향 제어 _p328
회로 : page 328
DCMotor.cpp

 */
#include "mbed.h"

// DC 모터의 방향 제어 출력 설정
DigitalOut In1(PA_5), In2(PA_6);


// DC 모터를 앞으로 이동
void forward(){
    In1 = false;
    In2 = true;
}

// DC 모터를 뒤로 이동
void backward(){
    In1 = true;
    In2 = false;
}

// DC 모터를 정지
void stop(){
    In1 = false;
    In2 = false;
}

int main(){
    while(1){
        forward();
        wait(2);
        backward();
        wait(2);
        stop();
        wait(2);
    }
}

```

### 결과 회로 사진
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter06_DC%20%EB%AA%A8%ED%84%B0/1_DCmotor_circuit.jpg)
### 결과 사진
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter06_DC%20%EB%AA%A8%ED%84%B0/1_DCmotor_picture.jpg)


## 2. DCmotorUsingTransister.cpp

### 코드
```c++
/*
2020-12-29    트랜지스터를 사용하여 DC 모터 회전 방향 제어 _p328
회로 : http://wiki.vctec.co.kr/opensource/arduino/dcmotorcontrol 참고
DCMotor_usingTransister.cpp

 */
#include "mbed.h"

// DC 모터의 방향 제어 출력 설정
DigitalOut In1(PA_5), In2(PA_6);
// 트랜지스터 베이스전압 출력핀 PA_7
PwmOut Power(PA_7);

// 속도 제어를 위한 Ticker
Ticker myTicker;
// 모터의 속도
float speed = 0.0f;
// 모터의 속도 증감 플래그 변수
bool speed_up = true;
// DC 모터를 앞으로 이동
void forward(){
    In1 = false;
    In2 = true;
}

// DC 모터를 뒤로 이동
void backward(){
    In1 = true;
    In2 = false;
}

// DC 모터를 정지
void stop(){
    In1 = false;
    In2 = false;
}

// 모터의 속도를 조절하는 함수
void speedControl(){
    if((speed <1.0f) && speed_up){
        speed += 0.1f;
    }
    else if((speed >0.0f) && !speed_up){
        speed -= 0.1f;
    }
    // 속도 증감
    Power.write(speed);
}

int main(){
    // 1초마다 속도 조절
    myTicker.attach(&speedControl, 1);

    while(1){
        forward();
        wait(2);
        backward();
        wait(2);
        stop();
        wait(2);
    }
}


```

### 결과 회로 사진
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter06_DC%20%EB%AA%A8%ED%84%B0/2_DCmotorUsingTransiter_circuit.jpg)
### 결과 사진
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter06_DC%20%EB%AA%A8%ED%84%B0/2_DCmotorUsingTransiter_picture.jpg)

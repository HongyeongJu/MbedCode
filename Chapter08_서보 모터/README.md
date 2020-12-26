# Servo motor(서보 모터)

## 서보모터 회선 제어 참고
링크 : ![](https://gent.tistory.com/85)

![서보모터 연결선]()

## 목차
1. ServoMotorTest.cpp
## 1. ServoMotorTest.cpp

### 코드
``` c++
/*
2020-12-26    서보 모터 제어
회로 : 336page 참고
1_ServoMotorTest.cpp
 */
#include "mbed.h"

// 펄스 폭 설정
#define WIDTH_MIN 750
#define WIDTH_MAX 2250

// Pwm 으로 서보모터 제어
PwmOut Servo(PA_6);

// 0~180도 각도를 펄스폭으로 변환
int calculateWidth(int a)
{
    float width = a * (WIDTH_MAX - WIDTH_MIN) / 180.0 + WIDTH_MIN;
    return (int)width;
}

int main()
{
    // 50 Hz 주파수 설정
    Servo.period_ms(20);

    while(1)
    {
        // 0도부터 180도까지 회전하는 서보모터
        for(int i = 0 ; i < 180; i++)
        {
            int width = calculateWidth(i);
            Servo.pulsewidth_us(width);
            wait_ms(5);
        }
        // 180도부터 0도까지 회전하는 서보모터
        for(int i = 180; i > 0; i--)
        {
            int width = calculateWidth(i);
            Servo.pulsewidth_us(width);
            wait_ms(5);
        }
    }
}


```
### 결과 회로 사진
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter07_%EC%8A%A4%ED%85%9D%20%EB%AA%A8%ED%84%B0/%EC%8A%A4%ED%85%9D%EB%AA%A8%ED%84%B0%20%ED%9A%8C%EB%A1%9C.jpg)
### 결과 사진
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter07_%EC%8A%A4%ED%85%9D%20%EB%AA%A8%ED%84%B0/1_StepperMotorTest_result_picture.jpg)

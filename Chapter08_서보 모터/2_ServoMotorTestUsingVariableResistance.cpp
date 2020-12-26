/*
2020-12-26    가변저항을 통한 서보 모터 제어
회로 : 340page 참고
2_ServoMotorTestUsingVariableResistance.cpp
 */
#include "mbed.h"

// 펄스 폭 설정
#define WIDTH_MIN 750
#define WIDTH_MAX 2250

// Pwm 으로 서보모터 제어
PwmOut Servo(PA_6);

// 가변저항을 A0핀에 연결
AnalogIn resistor(A0);

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

    while(true)
    {
        // 가변저항 값 읽어들이기 (0~1.0)
        float data = resistor.read();
        // 가변저항 값을 각도로 변환 (0~180)
        int angle = data * 180;
        // 각도를 펄스폭으로 변환
        int width = calculateWidth(angle);
        Servo.pulsewidth_us(width);
        wait_ms(10);
    }
}

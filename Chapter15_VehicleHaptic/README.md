# 자동차 햅틱스

## 1. Vehiclehaptic.cpp
### 코드
```c++
#include "mbed.h"

#define PI        (3.141592653589793238462)
#define AMPLITUDE (1.0)    // 진폭 : 4095 = 3.3V
#define PHASE     (PI * 1) // 2 * PI는 1개의 주기
#define RANGE     (4095/2) // 12 bits DAC   (0~4095 범위)
#define OFFSET    (4095/2) // 12 bits DAC   (0~4095 범위)

// 피에조 액추에이터에 출력하기 위한 AnalogOut 클래스 선언
AnalogOut my_output(PA_4);

// 액추에이터에게 줄 사인파 신호의 주파수 조작을 위한 Ticker 클래스
Ticker flipper1;

// 한 사인 웨이브의 샘플링 개수
#define BUFFER_SIZE (35)

// 샘플의 진폭을 저장하는 변수
float buffer[BUFFER_SIZE];

// 처음 초기 frequency는 1 Hz
int hz_frequency = 1;
int i = 0;

// 사인파 계산 함수 (BUFFER_SIZE개의 샘플의 전압(진폭)을 계산하는 함수)
void calculate_sinewave(void) {
    for (int i = 0; i < BUFFER_SIZE; i++) {
        double rads = (PI * i * 360) / (180.0 * BUFFER_SIZE); // degree 표현법을 radian 표현법으로 바꾼다.
        buffer[i] = (AMPLITUDE * (RANGE * (cos(rads + PHASE))) + OFFSET);
    }
}

// 사인파의 주기를 계산하는 함수(micro second단위)
uint16_t calculate_frequency(int hz) {
    return 1000000 / (hz * BUFFER_SIZE);    
}

// Ticker를 사용해서 사인파 생성함수
void flip1() {
    my_output.write(buffer[i]);
    i = (i + 1) % BUFFER_SIZE;
}

int main() {
    calculate_sinewave();

    // 처음에는 hz_frequency Hz 대역으로 주파수 신호 출력
    flipper1.attach_us(&flip1, calculate_frequency(hz_frequency));


    while (true) {}
}



```

### 회로 사진

![](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter15_VehicleHaptic/%ED%9A%8C%EB%A1%9C%20%EA%B7%B8%EB%A6%BC.PNG)

# 자동차 햅틱스

## 1. Vehiclehaptic.cpp
### 코드
```c++

 /*
자동차 햅틱스 1차년도 과제
 */

 #include "mbed.h"
 #include "FSR.h"
 // 피에조 액추에이터에 출력하기 위한 AnalogOut 클래스 선언
 AnalogOut my_output(PA_4);
 AnalogOut my_output2(PA_5);

// FSR 센서 값 받기
 FSR fsr_up(PA_3, 12);
 FSR fsr_down(PC_0, 12);
 DigitalOut led1(LED1);

// 각 액추에이터 별 주파수 조작을 위한 Ticker 클래스
 Ticker flipper1;
 Ticker flipper2;

 #define PI        (3.141592653589793238462)
 #define AMPLITUDE (1.0)    // x * 3.3V
 #define PHASE     (PI * 1) // 2*pi is one period
 #define RANGE     (4096/2) // 12 bits DAC
 #define OFFSET    (4096/2) // 12 bits DAC

  // 한 사인 웨이브의 샘플링 개수
 #define BUFFER_SIZE (35)
 uint16_t buffer[BUFFER_SIZE];
 uint16_t frequencies[202];
 int hz_frequency = 0;
 int i =0;
 int j = 0;

 // 사인파 계산 함수
 void calculate_sinewave(void){
   for (int i = 0; i < BUFFER_SIZE; i++) {
      double rads = (PI * i * 360) / (180.0 *BUFFER_SIZE); // degree 표현법을 radian 표현법으로 바꾼다.
      buffer[i] = (uint16_t)(AMPLITUDE * (RANGE * (cos(rads + PHASE))) + OFFSET) * 11;       //원래는 16을 곱했음
   }
   buffer[BUFFER_SIZE / 2] = 4096 * 11 -1;  // 원래는 16을 곱했음.
 }

// 사인파의 주파수 계산 함수
 void calculate_frequency(){
     for(int i = 0 ; i < 202 ; i++){
         frequencies[i] = 1000000 / ((1000 + i) * BUFFER_SIZE);
     }
 }

// Ticker를 사용해서 사인파 생성함수
 void flip1(){
     my_output.write_u16(buffer[i]);
     i = (i+1) % BUFFER_SIZE;
 }
 void flip2(){
     my_output2.write_u16(buffer[j]);
     j = (j+1) % BUFFER_SIZE;
 }
 int main() {
     calculate_sinewave();
     calculate_frequency();
     // 처음에는 1000 Hz대역으로 사인파 생성
     flipper1.attach_us(&flip1, frequencies[0]);
     flipper2.attach_us(&flip2, frequencies[0]);

     while(true){
       // 주파수 상승 fsr 센서를 누르면 주파수 증가
         if(fsr_up.readRaw() > 0.8){
             if(hz_frequency <200){
                 hz_frequency++;
                 flipper2.detach();
                 flipper2.attach_us(&flip2, frequencies[hz_frequency]);
                 wait_us(50000);
             }
         }

        // 주파수 감소 fsr 센서를 누르면 주파수 감소
         if(fsr_down.readRaw() > 0.8){
             if(hz_frequency >0){
                 hz_frequency--;
                 flipper2.detach();
                 flipper2.attach_us(&flip2, frequencies[hz_frequency]);
                 wait_us(50000);
             }
         }
     }
 }

```

### 회로 사진

![](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter15_VehicleHaptic/%ED%9A%8C%EB%A1%9C%20%EA%B7%B8%EB%A6%BC.PNG)

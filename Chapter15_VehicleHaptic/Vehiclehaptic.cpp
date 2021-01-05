/*

*/

#include "mbed.h"
#include "FSR.h"
AnalogOut my_output(PA_4);
AnalogOut my_output2(PA_5);
FSR fsr_up(PA_3, 12);
FSR fsr_down(PC_0, 12);
DigitalOut led1(LED1);

Ticker flipper1;
Ticker flipper2;

#define PI        (3.141592653589793238462)
#define AMPLITUDE (1.0)    // x * 3.3V
#define PHASE     (PI * 1) // 2*pi is one period
#define RANGE     (4096/2) // 12 bits DAC
#define OFFSET    (4096/2) // 12 bits DAC
#define MP_PROCESSING_TIME 6        //마프에서 프로세싱하는데 걸리는 시간 대략 6초.
 // 설정 바꾸기
#define BUFFER_SIZE (35)
uint16_t buffer[BUFFER_SIZE];
uint16_t frequencies[202];
int hz_frequency = 0;
int i =0;
int j = 0;


void calculate_sinewave(void);
void calculate_frequency(){
    for(int i = 0 ; i < 202 ; i++){
        frequencies[i] = 1000000 / ((1000 + i) * BUFFER_SIZE);
    }
}

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
    flipper1.attach_us(&flip1, frequencies[0]);
    flipper2.attach_us(&flip2, frequencies[0]);

    while(true){
        if(fsr_up.readRaw() > 0.8){
            if(hz_frequency <200){
                hz_frequency++;
                flipper2.detach();
                flipper2.attach_us(&flip2, frequencies[hz_frequency]);
                wait_us(50000);
            }
        }

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

// 사인파 계산 함수
void calculate_sinewave(void){
  for (int i = 0; i < BUFFER_SIZE; i++) {
     double rads = (PI * i * 360) / (180.0 *BUFFER_SIZE); // degree 표현법을 radian 표현법으로 바꾼다.
     buffer[i] = (uint16_t)(AMPLITUDE * (RANGE * (cos(rads + PHASE))) + OFFSET) * 11;       //원래는 16을 곱했음
  }
  buffer[BUFFER_SIZE / 2] = 4096 * 11 -1;  // 원래는 16을 곱했음.
}

/*
2020-12-22    창작
회로 : https://os.mbed.com/components/Force-Sensitive-Resistors-FSR/
FSR 센서의 값에 따른 LED 제어
 */
#include "mbed.h"
#include "FSR.h"


// UART2 포트, 컴퓨터 연결
Serial pc(USBTX, USBRX);
FSR fsr(A0, 10);        // A0 핀에 FSR센서의 AnalogIn을 받고, 저항은 10KΩ을 사용한다.
DigitalOut LED(PA_5);   // PA_5핀에 LED 출력
float data;             // FSR 센서 값을 저장할 변수
int main(){
    while(true){
        data = fsr.readRaw();

        // FSR 센서로 받은 데이터가 0.6 이상이면 눌렸다고 간주
        if(data>0.6){
            LED = true;
        }else {
            LED = false;
        }
        pc.printf("The raw data is %f And LED is %d\n", data, LED.read());               // 0~1사이의 소수 값
        wait(2);
    }
}

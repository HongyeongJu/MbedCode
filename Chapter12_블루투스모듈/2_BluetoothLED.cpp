/*
2020-12-21    15장_BluetoothLED(창작)
회로 : X
bluetooth 모듈을 사용하여 LED 제어
 */
#include "mbed.h"

// UART2 포트, 컴퓨터 연결
Serial pc(USBTX, USBRX);
// UART4 포트, 블루투스 모듈 연결
Serial bluetooth(PC_10, PC_11, 9600);

DigitalOut LED(PA_5);
bool state = false;
int main(){
    while(true){
        LED = state;

        // 스마트폰 어플리케이션 -> 블루투스 모듈 -> Mbed -> comport master 프로그램
        // t를 입력받으면 LED On f를 입력받으면 LED Off
        if(bluetooth.readable()){
            char ch = bluetooth.getc();
            if(ch=='t'){
                state = true;
            }
            else if(ch=='f'){
                state = false;
            }
            pc.putc(ch);
        }
    }
}

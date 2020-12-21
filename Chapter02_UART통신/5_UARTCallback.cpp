/*
2020-12-21    7장_UART CallBack_112page
회로 : 95page
컴퓨터와 UART 시리얼 통신- 콜백함수를 통해서 UART 통신값을 통해 LED 제어
 */
#include "mbed.h"

Serial PC(USBTX, USBRX, 115200);        // 115200보율을 사용하는 시리얼 통신
DigitalOut LED(PA_5);                           // PA_5 핀을 사용하는 LED
bool state = true;

void serial_callback(){
    /*
    if(PC.readable()){
        PC.putc(PC.getc());
    }
    */
    /*
    if(PC.getc()=='t'){                 // 컴퓨터로부터 문자 t를 입력받으면 LED On
        state = true;
    }else if(PC.getc()=='f'){           // 컴퓨터로부터 문자 f를 입력받으면 LED Off
        state = false;
    }*/
    state =!state;
    PC.putc(PC.getc());

}

int main(){
    PC.attach(&serial_callback);        // 콜백 함수 등록
    while(true){
        LED = state;
    }
}

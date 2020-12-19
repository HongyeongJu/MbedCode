/*
2020-12-20    7장_UART Eco_109page
회로 : X
컴퓨터와 UART 시리얼 통신- Eco
 */
#include "mbed.h"

Serial PC(SERIAL_TX, SERIAL_RX, 115200);        // 115200보율을 사용하는 시리얼 통신

int main(){
    while(true){
        // 컴퓨터로부터 수신한 데이터를 컴퓨터에게 다시 보냄
        PC.putc(PC.getc());
    }
}

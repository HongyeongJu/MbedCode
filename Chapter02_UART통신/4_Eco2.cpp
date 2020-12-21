/*
2020-12-20    7장_UART Eco_111page
회로 : X
컴퓨터와 UART 시리얼 통신- Eco2
readable() 함수를 이용하여 수신 버퍼에 데이터가 있는지 확인
 */
#include "mbed.h"

Serial PC(SERIAL_TX, SERIAL_RX, 115200);        // 115200보율을 사용하는 시리얼 통신

int main(){
    while(true){
        // 수신 버퍼에 데이터가 있을 때 컴퓨터로부터 수신한 데이터를 다시 컴퓨터로 보낸다.
        if(PC.readable()){
            PC.putc(PC.getc());
        }
    }
}

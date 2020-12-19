/*
2020-12-20    7장_UART 시리얼 통신_통신속도 변경_107page
회로 : X
컴퓨터와 UART 시리얼 통신- Serial 클래스를 사용하여 통신속도 및 핀제어
 */
#include "mbed.h"

Serial PC(SERIAL_TX, SERIAL_RX, 115200);        // 115200보율을 사용하는 시리얼 통신
// Serial PC(D1, D0, 115200);                   // 송신핀 D1, 수신핀 D0, 115200보율을 사용하는 시리얼 통신

int main(){
    int second = 1;
    PC.printf("Hello World!\n");       // 컴퓨터로 Hello World 출력

    while(true){
        PC.printf("second counts : %d\n", second++);
        wait(1);            // 1초동안 대기
    }
}

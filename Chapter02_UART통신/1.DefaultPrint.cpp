/*
2020-12-19    7장_UART 시리얼 통신_106page
회로 : X
컴퓨터와 UART 시리얼 통신- 디폴트로 출력
 */

#include "mbed.h"

int main(){
    int second = 1;

    printf("Hello World!\n");       // 컴퓨터로 Hello World 출력

    while(true){
        printf("This program runs for %d seconds.\n", second++);
        wait(1);            // 1초동안 대기
    }
}

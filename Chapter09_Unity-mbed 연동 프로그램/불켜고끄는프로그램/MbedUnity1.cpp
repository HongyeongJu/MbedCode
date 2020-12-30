/*
2020-12-30  UnityMbed 연동 프로그램1
회로 : DigitalIn 회로
UnityMbed1.cpp
 */
#include "mbed.h"

// 시리얼 통신
Serial Pc(USBTX, USBRX);

// PullDown 저항 방식을 사용하는 Button
DigitalIn button(PD_14, PullDown);

int main(){

    while(1){
        // 버튼을 누르면 방향 바뀌게하기
        if(button == true){
            printf("1");
        }
    }
}

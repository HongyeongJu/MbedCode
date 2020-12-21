/*
2020-12-21    15장_Bluetooth Test_211page
회로 : 210page
bluetooth 모듈을 이용한 통신 테스트- BluetoothTest
 */
#include "mbed.h"

// UART2 포트, 컴퓨터 연결
Serial pc(USBTX, USBRX);
// UART4 포트, 블루투스 모듈 연결
Serial bluetooth(PC_10, PC_11, 9600);

int main(){
    while(true){
        // comport master 프로그램-> Mbed -> 블루투스 모듈 -> 스마트폰 어플리케이션
        if(pc.readable()){
            bluetooth.putc(pc.getc());
        }

        // 스마트폰 어플리케이션 -> 블루투스 모듈 -> Mbed -> comport master 프로그램
        if(bluetooth.readable()){
            pc.putc(bluetooth.getc());
        }
    }
}

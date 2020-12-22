/*
2020-12-22    책에 없음
회로 : https://os.mbed.com/components/Force-Sensitive-Resistors-FSR/
FSR 센서 테스트
 */
#include "mbed.h"
#include "FSR.h"


// UART2 포트, 컴퓨터 연결
Serial pc(USBTX, USBRX);
FSR fsr(A0, 10);        // A0 핀에 FSR센서의 AnalogIn을 받고, 저항은 10KΩ을 사용한다.

int main(){
    while(true){
        pc.printf("The raw data is %f\n", fsr.readRaw());               // 0~1사이의 소수 값
        pc.printf("The resistance of the FSR is %f\n", fsr.readFSRResistance());        // FSR센서의 저항값, 눌리면 저항값이 줄어듦.
        pc.printf("The weight on the FSR is %f\n\n\n", fsr.readWeight());               // FSR센서에 가해지는 힘, 눌리면 증가함.
        wait(5);      // 5초 동안 기다림.
    }
}

#include "mbed.h"
#include "FSR.h"

// UART3 포트, 컴퓨터 연결
Serial pc(USBTX, USBRX);
// A0 핀에 FSR센서의 AnalogIn을 받고, 저항은 10KΩ을 사용한다.
FSR myFSR(A0, 10);
// Ticker 객체 생성
Ticker myTicker;
// FSR 센서 값을 저장할 변수
float data;

void Processing() {
    //data 변수에 FSR 값 저장
    data = myFSR.readRaw();

    //측정된 FSR값을 PC로 전송
    pc.printf("The raw data is %f \n", data);
}

int main()
{
    //myTicker 객체에 콜백 함수 (Processing) 등록 (주기 0.2초)
    myTicker.attach(&Processing, 0.2);

    while (true);
}

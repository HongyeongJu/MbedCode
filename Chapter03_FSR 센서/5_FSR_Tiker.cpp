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
    myFSR.readRaw();
    pc.printf("The raw data is %f \n", myFSR.readRaw());
}

int main()
{
    myTicker.attach(&Processing, 0.2);
  
    while (true);
}

#include "mbed.h"

// 시리얼 통신
Serial pc(USBTX, USBRX);

//Ticker 객체 생성
Ticker myTicker;

// 조도 센서를 A0 (PA_3)에 연결
AnalogIn myCdS(A0);


//조도값 저장 변수
float brightness = 0.0f;

void Processing()
{

    //조도 측정값을 변수에 저장
    brightness = myCdS.read();

    //어두우면 1을 전송 (Unity에서 1을 받으면 가상환경의 조명이 켜짐)
    if (brightness < 0.3f)
    {
        pc.printf("1");
    }
    else //밝으면 0을 전송 (Unity에서 0을 받으면 가상환경의 조명이 꺼짐)
    {
        pc.printf("0");
    }

}

int main()
{

    //myTicker에 콜백 함수 등록 (주기 0.01초)
    myTicker.attach(&Processing, 0.01);

    while (1){    }
}

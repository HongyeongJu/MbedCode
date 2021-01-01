/*
2021-01-01
Unity-mbed 연동프로그램 2

*/

#include "mbed.h"

// 시리얼 통신
Serial pc(USBTX, USBRX);

//Ticker 객체 생성
Ticker myTicker;

// 조도 센서를 A0 (PA_3)에 연결
AnalogIn myCdS(A0);

// DC 모터의 방향 제어 출력 설정
DigitalOut In1(PA_5), In2(PA_6);

// DC 모터를 앞으로 이동
void forward(){
    In1 = false;
    In2 = true;
}

// DC 모터 정지
void stop(){
    In1 = false;
    In2 = false;
}

//조도값 저장 변수
float brightness = 0.0f;

void Processing()
{
    // Unity로부터 값을 읽어들어서 '1'을 입력 받으면 모터가 움직이고 '2'를 입력받으면 모터가 멈추도록 한다.
    if(pc.readable()){
        char ch = pc.getc();
        if(ch == '1'){
            forward();
        }
        else if(ch == '2'){
            stop();
        }
    }

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

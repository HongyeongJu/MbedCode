#include "mbed.h"

// DC 모터의 방향 제어 출력 설정
PwmOut In1(PA_5), In2(PA_6);

// PullDown 저항 방식을 사용하는 Button
DigitalIn myBtn_Dir(PD_14, PullDown);


// PullDown 저항 방식을 사용하는 Button
DigitalIn myBtn_Speed(PD_15, PullDown);


// 버튼 감지를 위한 Ticker
Ticker myTickBtn;

// 모터 속도 제어를 위한 Ticker
Ticker myTickSpeed;

//모터 방향 플래그 (true = 정방향, false = 역방향)
bool bDir = true;

//모터 속도 플래그 (true = 가속, false = 감속)
bool bSpeedUp = true;

// 모터의 속도
float speed = 0.0f;


void btnRead()
{
    //방향 제어 버튼이 눌리면, 
    if (myBtn_Dir) 
    {
        //방향 제어 플래그 토글
        bDir = !bDir;
    }
    //속도 제어 버튼이 눌리면,
    if (myBtn_Speed)
    {
        //속도 제어 플래그 토글
        bSpeedUp = !bSpeedUp;
    }
}
// 모터의 속도를 조절하는 함수
void speedControl()
{
    //speed_up 함수가 true 이면, 모터의 속도를 증가시킴
    if (bSpeedUp && (speed < 1.0f)) 
    {
        speed += 0.1f;
    }
    //speed_up 함수가 false 이면, 모터의 속도를 감소시킴
    else if (!bSpeedUp && (speed > 0.0f)) 
    {
        speed -= 0.1f;
    }
}

int main()
{
    //버튼 감지 콜백 함수를 Ticker에 등록 (주기 0.01초)
    myTickBtn.attach(&btnRead, 0.01);
    //속도 제어 콜백 함수를 Ticker에 등록 (주기 1초)
    myTickSpeed.attach(&speedControl, 1);
    while (1)
    {
        //회전 방향이 정방향이라면, 
        if (bDir)
        {
            //현재 설정된 속도로 정방향 회전
            In1.write(speed);
            In2.write(0);
        }
        else { 
            //현재 설정된 속도로 역방향 회전
            In1.write(0);
            In2.write(speed);
        }
    }
}

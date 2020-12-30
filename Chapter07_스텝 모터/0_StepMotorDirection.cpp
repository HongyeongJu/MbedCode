#include "mbed.h"

//DigitalOut으로 4개의 출력핀 객체 생성
DigitalOut _A0(D0), _A1(D1), _A2(D2), _A3(D3);

//Ticker 객체 생성
Ticker myTicker;

//스텝 변수
unsigned int step = 0;

// InterrupIn 클래스를 이용한 버튼 인터럽트 제어
InterruptIn myBtnDir(PA_5);

// 방향 제어 변수
int direction = 0;

//회전 함수 (1-2상 여자 방식)
void Rotate(int current_step)
{
	switch (current_step) {
	case 1:
		_A0 = 0;
		_A1 = 0;
		_A2 = 0;
		_A3 = 1;
		break;
	case 2:
		_A0 = 0;
		_A1 = 0;
		_A2 = 1;
		_A3 = 1;
		break;
	case 3:
		_A0 = 0;
		_A1 = 0;
		_A2 = 1;
		_A3 = 0;
		break;
	case 4:
		_A0 = 0;
		_A1 = 1;
		_A2 = 1;
		_A3 = 0;
		break;
	case 5: {
		_A0 = 0;
		_A1 = 1;
		_A2 = 0;
		_A3 = 0;
	}
		  break;
	case 6:
		_A0 = 1;
		_A1 = 1;
		_A2 = 0;
		_A3 = 0;
		break;
	case 7:
		_A0 = 1;
		_A1 = 0;
		_A2 = 0;
		_A3 = 0;
		break;
	case 0:
		_A0 = 1;
		_A1 = 0;
		_A2 = 0;
		_A3 = 1;
		break;
	}

}

//콜백 함수
void Processing()
{
	//회전함수 호출
	Rotate(step);

	//direction 변수가 1이면 
	if (direction)	
	{
		//스텝 증가 (시계 방향 회전)
		step++;
	}
	else 
	{
		//스텝 증가 (반시계 방향 회전)
		step--;
	}

	//스텝의 범위를 0~7로 제한
	step %= 8;
}
void changeDirection() 
{
	direction = 1 - direction;
}
int main()
{
	//회전 콜백 함수를 Ticker에 등록 (주기 0.1초)
	myTicker.attach(&Processing, 0.1);

	// myBtnDir은 PullDown 방식의 저항을 사용하는 버튼
	myBtnDir.mode(PullDown);

	// 버튼이 눌렸을 때 호출되는 콜백함수 설정 (PullUp 방식은 myBtnDir.fall() 함수를 통해 호출)
	myBtnDir.rise(changeDirection);

	while (1)
	{
	}
}

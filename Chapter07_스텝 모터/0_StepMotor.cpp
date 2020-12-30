#include "mbed.h"

DigitalOut _A0(D0), _A1(D1), _A2(D2), _A3(D3);

Ticker myTicker;

unsigned int step = 0;
//회전 함수
void Rotate(int current_step)
{
	switch (current_step) {
	case 1: {
		_A0 = 0;
		_A1 = 0;
		_A2 = 0;
		_A3 = 1;
	}
		  break;
	case 2: {
		_A0 = 0;
		_A1 = 0;
		_A2 = 1;
		_A3 = 1;
	}
		  break;
	case 3: {
		_A0 = 0;
		_A1 = 0;
		_A2 = 1;
		_A3 = 0;
	}
		  break;
	case 4: {
		_A0 = 0;
		_A1 = 1;
		_A2 = 1;
		_A3 = 0;
	}
		  break;
	case 5: {
		_A0 = 0;
		_A1 = 1;
		_A2 = 0;
		_A3 = 0;
	}
		  break;
	case 6: {
		_A0 = 1;
		_A1 = 1;
		_A2 = 0;
		_A3 = 0;
	}
		  break;
	case 7: {
		_A0 = 1;
		_A1 = 0;
		_A2 = 0;
		_A3 = 0;
	}
		  break;
	case 0: {
		_A0 = 1;
		_A1 = 0;
		_A2 = 0;
		_A3 = 1;
	}
		  break;
	}

}

//콜백 함수
void Processing() 
{
	//회전함수 호출
	Rotate(step);
	//스텝 증가
	step++;
	//스텝의 범위를 0~7로 제한
	step %= 8;
}

int main()
{
	//회전 콜백 함수를 Ticker에 등록 (주기 0.1초)
	myTicker.attach(&Processing, 0.1);

	while (1)
	{		
	}
}

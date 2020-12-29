/*
2020-12-29  DC 모터 버튼을 눌러 회전 방향 제어 _p328
회로 : http://wiki.vctec.co.kr/opensource/arduino/dcmotorcontrol 참고
DCMotorButton_usingTransister.cpp
 */
#include "mbed.h"

// DC 모터의 방향 제어 출력 설정
DigitalOut In1(PA_5), In2(PA_6);
// 트랜지스터 베이스전압 출력핀 PA_7
PwmOut Power(PA_7);

// PullDown 저항 방식을 사용하는 Button
DigitalIn button(PD_14, PullDown);
// 처음에는 앞으로 이동
bool direction = true;
// DC 모터를 앞으로 이동
void forward(){
    In1 = false;
    In2 = true;
}

// DC 모터를 뒤로 이동
void backward(){
    In1 = true;
    In2 = false;
}

// DC 모터를 정지
void stop(){
    In1 = false;
    In2 = false;
}


int main(){
    // 모터 작동시키기
    Power.write(1);
    // 처음에는 앞으로 이동
    forward();

    while(1){
        // 버튼을 누르면 방향 바뀌게하기
        if(button == true){
            direction = !direction;

            if(direction){
                forward();
                wait(1);
            }
            else{
                backward();
                wait(1);
            }
        }
    }
}

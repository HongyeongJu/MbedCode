/*
2020-12-16    6장_DigitalOut_93page
회로 : 92page 그림 6-12 참고
 2개의 LED 키고 끄기
 */

 #include "mbed.h"

 DigitalOut LED_1(PA_5);            // PA_5 핀에 연결된 LED를 출력으로 사용
 DigitalOut LED_2(PA_6);            // PA_6 핀에 연결된 LED를 출력으로 사용

 int main(){
     bool condition = true;             // LED_1의 상태

     while(1){
         // 연산자 재정의를 통한 디지털 데이터 출력
         LED_1 = condition;
         LED_2 = !condition;

         // 맴버 함수를 통해 디지털 데이터 출력
         //LED_1.write(condition);
         // LED_2.write(!LED_1.read());

         condition = !condition;

         wait(0.5);
    }
}

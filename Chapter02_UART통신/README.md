# UART 통신
## 장치관리자
![장치관리자 사진](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter02_UART%ED%86%B5%EC%8B%A0/%EC%9E%A5%EC%B9%98%EA%B4%80%EB%A6%AC%EC%9E%90.png)
## 목차
1. DefaultPrint
2. SerialClassPrint
3. Eco

## 1. DefaultPrint
## 1.1 책 코드
### 코드
```c++
/*
2020-12-19    7장_UART 시리얼 통신_106page
회로 : X
컴퓨터와 UART 시리얼 통신- 디폴트로 출력
 */

#include "mbed.h"

int main(){
    int second = 1;

    printf("Hello World!\n");       // 컴퓨터로 Hello World 출력

    while(true){
        printf("This program runs for %d seconds.\n", second++);       
        wait(1);            // 1초동안 대기
    }
}
```
### 결과 사진
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter02_UART%ED%86%B5%EC%8B%A0/1_DefaultPrint_result.jpg)

## 1.2 수정된 코드
### 코드
```c++
#include "mbed.h"

int main() {
    printf("Hello World!\n");       //문자열 "Hello World!"를 Serial 통신을 통해 PC로 전송
}
```
### 결과 사진
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter02_UART%ED%86%B5%EC%8B%A0/1_2_DefaultPrint_result(%EC%88%98%EC%A0%95%EB%90%9C%20%EC%BD%94%EB%93%9C).jpg)


## 2. SerialClassPrint
### 코드
```c++
/*
2020-12-20    7장_UART 시리얼 통신_통신속도 변경_107page
회로 : X
컴퓨터와 UART 시리얼 통신- Serial 클래스를 사용하여 통신속도 및 핀제어
 */
#include "mbed.h"

Serial PC(SERIAL_TX, SERIAL_RX, 115200);        // 115200보율을 사용하는 시리얼 통신
// Serial PC(D1, D0, 115200);                   // 송신핀 D1, 수신핀 D0, 115200보율을 사용하는 시리얼 통신

int main(){
    int second = 1;
    PC.printf("Hello World!\n");       // 컴퓨터로 Hello World 출력

    while(true){
        PC.printf("second counts : %d\n", second++);
        wait(1);            // 1초동안 대기
    }
}

```
### 결과 사진
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter02_UART%ED%86%B5%EC%8B%A0/2_SerialClassPrint_result.jpg)



## 3. Eco
### 코드
```c++
/*
2020-12-20    7장_UART Eco_109page
회로 : X
컴퓨터와 UART 시리얼 통신- Eco
 */
#include "mbed.h"

Serial PC(SERIAL_TX, SERIAL_RX, 115200);        // 115200보율을 사용하는 시리얼 통신

int main(){
    while(true){
        // 컴퓨터로부터 수신한 데이터를 컴퓨터에게 다시 보냄
        PC.putc(PC.getc());
    }
}

```
### 결과 사진
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter02_UART%ED%86%B5%EC%8B%A0/3_Eco_result.jpg)

## 4. Eco2
### 코드
```c++
/*
2020-12-20    7장_UART Eco_111page
회로 : X
컴퓨터와 UART 시리얼 통신- Eco2
readable() 함수를 이용하여 수신 버퍼에 데이터가 있는지 확인
 */
#include "mbed.h"

Serial PC(SERIAL_TX, SERIAL_RX, 115200);        // 115200보율을 사용하는 시리얼 통신

int main(){
    while(true){
        // 수신 버퍼에 데이터가 있을 때 컴퓨터로부터 수신한 데이터를 다시 컴퓨터로 보낸다.
        if(PC.readable()){
            PC.putc(PC.getc());
        }
    }
}
```
### 결과 사진
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter02_UART%ED%86%B5%EC%8B%A0/4_Eco2_result.jpg)

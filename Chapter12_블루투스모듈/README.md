# 블루투스 모듈
## 스마트폰 블루투스 연결 사진
![ConnectionPicture](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter03_%EB%B8%94%EB%A3%A8%ED%88%AC%EC%8A%A4%EB%AA%A8%EB%93%88/connectionPicture.jpg)

## 목차
1. Bluetooth Test
2. Bluetooth LED(창작)
## 1. Bluetooth Test
### 코드
```c++
/*
2020-12-21    15장_Bluetooth Test_211page
회로 : 210page
bluetooth 모듈을 이용한 통신 테스트- BluetoothTest
 */
#include "mbed.h"

// UART2 포트, 컴퓨터 연결
Serial pc(USBTX, USBRX);
// UART4 포트, 블루투스 모듈 연결
Serial bluetooth(PC_10, PC_11, 9600);

int main(){
    while(true){
        // comport master 프로그램-> Mbed -> 블루투스 모듈 -> 스마트폰 어플리케이션
        if(pc.readable()){
            bluetooth.putc(pc.getc());
        }

        // 스마트폰 어플리케이션 -> 블루투스 모듈 -> Mbed -> comport master 프로그램
        if(bluetooth.readable()){
            pc.putc(bluetooth.getc());
        }
    }
}
```
### 결과 회로 사진
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter03_%EB%B8%94%EB%A3%A8%ED%88%AC%EC%8A%A4%EB%AA%A8%EB%93%88/1_BluetoothTest_circuit.jpg)
### 결과 사진
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter03_%EB%B8%94%EB%A3%A8%ED%88%AC%EC%8A%A4%EB%AA%A8%EB%93%88/1_BluetoothTest_result1.jpg)
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter03_%EB%B8%94%EB%A3%A8%ED%88%AC%EC%8A%A4%EB%AA%A8%EB%93%88/1_BluetoothTest_result2.jpg)
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter03_%EB%B8%94%EB%A3%A8%ED%88%AC%EC%8A%A4%EB%AA%A8%EB%93%88/1_BluetoothTest_result3.jpg)



## 2. Bluetooth LED
### 코드
```c++
/*
2020-12-21    15장_BluetoothLED(창작)
회로 : X
bluetooth 모듈을 사용하여 LED 제어
 */
#include "mbed.h"

// UART2 포트, 컴퓨터 연결
Serial pc(USBTX, USBRX);
// UART4 포트, 블루투스 모듈 연결
Serial bluetooth(PC_10, PC_11, 9600);

DigitalOut LED(PA_5);
bool state = false;
int main(){
    while(true){
        LED = state;
        // 스마트폰 어플리케이션 -> 블루투스 모듈 -> Mbed -> comport master 프로그램
        // t를 입력받으면 LED On f를 입력받으면 LED Off
        if(bluetooth.readable()){
            char ch = bluetooth.getc();
            if(ch=='t'){
                state = true;
            }
            else if(ch=='f'){
                state = false;
            }
            pc.putc(ch);
        }
    }
}

```
### 결과 회로 사진
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter03_%EB%B8%94%EB%A3%A8%ED%88%AC%EC%8A%A4%EB%AA%A8%EB%93%88/2_BluetoothLED_result1_r.jpg)
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter03_%EB%B8%94%EB%A3%A8%ED%88%AC%EC%8A%A4%EB%AA%A8%EB%93%88/2_BluetoothLED_result2_r.jpg)
### 결과 사진
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter03_%EB%B8%94%EB%A3%A8%ED%88%AC%EC%8A%A4%EB%AA%A8%EB%93%88/2_BluetoothLED_result1.jpg)
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter03_%EB%B8%94%EB%A3%A8%ED%88%AC%EC%8A%A4%EB%AA%A8%EB%93%88/2_BluetoothLED_result1_p.jpg)
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter03_%EB%B8%94%EB%A3%A8%ED%88%AC%EC%8A%A4%EB%AA%A8%EB%93%88/2_BluetoothLED_result2.jpg)
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter03_%EB%B8%94%EB%A3%A8%ED%88%AC%EC%8A%A4%EB%AA%A8%EB%93%88/2_BluetoothLED_result2_p.jpg)

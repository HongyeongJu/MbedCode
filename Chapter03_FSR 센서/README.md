# FSR 센서
## FSR 센서를 사용하기 위한 Library
링크 : !(https://os.mbed.com/users/cshao06/code/FSR/)

## 목차
1. FSR.cpp  (외부라이브러리)
2. FSR.h    (외부라이브러리 헤더파일)
3. FSRTest.cpp
4. FSRLED   (창작)
## 1.FSR.cpp
### 코드
```c++
#include "FSR.h"
#include "mbed.h"

FSR::FSR(PinName pin, float resistance) : _ain(pin), _r(resistance)
{
}

float FSR::readRaw()
{
    float read = _ain;
    return read;
}

float FSR::readFSRResistance()
{
    float read = _ain;
    return _r * 1 / read - _r;
}

float FSR::readWeight()
{
    float read = _ain;
    float rfsr = _r * 1 / read - _r;
    float slope = (4 - 2) / (log10(6.2) - log10(0.25));
    float a = log10(rfsr);
    if (a < log10(6.2))
    {
        return pow(10, ((log10(6.2) - a) * slope + 2));
    }
    else
    {
        return 0;
    }
}

```

## 2.FSR.h
### 코드
```c++
#ifndef FSR_H
#define FSR_H

#include "mbed.h"

/** Force sensitive resistor class using an AnalogIn pin
 *
 * Example:
 * @code
 * #include "mbed.h"
 * #include "FSR.h"
 * FSR fsr(p20, 10); // Pin 20 is used as the AnalogIn pin and a 10k resistor is used as a voltage divider
 * int main(){
 *     while (1)
 *     {
 *         printf("The raw data is %f\n", fsr.readRaw());
 *         printf("The resistance of the FSR is %f\n", fsr.readFSRResistance());
 *         printf("The weight on the FSR is %f\n\n", fsr.readWeight());
 *         wait(0.3); //just here to slow down the output for easier reading
 *     }
 * }
 * @endcode
 */

class FSR
{
public:
    /** Create an FSR object
     *
     * @param Pin AnalogIn pin number
     * @param resistance resistance of the voltage divider resistor in k
     */
    FSR(PinName Pin, float resistance);

    /** Read the raw data
     *
     * @return the raw float data ranging from 0 to 1
     */
    float readRaw();

    /** Read the resistance of the FSR
     *
     * @return the resistance of the FSR
     */
    float readFSRResistance();

    /** Read the weight in N. 0 anyway if the weight is less than 100g
     *
     * @return the weight ranging from 100g to 10000g
     */
     float readWeight();
protected:
    AnalogIn _ain;
    float _r;
};

#endif
```

## 3.FSRTest.cpp
### 코드
```c++
/*
2020-12-22    책에 없음
회로 : https://os.mbed.com/components/Force-Sensitive-Resistors-FSR/
FSR 센서 테스트
 */
#include "mbed.h"
#include "FSR.h"


// UART2 포트, 컴퓨터 연결
Serial pc(USBTX, USBRX);
FSR fsr(A0, 10);        // A0 핀에 FSR센서의 AnalogIn을 받고, 저항은 10KΩ을 사용한다.

int main(){
    while(true){
        pc.printf("The raw data is %f\n", fsr.readRaw());               // 0~1사이의 소수 값
        pc.printf("The resistance of the FSR is %f\n", fsr.readFSRResistance());        // FSR센서의 저항값, 눌리면 저항값이 줄어듦.
        pc.printf("The weight on the FSR is %f\n\n\n", fsr.readWeight());               // FSR센서에 가해지는 힘, 눌리면 증가함.
        wait(5);      // 5초 동안 기다림.
    }
}

```
### 결과 회로 사진
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter12_%EB%B8%94%EB%A3%A8%ED%88%AC%EC%8A%A4%EB%AA%A8%EB%93%88/1_BluetoothTest_circuit.jpg)
### 결과 사진
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter12_%EB%B8%94%EB%A3%A8%ED%88%AC%EC%8A%A4%EB%AA%A8%EB%93%88/1_BluetoothTest_result1.jpg)
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter12_%EB%B8%94%EB%A3%A8%ED%88%AC%EC%8A%A4%EB%AA%A8%EB%93%88/1_BluetoothTest_result2.jpg)
![DefaultPrint](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter12_%EB%B8%94%EB%A3%A8%ED%88%AC%EC%8A%A4%EB%AA%A8%EB%93%88/1_BluetoothTest_result3.jpg)

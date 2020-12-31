# 온습도 센서
## 온습도 센서를 사용하기 위한 Library
링크 : !(https://os.mbed.com/users/cshao06/code/FSR/)

## 현재상황

- 현재 Mbed홈페이지 서버다운이되서 서버 풀리는 즉시 테스트하고 사진 올리겠습니다.


## 온습도 센서 라이브러리 임포트하는 과정

![1]()

- compiler 좌측 상단에 있는 Import 버튼을 누른다.

![2]()

- 라이브러리 탭에서 DHT를 누르고 다음과 같은 라이브러리를 임포트를 한다.

![3]()

## 목차
1. DHT11.cpp
2. DHT11UsingTicker.cpp

## 1. DHT11.cpp
### 코드
```c++
/*
2020-12-31   온습도 센서_ 245page
회로 : 240page
온습도 센서 제어
 */

#include "mbed.h"
#include "DHT.h"

//DHT 11센서를 사용한다.
DHT dht(D0, DHT11);

int main(){
  // 센서가 안정화 될때까지 기다린다.
  wait(2);
  while(1){
    // 센서 데이터를 읽어드린다.
    int data = dht.readData();

    // 센서 데이터 읽기 성공하면
    if(data == ERROR_NONE){
      //섭씨로 온도를 측정
      float temperature = dht.ReadTemperature(CELCIUS);
      // 습도 측정
      float humidity = dht.ReadHumidity();

      printf("Temperature : $.2f, Humidity : %.2f\n", temperature, humidity);
    }
    else{   // 데이터를 읽는 도중 오류가 발생함
      printf(" -- Error Occurred ! : %d\n", data);
    }

    wait(5);

  }
}

```

### 결과 사진

### 결과 회로 사진


## 2. DHT11UsingTicker.cpp
###코드

```c++
/*
2020-12-31   온습도 센서Ticker_ 245page
회로 : 240page
Ticker를 사용하여 온습도 센서 제어
 */

#include "mbed.h"
#include "DHT.h"

//DHT 11센서를 사용한다.
DHT dht(D0, DHT11);
// Ticker 객체 생성
Ticker myTicker;

void processing(){
  // 센서 데이터를 읽어드린다.
  int data = dht.readData();

  // 센서 데이터 읽기 성공하면
  if(data == ERROR_NONE){
    //섭씨로 온도를 측정
    float temperature = dht.ReadTemperature(CELCIUS);
    // 습도 측정
    float humidity = dht.ReadHumidity();

    printf("Temperature : $.2f, Humidity : %.2f\n", temperature, humidity);
  }
  else{   // 데이터를 읽는 도중 오류가 발생함
    printf(" -- Error Occurred ! : %d\n", data);
  }
}

int main(){
  // 센서가 안정화 될때까지 기다린다.
  wait(2);

  myTicker.attach(&processing, 5);
  while(1){
  }
}

```

### 결과 사진

### 결과 회로 사진

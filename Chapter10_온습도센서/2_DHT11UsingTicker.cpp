/*
2020-12-31   온습도 센서Ticker_ 245page
회로 : 240page
Ticker를 사용하여 온습도 센서 제어
 */

#include "mbed.h"
#include "DHT.h"

//DHT 11센서를 사용한다.
DHT dht(D2, DHT11);
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

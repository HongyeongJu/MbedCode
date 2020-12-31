/*
2020-12-31   온습도 센서_ 245page
회로 : 240page
온습도 센서 제어
 */

#include "mbed.h"
#include "DHT.h"

//DHT 11센서를 사용한다.
DHT dht(D2, DHT11);

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

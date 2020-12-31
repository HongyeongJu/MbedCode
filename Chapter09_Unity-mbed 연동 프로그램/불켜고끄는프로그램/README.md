# Mbed-Unity 연동 프로그램 (불키고 켜는 프로그램)

## 링크

!(https://drive.google.com/drive/folders/13JNyFivjLItN2A8ewmxb8JqruMPzrCyh)

# 제작과정

![1]()

- unity hub를 열고 새로생성 버튼을 누른뒤 "UnityMbed" 라는 제목으로 프로젝트를 생성한다. 템플릿은 3D를 사용한다.

![2]()

- unity를 열었으면, Hierarchy 창에서  마우스 오른쪽 클릭을 하여 Cube 객체를 생성한다.

![3]()

- 생성된 Cube객체의 Inspector창을 통해서 Transform 변수를 위 그림과 같이 변경한다.

![4]()

- 큐브 객체를 Ctrl+ C , Ctrl+ V하여 복사하고 위의 그림과 같이 변수를 변경한다.

![5]()

- 앞에서 서술한 방법대로 위의 그림처럼 한쪽 면만 열려있는 방을 하나 만든다.

![6]()

- Hierachy 창에서 마우스 오른쪽 클릭하여 Light-> Point Light 객체를 생성한다.

-[7]()

- 생성된 Point Light를 클릭하여 Inspector 창에서 위의 그림과 같이 변수를 변경한다.

-[8]()

- Assets 창에서 마우스 오른쪽 버튼을 누르고 Create-> C# script를 눌러서 새로운 스크립트를 생성한다. 이 새로운 스크립트의 이름은 "lightControl"으로 변경한다.

-[9]()

- 새로 생성된 스크립트를 두번 클릭하여
## 프로그램 사진

![켜져있을 때](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EC%BC%9C%EC%A0%B8%EC%9E%88%EC%9D%84%EB%95%8C.jpg)

- 불이 켜졌을 때

![꺼져있을 떄](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EA%BA%BC%EC%A0%B8%EC%9E%88%EC%9D%84%20%EB%95%8C.jpg)

- 불이 꺼졌을 때

### MbedUnity1.cpp
```c++
/*
2020-12-30  UnityMbed 연동 프로그램1
회로 : DigitalIn 회로
UnityMbed1.cpp
 */
#include "mbed.h"

// 시리얼 통신
Serial Pc(USBTX, USBRX);

// PullDown 저항 방식을 사용하는 Button
DigitalIn button(PD_14, PullDown);

int main(){

    while(1){
        // 버튼을 누르면 방향 바뀌게하기
        if(button == true){
            printf("1");
        }
    }
}

```

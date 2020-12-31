# Mbed-Unity 연동 프로그램 (불키고 켜는 프로그램)

## 링크

!(https://drive.google.com/drive/folders/13JNyFivjLItN2A8ewmxb8JqruMPzrCyh)

# 제작과정

![1](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EC%82%AC%EC%A7%84/1.jpg)

- unity hub를 열고 새로생성 버튼을 누른뒤 "UnityMbed" 라는 제목으로 프로젝트를 생성한다. 템플릿은 3D를 사용한다.

![2](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EC%82%AC%EC%A7%84/2.jpg)

- unity를 열었으면, Hierarchy 창에서  마우스 오른쪽 클릭을 하여 Cube 객체를 생성한다.

![3](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EC%82%AC%EC%A7%84/3.jpg)

- 생성된 Cube객체의 Inspector창을 통해서 Transform 변수를 위 그림과 같이 변경한다.

![4](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EC%82%AC%EC%A7%84/4.jpg)

- 큐브 객체를 Ctrl+ C , Ctrl+ V하여 복사하고 위의 그림과 같이 변수를 변경한다.

![5](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EC%82%AC%EC%A7%84/5.jpg)

- 앞에서 서술한 방법대로 위의 그림처럼 한쪽 면만 열려있는 방을 하나 만든다.

![6](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EC%82%AC%EC%A7%84/6.jpg)

- Hierachy 창에서 마우스 오른쪽 클릭하여 Light-> Point Light 객체를 생성한다.

![7](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EC%82%AC%EC%A7%84/7.jpg)

- 생성된 Point Light를 클릭하여 Inspector 창에서 위의 그림과 같이 변수를 변경한다.

![8](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EC%82%AC%EC%A7%84/8.jpg)

- Assets 창에서 마우스 오른쪽 버튼을 누르고 Create-> C# script를 눌러서 새로운 스크립트를 생성한다. 이 새로운 스크립트의 이름은 "lightControl"으로 변경한다.

![9](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EC%82%AC%EC%A7%84/9.jpg)

- 새로 생성된 스크립트를 두번 하여 비주얼 스튜디오를 열고 다음의 코드를 복사 붙여넣기한다.

### lightControl.cs
```cs

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;
using System;

public class lightControl : MonoBehaviour
{
    // 시리얼 통신 객체
    SerialPort m_SerialPort = new SerialPort("COM3", 9600, Parity.None, 8, StopBits.One);

    // Start is called before the first frame update
    void Start()
    {
        // 시리얼 포트 시작
        m_SerialPort.Open();
    }

    // Update is called once per frame
    void Update()
    {
        // 시리얼 통신을 통해 Mbed로부터 데이터를 받는다.
		if (m_SerialPort.IsOpen)
		{
            String temp = m_SerialPort.ReadExisting();
            // mbed로부터 받은 데이터가 비었는지 검사
            if (temp != "")
			{
                // Mbed로부터 1을 받으면(조도센서가 어두워졌을 때) Light On
                if(temp[0] == '1')
				{
                    GetComponent<Light>().enabled = true;
				}
                // Mbed로부터 0을 받으면(조도센서가 밝아졌을 때) Light Off
				else if(temp[0] == '0')
				{
                    GetComponent<Light>().enabled = false;
				}
            }
        }
    }

	private void OnDestroy()
	{
        // 시리얼 포트 종료
        m_SerialPort.Close();
	}
}


```

![10](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EC%82%AC%EC%A7%84/10.jpg)

- 시리얼 통신을 하는 클래스를 사용하기 위해 Unity 좌측 상단 메뉴에서 File-> Build Settings-> Player settings을 누르고 player 탭을 선택한다.

![11](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EC%82%AC%EC%A7%84/11.jpg)

- Player탭에서 Api Compatibility Level 을 .NET 4.x으로 바꿔준다.

![12](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EC%82%AC%EC%A7%84/12.jpg)

- lightControl 스크립트를 Point Light 객체의 Inspector 창으로 드래그앤 드롭을 한다.

- Mbed에 다음의 코드를 컴파일하여 플레이버튼을 누른다.

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



## 프로그램 사진

![켜져있을 때](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EC%BC%9C%EC%A0%B8%EC%9E%88%EC%9D%84%EB%95%8C.jpg)

- 불이 켜졌을 때

![꺼져있을 떄](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EA%BA%BC%EC%A0%B8%EC%9E%88%EC%9D%84%20%EB%95%8C.jpg)

- 불이 꺼졌을 때

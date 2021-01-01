# Mbed-Unity 연동 프로그램 (불키고 켜는 프로그램)

## 링크

!(https://drive.google.com/drive/folders/13JNyFivjLItN2A8ewmxb8JqruMPzrCyh)

-선풍기 애셋

!(https://assetstore.unity.com/packages/3d/underground-industrial-models-69927)

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

- Hierachy 창에서 마우스 오른쪽 클릭하여 Light-> Point Light 객체를 생성한다. 또한 Point Light 객체의 이름을 Light로 변경한다.

![7](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EC%82%AC%EC%A7%84/7_2.jpg)

- 생성된 Light를 클릭하여 Inspector 창에서 위의 그림과 같이 변수를 변경한다.

![8](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EC%82%AC%EC%A7%84/8.jpg)

- Assets 창에서 마우스 오른쪽 버튼을 누르고 Create-> C# script를 눌러서 새로운 스크립트를 생성한다. 이 새로운 스크립트의 이름은 "Control"으로 변경한다.

![9](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EC%82%AC%EC%A7%84/9.jpg)

- 새로 생성된 스크립트를 두번 하여 비주얼 스튜디오를 열고 다음의 코드를 복사 붙여넣기한다.

### Control.cs
```cs
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;
using System;

public class Control : MonoBehaviour
{
    GameObject Light;
    GameObject Fan;

    // 시리얼 통신 객체
    SerialPort m_SerialPort = new SerialPort("COM3", 9600, Parity.None, 8, StopBits.One);
    // 토글 버튼을 눌렀는지 확인하는 스위치 변수
    bool toggle = false;

    // Start is called before the first frame update
    void Start()
    {
        Light = GameObject.Find("Light");
        Fan = GameObject.Find("Center");
        // 시리얼 포트 시작
        m_SerialPort.Open();
    }

	// Update is called once per frame
	void FixedUpdate()
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
                    Light.GetComponent<Light>().enabled = true;
				}
                // Mbed로부터 0을 받으면(조도센서가 밝아졌을 때) Light Off
				else if(temp[0] == '0')
				{
                    Light.GetComponent<Light>().enabled = false;
				}
            }

            // 토글 버튼이 체크되어있으면 팬을 회전한다.
            if (toggle)
            {
                Fan.transform.Rotate(new Vector3(80f, 0f, 0f) * Time.deltaTime);
                m_SerialPort.Write("1");
            }else
			{
                m_SerialPort.Write("2");
			}

        }


    }

    // 토글 버튼이 눌리면 현재 토글 상태를 받아서 스위치 변수에 저장하는 함수.
    public void OnValueChanged(bool toggle)
    {
        this.toggle = toggle;
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

- Create -> GameObject를 눌러서 새로운 객체를 만들고 그 객체의 이름을 System 으로 변경한다.

![13](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EC%82%AC%EC%A7%84/13.jpg)

- 유니티 상단 메뉴에서 Window-> AssetStore 메뉴를 누르고 Asset Store를 켠다.

![14](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EC%82%AC%EC%A7%84/14.jpg)

- 검색에 Underground Industrial Models 라고 입력하고 검색하고, 가장 첫번째 에셋을 선택한다.

![15](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EC%82%AC%EC%A7%84/15.jpg)

- 위 에셋을 Import 버튼을 눌러서 Unity로 불러온다.

![16](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EC%82%AC%EC%A7%84/16.jpg)

- 에셋의 Import가 완료가 되었으면 Asset 폴더-> Props 폴더 -> Fan 폴더로 들어가고 Fan Prefab을 드래그엔 드롭하여 Hierarchy창으로 옮긴다.

![17](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EC%82%AC%EC%A7%84/17.jpg)

- 생성된 Fan 객체를 case라는 이름으로 고치 다음과 같이 Transform 속성의 항목을 수정한다.

![18](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EC%82%AC%EC%A7%84/18.jpg)

- Fan 객체 안에 다음과 같이 새로운 GameObject를 만들고 Fan을 GameObject에 종속되게 만든다. 또한 위의 그림과 같이 Transform 변수를 수정한다.

![19](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EC%82%AC%EC%A7%84/19.jpg)

- GameObject의 이름 Center로 변경한다.

![20](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EC%82%AC%EC%A7%84/20.jpg)

- Hierarchy 창에서 마우스 오른쪽 버튼을 누르고 UI -> Toggle 버튼을 눌러서 Toggle 버튼을 만든다.

![21](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EC%82%AC%EC%A7%84/21.jpg)

- Hierarchy 에서 Canvas-> Toggle 을 누르고 다음과 같이 변수를 변경한다.

![22](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EC%82%AC%EC%A7%84/22.jpg)

- 토글 버튼아래에 있는 Label을 다음과 같이 변수를 바꾼다.

![23](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EC%82%AC%EC%A7%84/23.jpg)

- 토글 버튼 아래에 있는 Checkmark도 다음과 같이 변수를 바꾼다.

![24](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EC%82%AC%EC%A7%84/24.jpg)

- System 객체를 클릭하여 Assets 폴더에 있는 Control 스크립트를 드래그앤 드롭을 한다.

![25](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EC%82%AC%EC%A7%84/25.jpg)

- Toggle 객체를 클릭하고 Inspector 창에서 Toggle 속성에서 On Value Changed가 있는데, 런타임 밑의 상자에 System 객체를 끌어서 넣는다.

![26](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EC%82%AC%EC%A7%84/26.jpg)

- No Function 버튼을 누르고  Control-> OnValueChanged 버튼을 순서대로 누른다.

- Mbed에 다음의 코드를 컴파일하여 플레이버튼을 누른다.

### MbedUnity1.cpp
```c++
/*
2021-01-01
Unity-mbed 연동프로그램 2

*/

#include "mbed.h"

// 시리얼 통신
Serial pc(USBTX, USBRX);

//Ticker 객체 생성
Ticker myTicker;

// 조도 센서를 A0 (PA_3)에 연결
AnalogIn myCdS(A0);

// DC 모터의 방향 제어 출력 설정
DigitalOut In1(PA_5), In2(PA_6);

// DC 모터를 앞으로 이동
void forward(){
    In1 = false;
    In2 = true;
}

// DC 모터 정지
void stop(){
    In1 = false;
    In2 = false;
}

//조도값 저장 변수
float brightness = 0.0f;

void Processing()
{
    // Unity로부터 값을 읽어들어서 '1'을 입력 받으면 모터가 움직이고 '2'를 입력받으면 모터가 멈추도록 한다.
    if(pc.readable()){
        char ch = pc.getc();
        if(ch == '1'){
            forward();
        }
        else if(ch == '2'){
            stop();
        }
    }

    //조도 측정값을 변수에 저장
    brightness = myCdS.read();

    //어두우면 1을 전송 (Unity에서 1을 받으면 가상환경의 조명이 켜짐)
    if (brightness < 0.3f)
    {
        pc.printf("1");
    }
    else //밝으면 0을 전송 (Unity에서 0을 받으면 가상환경의 조명이 꺼짐)
    {
        pc.printf("0");
    }

}

int main()
{
    //myTicker에 콜백 함수 등록 (주기 0.01초)
    myTicker.attach(&Processing, 0.01);

    while (1){    }
}


```



## 프로그램 사진

![켜져있을 때](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EC%BC%9C%EC%A0%B8%EC%9E%88%EC%9D%84%EB%95%8C.jpg)

- 불이 켜졌을 때

![꺼져있을 떄](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EA%BA%BC%EC%A0%B8%EC%9E%88%EC%9D%84%20%EB%95%8C.jpg)

- 불이 꺼졌을 때


## mbed 회로 사진

- ![real](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%B6%88%EC%BC%9C%EA%B3%A0%EB%81%84%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EC%82%AC%EC%A7%84/circuit_realpicture.jpg)

# MbedUnity연동 프로그램

## 목차
1. 미사일피하기 게임

## 1. 미사일피하기 게임

### 게임 유니티 다운로드 링크

!(https://drive.google.com/drive/folders/13JNyFivjLItN2A8ewmxb8JqruMPzrCyh?usp=sharing)

### 제작 과정

![1](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/1.jpg)

- 생성 버튼을 누른다.

![2](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/2.jpg)

- 템플릿: 2D를 누르고 프로젝트 명과 저장위치를 정한다.

![3](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/3.jpg)

- Unity가 켜졌으면, Assets 창에 마우스 오른쪽 클릭을 하여 Create-> Folder를 눌러서 Sprite라는 이름을 가지는 폴더를 만든다.

![4](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/4.jpg)

- Sprite 폴더안에 준비도니 그림들 (게임오버, 미사일, 비행기 그림등을 넣는다.)

![5](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/5.jpg)

- plane 그림을 눌러서 Inspector 창을 띄우고 Sprite Mode를 Single에서 Multiple로 바꾼뒤 Sprite Editor를 누른다.

![6](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/6.jpg)

- sprite Editor가 열렸으면 왼쪽 상단에 있는 Slice 버튼을 누르고 Type :Automatic인것을 확인하고 Slice 버튼을 누른다.

![7](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/7.jpg)

- slice가 잘 되었다면 비행기들이 네모란 칸에 둘러쌓여있을 것이다. 확인한 후 닫기버튼을 누르고 Apply을 눌러서 저장한다.

![8](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/8.jpg)

- Sprite 폴더에서 sky 그림을 Scene으로 드래그앤 드롭을 한다.

![9](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/9.jpg)

- 드래그앤 드롭한 sky 객체를 눌러서 Inspector 창을 열고 다음과 같이 속성을 수정한다 (Position, Scale)

![10](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/10.jpg)

- Sprite 폴더에서 Plane sprite 화살표를 누르고 Plane_0을 선택하고 드래그앤 드롭하여 Scene으로 옮긴다.

![11](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/11.jpg)

- Plane 객체를 누르고 Inspector 창에서 다음과 같이 Transform 을 수정하고 Sprite Renderer에서 Order in Layer를 1로 수정한다. 또한 이름을 plane으로 수정한다.

![12](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/12.jpg)

- Sprite 폴더에서 Gameover Sprite를 Scene으로 드래그앤 드롭한다.

![13](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/13.jpg)

- Inspector 창에서 다음 그림과 같이 Transform와 이름 옆에 있는 체크박스를 풀어서 화면에 보이지 않도록 만든다. 또한 Order in Layer를 1로 설정하는 것을 잊지않도록 한다.

![14](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/14.jpg)

- Sprite 폴더에서 missile sprite를 Scene으로 드래그앤 드롭한다.

![15](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/15.jpg)

- missile 객체를 클릭하여 Inspector 창에서 다음과 같이 값을 수정해준다. Transform, Order in layer.

![16](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/16.jpg)

- Inspector 창의 이름 아래에 Tag를 눌러서 Add Tag를 누른다.

![17](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/17.jpg)

- Missile 이라는 이름으로 태그를 하나 추가해준다.

![18](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/18.jpg)

- Hierarchy 창에서 마우스 오른쪽 버튼을 누르고 UI -> Text 버튼을 눌러 Text 객체를 생성한다.

![19](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/19.jpg)

- Text 객체의 Inspector창에서 Rect Transform안에 있는 anchor Preset 버튼을 클릭한다.

![20](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/20.jpg)

- Ctrl + Alt 버튼을 누르면서 원하는 anchor preset 위치를 선택한다. 우리는 top과 right 쪽을 선택할 것이다.

![21](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/21.jpg)

- Text Inspector 창에서 다음과 같이 수치를 변경한다. 또한 Text 속성에서 Score: 0 로 바꾸고 Font Size :22, bold 체로 설정한다.

![22](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/22.jpg)

- Asset 폴더에서 Script 폴더와 Prefab 폴더를 생성한다.

![23](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/23.jpg)

- Script 폴더에서 마우스 오른쪽 클릭하여 Create-> Script를 누르고 새로운 스크립트 이름을 MissileCollision으로 짓고 똑같이 Moving, SponManager 이라는 스크립트를 만든다.

![24](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/24.jpg)

- 각각 스크립트 더블 클릭하고 비주얼 스튜디오를 연다음 아래 코드를 붙여넣는다.

### MissileCollision
```cs
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class MissileCollision : MonoBehaviour
{
	// text 객체
	public GameObject text;
	// 스코어 변수
	int score = 0;
    // Start is called before the first frame update
    void Start()
    {

    }

	// 미사일과 collision 객체가 충돌되었을 때 호출되는 콜백 함수
	private void OnCollisionEnter2D(Collision2D collision)
	{
		// movingScript에서 isPlaying 변수를 빼오기 위해 movingScript 가져오기
		Moving movingScript = GameObject.Find("plane").GetComponent<Moving>();

		// 충돌된 객체가 Missile이라는 tag를 가지고 있는가??
		if (collision.gameObject.tag == "Missile")
		{
			// 충돌된 객체를 제거
			Destroy(collision.gameObject);

			// 현재 게임이 진행중인가?
			if (movingScript.isPlaying)
			{
				// 점수 증가 및 표시
				string scoreString = string.Format("Score : {0}", ++score);
				text.GetComponent<Text>().text = scoreString;
			}
		}
	}

	// Update is called once per frame
	void Update()
    {

    }
}

```

### Moving.cs
```cs
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using System.IO.Ports;
using System;

public class Moving : MonoBehaviour
{
    // Mbed와 시리얼 통신을 위한 SerialPort 객체 생성 (COM 번호, 보율 , 패리티비트, data비트, 스톱 비트)
    SerialPort m_SerialPort = new SerialPort("COM5", 9600, Parity.None, 8, StopBits.One);

    // Mbed로부터 전달받은 데이터
    string m_data = null;
    // 예전 인코더값 비교 변수
    int last_value = 0;
    // 시리얼 통신
    bool s_flag = false;

    // 게임오버 객체
    public GameObject GameOverObject;
    // 게임 진행 플래그 변수
    public bool isPlaying = true;
    // Start is called before the first frame update
    void Start()
    {
        // 시리얼 통신 연결
        m_SerialPort.Open();
    }

    // ms 단위의 딜레이를 주는 함수
    private static DateTime Delay(int MS)
    {
        DateTime ThisMoment = DateTime.Now;
        TimeSpan duration = new TimeSpan(0, 0, 0, 0, MS);
        DateTime AfterWards = ThisMoment.Add(duration);

        while (AfterWards >= ThisMoment)
        {
            ThisMoment = DateTime.Now;
        }

        return DateTime.Now;
    }

    // 미사일과 비행기가 충돌되었을 때 발생하는 콜백함수
    private void OnCollisionEnter2D(Collision2D collision)
	{
		if(collision.gameObject.tag == "Missile")
		{
            Destroy(collision.gameObject);
            GameOverObject.active = true;
            SponManager sponManager = GameObject.Find("System").GetComponent<SponManager>();
            sponManager.enableSpawn = false;
            isPlaying = false;
		}
	}

	// Update is called once per frame
	void Update()
    {
        // 게임이 진행중이면 Serial_Communication()함수를 통해 Mbed와 시리얼 통신
		if (isPlaying)
		{
            Serial_Communication();
        }
		else
		{
            // R키를 누르면 게임 다시시작
			if (Input.GetKey(KeyCode.R))
			{
                SceneManager.LoadScene(0);
			}
		}
    }

    // Mbed와 시리얼 통신을 함수
    private void Serial_Communication()
	{
        try
        {
            if (m_SerialPort.IsOpen)
            {
                // Mbed로부터 데이터를 받는다.
                String temp = m_SerialPort.ReadExisting();
                assemble_data(temp);
                Delay(20);
            }
        }
        catch (Exception e)
        {

        }
    }

    // Mbed로부터 받은 데이터를 조립하여 의미있는 데이터로 만드는 함수
    void assemble_data(string temp)
	{
        // 문자열이 비어있는지 확인
        if (temp != "")
        {
            // 문자열에서 시작기호 #가 포함되어있으면 데이터를 넣는 것을 시작한다.
            if (temp.Contains("#") && !s_flag)
            {
                m_data += temp.Substring(temp.IndexOf("#"));
                s_flag = true;
                temp = "";
            }

            // #와 $이 포함되지 않은 내용부분이라면 내용을 넣는다.
            if(!temp.Contains("$") &&s_flag)
            {
                m_data += temp.Trim();
                temp = "";
            }

            // 문자열에서 종료기호 $ 가 포함되어있으면 완전한 데이터를 처리한다.
            if (temp.Contains("$") && s_flag)
            {
                m_data += temp.Substring(0, temp.IndexOf("$") + 1);
                // 의미있는 데이터를 가지고 어느 방향으로 움직여야하는지 결정한다.
                CalculateMoving(m_data);
                m_data = "";
                temp = "";
                s_flag = false;
            }
        }
    }

    // 문자열을 통해서 어느 방향으로 움직일지 결정하는 함수
    private void CalculateMoving(String m_data)
    {
        string temp;
        if (m_data.Contains("#") && m_data.Contains("$"))
        {
            // 문자열 (#숫자$) 안에 있는 숫자를 추출한다.
            temp = m_data.Substring(1, m_data.IndexOf("$") - 1);
            // 문자열을 숫자로 추출한다.
            int value = int.Parse(temp);
            //왼쪽
            if ((last_value - value) >= 0)
            {
                // 비행기는 x축으로 10의 밖으로 벗어나면 안된다.
                if (transform.position.x < 10)
                {
                    transform.Translate(Vector3.right * 3 * Time.deltaTime);
                }
            }
            // 오른쪽 이동
            else
            {
                // 비행기는 x축으로 -10의 밖으로 벗어나면 안된다.
                if (transform.position.x > -10)
                {
                    transform.Translate(Vector3.left * 3 * Time.deltaTime);
                }
            }
            // 예전 숫자를 기록한다.
            last_value = value;
        }
    }

    private void OnDestroy()
    {
        m_SerialPort.Close();
    }
}

```

### SponManager.cs
```cs
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SponManager : MonoBehaviour
{
    // 스폰 스위치
    public bool enableSpawn = false;
    // 미사일 객체
    public GameObject Missile;

    // 미사일 객체를 랜덤으로 생성하는 함수
    void SpawnMissile()
	{
        // 랜덤하게 x축으로 -10.0f , 10.0f 범위로 설정
        float randomX = Random.Range(-10.0f, 10.0f);
        // 스폰 스위치가 On이면 미사일 객체 생성
        if (enableSpawn)
        {
            GameObject missile = (GameObject)Instantiate(Missile, new Vector3(randomX, 5, 0), Missile.transform.rotation);
        }
    }

	void Start()
	{
        // 1초에서 4초사이로 랜덤으로 설정
        int time = Random.Range(1, 4);
        // SpawnMissile 함수를 time 변수에 맞춰서 호출
        InvokeRepeating("SpawnMissile", 1, time);
    }

}

```

![25](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/25.jpg)

- 복사를 하고나고 저장을 하면 다음 그림과 같이 Moving.cs 파일에서 System.IO.Ports가 못찾는다고 뜰 것이다. 이를 해결하기 위해 다음과 같은 과정을 진행한다.

![26](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/26.jpg)

- Unity 메뉴에서 File -> Build Seettings를 클릭한다.

![27](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/27.jpg)

- Build Settings가 뜨면 Player Settings 버튼을 클릭한다.

![28](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/28.jpg)

- Project Settings에서 왼쪽 Player 탭을 선택하고 거기서 Other Settings를 눌러서 확장시킨다.

![29](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/29.jpg)

- Configuration 탭에서 Api Compatibility Level을 .NET 4.x으로 변경한다. 그러면 코드를 복사하는 과정에서 생긴 버그를 해결할 수가 있다.

![30](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/30.jpg)

- Build Settings 창에서 Add Open Scenes 버튼을 클릭하여 현재 씬을 프로젝트에 추가한다. 그리고 닫기버튼을 누른다.

![31](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/31.jpg)

- Hierachy 창에서 plane 객체를 클릭한다. 또 Script 폴더에서 Moving 스크립트를 Inspector 창으로 드래그앤 드롭한다.

![32](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/32.jpg)

- 충돌 처리를 위해서 Plane 의 Inspector 창에서 Add Components 버튼을 누르고 Box Collider 2D를 추가한다.

![33](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/33.jpg)

- plane 객체의 Moving 스크립트에서 Game Over Object 객체를 지정해주어야된다. Hierachy 창에서 GameOver객체를 드래그앤 드롭하여 GameOverObject로 끌고온다.

![34](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/34.jpg)

- Hierarchy 창에서 마우스 오른쪽 버튼을 클릭하여 Create Empty 버튼을 클릭한다.

![35](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/35.jpg)

- 생성된 GameObject를 Colision으로 이름을 바꾼다.

![36](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/36.jpg)

- Collision 객체에서 Add Component를 눌러서 Box Collider 2D와 Rigidbody 2D를 추가하고 Script 폴더에서 Missile Collision 스크립트를 드래그앤 드롭하여 추가한다.
- 또한 위의 그림과 같이 변수를 변경해준다.

![37](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/37.jpg)

- Missile Collision 스크립트에서 Text 객체를 선택해주어야된다. Hierarchy 창에서 Text 객체를 찾아서 드래그앤 드롭하여 선택해준다.

![38](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/38.jpg)

- Hierarchy 창에서 Create-> Empty Object 버튼을 눌러서 새로운 GameObject를 만들고 그것의 이름을 System으로 바꾼다.

![39](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/39.jpg)

- Script 폴더에서 SponManager 스크립트를 System 객체에 드래그앤 드롭하여 추가해준다.

![40](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/40.jpg)

- Spon Manager에서 Enable Spawn 체크박스를 체크해주고 Missile 은 Hierarchy창에서 missile 객체를 찾아서 선택해준다.

![41](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/41.jpg)

- Mbed와 컴퓨터랑 연결하고 윈도우에서 장치관리자를 열고 PORT번호를 확인한다. 현재 COM3에 물려있는 것을 확인할 수가 있다.

![42](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/42.jpg)

- Moving 스크립트를 열고 현재 상황에 맞는 PORT번호 스크립트를 변경해준다.

![43](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/43.jpg)

- hierachy 창에서 missile 객체를 찾고 missile 객체에 Rigidbody 2D와 Box collider 2D를 추가한다. 또한 위 그림처럼 Rigidbody 2D의 변수를 바꿔준다. "Gravity Scale: 0"을 잊지 말자.

![44](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/44.jpg)

- Add Component를 눌러서 new script를 찾고 script의 이름을 MissileMoving으로 짓는다.

![45](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/%EC%82%AC%EC%A7%84/45.jpg)

- Hierachy 창에서 MissileMoving 스크립트를 찾고 비주얼스튜디오를 열어서 다음의 코드를 추가해준다.

### MissileMoving.cs
```cs
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class missileMoving : MonoBehaviour
{

    public int speed = 2;
    // Start is called before the first frame update
    void Start()
    {

    }


	// Update is called once per frame
	void Update()
    {
        Vector3 direction = new Vector3(0, -1, 0);
        transform.Translate(direction * Time.deltaTime * speed, Space.World );
    }
}


```

- 또한 아래의 Mbed 코드를 Mbed에 넣고 Mbed와 Unity 사이 연동을 해준다.

### Mbed 코드
```c++
/*
2020-12-28    Mbed-Unity 연동 프로그램 (로터리 엔코더 모듈 사용)
회로 : page 222
MbedUnityCode1.cpp
 */
#include "mbed.h"
#include "mRotaryEncoder.h"

// UART2 포트, 컴퓨터 연결
Serial pc(USBTX, USBRX);
// PA_5 핀으로 LED 제어
DigitalOut LED(PA_5);
// 이벤트 큐
EventQueue *queue = mbed_event_queue();

// 로터리 인코더(S1핀, S2핀, Key핀)
mRotaryEncoder encoder(D0,D1,D2);
int data;

// 로터리 인코더 회전을 할 때 Unity에게 값을 전송 (#(숫자)$)형식으로 전달
void print(){
   pc.printf("#%d$\n", encoder.Get());
}

// 로터리 인코더를 회전할 때 호출되는 함수
void rotate(){
    queue->call(&print);
}

int main(){
    LED = false;
    // 회전되었을 때 호출되는 콜백함수 설정
    encoder.attachROT(&rotate);
    queue->dispatch_forever();

    while(true){
    }
}
```

### Mbed 회로 결과사진
![](https://github.com/HongyeongJu/MbedCode/blob/master/Chapter09_Unity-mbed%20%EC%97%B0%EB%8F%99%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/%EB%AF%B8%EC%82%AC%EC%9D%BC%ED%94%BC%ED%95%98%EA%B8%B0%EA%B2%8C%EC%9E%84/MbedUnity_Picture.jpg)

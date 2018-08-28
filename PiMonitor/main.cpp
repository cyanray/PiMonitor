#include <iostream>
#include <unistd.h>
#include "HTTP.h"
#include "DHT11.h"

using Cyan::HTTP;
using namespace std;
static const unsigned int DHTPIN = 7;//ʹ�� GPIO.7 ���� DHT11 ������
int main()
{
	unsigned long temperture = 0, humidity = 0;
	DHT11 dht11 = DHT11(DHTPIN);
	HTTP http = HTTP();
	string pData = "", re = "";
	cout << "Hello PiMonitor!" << endl;
	dht11.ReadData(temperture, humidity);//��ȡ��һ�����ݣ���һ�ε������ǲ�׼ȷ�ġ�
	sleep(2);
	while (1)
	{
		dht11.ReadData(temperture, humidity);
		pData = "Temp=" + to_string(temperture) + "&Hum=" + to_string(humidity);
		cout << pData << endl;
		re = http.Post("http://127.0.0.1/MyRoom/AddState.php", pData);
		cout << re << endl;
		sleep(60 * 10);
	}
    return 0;
}
#include <iostream>
#include <unistd.h>
#include "HTTP.h"
#include "DHT11.h"

using Cyan::HTTP;
using namespace std;
static const unsigned int DHTPIN = 7;//使用 GPIO.7 输入 DHT11 的数据
int main()
{
	unsigned long temperture = 0, humidity = 0;
	DHT11 dht11 = DHT11(DHTPIN);
	HTTP http = HTTP();
	string pData = "", re = "";
	cout << "Hello PiMonitor!" << endl;
	dht11.ReadData(temperture, humidity);//读取第一次数据，第一次的数据是不准确的。
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
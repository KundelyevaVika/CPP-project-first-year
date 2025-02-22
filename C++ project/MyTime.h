#pragma once
#include<iostream>;
#include<ctime>;
using namespace std;

struct MyTime {
	int hours = 0;
	int min = 0;
	int sec = 0;
	char str[50] = "";
	
	//методы структуры

	void fillTime() {
	// подключить #include <iostream> !!!
		cout << "Введите часы, минуты, секунды: ";
		cin >> hours >> min >> sec;
	}

	void printTime() {
		cout << hours / 10 << hours % 10 << ":"<< min / 10 << min % 10 << ":" << sec / 10 << sec % 10 << endl;
	}

	const char* toString(const char* format="%X") {
		// подключить #include <ctime> !!!
		tm buffer = { sec, min, hours };
		strftime(str, 50, format, &buffer);
		return str;
	}

	void getNowTime() {
		// создаем стд объект даты и времени
		tm* tim = new tm;
		// определяем текущую млисекунду
		time_t tt = time(NULL);
		//заполняем все поля стд структуры
		localtime_s(tim, &tt);
		//заполняем нужные поля нашей структуры
		sec = tim->tm_sec;
		min = tim->tm_min;
		hours = tim->tm_hour;
	}

	//==================================

	void addSecond() {
		tm extraTime{sec,min,hours,0,0,71};
		time_t seconds = time(NULL);
		seconds = mktime(&extraTime);
		seconds+=1;
		localtime_s(&extraTime, &seconds);
		sec = extraTime.tm_sec;
		min = extraTime.tm_min;
		hours = extraTime.tm_hour;
	}

	void delSecond() {
		tm extraTime{ sec,min,hours,0,0,71 };
		time_t seconds = time(NULL);
		seconds = mktime(&extraTime);
		seconds -= 1;
		localtime_s(&extraTime, &seconds);
		sec = extraTime.tm_sec;
		min = extraTime.tm_min;
		hours = extraTime.tm_hour;
	}

	void addMinute() {
		tm extraTime{ sec,min,hours,0,0,71 };
		time_t seconds = time(NULL);
		seconds = mktime(&extraTime);
		seconds += 60;
		localtime_s(&extraTime, &seconds);
		sec = extraTime.tm_sec;
		min = extraTime.tm_min;
		hours = extraTime.tm_hour;
	}

	void delMinute() {
		tm extraTime{ sec,min,hours,0,0,71 };
		time_t seconds = time(NULL);
		seconds = mktime(&extraTime);
		seconds -= 60;
		localtime_s(&extraTime, &seconds);
		sec = extraTime.tm_sec;
		min = extraTime.tm_min;
		hours = extraTime.tm_hour;
	}

	void addHour() {
		tm extraTime{ sec,min,hours,0,0,71 };
		time_t seconds = time(NULL);
		seconds = mktime(&extraTime);
		seconds += 3600;
		localtime_s(&extraTime, &seconds);
		sec = extraTime.tm_sec;
		min = extraTime.tm_min;
		hours = extraTime.tm_hour;
	}

	void delHour() {
		tm extraTime{ sec,min,hours,0,0,71 };
		time_t seconds = time(NULL);
		seconds = mktime(&extraTime);
		seconds -= 3600;
		localtime_s(&extraTime, &seconds);
		sec = extraTime.tm_sec;
		min = extraTime.tm_min;
		hours = extraTime.tm_hour;
	}

	//=================================================

	void addSeconds(int s) {
		tm extraTime{ sec,min,hours,0,0,71 };
		time_t seconds = time(NULL);
		seconds = mktime(&extraTime);
		seconds += s;
		localtime_s(&extraTime, &seconds);
		sec = extraTime.tm_sec;
		min = extraTime.tm_min;
		hours = extraTime.tm_hour;
	}

	void delSeconds(int s) {
		tm extraTime{ sec,min,hours,0,0,71 };
		time_t seconds = time(NULL);
		seconds = mktime(&extraTime);
		seconds -= s;
		localtime_s(&extraTime, &seconds);
		sec = extraTime.tm_sec;
		min = extraTime.tm_min;
		hours = extraTime.tm_hour;
	}

	void addMinutes(int m) {
		tm extraTime{ sec,min,hours,0,0,71 };
		time_t seconds = time(NULL);
		seconds = mktime(&extraTime);
		seconds += 60*m;
		localtime_s(&extraTime, &seconds);
		sec = extraTime.tm_sec;
		min = extraTime.tm_min;
		hours = extraTime.tm_hour;
	}

	void delMinutes(int m) {
		tm extraTime{ sec,min,hours,0,0,71 };
		time_t seconds = time(NULL);
		seconds = mktime(&extraTime);
		seconds -= 60 * m;
		localtime_s(&extraTime, &seconds);
		sec = extraTime.tm_sec;
		min = extraTime.tm_min;
		hours = extraTime.tm_hour;
	}

	void addHours(int h) {
		tm extraTime{ sec,min,hours,0,0,71 };
		time_t seconds = time(NULL);
		seconds = mktime(&extraTime);
		seconds += 3660 * h;
		localtime_s(&extraTime, &seconds);
		sec = extraTime.tm_sec;
		min = extraTime.tm_min;
		hours = extraTime.tm_hour;
	}

	void delHours(int h) {
		tm extraTime{ sec,min,hours,0,0,71 };
		time_t seconds = time(NULL);
		seconds = mktime(&extraTime);
		seconds -= 3660 * h;
		localtime_s(&extraTime, &seconds);
		sec = extraTime.tm_sec;
		min = extraTime.tm_min;
		hours = extraTime.tm_hour;
	}
};

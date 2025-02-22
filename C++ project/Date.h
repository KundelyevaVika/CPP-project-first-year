#pragma once
#include<iostream>;
#include<ctime>;
using namespace std;

struct Date {
	int day = 0;
	int month = 0;
	int year = 0;
	char str[50] ="";

	void fillDate() {
		cout << "¬ведите день: ";
		cin >> day;
		cout << "¬ведите мес€ц: ";
		cin >> month;
		cout << "¬ведите год: ";
		cin >> year;
	}

	void printDate() {
		cout << day / 10 << day % 10 << "." << month / 10 << month % 10 << "." << year;
	}

	const char* toString(const char* format = "%d %B %Y") {
		tm dateInfo = { 0,0,0,day,month-1,year-1900 };
		strftime(str, 50, format, &dateInfo);
		return str;
	}

	void getCurrentDate(){
		tm dateInfo = { 0 };
		time_t seconds = time(NULL);
		localtime_s(&dateInfo, &seconds);

		year = dateInfo.tm_year + 1900;
		month = dateInfo.tm_mon+1;
		day = dateInfo.tm_mday;
	}

	void toNextDate() {
		tm dateInfo = { 0,0,0,day,month - 1,year - 1900 };
		time_t seconds = mktime(&dateInfo);
		seconds += 3600 * 24;//+ 1 день
		localtime_s(&dateInfo, &seconds);
		year = dateInfo.tm_year + 1900;
		month = dateInfo.tm_mon + 1;
		day = dateInfo.tm_mday;
	}

	void toPreviousDate() {
		tm dateInfo = { 0,0,0,day,month - 1,year - 1900 };
		time_t seconds = mktime(&dateInfo);
		seconds -= 3600 * 24;//- 1 день
		localtime_s(&dateInfo, &seconds);
		year = dateInfo.tm_year + 1900;
		month = dateInfo.tm_mon + 1;
		day = dateInfo.tm_mday;
	}

	void addDays(int d) {
		tm dateInfo = { 0,0,0,day,month - 1,year - 1900 };
		time_t seconds = mktime(&dateInfo);
		seconds += 3600 * 24*d;//+ d дней
		localtime_s(&dateInfo, &seconds);
		year = dateInfo.tm_year + 1900;
		month = dateInfo.tm_mon + 1;
		day = dateInfo.tm_mday;
	}

	void delDays(int d) {
		tm dateInfo = { 0,0,0,day,month - 1,year - 1900 };
		time_t seconds = mktime(&dateInfo);
		seconds -= 3600 * 24 * d;//- d дней
		localtime_s(&dateInfo, &seconds);
		year = dateInfo.tm_year + 1900;
		month = dateInfo.tm_mon + 1;
		day = dateInfo.tm_mday;
	}

	void copy_date(tm &date) {
		date.tm_mday = day;
		date.tm_mon = month-1;
		date.tm_year = year-1900;
	}
};
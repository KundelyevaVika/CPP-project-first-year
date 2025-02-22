#pragma once
#include<iostream>;
#include<cstring>;
using namespace std;

struct MyString {
	char* str = new char[1]{ '\0' };
	int length = 1;

	void setMyString(const char* s) {
		//if (str != NULL) {
		//	delete[] str;
		//}
		length = strlen(s)+1;
		str = new char[length];
		strcpy_s(str,length, s);
	}

	void set_MyString_without_enter(const char* s) {
		//if (str != NULL) {
		//	delete[] str;
		//}
		length = strlen(s)-1;
		str = new char[length];
		for (int i = 0; i < length; i++)
		{
			str[i] = s[i];
		}
		str[length] = '\0';
	}

	void delMyString() {
		if (str != NULL) {
			delete[] str;
		}
		length = 1;
		str = new char[1]{'\0'};
	}

	void toFisrtUpper() {
		str[0] = toupper(str[0]);
	}
	
	void toAllLower() {
		for (int i = 0;i < length;i++) {
			if (isupper(str[i])) {
				str[i] = tolower(str[i]);
			}
		}
	}

	void oneSpace() {
		for (int i = 0;i < length;i++) {
			if (str[i] == ' '&&str[i+1]==' ') {
				for (int j = i;j < length;j++) {
					str[j] = str[j + 1];
				}
				length--;
				i--;
			}
		}
	}

	void spacesToLine() {
		for (int i = 0;i < length;i++) {
			if (str[i] == ' ') {
				str[i] = '_';
			}
		}
	}

	int words() {
		int ctn = 1;
		for (int i = 0; i < strlen(str); i++) {
			if (str[i] == ' ' && str[i + 1] != ' ') ctn++;
		}
		return ctn;
	}
};
#pragma once

#include<iostream>;
#include"MyString.h";
#include"Game.h";
#include<Windows.h>;
#include<conio.h>;
#include"Profile.h";

struct Admin {
	MyString name;
	MyString password;

	void save_admin(FILE* fp) {
		fprintf(fp, "%s", name.str);
		fprintf(fp, "\n");
		fprintf(fp, "%s", password.str);
		fprintf(fp, "\n");
	}

	void load_admin(FILE* fp) {
		char tmp[1000];
		fscanf_s(fp, "\n");
		fgets(tmp, 1000, fp);
		name.set_MyString_without_enter(tmp);
		fgets(tmp, 1000, fp);
		password.set_MyString_without_enter(tmp);
	}

	bool check_password() {
		char tmp[100];
		cout << "\nВведите пароль: ";
		cin.getline(tmp, 100);
		if (strcmp(tmp, password.str) == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	void print_admin() {
		cout << "Имя: " << name.str<<endl;
		cout << "Пароль: " << password.str<<endl;
	}
};

void save_arr_admin(FILE* fp, Admin* arr, int size, int index) {
	fprintf(fp, "%d", index);
	fprintf(fp, "\n");
	//При сохранении массива в файл первым сохраняем его размерность!
	fprintf(fp, "%d", size);
	fprintf(fp, "\n");
	if (size > 0) {
		for (int i = 0; i < size; i++)
		{
			arr[i].save_admin(fp);
		}
	}
}

void load_arr_admin(FILE* fp, Admin*& arr, int& size, int& index) {
	fscanf_s(fp, "%d", &index);
	fscanf_s(fp, "\n");
	fscanf_s(fp, "%d", &size);
	if (size > 0) {
		arr = new Admin[size];
		for (int i = 0; i < size; i++)
		{
			arr[i].load_admin(fp);
		}
	}
	else {
		arr = nullptr;
		size = 0;
		return;
	}
}

void sign_in_admin(Admin* arr, int size, int& index) {
	char tmp[100];
	bool found = false;
	int menu = -1, ind;
	do {
		found = false;
		cout << "Введите никнейм: ";
		cin.ignore();
		cin.getline(tmp, 100);
		for (int i = 0; i < size; i++)
		{
			if (strcmp(tmp, arr[i].name.str) == 0) {
				ind = i;
				found = true;
				break;
			}
		}
		if (found == true) {  // error ++
			for (;;) {
				if (arr[ind].check_password() == true) {
					cout << "\nДобро пожаловать в DragonForce!\n";
					cout << "\nХе-хе, не шалите!\n";
					index = ind;
					char a;
					cout << "\nНажмите что-нибудь чтобы продолжить.\n";
					a = _getch();
					menu = 2;
					break;
				}
				else {
					cout << "Неверный ввод пароля.\n";
					cout << "\n1. Попробовать еще раз.\n"; //+ //+
					cout << "2. <-- Вернуться.\n"; //+ //+
					cout << "\nВаш выбор: ";
					cin >> menu;
					cout << endl;
					if (menu > 2 || menu < 1) {
						system("color 04");
						cout << "Ошибка ввода.\n\n";
						Sleep(2000);
						system("color 07");
					}
					else {
						break;
					}
				}
			}
		}
		else {  // error ++
			for (;;) {
				cout << "Пользователь с таким именем не найден.\n";
				cout << "\n1. Попробовать еще раз.\n"; //+ //+
				cout << "2. <-- Вернуться.\n"; //+ //+
				cout << "\nВаш выбор: ";
				cin >> menu;
				if (menu > 2 || menu < 1) {
					system("color 04");
					cout << "Ошибка ввода.\n";
					Sleep(2000);
					system("color 07");
				}
				else {
					break;
				}
			}
		}
	} while (menu != 2);
}
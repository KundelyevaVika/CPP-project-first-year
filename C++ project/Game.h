#pragma once

#include<iostream>;
#include"Profile.h";
#include"MyString.h";
#include"Date.h";
#include<Windows.h>;
#include<conio.h>;
using namespace std;

struct Game {
	MyString name;
	MyString developer;
	MyString genre;
	Date date_creation;
	MyString description;
	MyString trailer;
	float rating;
	float price;
	MyString file_name;
	float weight;

	void fill_game() {
		system("cls");
		HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
		cout << endl;
		for (int i = 0; i < 211; i++)
		{
			cout << "-";
		}
		cout << endl;
		SetConsoleTextAttribute(console_color, 14);
		cout << "\n|";
		for (int i = 0; i < 56; i++)
		{
			cout << " ";
		}
		cout << "(`·._.·(`·._.·(`·._.·(`·._.·(`·._.·(`·._.· Dragon Force ·._.·`)·._.·`)·._.·`)·._.·`)·._.·`)·._.·`)";
		for (int i = 0; i < 55; i++)
		{
			cout << " ";
		}
		cout << "|\n";
		SetConsoleTextAttribute(console_color, 15);
		cout << endl;
		for (int i = 0; i < 211; i++)
		{
			cout << "-";
		}
		cout << endl<<endl;
		char tmp[3000] = "";
		cin.ignore();
		cout << "Введите название: ";
		cin.getline(tmp, 3000);
		name.setMyString(tmp);
		name.toFisrtUpper();
		cout << "Введите название разработчика: ";
		cin.getline(tmp, 3000);
		developer.setMyString(tmp);
		cout << "Введите жанр: ";
		cin.getline(tmp, 3000);
		genre.setMyString(tmp);
		cout << "Введите дату выхода:\n";
		date_creation.fillDate();
		cin.ignore();
		cout << "Введите описание (до 1000 символов): ";
		cin.getline(tmp, 3000);
		description.setMyString(tmp);
		cout << "Введите ссылку на трейлер: ";
		cin.getline(tmp, 3000);
		trailer.setMyString(tmp);
		cout << "Введите рейтинг: ";
		cin >> rating;
		cout << "Введите цену: ";
		cin >> price;
		cin.ignore();
		cout << "Добавьте файл игры: ";
		cin.getline(tmp, 3000);
		file_name.setMyString(tmp);
		cout << "Введите размер: ";
		cin >> weight;
	}

	void print_game() {
		cout << "Название: " << name.str<<endl;
		cout << "Разработчик: " << developer.str<<endl;
		cout << "Жанр: " << genre.str<<endl;
		cout << "Дата выхода: ";
		date_creation.printDate();
		//cout << "\nОписание: " << description.str << endl;
		cout << endl;
		cout << "Описание: ";
		for (int i = 0; i < description.length; i++)
		{
			cout << description.str[i];
			if (i % 60 == 0&&i!=0) {
				cout << "\n";
			}
		}
		cout << endl;
		cout << "Ссылка на трейлер: " << trailer.str << endl;
		cout << "Рейтинг: " << rating << endl;
		cout << "Цена: " << price <<"$"<< endl;
		cout << "Файл: " << file_name.str << endl;
		cout << "Размер файла: " << weight<<" МБ" << endl;
	}

	void save_game(FILE* fp) {
		fprintf(fp, "%s", name.str);
		fprintf(fp, "\n");
		fprintf(fp, "%s", developer.str);
		fprintf(fp, "\n");
		fprintf(fp, "%s", genre.str);
		fprintf(fp, "\n");
		fprintf(fp, "%d", date_creation.day);
		fprintf(fp, "\n");
		fprintf(fp, "%d", date_creation.month);
		fprintf(fp, "\n");
		fprintf(fp, "%d", date_creation.year);
		fprintf(fp, "\n");
		fprintf(fp, "%s", description.str);
		fprintf(fp, "\n");
		fprintf(fp, "%s", trailer.str);
		fprintf(fp, "\n");
		fprintf(fp, "%f", rating);
		fprintf(fp, "\n");
		fprintf(fp, "%f", price);
		fprintf(fp, "\n");
		fprintf(fp, "%s", file_name.str);
		fprintf(fp, "\n");
		fprintf(fp, "%f", weight);
		fprintf(fp, "\n");
	}

	void load_game(FILE* fp) {
		fscanf_s(fp, "\n");
		char tmp[3000];
		fgets(tmp, 1000, fp);
		name.set_MyString_without_enter(tmp);
		fgets(tmp, 3000, fp);
		developer.set_MyString_without_enter(tmp);
		fgets(tmp, 3000, fp);
		genre.set_MyString_without_enter(tmp);
		fscanf_s(fp, "%d", &date_creation.day);
		fscanf_s(fp, "%d", &date_creation.month);
		fscanf_s(fp, "%d", &date_creation.year);
		fscanf_s(fp, "\n");
		fgets(tmp, 3000, fp);
		description.set_MyString_without_enter(tmp);
		fgets(tmp, 3000, fp);
		trailer.set_MyString_without_enter(tmp);
		fscanf_s(fp, "%f", &rating);
		fscanf_s(fp, "%f", &price);
		fscanf_s(fp, "\n");
		fgets(tmp, 3000, fp);
		file_name.set_MyString_without_enter(tmp);
		fscanf_s(fp, "%f", &weight);
	}

	void change_game() {
		int menu;
		float a;
		char b;
		char tmp[100];
		char tmp1[100];
		cin.ignore();
		do {
			system("cls");
			cout << "1. Изменить название.\n"; //+ //+
			cout << "2. Изменить разработчика.\n"; //+ //+
			cout << "3. Изменить жанр.\n"; //+ //+
			cout << "4. Изменить дату.\n"; //+ //+
			cout << "5. Изменить описание.\n"; //+ //+
			cout << "6. Изменить трейлер.\n"; //+ //+
			cout << "7. Изменить рейтинг.\n"; //-
			cout << "8. Изменить цену.\n"; //-
			cout << "9. Изменить файл.\n"; //-
			cout << "10. Изменить вес.\n"; //-
			cout << "11. <-- Вернуться.\n"; //+ //+
			cout << "\nВаш выбор: ";
			cin >> menu;
			cout << endl;
			switch (menu)
			{
			case 1:
				cout << "Введите название: ";
				cin.ignore();
				cin.getline(tmp, 100);
				name.setMyString(tmp);
				cout << "\nНовое название сохранено.\n\n";
				cout << "Нажмите что-нибудь чтобы продолжить.\n";
				b = _getch();
				break;
			case 2:
				cout << "Введите разработчика: ";
				cin.ignore();
				cin.getline(tmp, 100);
				name.setMyString(tmp);
				cout << "\nРазработчик сохраненен.\n\n";
				cout << "Нажмите что-нибудь чтобы продолжить.\n";
				b = _getch();
				break;
			case 3:
				cout << "Введите жанр: ";
				cin.ignore();
				cin.getline(tmp, 100);
				name.setMyString(tmp);
				cout << "\nНовый жанр сохранен.\n\n";
				cout << "Нажмите что-нибудь чтобы продолжить.\n";
				b = _getch();
				break;
			case 4:
				cout << "Введите дату выхода:\n";
				date_creation.fillDate();
				cout << "\nНовая дата выхода сохранена.\n\n";
				cout << "Нажмите что-нибудь чтобы продолжить.\n";
				b = _getch();
				break;
			case 11:
				break;
			default:
				system("color 04");
				cout << "Ошибка ввода.\n";
				Sleep(2000);
				system("color 07");
				break;
			}
		} while (menu != 11);
	}
};

//функции

void add_game(Game* &arr, int &size) {
	Game* tmp = new Game[size + 1];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}
	cout << "Введите данные о новой игре:\n";
	tmp[size].fill_game();
	size++;
	if (arr != nullptr) delete[] arr;
	arr = tmp;
}

void add_existing_game(Game*& arr, int& size, Game game) {
	Game* tmp = new Game[size + 1];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}
	tmp[size] = game;
	if (arr != nullptr) {
		delete[]arr;
	}
	arr = tmp;
	size++;
}

void save_arr_game(FILE* fp, Game* arr, int size) {
	//При сохранении массива в файл первым сохраняем его размерность!
	fprintf(fp, "%d", size);
	fprintf(fp, "\n");
	if (size > 0) {
		for (int i = 0; i < size; i++)
		{
			arr[i].save_game(fp);
		}
	}
}

void load_arr_game(FILE* fp, Game*& arr, int& size) {
	fscanf_s(fp, "%d", &size);
	if (size > 0) {
		arr = new Game[size];
		for (int i = 0; i < size; i++)
		{
			arr[i].load_game(fp);
		}
	}
	else {
		arr = nullptr;
		size = 0;
		return;
	}
}

void print_arr_game(Game* arr, int size) {
	int menu, number;
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ".\n";
		arr[i].print_game();
		cout << endl;
	}
	cout << "=========================\n";
}

int print_arr_game_1(Game* arr, int size) {
	int menu,number;
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ".\n";
		arr[i].print_game();
		cout << endl;
	}
	cout << "=========================\n";

	do { // error ++ 
		cout << "1. Детальнее.\n"; //+ //+
		cout << "2. <-- Вернуться.\n"; //+ //+
		cout << "\nВаш выбор: ";
		cin >> menu;
		cout << endl;
		switch (menu)
		{
		case 1:
			cout << "Введите номер игры: ";
			cin >> number;
			if (number > size || number < 0) {
				cout << "Ошибка.\n";
			}
			else {
				number -= 1;
				return number;
			}
			break;
		case 2:
			return -1;
			break;
		default:
			system("color 04");
			cout << "Ошибка ввода.\n";
			Sleep(2000);
			system("color 07");
			break;
		}
	} while (menu != 2);
}

void show_newest_games(Game* arr, int size, Game*& arr1, int& size1) {
	//разница: 2678400 - 31 день
	int counter = 0;
	Date tmp;
	tmp.getCurrentDate();
	tm tmpInfo = { 0,0,0,tmp.day,tmp.month - 1,tmp.year - 1900 };
	time_t secondsTmp = mktime(&tmpInfo);
	tm gameInfo = { 0 };
	time_t secondsGame;
	unsigned int difference;
	for (int i = 0; i < size; i++)
	{
		gameInfo.tm_mday = arr[i].date_creation.day;
		gameInfo.tm_mon = arr[i].date_creation.month - 1;
		gameInfo.tm_year = arr[i].date_creation.year - 1900;
		time_t secondsGame = mktime(&gameInfo);
		difference = secondsTmp - secondsGame;
		if (difference <= 2678400) {
			counter++;
		}
	}
	if (counter > 0) {
		cout << "Свежие релизы игр:\n\n";
		size1 = counter;
		if (arr1 != NULL) {
			delete[]arr1;
		}
		arr1 = new Game[size1];
		counter = 0;
		for (int i = 0; i < size; i++)
		{
			gameInfo.tm_mday = arr[i].date_creation.day;
			gameInfo.tm_mon = arr[i].date_creation.month - 1;
			gameInfo.tm_year = arr[i].date_creation.year - 1900;
			time_t secondsGame = mktime(&gameInfo);
			difference = secondsTmp - secondsGame;
			if (difference <= 2678400) {
				arr1[counter] = arr[i];
				counter++;
			}
		}
	}
}

void del_game(Game*& arr, int& size, int index) {
	Game* tmp = new Game[size - 1];
	int a = 0;
	for (int i = 0; i < size; i++)
	{
		if (i != index) {
			tmp[a] = arr[i];
			a++;
		}
	}
	size--;
	if (size == 0) {
		arr = nullptr;
	}
	else {
		if (arr != nullptr) delete[] arr;
		arr = tmp;
	}
	cout << "Игра удалена.\n";
}

//функции сортировки

int sort_arr_game_by_alphabet(Game* arr, int size) {
	int menu,number;
	Game* tmp = new Game[size];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			for (int k = 0; k < strlen(arr[j].name.str); k++)
			{
				if (int(tmp[j].name.str[k]) > int(tmp[j + 1].name.str[k]))
				{
					Game b = tmp[j];
					tmp[j] = tmp[j + 1];
					tmp[j + 1]=b;
					break;
				}
			}
		}
	}
	print_arr_game(tmp, size);

	do { // error ++ 
		cout << "1. Детальнее.\n"; //+ //+
		cout << "2. <-- Вернуться.\n"; //+ //+
		cout << "\nВаш выбор: ";
		cin >> menu;
		cout << endl;
		switch (menu)
		{
		case 1:
			cout << "Введите номер игры: ";
			cin >> number;
			cout << endl;
			if (number > size || number < 0) {
				system("color 04");
				cout << "Ошибка ввода.\n\n";
				Sleep(2000);
				system("color 07");
			}
			else {
				number -= 1;
				for (int i = 0; i < size; i++)
				{
					if (strcmp(arr[i].name.str, tmp[number].name.str) == 0) {
						number = i;
						break;
					}
				}
				return number;
			}
			break;
		case 2:
			return -1;
			break;
		default:
			system("color 04");
			cout << "Ошибка ввода.\n\n";
			Sleep(2000);
			system("color 07");
			break;
		}
	} while (menu != 2);
}

int sort_arr_game_by_developer(Game* arr, int size) {
	int menu, number=0;
	Game* tmp = new Game[size];
	char developerStr[100];
	int a = 0;
	for (int i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}
	do { 
		strcpy_s(developerStr, 100, tmp[a].developer.str);
		cout << "Игры от " << developerStr << ":\n\n";
		for (int i = a; i < size; i++)
		{
			if (strcmp(tmp[i].developer.str, developerStr) == 0) {
				cout << a+1<<".\n";
				Game b = tmp[i];
				tmp[i] = tmp[a];
				tmp[a] = b;
				tmp[a].print_game();
				cout << endl;
				a++;
			}
		}
		cout <<"======================================\n";
	} while (a <= size - 1);

	do { // error ++ 
		cout << "1. Детальнее.\n"; //+ //+
		cout << "2. <-- Вернуться.\n"; //+ //+
		cout << "\nВаш выбор: ";
		cin >> menu;
		cout << endl;
		switch (menu)
		{
		case 1:
			cout << "Введите номер игры: ";
			cin >> number;
			cout << endl;
			if (number > size || number < 0) {
				system("color 04");
				cout << "Ошибка ввода.\n\n";
				Sleep(2000);
				system("color 07");
			}
			else {
				number -= 1;
				for (int i = 0; i < size; i++)
				{
					if (strcmp(arr[i].name.str, tmp[number].name.str) == 0) {
						number = i;
						break;
					}
				}
				return number;
			}
			break;
		case 2:
			return -1;
			break;
		default:
			system("color 04");
			cout << "Ошибка ввода.\n\n";
			Sleep(2000);
			system("color 07");
			break;
		}
	} while (menu != 2);
}

int sort_arr_game_by_genre(Game* arr, int size) { 
	int menu, number;
	Game* tmp = new Game[size];
	char genreStr[100];
	int a = 0;
	for (int i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}
	do {
		strcpy_s(genreStr, 100, tmp[a].genre.str);
		cout << "Игры в жанре \"" << genreStr << "\":\n\n";
		for (int i = a; i < size; i++)
		{
			if (strcmp(tmp[i].genre.str, genreStr) == 0) {
				cout << a+1 << ".\n";
				Game b = tmp[i];
				tmp[i] = tmp[a];
				tmp[a] = b;
				tmp[a].print_game();
				cout << endl;
				a++;
			}
		}
		cout << "======================================\n";
	} while (a <= size - 1);

	do { // error ++ 
		cout << "1. Детальнее.\n"; //+ //+
		cout << "2. <-- Вернуться.\n"; //+ //+
		cout << "\nВаш выбор: ";
		cin >> menu;
		cout << endl;
		switch (menu)
		{
		case 1:
			cout << "Введите номер игры: ";
			cin >> number;
			cout << endl;
			if (number > size || number < 0) {
				system("color 04");
				cout << "Ошибка ввода.\n\n";
				Sleep(2000);
				system("color 07");
			}
			else {
				number -= 1;
				for (int i = 0; i < size; i++)
				{
					if (strcmp(arr[i].name.str, tmp[number].name.str) == 0) {
						number = i;
						break;
					}
				}
				return number;
			}
			break;
		case 2:
			return -1;
			break;
		default:
			system("color 04");
			cout << "Ошибка ввода.\n\n";
			Sleep(2000);
			system("color 07");
			break;
		}
	} while (menu != 2);
}

int sort_arr_game_by_date(Game* arr, int size) {
	int menu, number;
	int counter = 0;
	Game* tmp = new Game[size];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}
	tm tmp1 = {0};
	time_t secondsTmp1;
	tm tmp2 = {0};
	time_t secondsTmp2;
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			tmp[j].date_creation.copy_date(tmp1);
			secondsTmp1 = mktime(&tmp1);
			tmp[j+1].date_creation.copy_date(tmp2);
			secondsTmp2 = mktime(&tmp2);
			if (secondsTmp1<secondsTmp2) {
				Game b = tmp[j];
				tmp[j] = tmp[j+1];
				tmp[j+1] = b;
			}
			
		}
	}
	print_arr_game(tmp, size);

	do { // error ++ 
		cout << "1. Детальнее.\n"; //+ //+
		cout << "2. <-- Вернуться.\n"; //+ //+
		cout << "\nВаш выбор: ";
		cin >> menu;
		cout << endl;
		switch (menu)
		{
		case 1:
			cout << "Введите номер игры: ";
			cin >> number;
			cout << endl;
			if (number > size || number < 0) {
				system("color 04");
				cout << "Ошибка ввода.\n\n";
				Sleep(2000);
				system("color 07");
			}
			else {
				number -= 1;
				for (int i = 0; i < size; i++)
				{
					if (strcmp(arr[i].name.str, tmp[number].name.str) == 0) {
						number = i;
						break;
					}
				}
				return number;
			}
			break;
		case 2:
			return -1;
			break;
		default:
			system("color 04");
			cout << "Ошибка ввода.\n\n";
			Sleep(2000);
			system("color 07");
			break;
		}
	} while (menu != 2);
}

int sort_arr_game_by_rating(Game* arr, int size) {
	int menu, number;
	Game* tmp = new Game[size];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (tmp[j].rating < tmp[j+1].rating)
			{
				Game b = tmp[j];
				tmp[j] = tmp[j + 1];
				tmp[j + 1] = b;
			}
		}
	}
	print_arr_game(tmp, size);

	do { // error ++ 
		cout << "1. Детальнее.\n"; //+ //+
		cout << "2. <-- Вернуться.\n"; //+ //+
		cout << "\nВаш выбор: ";
		cin >> menu;
		cout << endl;
		switch (menu)
		{
		case 1:
			cout << "Введите номер игры: ";
			cin >> number;
			cout << endl;
			if (number > size || number < 0) {
				system("color 04");
				cout << "Ошибка ввода.\n\n";
				Sleep(2000);
				system("color 07");
			}
			else {
				number -= 1;
				for (int i = 0; i < size; i++)
				{
					if (strcmp(arr[i].name.str, tmp[number].name.str) == 0) {
						number = i;
						break;
					}
				}
				return number;
			}
			break;
		case 2:
			return -1;
			break;
		default:
			system("color 04");
			cout << "Ошибка ввода.\n\n";
			Sleep(2000);
			system("color 07");
			break;
		}
	} while (menu != 2);
}

int sort_arr_game_by_price(Game* arr, int size) {
	int menu, number;
	Game* tmp = new Game[size];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (tmp[j].price < tmp[j + 1].price)
			{
				Game b = tmp[j];
				tmp[j] = tmp[j + 1];
				tmp[j + 1] = b;
			}
		}
	}
	print_arr_game(tmp, size);

	do { // error ++ 
		cout << "1. Детальнее.\n"; //+ //+
		cout << "2. <-- Вернуться.\n"; //+ //+
		cout << "\nВаш выбор: ";
		cin >> menu;
		cout << endl;
		switch (menu)
		{
		case 1:
			cout << "Введите номер игры: ";
			cin >> number;
			cout << endl;
			if (number > size || number < 0) {
				system("color 04");
				cout << "Ошибка ввода.\n\n";
				Sleep(2000);
				system("color 07");
			}
			else {
				number -= 1;
				for (int i = 0; i < size; i++)
				{
					if (strcmp(arr[i].name.str, tmp[number].name.str) == 0) {
						number = i;
						break;
					}
				}
				return number;
			}
			break;
		case 2:
			return -1;
			break;
		default:
			system("color 04");
			cout << "Ошибка ввода.\n\n";
			Sleep(2000);
			system("color 07");
			break;
		}
	} while (menu != 2);
}

int sort_arr_game_by_weight(Game* arr, int size) {
	int menu, number;
	Game* tmp = new Game[size];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (tmp[j].weight < tmp[j + 1].weight)
			{
				Game b = tmp[j];
				tmp[j] = tmp[j + 1];
				tmp[j + 1] = b;
			}
		}
	}
	print_arr_game(tmp, size);

	do { // error ++ 
		cout << "1. Детальнее.\n"; //+ //+
		cout << "2. <-- Вернуться.\n"; //+ //+
		cout << "\nВаш выбор: ";
		cin >> menu;
		cout << endl;
		switch (menu)
		{
		case 1:
			cout << "Введите номер игры: ";
			cin >> number;
			cout << endl;
			if (number > size || number < 0) {
				system("color 04");
				cout << "Ошибка ввода.\n\n";
				Sleep(2000);
				system("color 07");
			}
			else {
				number -= 1;
				for (int i = 0; i < size; i++)
				{
					if (strcmp(arr[i].name.str, tmp[number].name.str) == 0) {
						number = i;
						break;
					}
				}
				return number;
			}
			break;
		case 2:
			return -1;
			break;
		default:
			system("color 04");
			cout << "Ошибка ввода.\n\n";
			Sleep(2000);
			system("color 07");
			break;
		}
	} while (menu != 2);
}

//функции поиска

int find_in_arr_game_name(Game* arr, int size,char* name) {
	int menu, number;
	Game* tmp = nullptr;
	bool was_printed1 = false;
	int counter=0,counter1=0;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(arr[i].name.str, name) == 0) {
			counter1++;
		}
	}
	if (counter1 == 0) {
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < strlen(name); j++)
			{
				for (int k = 0; k < strlen(arr[i].name.str); k++)
				{
					if (name[j] == arr[i].name.str[k]) {
						counter++;
						break;
					}
				}

			}
			if (counter > strlen(arr[i].name.str) / 2) {
				counter1++;
			}
			counter = 0;
		}
	}
	if (counter1 == 0) {
		cout << "К сожалению, у нас нет игр с похожим названием.\n\n";
		return -2;
	}
	else {
		tmp = new Game[counter1];
		for (int i = 0; i < size; i++)
		{
			if (strcmp(arr[i].name.str, name) == 0) {
				if (was_printed1 == false) {
					cout << "Игры с названием \"" << name << "\" ("<<counter1<<"):\n\n";
					was_printed1 = true;
					counter1 = 0;
				}
				cout << counter1+1 << ".\n";
				arr[i].print_game();
				cout << endl;
				counter++;
				tmp[counter1] = arr[i];
				counter1++;
			}
		}
		if (counter == 0) {
			bool was_printed2 = false;
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < strlen(name); j++)
				{
					for (int k = 0; k < strlen(arr[i].name.str); k++)
					{
						if (name[j] == arr[i].name.str[k]) {
							counter++;
							break;
						}
					}

				}
				if (counter > strlen(arr[i].name.str) / 2) {
					if (was_printed2 == false) {
						cout << "Похоже, игр с названием \"" << name << "\" нет, но может вы искали это:\n\n";
						was_printed2 = true;
						counter1 = 0;
					}
					cout << counter1 + 1 << ".\n";
					arr[i].print_game();
					cout << endl;
					tmp[counter1] = arr[i];
					counter1++;
				}
				counter = 0;
			}
		}

		do { // error ++ 
			cout << "1. Детальнее.\n"; //+ //+
			cout << "2. <-- Вернуться.\n"; //+ //+
			cout << "\nВаш выбор: ";
			cin >> menu;
			cout << endl;
			switch (menu)
			{
			case 1:
				cout << "Введите номер игры: ";
				cin >> number;
				cout << endl;
				if (number > counter1 + 1 || number < 0) {
					system("color 04");
					cout << "Ошибка ввода.\n\n";
					Sleep(2000);
					system("color 07");
				}
				else {
					number -= 1;
					for (int i = 0; i < size; i++)
					{
						if (strcmp(arr[i].name.str, tmp[number].name.str) == 0) {
							number = i;
							break;
						}
					}
					return number;
				}
				break;
			case 2:
				return -1;
				break;
			default:
				system("color 04");
				cout << "Ошибка ввода.\n\n";
				Sleep(2000);
				system("color 07");
				break;
			}
		} while (menu != 2);
	}
}

int find_in_arr_game_developer(Game* arr, int size, char* developer) {
	int menu, number;
	Game* tmp = nullptr;
	bool was_printed1 = false;
	int counter = 0, counter1 = 0;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(arr[i].developer.str, developer) == 0) {
			counter1++;
		}
	}
	if (counter1 == 0) {
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < strlen(developer); j++)
			{
				for (int k = 0; k < strlen(arr[i].developer.str); k++)
				{
					if (developer[j] == arr[i].developer.str[k]) {
						counter++;
						break;
					}
				}

			}
			if (counter > strlen(arr[i].developer.str) / 2) {
				counter1++;
			}
			counter = 0;
		}
	}
	if (counter1 == 0) {
		cout << "К сожалению, у нас нет игр от этого разработчика.\n\n";
		return -2;
	}
	else {
		tmp = new Game[counter1];
		for (int i = 0; i < size; i++)
		{
			if (strcmp(arr[i].developer.str, developer) == 0) {
				if (was_printed1 == false) {
					cout << "Игры от " << developer << " (" << counter1 << "):\n\n";
					was_printed1 = true;
					counter1 = 0;
				}
				cout << counter1 + 1 << ".\n";
				arr[i].print_game();
				cout << endl;
				counter++;
				tmp[counter1] = arr[i];
				counter1++;
			}
		}
		if (counter == 0) {
			bool was_printed2 = false;
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < strlen(developer); j++)
				{
					for (int k = 0; k < strlen(arr[i].developer.str); k++)
					{
						if (developer[j] == arr[i].developer.str[k]) {
							counter++;
							break;
						}
					}

				}
				if (counter > strlen(arr[i].developer.str) / 2) {
					if (was_printed2 == false) {
						cout << "Похоже, игр от " << developer << " нет, но может вы искали это:\n\n";
						was_printed2 = true;
						counter1 = 0;
					}
					cout << counter1 + 1 << ".\n";
					arr[i].print_game();
					cout << endl;
					tmp[counter1] = arr[i];
					counter1++;
				}
				counter = 0;
			}
		}

		do { // error ++ 
			cout << "1. Детальнее.\n"; //+ //+
			cout << "2. <-- Вернуться.\n"; //+ //+
			cout << "\nВаш выбор: ";
			cin >> menu;
			cout << endl;
			switch (menu)
			{
			case 1:
				cout << "Введите номер игры: ";
				cin >> number;
				cout << endl;
				if (number > counter1 + 1 || number < 0) {
					system("color 04");
					cout << "Ошибка ввода.\n\n";
					Sleep(2000);
					system("color 07");
				}
				else {
					number -= 1;
					for (int i = 0; i < size; i++)
					{
						if (strcmp(arr[i].name.str, tmp[number].name.str) == 0) {
							number = i;
							break;
						}
					}
					return number;
				}
				break;
			case 2:
				return -1;
				break;
			default:
				system("color 04");
				cout << "Ошибка ввода.\n\n";
				Sleep(2000);
				system("color 07");
				break;
			}
		} while (menu != 2);
	}
}

int find_in_arr_game_genre(Game* arr, int size, char* genre) {
	int menu, number;
	Game* tmp = nullptr;
	bool was_printed1 = false;
	int counter = 0, counter1 = 0;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(arr[i].genre.str, genre) == 0) {
			counter1++;
		}
	}
	if (counter1 == 0) {
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < strlen(genre); j++)
			{
				for (int k = 0; k < strlen(arr[i].genre.str); k++)
				{
					if (genre[j] == arr[i].genre.str[k]) {
						counter++;
						break;
					}
				}

			}
			if (counter > strlen(arr[i].genre.str) / 2) {
				counter1++;
			}
			counter = 0;
		}
	}
	if (counter1 == 0) {
		cout << "К сожалению, у нас нет игр в этом жанре.\n\n";
		return -2;
	}
	else {
		tmp = new Game[counter1];
		for (int i = 0; i < size; i++)
		{
			if (strcmp(arr[i].genre.str, genre) == 0) {
				if (was_printed1 == false) {
					cout << "Игры в жанре \"" << genre << "\""<<counter1<<":\n\n";
					was_printed1 = true;
					counter1 = 0;
				}
				cout << counter1 + 1 << ".\n";
				arr[i].print_game();
				cout << endl;
				counter++;
				tmp[counter1] = arr[i];
				counter1++;
			}
		}
		if (counter == 0) {
			bool was_printed2 = false;
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < strlen(genre); j++)
				{
					for (int k = 0; k < strlen(arr[i].genre.str); k++)
					{
						if (genre[j] == arr[i].genre.str[k]) {
							counter++;
							break;
						}
					}

				}
				if (counter > strlen(arr[i].genre.str) / 2) {
					if (was_printed2 == false) {
						cout << "Похоже, игр в жанре \"" << genre << "\" нет, но может вы искали это:\n\n";
						was_printed2 = true;
						counter1 = 0;
					}
					cout << counter1 + 1 << ".\n";
					arr[i].print_game();
					cout << endl;
					tmp[counter1] = arr[i];
					counter1++;
				}
				counter = 0;
			}
		}

		do { // error ++ 
			cout << "1. Детальнее.\n"; //+ //+
			cout << "2. <-- Вернуться.\n"; //+ //+
			cout << "\nВаш выбор: ";
			cin >> menu;
			cout << endl;
			switch (menu)
			{
			case 1:
				cout << "Введите номер игры: ";
				cin >> number;
				cout << endl;
				if (number > counter1 + 1 || number < 0) {
					system("color 04");
					cout << "Ошибка ввода.\n\n";
					Sleep(2000);
					system("color 07");
				}
				else {
					number -= 1;
					for (int i = 0; i < size; i++)
					{
						if (strcmp(arr[i].name.str, tmp[number].name.str) == 0) {
							number = i;
							break;
						}
					}
					return number;
				}
				break;
			case 2:
				return -1;
				break;
			default:
				system("color 04");
				cout << "Ошибка ввода.\n\n";
				Sleep(2000);
				system("color 07");
				break;
			}
		} while (menu != 2);
	}
}

int find_in_arr_game_date(Date date1, Date date2, Game* arr, int size) {
	int menu, number,counter=0;
	Game* tmp = nullptr;
	tm tmpInfo = { 0 };
	date1.copy_date(tmpInfo);
	time_t secondsTmp = mktime(&tmpInfo);
	tm tmpInfo1 = { 0 };
	date2.copy_date(tmpInfo1);
	time_t secondsTmp1 = mktime(&tmpInfo1);
	time_t seconds_tmp;
	if (secondsTmp > secondsTmp1) {
		seconds_tmp = secondsTmp;
		secondsTmp = secondsTmp1;
		secondsTmp1 = seconds_tmp;
	}
	tm arrInfo = { 0 };
	time_t seconds_arr;
	bool found = false;
	for (int i = 0; i < size; i++)
	{
		arr[i].date_creation.copy_date(arrInfo);
		seconds_arr = mktime(&arrInfo);
		if (seconds_arr >= secondsTmp && seconds_arr <= secondsTmp1) {
			counter++;
		}
	}
	if (counter==0) {
		cout << "К сожалению, у нас нет игр с датой выхода в этом промежутке.\n\n";
		return -2;
	}
	else {
		tmp = new Game[counter];
		for (int i = 0; i < size; i++)
		{
			arr[i].date_creation.copy_date(arrInfo);
			seconds_arr = mktime(&arrInfo);
			if (seconds_arr >= secondsTmp && seconds_arr <= secondsTmp1) {
				if (found == false) {
					cout << "Игры, релиз которых состоялся между ";
					date1.printDate();
					cout << " и ";
					date2.printDate();
					found = true;
					cout << " ("<<counter<<"):\n\n";
					counter = 0;
				}
				cout << counter + 1 << ".\n";
				arr[i].print_game();
				cout << endl;
				tmp[counter] = arr[i];
				counter++;
			}
		}

		do { // error ++ 
			cout << "1. Детальнее.\n"; //+ //+
			cout << "2. <-- Вернуться.\n"; //+ //+
			cout << "\nВаш выбор: ";
			cin >> menu;
			cout << endl;
			switch (menu)
			{
			case 1:
				cout << "Введите номер игры: ";
				cin >> number;
				cout << endl;
				if (number > counter + 1 || number < 0) {
					system("color 04");
					cout << "Ошибка ввода.\n\n";
					Sleep(2000);
					system("color 07");
				}
				else {
					number -= 1;
					for (int i = 0; i < size; i++)
					{
						if (strcmp(arr[i].name.str, tmp[number].name.str) == 0) {
							number = i;
							break;
						}
					}
					return number;
				}
				break;
			case 2:
				return -1;
				break;
			default:
				system("color 04");
				cout << "Ошибка ввода.\n\n";
				Sleep(2000);
				system("color 07");
				break;
			}
		} while (menu != 2);
	}
}

int find_in_arr_game_rating(Game* arr, int size, float rating1, float rating2) {
	int menu, number, counter = 0;
	Game* tmp = nullptr;
	float rating_tmp;
	if (rating1 > rating2) {
		rating_tmp = rating1;
		rating1 = rating2;
		rating2 = rating_tmp;
	}
	bool found = false;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].rating >= rating1 && arr[i].rating <= rating2) {
			counter++;
		}
	}
	if (counter == 0) {
		cout << "У нас нет игр с таким рейтингом.\n\n";
		return -2;
	}
	else {
		tmp = new Game[counter];
		for (int i = 0; i < size; i++)
		{
			if (arr[i].rating >= rating1 && arr[i].rating <= rating2) {
				if (found == false) {
					cout << "Игры с рейтингом от " << rating1 << " до " << rating2 <<" ("<<counter << "):\n\n";
					found = true;
					counter = 0;
				}
				cout << counter + 1 << ".\n";
				arr[i].print_game();
				cout <<endl;
				tmp[counter] = arr[i];
				counter++;
			}
		}

		do { // error ++ 
			cout << "1. Детальнее.\n"; //+ //+
			cout << "2. <-- Вернуться.\n"; //+ //+
			cout << "\nВаш выбор: ";
			cin >> menu;
			cout << endl;
			switch (menu)
			{
			case 1:
				cout << "Введите номер игры: ";
				cin >> number;
				cout << endl;
				if (number > counter + 1 || number < 0) {
					system("color 04");
					cout << "Ошибка ввода.\n\n";
					Sleep(2000);
					system("color 07");
				}
				else {
					number -= 1;
					for (int i = 0; i < size; i++)
					{
						if (strcmp(arr[i].name.str, tmp[number].name.str) == 0) {
							number = i;
							break;
						}
					}
					return number;
				}
				break;
			case 2:
				return -1;
				break;
			default:
				system("color 04");
				cout << "Ошибка ввода.\n\n";
				Sleep(2000);
				system("color 07");
				break;
			}
		} while (menu != 2);
	}
}

int find_in_arr_game_price(Game* arr, int size, float price1, float price2) {
	int menu, number, counter = 0;
	Game* tmp = nullptr;
	float price_tmp;
	if (price1 > price2) {
		price_tmp = price1;
		price1 = price2;
		price2 = price_tmp;
	}
	bool found = false;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].price >= price1 && arr[i].price <= price2) {
			counter++;
		}
	}
	if (counter == 0) {
		cout << "У нас нет игр в такой ценовой категории.\n\n";
		return -2;
	}
	else {
		tmp = new Game[counter];
		for (int i = 0; i < size; i++)
		{
			if (arr[i].price >= price1 && arr[i].price <= price2) {
				if (found == false) {
					cout << "Игры в ценовой категории от " << price1 << "$ до " << price2 << "$ (" << counter<<"):\n\n";
					found = true;
					counter = 0;
				}
				cout << counter + 1 << ".\n";
				arr[i].print_game();
				cout << endl;
				tmp[counter] = arr[i];
				counter++;
			}
		}

		do { // error ++ 
			cout << "1. Детальнее.\n"; //+ //+
			cout << "2. <-- Вернуться.\n"; //+ //+
			cout << "\nВаш выбор: ";
			cin >> menu;
			cout << endl;
			switch (menu)
			{
			case 1:
				cout << "Введите номер игры: ";
				cin >> number;
				cout << endl;
				if (number > counter + 1 || number < 0) {
					system("color 04");
					cout << "Ошибка ввода.\n\n";
					Sleep(2000);
					system("color 07");
				}
				else {
					number -= 1;
					for (int i = 0; i < size; i++)
					{
						if (strcmp(arr[i].name.str, tmp[number].name.str) == 0) {
							number = i;
							break;
						}
					}
					return number;
				}
				break;
			case 2:
				return -1;
				break;
			default:
				system("color 04");
				cout << "Ошибка ввода.\n\n";
				Sleep(2000);
				system("color 07");
				break;
			}
		} while (menu != 2);
	}
}

int find_in_arr_game_weight(Game* arr, int size, float weight1, float weight2) {
	int menu, number, counter = 0;
	Game* tmp = nullptr;
	float weight_tmp;
	if (weight1 > weight2) {
		weight_tmp = weight1;
		weight1 = weight2;
		weight2 = weight_tmp;
	}
	bool found = false;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].weight >= weight1 && arr[i].weight <= weight2) {
			counter++;
		}
	}
	if (counter == 0) {
		cout << "У нас нет игр с таким размером.\n\n";
		return -2;
	}
	else {
		tmp = new Game[counter];
		for (int i = 0; i < size; i++)
		{
			if (arr[i].weight >= weight1 && arr[i].weight <= weight2) {
				if (found == false) {
					cout << "Игры с размером от " << weight1 << " Мб до " << weight2 <<" Мб ("<<counter << "):\n\n";
					found = true;
					counter = 0;
				}
				cout << counter + 1 << ".\n";
				arr[i].print_game();
				cout << endl;
				tmp[counter] = arr[i];
				counter++;
			}
		}

		do { // error ++ 
			cout << "1. Детальнее.\n"; //+ //+
			cout << "2. <-- Вернуться.\n"; //+ //+
			cout << "\nВаш выбор: ";
			cin >> menu;
			cout << endl;
			switch (menu)
			{
			case 1:
				cout << "Введите номер игры: ";
				cin >> number;
				cout << endl;
				if (number > counter + 1 || number < 0) {
					system("color 04");
					cout << "Ошибка ввода.\n\n";
					Sleep(2000);
					system("color 07");
				}
				else {
					number -= 1;
					for (int i = 0; i < size; i++)
					{
						if (strcmp(arr[i].name.str, tmp[number].name.str) == 0) {
							number = i;
							break;
						}
					}
					return number;
				}
				break;
			case 2:
				return -1;
				break;
			default:
				system("color 04");
				cout << "Ошибка ввода.\n\n";
				Sleep(2000);
				system("color 07");
				break;
			}
		} while (menu != 2);
	}
}
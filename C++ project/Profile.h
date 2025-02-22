#pragma once

#include<iostream>;
#include"MyString.h";
#include"Game.h";
#include<Windows.h>;
#include<conio.h>;
using namespace std;

struct Profile {
	MyString name;
	MyString nickname;
	MyString mail;
	MyString country;
	MyString password;
	MyString about_yourself;
	float cash = 0;
	Game* arr_Bought_Games = nullptr;
	int length_arr_Bought_Games = 0;
	Game* arr_Favourite_Games = nullptr;
	int length_arr_Favourite_Games = 0;
	Game* arr_Saved_Games = nullptr;
	int length_arr_Saved_Games = 0;

	void print_profile() {
		cout << "���: " << name.str<<endl;
		cout << "���������������� �������: " << nickname.str << endl;
		cout << "����� ����������� �����: " << mail.str << endl;
		cout << "������: " << country.str << endl;
		cout << "���������� � ����: " << about_yourself.str << endl;
		cout << "������: " << cash << " $\n";
	}

	void save_profile(FILE* fp) {
		fprintf(fp, "%s", name.str);
		fprintf(fp, "\n");
		fprintf(fp, "%s", nickname.str);
		fprintf(fp, "\n");
		fprintf(fp, "%s", mail.str);
		fprintf(fp, "\n");
		fprintf(fp, "%s", country.str);
		fprintf(fp, "\n");
		fprintf(fp, "%s", password.str);
		fprintf(fp, "\n");
		fprintf(fp, "%s", about_yourself.str);
		fprintf(fp, "\n");
		fprintf(fp, "%f", cash);
		fprintf(fp, "\n");
		save_arr_game(fp,arr_Bought_Games, length_arr_Bought_Games);
		save_arr_game(fp,arr_Favourite_Games, length_arr_Favourite_Games);
		save_arr_game(fp,arr_Saved_Games, length_arr_Saved_Games);
	}

	void load_profile(FILE* fp) {
		char tmp[1000];
		fscanf_s(fp, "\n");
		fgets(tmp, 1000, fp);
		name.set_MyString_without_enter(tmp);
		fgets(tmp, 1000, fp);
		nickname.set_MyString_without_enter(tmp);
		fgets(tmp, 1000, fp);
		mail.set_MyString_without_enter(tmp);
		fgets(tmp, 1000, fp);
		country.set_MyString_without_enter(tmp);
		fgets(tmp, 1000, fp);
		password.set_MyString_without_enter(tmp);
		fgets(tmp, 1000, fp);
		about_yourself.set_MyString_without_enter(tmp);
		fscanf_s(fp, "%f ",&cash);
		fscanf_s(fp, "\n");
		load_arr_game(fp, arr_Bought_Games, length_arr_Bought_Games);
		load_arr_game(fp, arr_Favourite_Games, length_arr_Favourite_Games);
		load_arr_game(fp, arr_Saved_Games, length_arr_Saved_Games);
	}

	void change_my_profile() {
		int menu;
		float a;
		char b;
		char tmp[100];
		char tmp1[100];
		cin.ignore();
		for (;;) {
			if (check_password() == true) { // error +
				do {
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
					cout << "(`�._.�(`�._.�(`�._.�(`�._.�(`�._.�(`�._.� Dragon Force �._.�`)�._.�`)�._.�`)�._.�`)�._.�`)�._.�`)";
					for (int i = 0; i < 55; i++)
					{
						cout << " ";
					}
					cout << "|\n";
					SetConsoleTextAttribute(console_color, 15);
					cout << endl<<endl;
					for (int i = 0; i < 211; i++)
					{
						cout << "-";
					}
					cout << endl;
					cout << "1. �������� ���.\n"; //+ //+
					cout << "2. �������� �������.\n"; //+ //+
					cout << "3. �������� �����.\n"; //+ //+
					cout << "4. �������� ������.\n"; //+ //+
					cout << "5. �������� ������.\n"; //+ //+
					cout << "6. �������� ���������� � ����.\n"; //+ //+
					cout << "7. ��������� ����.\n"; //-
					cout << "8. <-- ���������.\n"; //+ //+
					cout << "\n��� �����: ";
					cin >> menu;
					cout << endl;
					switch (menu)
					{
					case 1:
						cout << "������� ����� ���: ";
						cin.ignore();
						cin.getline(tmp, 100);
						name.setMyString(tmp);
						cout << "\n����� ��� ���������.\n\n";
						cout << "������� ���-������ ����� ����������.\n";
						b = _getch();
						break;
					case 2:
						cout << "������� ����� �������: ";
						cin.ignore();
						cin.getline(tmp, 100);
						nickname.setMyString(tmp);
						cout << "\n����� ������� ��������.\n\n";
						cout << "������� ���-������ ����� ����������.\n";
						b = _getch();
						break;
					case 3:
						cout << "������� ����� �������� �����: ";
						cin.ignore();
						cin.getline(tmp, 100);
						mail.setMyString(tmp);
						cout << "\n����� �������� ����� ��������.\n\n";
						cout << "������� ���-������ ����� ����������.\n";
						b = _getch();
						break;
					case 4:
						cout << "������� ������: ";
						cin.ignore();
						cin.getline(tmp, 100);
						country.setMyString(tmp);
						cout << "\n������ ���������.\n\n";
						cout << "������� ���-������ ����� ����������.\n";
						b = _getch();
						break;
					case 5: // error +
						cin.ignore();
						for (;;) {
							cout << "������� ������ (�� 20 ��������): ";
							cin.getline(tmp, 21);
							cout << endl;
							bool letter = false;
							bool numb = false;
							bool upper = false;
							bool lower = false;
							for (int i = 0; i < strlen(tmp); i++)
							{
								if (isalpha(tmp[i]) != 0) {
									letter = true;
								}
								if (isdigit(tmp[i]) != 0) {
									numb = true;
								}
								if (isupper(tmp[i]) != 0) {
									upper = true;
								}
								if (islower(tmp[i]) != 0) {
									lower = true;
								}
							}
							if (letter == 1 && numb == 1 && upper == 1 && lower == 1) {
								password.setMyString(tmp);
								break;
							}
							if (letter == 0) {
								cout << "��� ��������� ������ ����� �����.\n\n";
							}
							if (numb == 0) {
								cout << "��� ��������� ������ ����� �����.\n\n";
							}
							if (upper == 0 || lower == 0) {
								cout << "��� ��������� ������ ����� ����� � ������ ��������.\n\n";
							}
						}
						for (;;) {
							cout << "����������� ������: ";
							cin.getline(tmp1, 21);
							cout << endl;
							if (strcmp(tmp, tmp1) == 0) {
								cout << "����� ������ ��������.\n\n";
								cout << "������� ���-������ ����� ����������.\n";
								b = _getch();
								break;
							}
							else {
								system("color 04");
								cout << "�������� ����.\n";
								Sleep(2000);
								system("color 07");
							}
						}
						break;
					case 6:
						cout << "������� ����� ���������� � ����: ";
						cin.ignore();
						cin.getline(tmp, 100);
						about_yourself.setMyString(tmp);
						cout << "\n���������� ���������.\n\n";
						cout << "������� ���-������ ����� ����������.\n";
						b = _getch();
						break;
					case 7:  // error +
					{
						int menu1;
						cout << "������� �����: ";
						cin >> a;
						if (a < 0) {
							do {
								cout << "1. ����������� ��� ���.\n";
								cout << "2. <-- ���������.\n";
								cout << "\n��� �����: ";
								cin >> menu1;
								cout << endl;
								switch (menu1)
								{
								case 1:
									cout << "������� �����: ";
									cin >> a;
									cash += a;
									if (a >= 0) {
										cout << "\n����� ������� ���������.\n��� ������: " << cash << " $\n\n";
										cout << "������� ���-������ ����� ����������.\n";
										b = _getch();
										menu1 = 2;
									}
									break;
								case 2:
									system("color 04");
									cout << "������ �����.\n\n";
									Sleep(2000);
									system("color 07");
									break;
								default:
									break;
								}
							} while (menu1 != 2);
						}
						else {
							cash += a;
							cout << "\n����� ������� ���������.\n��� ������: " << cash << " $\n\n";
							cout << "������� ���-������ ����� ����������.\n";
							b = _getch();
						}
						break;
					}
					case 8:
						break;
					default:
						system("color 04");
						cout << "������ �����.\n";
						Sleep(2000);
						system("color 07");
						break;
					}
				} while (menu != 8);
				break;
			}
			else {
			    bool flag = false;
				do {
					cout << "�������� ���� ������.\n";
					cout << "\n1. ����������� ��� ���.\n";
					cout << "2. <-- ���������.\n";
					cout << "\n��� �����: ";
					cin >> menu;
					if (menu == 2) {
						flag = true;
					}
					else if (menu == 1) {
						cin.ignore();
						menu = 2;
					}
					else if (menu > 2 || menu < 1) {
						system("color 04");
						cout << "������ �����.\n";
						Sleep(2000);
						system("color 07");
					}
				} while (menu != 2);

				if (flag == true) {
					break;
				}
			}
		}
	}

	void change_profile() {
		int menu;
		float a;
		char b;
		char tmp[100];
		char tmp1[100];
		cin.ignore();
		do {
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
			cout << "(`�._.�(`�._.�(`�._.�(`�._.�(`�._.�(`�._.� Dragon Force �._.�`)�._.�`)�._.�`)�._.�`)�._.�`)�._.�`)";
			for (int i = 0; i < 55; i++)
			{
				cout << " ";
			}
			cout << "|\n";
			SetConsoleTextAttribute(console_color, 15);
			cout << endl<<endl;
			for (int i = 0; i < 211; i++)
			{
				cout << "-";
			}
			cout << endl;
			cout << "1. �������� ���.\n"; //+ //+
			cout << "2. �������� �������.\n"; //+ //+
			cout << "3. �������� �����.\n"; //+ //+
			cout << "4. �������� ������.\n"; //+ //+
			cout << "5. �������� ������.\n"; //+ //+
			cout << "6. �������� ���������� � ����.\n"; //+ //+
			cout << "7. �������� ����.\n"; //-
			cout << "8. <-- ���������.\n"; //+ //+
			cout << "\n��� �����: ";
			cin >> menu;
			cout << endl;
			switch (menu)
			{
			case 1:
				cout << "������� ����� ���: ";
				cin.ignore();
				cin.getline(tmp, 100);
				name.setMyString(tmp);
				cout << "\n����� ��� ���������.\n\n";
				cout << "������� ���-������ ����� ����������.\n";
				b = _getch();
				break;
			case 2:
				cout << "������� ����� �������: ";
				cin.ignore();
				cin.getline(tmp, 100);
				nickname.setMyString(tmp);
				cout << "\n����� ������� ��������.\n\n";
				cout << "������� ���-������ ����� ����������.\n";
				b = _getch();
				break;
			case 3:
				cout << "������� ����� �������� �����: ";
				cin.ignore();
				cin.getline(tmp, 100);
				mail.setMyString(tmp);
				cout << "\n����� �������� ����� ��������.\n\n";
				cout << "������� ���-������ ����� ����������.\n";
				b = _getch();
				break;
			case 4:
				cout << "������� ������: ";
				cin.ignore();
				cin.getline(tmp, 100);
				country.setMyString(tmp);
				cout << "\n������ ���������.\n\n";
				cout << "������� ���-������ ����� ����������.\n";
				b = _getch();
				break;
			case 5: // error +
				cin.ignore();
				for (;;) {
					cout << "������� ������ (�� 20 ��������): ";
					cin.getline(tmp, 21);
					cout << endl;
					bool letter = false;
					bool numb = false;
					bool upper = false;
					bool lower = false;
					for (int i = 0; i < strlen(tmp); i++)
					{
						if (isalpha(tmp[i]) != 0) {
							letter = true;
						}
						if (isdigit(tmp[i]) != 0) {
							numb = true;
						}
						if (isupper(tmp[i]) != 0) {
							upper = true;
						}
						if (islower(tmp[i]) != 0) {
							lower = true;
						}
					}
					if (letter == 1 && numb == 1 && upper == 1 && lower == 1) {
						password.setMyString(tmp);
						break;
					}
					if (letter == 0) {
						cout << "��� ��������� ������ ����� �����.\n\n";
					}
					if (numb == 0) {
						cout << "��� ��������� ������ ����� �����.\n\n";
					}
					if (upper == 0 || lower == 0) {
						cout << "��� ��������� ������ ����� ����� � ������ ��������.\n\n";
					}
				}
				for (;;) {
					cout << "����������� ������: ";
					cin.getline(tmp1, 21);
					cout << endl;
					if (strcmp(tmp, tmp1) == 0) {
						cout << "����� ������ ��������.\n\n";
						cout << "������� ���-������ ����� ����������.\n";
						b = _getch();
						break;
					}
					else {
						system("color 04");
						cout << "�������� ����.\n";
						Sleep(2000);
						system("color 07");
					}
				}
				break;
			case 6:
				cout << "������� ����� ����������: ";
				cin.ignore();
				cin.getline(tmp, 100);
				about_yourself.setMyString(tmp);
				cout << "\n���������� ���������.\n\n";
				cout << "������� ���-������ ����� ����������.\n";
				b = _getch();
				break;
			case 7:  // error +
			{
				int menu1;
				cout << "������� �����: ";
				cin >> a;
				if (a < 0) {
					do {
						cout << "1. ����������� ��� ���.\n";
						cout << "2. <-- ���������.\n";
						cout << "\n��� �����: ";
						cin >> menu1;
						cout << endl;
						switch (menu1)
						{
						case 1:
							cout << "������� �����: ";
							cin >> a;
							cash += a;
							if (a >= 0) {
								cout << "\n����� ��������.\n������: " << cash << " $\n\n";
								cout << "������� ���-������ ����� ����������.\n";
								b = _getch();
								menu1 = 2;
							}
							break;
						case 2:
							system("color 04");
							cout << "������ �����.\n\n";
							Sleep(2000);
							system("color 07");
							break;
						default:
							break;
						}
					} while (menu1 != 2);
				}
				else {
					cash = a;
					cout << "\n����� ��������.\n������: " << cash << " $\n\n";
					cout << "������� ���-������ ����� ����������.\n";
					b = _getch();
				}
				break;
			}
			case 8:
				break;
			default:
				system("color 04");
				cout << "������ �����.\n";
				Sleep(2000);
				system("color 07");
				break;
			}
		} while (menu != 8);
	}

	bool check_password() {
		char tmp[100];
		cout << "\n������� ������: ";
		cin.getline(tmp, 100);
		if (strcmp(tmp, password.str) == 0) {
			return true;
		}
		else {
			return false;
		}
	}
};

//�������

void add_profile(Profile*& arr, int& size) {
	Profile* tmp = new Profile[size + 1];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}
	cout << "������� ������ � ����� ������������:\n";
	//tmp[size].register_profile();
	size++;
	if (arr != nullptr) delete[] arr;
	arr = tmp;
}

void del_profile(Profile*& arr, int& size, int index) {
	Profile* tmp = new Profile[size - 1];
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
	cout << "������� ������.\n";
}

void save_arr_profile(FILE* fp, Profile* arr, int size,int index) {
	fprintf(fp, "%d", index);
	fprintf(fp, "\n");
	//��� ���������� ������� � ���� ������ ��������� ��� �����������!
	fprintf(fp, "%d", size);
	fprintf(fp, "\n");
	if (size > 0) {
		for (int i = 0; i < size; i++)
		{
			arr[i].save_profile(fp);
		}
	}
}

void load_arr_profile(FILE* fp, Profile*& arr, int& size,int &index) {
	fscanf_s(fp, "%d", &index);
	fscanf_s(fp, "\n");
	fscanf_s(fp, "%d", &size);
	if (size > 0) {
		arr = new Profile[size];
		for (int i = 0; i < size; i++)
		{
			arr[i].load_profile(fp);
		}
	}
	else {
		arr = nullptr;
		size = 0;
		return;
	}
}

void print_arr_profile(Profile* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ". ";
		arr[i].print_profile();
		cout << endl;
	}
	cout << "=========================\n";
}

int print_arr_profile_1(Profile* arr, int size) {
	int menu, number;
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ".\n";
		arr[i].print_profile();
		cout << endl;
	}
	cout << "=========================\n";

	do { // error ++ 
		cout << "1. ���������.\n"; //+ //+
		cout << "2. <-- ���������.\n"; //+ //+
		cout << "\n��� �����: ";
		cin >> menu;
		cout << endl;
		switch (menu)
		{
		case 1:
			cout << "������� ����� �������: ";
			cin >> number;
			if (number > size || number < 0) {
				cout << "������.\n";
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
			cout << "������ �����.\n";
			Sleep(2000);
			system("color 07");
			break;
		}
	} while (menu != 2);
}

void sign_in(Profile* arr, int size, int& index) {
	char tmp[100];
	bool found = false;
	int menu = -1, ind;
	do {
		found = false;
		cout << "������� �������: ";
		cin.ignore();
		cin.getline(tmp, 100);
		for (int i = 0; i < size; i++)
		{
			if (strcmp(tmp, arr[i].nickname.str) == 0) {
				ind = i;
				found = true;
				break;
			}
		}
		if (found == true) {  // error ++
			for (;;) {
				if (arr[ind].check_password() == true) {
					cout << "\n����� ���������� � DragonForce!\n";
					index = ind;
					char a;
					cout << "\n������� ���-������ ����� ����������.\n";
					a = _getch();
					menu = 2;
					break;
				}
				else {
					cout << "�������� ���� ������.\n";
					cout << "\n1. ����������� ��� ���.\n"; //+ //+
					cout << "2. <-- ���������.\n"; //+ //+
					cout << "\n��� �����: ";
					cin >> menu;
					cout << endl;
					if (menu > 2 || menu < 1) {
						system("color 04");
						cout << "������ �����.\n\n";
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
				cout << "������������ � ����� ������ �� ������.\n";
				cout << "\n1. ����������� ��� ���.\n"; //+ //+
				cout << "2. <-- ���������.\n"; //+ //+
				cout << "\n��� �����: ";
				cin >> menu;
				if (menu > 2 || menu < 1) {
					system("color 04");
					cout << "������ �����.\n";
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

void register_profile(Profile*& arr, int& size, int& index) {
	Profile* tmp_arr = new Profile[size + 1];
	for (int i = 0; i < size; i++)
	{
		tmp_arr[i] = arr[i];
	}
	char tmp[100] = "";
	char tmp1[100] = "";
	cin.ignore();
	cout << "������� ������ ���: ";
	cin.getline(tmp, 100);
	cout << endl;
	tmp_arr[size].name.setMyString(tmp);
	cout << "������� ���������������� �������: ";
	cin.getline(tmp, 100);
	cout << endl;
	tmp_arr[size].nickname.setMyString(tmp);
	cout << "������� ����� ����������� �����: ";
	cin.getline(tmp, 100);
	cout << endl;
	tmp_arr[size].mail.setMyString(tmp);
	cout << "������� ������ ����������: ";
	cin.getline(tmp, 100);
	cout << endl;
	tmp_arr[size].country.setMyString(tmp);
	tmp_arr[size].country.toFisrtUpper();
	for (;;) {  // error ++
		cout << "������� ������ (�� 20 ��������): ";
		cin.getline(tmp, 21);
		cout << endl;
		bool letter = false;
		bool numb = false;
		bool upper = false;
		bool lower = false;
		for (int i = 0; i < strlen(tmp); i++)
		{
			if (isalpha(tmp[i]) != 0) {
				letter = true;
			}
			if (isdigit(tmp[i]) != 0) {
				numb = true;
			}
			if (isupper(tmp[i]) != 0) {
				upper = true;
			}
			if (islower(tmp[i]) != 0) {
				lower = true;
			}
		}
		if (letter == 1 && numb == 1 && upper == 1 && lower == 1) {
			tmp_arr[size].password.setMyString(tmp);
			break;
		}
		if (letter == 0) {
			cout << "��� ��������� ������ ����� �����.\n\n";
		}
		if (numb == 0) {
			cout << "��� ��������� ������ ����� �����.\n\n";
		}
		if (upper == 0 || lower == 0) {
			cout << "��� ��������� ������ ����� ����� � ������ ��������.\n\n";
		}
	}
	for (;;) {
		cout << "����������� ������: ";
		cin.getline(tmp1, 21);
		cout << endl;
		if (strcmp(tmp, tmp1) == 0) {
			break;
		}
		else { 
			system("color 04");
			cout << "������ �����.\n\n";
			Sleep(2000);
			system("color 07");
		}
	}
	cout << "������� ������� ���������� � ���� (�� 1000 ��������): ";
	cin.getline(tmp, 1000);
	tmp_arr[size].about_yourself.setMyString(tmp);
	cout << endl;
	size++;
	if (arr != nullptr) delete[] arr;
	arr = tmp_arr;
	index = size - 1;
}
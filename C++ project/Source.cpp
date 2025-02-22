// DragonForce

/* Записочки

1. Длина полного экрана - 211 "-".
2. В названии 11 букв.

*/

#include"Profile.h";
#include"Game.h";
#include<Windows.h>;
#include<conio.h>;
#include"Admin.h";
using namespace std;

void print_DragonForce() {
	HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << endl;
	for (int i = 0; i < 211; i++)
	{
		cout << "-";
	}
	cout<<endl;
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
	cout << endl;
}

void present_game(Profile* &arr_pr, Game* &arr_gm, int size_pr, int &size_gm, int index_pr, int index_gm) {
	int menu;
	char tmp[10];
	do { // error ++ 
		system("cls");
		print_DragonForce();
		cout << endl;
		arr_gm[index_gm].print_game();
		cout << "===================================\n\n";
		cout << "1. Купить игру.\n"; //+ //+
		cout << "2. Добавить в избранное.\n"; //+ //+
		cout << "3. Сохранить игру.\n"; //+ //+
		cout << "4. <-- Вернуться.\n"; //+ //+
		cout << "\nВаш выбор: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
		{
			if (index_pr != -1) {
				bool found = false;
				for (int i = 0; i < arr_pr[index_pr].length_arr_Bought_Games; i++)
				{
					if (strcmp(arr_gm[index_gm].name.str, arr_pr[index_pr].arr_Bought_Games[i].name.str) == 0) {
						found = true;
					}
				}
				if (found == false) { 
					if (arr_pr[index_pr].cash >= arr_gm[index_gm].price) { // error ++
						for (;;) {
							cout << "Вы точно хотите купить эту игру?\n(Да/нет): ";
							cin >> tmp;
							if (strcmp(tmp, "Да") == 0 || strcmp(tmp, "да") == 0) {
								add_existing_game(arr_pr[index_pr].arr_Bought_Games, arr_pr[index_pr].length_arr_Bought_Games, arr_gm[index_gm]);
								arr_pr[index_pr].cash -= arr_gm[index_gm].price;
								cout << "У вас куплена 1 новая игра!\nОсталось средств: " << arr_pr[index_pr].cash << " $\n";
								char a;
								cout << "\nНажмите что-нибудь чтобы продолжить.\n";
								a = _getch();
								break;
							}
							else if (strcmp(tmp, "нет") != 0 && strcmp(tmp, "Нет") != 0) {
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
					else {
						cout << "Не хватает средств на счету.\n";
						char a;
						cout << "\nНажмите что-нибудь чтобы продолжить.\n";
						a = _getch();
					}
				}
				else {
					cout << "У вас уже эта игра куплена.\n";
					char a;
					cout << "\nНажмите что-нибудь чтобы продолжить.\n";
					a = _getch();
				}
			}
			else {
				cout << "Вы еще не вошли в систему.\n";
				char a;
				cout << "\nНажмите что-нибудь чтобы продолжить.\n";
				a = _getch();
			}
			break;
		}
		case 2:
		{
			if (index_pr != -1) {
				bool found1 = false;
				for (int i = 0; i < arr_pr[index_pr].length_arr_Favourite_Games; i++)
				{
					if (strcmp(arr_gm[index_gm].name.str, arr_pr[index_pr].arr_Favourite_Games[i].name.str) == 0) {
						found1 = true;
					}
				}
				if (found1 == false) {
					bool found = false;
					for (int i = 0; i < arr_pr[index_pr].length_arr_Bought_Games; i++)
					{
						if (strcmp(arr_pr[index_pr].arr_Bought_Games[i].name.str, arr_gm[index_gm].name.str) == 0) {
							add_existing_game(arr_pr[index_pr].arr_Favourite_Games, arr_pr[index_pr].length_arr_Favourite_Games, arr_gm[index_gm]);
							cout << "Игра добавлена в \"Избранное\".\n";
							found = true;
							char a;
							cout << "\nНажмите что-нибудь чтобы продолжить.\n";
							a = _getch();
							break;
						}
					}
					if (found == false) {
						cout << "Игру можно добавлять в \"Избранное\" если она у вас куплена. ";
						char a;
						cout << "\nНажмите что-нибудь чтобы продолжить.\n";
						a = _getch();
					}
				}
				else {
					cout << "У вас уже эта игра добавлена в \"Избранное\".\n";
					char a;
					cout << "\nНажмите что-нибудь чтобы продолжить.\n";
					a = _getch();
				}
			}
			else {
				cout << "Вы еще не вошли в систему.\n";
				char a;
				cout << "\nНажмите что-нибудь чтобы продолжить.\n";
				a = _getch();
			}
			break;
		}
		case 3:
		{
			if (index_pr != -1) {
				bool found = false;
				for (int i = 0; i < arr_pr[index_pr].length_arr_Saved_Games; i++)
				{
					if (strcmp(arr_gm[index_gm].name.str, arr_pr[index_pr].arr_Saved_Games[i].name.str) == 0) {
						found = true;
					}
				}
				if (found == false) {
					add_existing_game(arr_pr[index_pr].arr_Saved_Games, arr_pr[index_pr].length_arr_Saved_Games, arr_gm[index_gm]);
					cout << "Игра сохранена.\n";
					char a;
					cout << "\nНажмите что-нибудь чтобы продолжить.\n";
					a = _getch();
				}
				else {
					cout << "У вас уже эта игра сохранена.\n";
					char a;
					cout << "\nНажмите что-нибудь чтобы продолжить.\n";
					a = _getch();
				}
			}
			else {
				cout << "Вы еще не вошли в систему.\n";
				char a;
				cout << "\nНажмите что-нибудь чтобы продолжить.\n";
				a = _getch();
			}
			break;
		}
		case 4:
			break;
		default:
			system("color 04");
			cout << "Ошибка ввода.";
			Sleep(2000);
			system("color 07");
			break;
		}
	} while (menu != 4);
}

int main() {
	setlocale(0, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	int menu;
	int menuProfile;
	int menuProfile_1;
	int menu_profile_sign_in;
	int menuShop;
	int menuShop_1;
	int menuShop_2;
	int menuAdmin;
	int menuAdmin1;
	Game* arr_Game = nullptr;
	int size_arr_Game = 0;
	Game* arr_newest_Games = nullptr;
	int size_arr_newest_Games = 0;
	Profile* arr_Profile = nullptr;
	int size_arr_Profile = 0;
	Admin* arr_Admin = nullptr;
	int size_arr_Admin = 0;
	int index_my_profile = 1;
	int index_my_admin = -1;
	FILE* fp;
	bool profile_was_loaded = false;

	//вспомогательные переменные
	char str[100];
	Date date_tmp;
	Date date_tmp1;
	float float_variable = 0;
	float float_variable1 = 0;
	int int_variable = 0;

	fopen_s(&fp, "array_profiles.txt", "r");
	if (fp == NULL) {
		cout << "Ошибка открытия файла array_profiles.txt\n";
	}
	else {
		load_arr_profile(fp, arr_Profile, size_arr_Profile, index_my_profile);
		fclose(fp);
	}
	fopen_s(&fp, "array_games.txt", "r");
	if (fp == NULL) {
		cout << "Ошибка открытия файла array_games.txt\n";
	}
	else {
		load_arr_game(fp, arr_Game, size_arr_Game);
		fclose(fp);
	}
	fopen_s(&fp, "array_admins.txt", "r");
	if (fp == NULL) {
		cout << "Ошибка открытия файла array_admins.txt\n";
	}
	else {
		load_arr_admin(fp, arr_Admin, size_arr_Admin,index_my_admin);
		fclose(fp);
	}

	//основное
	for (;;) {
		char a;
		int b=100;
		print_DragonForce();
		cout << "\n | ~ Приветствуем вас в Dragon Force!\n\n";
		cout << " | ~ Нажмите что-нибудь чтобы начать приключение!\n\n\n";
		a = _getch();
		SetConsoleTextAttribute(console_color, 14);
		cout << "                                                 __----~~~~~~~~~~~------___\n";
		Sleep(b);
		cout << "                                      .  .   ~~//====......          __--~ ~~\n";
		Sleep(b);
		cout << "                      -.            \_|//     |||\\\\  ~~~~~~::::... /~\n";
		Sleep(b);
		cout << "                   ___-==_       _-~o~  \/    |||  \\ \\           _/~~-\n";
		Sleep(b);
		cout << "           __---~~~.==~||\\=_    -_--~/_-~|-   |\\\\   \\\\        _/~\n";
		Sleep(b);
		cout << "       _-~~     .=~    |  \\\\-_    '-~7  /-   /  ||    \\      /\n";
		Sleep(b);
		cout << "     .~       .~       |   \\\\ -_    /  /-   /   ||      \\   /\n";
		Sleep(b);
		cout << "    /  ____  /         |     \\\\ ~-_/  /|- _/   .||       \\ /\n";
		Sleep(b);
		cout << "    |~~    ~~|--~~~~--_ \\     ~==-/   | \\~--===~~        .\\\n";
		Sleep(b);
		cout << "             '         ~-|      /|    |-~\\~~       __--~~\n";
		Sleep(b);
		cout << "                         |-~~-_/ |    |   ~\\_   _-~            /\\\n";
		Sleep(b);
		cout << "                              /  \\     \\__   \\/~                \\__\n";
		Sleep(b);
		cout << "                          _--~ _/ | .-~~____--~-/                  ~~==.\n";
		Sleep(b);
		cout << "                         ((->/~   '.|||' -_|    ~~-/ ,              . _||\n";
		Sleep(b);
		cout << "                                    -_     ~\\      ~~---l__i__i__i--~~_/\n";
		Sleep(b);
		cout << "                                    _-~-__   ~)  \\--______________--~~\n";
		Sleep(b);
		cout << "                                  //.-~~~-~_--~- |-------~~~~~~~~\n";
		Sleep(b);
		cout << "                                         //.-~~~--\\\n";
		Sleep(b);
		SetConsoleTextAttribute(console_color, 15);
		cout << "\n\n\n | ~ Да начнется же оно!";
		Sleep(5000);
		break;
	}

	do {
		system("cls");
		print_DragonForce();
		cout << "\n1. Магазин.\n"; //+ //+
		cout << "2. Профиль.\n"; //+ //+
		cout << "3. Для админов.\n"; //+ //+
		cout << "4. Информация о магазине.\n"; //+ //+
		cout << "5. Выйти.\n"; //+ //+
		cout << "\nВаш выбор: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			do {
				system("cls");
				print_DragonForce();
				cout << endl;
				show_newest_games(arr_Game, size_arr_Game, arr_newest_Games, size_arr_newest_Games);
				print_arr_game(arr_newest_Games, size_arr_newest_Games);
				if (size_arr_newest_Games > 0) {
					cout << endl;
					cout << "1. Детальнее.\n"; //+ //+
					cout << "2. Показать все игры.\n"; //+ //+
					cout << "3. Поиск игр.\n"; //+ //+
					cout << "4. <-- Вернуться.\n"; //+ //+
					cout << "\nВаш выбор: ";
					cin >> menuShop;
				}
				else {
					cout << "1. Показать все игры.\n"; //+ //+
					cout << "2. Поиск игр.\n"; //+ //+
					cout << "3. <-- Вернуться.\n"; //+ //+
					cout << "\nВаш выбор: ";
					cin >> menuShop;
					menuShop += 1;
				}
				cout << endl;
				switch (menuShop)
				{
				case 1:
					for (;;) {
						cout << "Введите номер игры: ";
						cin >> int_variable;
						cout << endl;
						if (int_variable > size_arr_newest_Games || int_variable <= 0) {
							system("color 04");
							cout << "Ошибка ввода.\n\n";
							Sleep(2000);
							system("color 07");
						}
						else {
							int_variable -= 1;
							for (int i = 0; i < size_arr_Game; i++)
							{
								if (strcmp(arr_Game[i].name.str, arr_newest_Games[int_variable].name.str) == 0) {
									int_variable = i;
									menu = 2;
									break;
								}
							}

							if (int_variable != -1) {
								present_game(arr_Profile, arr_Game, size_arr_Profile, size_arr_Game, index_my_profile, int_variable);
								fopen_s(&fp, "array_profiles.txt", "w");
								if (fp == NULL) {
									cout << "Ошибка открытия файла array_profiles.txt\n";
								}
								else {
									save_arr_profile(fp, arr_Profile, size_arr_Profile, index_my_profile);
									fclose(fp);
								}
							}
							break;
						}
					}
					break;
				case 2:
					do {
						system("cls");
						print_DragonForce();
						cout << endl;
						cout << "Сортировка по:\n\n";
						cout << "1. Алфавитному порядку.\n"; //+ //+
						cout << "2. Разработчику.\n"; //+ //+
						cout << "3. Жанру.\n"; //+ //+
						cout << "4. Дате выхода.\n"; //+ //+
						cout << "5. Рейтингу.\n"; //+ //+
						cout << "6. Стоимости.\n"; //+ //+
						cout << "7. Размеру.\n"; //+ //+
						cout << "8. Показать всё.\n"; //+ //+
						cout << "9. <-- Вернуться.\n"; //+ //+
						cout << "\nВаш выбор: ";
						cin >> menuShop_1;
						switch (menuShop_1)
						{
						case 1:
							system("cls");
							print_DragonForce();
							cout << endl;
							cout << "Сортировка в алфавитном порядке:\n\n";
							int_variable = sort_arr_game_by_alphabet(arr_Game, size_arr_Game);
							if (int_variable != -1) {
								present_game(arr_Profile, arr_Game, size_arr_Profile, size_arr_Game, index_my_profile, int_variable);
								fopen_s(&fp, "array_profiles.txt", "w");
								if (fp == NULL) {
									cout << "Ошибка открытия файла array_profiles.txt\n";
								}
								else {
									save_arr_profile(fp, arr_Profile, size_arr_Profile, index_my_profile);
									fclose(fp);
								}
							}
							break;
						case 2:
							system("cls");
							print_DragonForce();
							cout << endl;
							cout << "Сортировка по разработчику:\n\n";
							int_variable = sort_arr_game_by_developer(arr_Game, size_arr_Game);
							if (int_variable != -1) {
								present_game(arr_Profile, arr_Game, size_arr_Profile, size_arr_Game, index_my_profile, int_variable);
								fopen_s(&fp, "array_profiles.txt", "w");
								if (fp == NULL) {
									cout << "Ошибка открытия файла array_profiles.txt\n";
								}
								else {
									save_arr_profile(fp, arr_Profile, size_arr_Profile, index_my_profile);
									fclose(fp);
								}
							}
							break;
						case 3:
							system("cls");
							print_DragonForce();
							cout << endl;
							cout << "Сортировка по жанру:\n\n";
							int_variable = sort_arr_game_by_genre(arr_Game, size_arr_Game);
							if (int_variable != -1) {
								present_game(arr_Profile, arr_Game, size_arr_Profile, size_arr_Game, index_my_profile, int_variable);
								fopen_s(&fp, "array_profiles.txt", "w");
								if (fp == NULL) {
									cout << "Ошибка открытия файла array_profiles.txt\n";
								}
								else {
									save_arr_profile(fp, arr_Profile, size_arr_Profile, index_my_profile);
									fclose(fp);
								}
							}
							break;
						case 4:
							system("cls");
							print_DragonForce();
							cout << endl;
							cout << "Сортировка по дате выхода:\n\n";
							int_variable = sort_arr_game_by_date(arr_Game, size_arr_Game);
							if (int_variable != -1) {
								present_game(arr_Profile, arr_Game, size_arr_Profile, size_arr_Game, index_my_profile, int_variable);
								fopen_s(&fp, "array_profiles.txt", "w");
								if (fp == NULL) {
									cout << "Ошибка открытия файла array_profiles.txt\n";
								}
								else {
									save_arr_profile(fp, arr_Profile, size_arr_Profile, index_my_profile);
									fclose(fp);
								}
							}
							break;
						case 5:
							system("cls");
							print_DragonForce();
							cout << endl;
							cout << "Сортировка по рейтингу:\n\n";
							int_variable = sort_arr_game_by_rating(arr_Game, size_arr_Game);
							if (int_variable != -1) {
								present_game(arr_Profile, arr_Game, size_arr_Profile, size_arr_Game, index_my_profile, int_variable);
								fopen_s(&fp, "array_profiles.txt", "w");
								if (fp == NULL) {
									cout << "Ошибка открытия файла array_profiles.txt\n";
								}
								else {
									save_arr_profile(fp, arr_Profile, size_arr_Profile, index_my_profile);
									fclose(fp);
								}
							}
							break;
						case 6:
							system("cls");
							print_DragonForce();
							cout << endl;
							cout << "Сортировка по стоимости:\n\n";
							int_variable = sort_arr_game_by_price(arr_Game, size_arr_Game);
							if (int_variable != -1) {
								present_game(arr_Profile, arr_Game, size_arr_Profile, size_arr_Game, index_my_profile, int_variable);
								fopen_s(&fp, "array_profiles.txt", "w");
								if (fp == NULL) {
									cout << "Ошибка открытия файла array_profiles.txt\n";
								}
								else {
									save_arr_profile(fp, arr_Profile, size_arr_Profile, index_my_profile);
									fclose(fp);
								}
							}
							break;
						case 7:
							system("cls");
							print_DragonForce();
							cout << endl;
							cout << "Сортировка по размеру:\n\n";
							int_variable = sort_arr_game_by_weight(arr_Game, size_arr_Game);
							if (int_variable != -1) {
								present_game(arr_Profile, arr_Game, size_arr_Profile, size_arr_Game, index_my_profile, int_variable);
								fopen_s(&fp, "array_profiles.txt", "w");
								if (fp == NULL) {
									cout << "Ошибка открытия файла array_profiles.txt\n";
								}
								else {
									save_arr_profile(fp, arr_Profile, size_arr_Profile, index_my_profile);
									fclose(fp);
								}
							}
							break;
						case 8:
							system("cls");
							print_DragonForce();
							cout << endl;
							cout << "Все игры:\n";
							int_variable = print_arr_game_1(arr_Game, size_arr_Game);
							if (int_variable != -1) {
								present_game(arr_Profile, arr_Game, size_arr_Profile, size_arr_Game, index_my_profile, int_variable);
								fopen_s(&fp, "array_profiles.txt", "w");
								if (fp == NULL) {
									cout << "Ошибка открытия файла array_profiles.txt\n";
								}
								else {
									save_arr_profile(fp, arr_Profile, size_arr_Profile, index_my_profile);
									fclose(fp);
								}
							}
							break;
						case 9:
							break;
						default:
							system("color 04");
							cout << "Ошибка ввода.";
							Sleep(2000);
							system("color 07");
							break;
						}
					} while (menuShop_1 != 9);
					break;
				case 3:
					do {
						system("cls");
						print_DragonForce();
						cout << endl;
						cout << "Поиск по:\n\n";
						cout << "1. Названию.\n"; //+ //+
						cout << "2. Разработчику.\n"; //+ //+
						cout << "3. Жанру.\n"; //+ //+
						cout << "4. Дате выхода.\n"; //+ //+
						cout << "5. Рейтингу.\n"; //+ //+
						cout << "6. Стоимости.\n"; //+ //+
						cout << "7. Размеру.\n"; //+ //+
						cout << "8. <-- Вернуться.\n"; //+ //+
						cout << "\nВаш выбор: ";
						cin >> menuShop_1;
						cout << endl;
						switch (menuShop_1)
						{
						case 1:
							cout << "Введите название игры: ";
							cin.ignore();
							cin.getline(str, 100);
							cout << endl;
							int_variable = find_in_arr_game_name(arr_Game, size_arr_Game, str);
							if (int_variable >= 0) {
								present_game(arr_Profile, arr_Game, size_arr_Profile, size_arr_Game, index_my_profile, int_variable);
								fopen_s(&fp, "array_profiles.txt", "w");
								if (fp == NULL) {
									cout << "Ошибка открытия файла array_profiles.txt\n";
								}
								else {
									save_arr_profile(fp, arr_Profile, size_arr_Profile, index_my_profile);
									fclose(fp);
								}
							}
							else if (int_variable == -2) {
								char a;
								cout << "Нажмите что-нибудь чтобы продолжить.\n";
								a = _getch();
							}
							break;
						case 2:
							cout << "Введите разработчика: ";
							cin.ignore();
							cin.getline(str, 100);
							cout << endl;
							int_variable = find_in_arr_game_developer(arr_Game, size_arr_Game, str);
							if (int_variable >= 0) {
								present_game(arr_Profile, arr_Game, size_arr_Profile, size_arr_Game, index_my_profile, int_variable);
								fopen_s(&fp, "array_profiles.txt", "w");
								if (fp == NULL) {
									cout << "Ошибка открытия файла array_profiles.txt\n";
								}
								else {
									save_arr_profile(fp, arr_Profile, size_arr_Profile, index_my_profile);
									fclose(fp);
								}
							}
							else if (int_variable == -2) {
								char a;
								cout << "Нажмите что-нибудь чтобы продолжить.\n";
								a = _getch();
							}
							break;
						case 3:
							cout << "Введите жанр: ";
							cin.ignore();
							cin.getline(str, 100);
							cout << endl;
							int_variable = find_in_arr_game_genre(arr_Game, size_arr_Game, str);
							if (int_variable >= 0) {
								present_game(arr_Profile, arr_Game, size_arr_Profile, size_arr_Game, index_my_profile, int_variable);
								fopen_s(&fp, "array_profiles.txt", "w");
								if (fp == NULL) {
									cout << "Ошибка открытия файла array_profiles.txt\n";
								}
								else {
									save_arr_profile(fp, arr_Profile, size_arr_Profile, index_my_profile);
									fclose(fp);
								}
							}
							else if (int_variable == -2) {
								char a;
								cout << "Нажмите что-нибудь чтобы продолжить.\n";
								a = _getch();
							}
							break;
						case 4:
							cout << "Введите промежуток времени.\n\nОт:\n";
							date_tmp.fillDate();
							cout << "\nДо:\n";
							date_tmp1.fillDate();
							cout << endl;
							int_variable = find_in_arr_game_date(date_tmp, date_tmp1, arr_Game, size_arr_Game);
							if (int_variable >= 0) {
								present_game(arr_Profile, arr_Game, size_arr_Profile, size_arr_Game, index_my_profile, int_variable);
								fopen_s(&fp, "array_profiles.txt", "w");
								if (fp == NULL) {
									cout << "Ошибка открытия файла array_profiles.txt\n";
								}
								else {
									save_arr_profile(fp, arr_Profile, size_arr_Profile, index_my_profile);
									fclose(fp);
								}
							}
							else if (int_variable == -2) {
								char a;
								cout << "Нажмите что-нибудь чтобы продолжить.\n";
								a = _getch();
							}
							break;
						case 5:
							cout << "Введите диапазон рейтинга.\n\nОт: ";
							cin >> float_variable;
							cout << "До: ";
							cin >> float_variable1;
							cout << endl;
							int_variable = find_in_arr_game_rating(arr_Game, size_arr_Game, float_variable, float_variable1);
							if (int_variable >= 0) {
								present_game(arr_Profile, arr_Game, size_arr_Profile, size_arr_Game, index_my_profile, int_variable);
								fopen_s(&fp, "array_profiles.txt", "w");
								if (fp == NULL) {
									cout << "Ошибка открытия файла array_profiles.txt\n";
								}
								else {
									save_arr_profile(fp, arr_Profile, size_arr_Profile, index_my_profile);
									fclose(fp);
								}
							}
							else if (int_variable == -2) {
								char a;
								cout << "Нажмите что-нибудь чтобы продолжить.\n";
								a = _getch();
							}
							break;
						case 6:
							cout << "Введите ценовую категорию.\n\nОт: ";
							cin >> float_variable;
							cout << "До: ";
							cin >> float_variable1;
							cout << endl;
							int_variable = find_in_arr_game_price(arr_Game, size_arr_Game, float_variable, float_variable1);
							if (int_variable >= 0) {
								present_game(arr_Profile, arr_Game, size_arr_Profile, size_arr_Game, index_my_profile, int_variable);
								fopen_s(&fp, "array_profiles.txt", "w");
								if (fp == NULL) {
									cout << "Ошибка открытия файла array_profiles.txt\n";
								}
								else {
									save_arr_profile(fp, arr_Profile, size_arr_Profile, index_my_profile);
									fclose(fp);
								}
							}
							else if (int_variable == -2) {
								char a;
								cout << "Нажмите что-нибудь чтобы продолжить.\n";
								a = _getch();
							}
							break;
						case 7:
							cout << "Введите диапазон размера.\n\nОт: ";
							cin >> float_variable;
							cout << "До: ";
							cin >> float_variable1;
							cout << endl;
							int_variable = find_in_arr_game_weight(arr_Game, size_arr_Game, float_variable, float_variable1);
							if (int_variable >= 0) {
								present_game(arr_Profile, arr_Game, size_arr_Profile, size_arr_Game, index_my_profile, int_variable);
								fopen_s(&fp, "array_profiles.txt", "w");
								if (fp == NULL) {
									cout << "Ошибка открытия файла array_profiles.txt\n";
								}
								else {
									save_arr_profile(fp, arr_Profile, size_arr_Profile, index_my_profile);
									fclose(fp);
								}
							}
							else if (int_variable == -2) {
								char a;
								cout << "Нажмите что-нибудь чтобы продолжить.\n";
								a = _getch();
							}
							break;
						case 8:
							break;
						default:
							system("color 04");
							cout << "Ошибка ввода.";
							Sleep(2000);
							system("color 07");
							break;
						}
					} while (menuShop_1 != 8);
					break;
				case 4:
					break;
				default:
					system("color 04");
					cout << "Ошибка ввода.";
					Sleep(2000);
					system("color 07");
					break;
				}
			} while (menuShop != 4);
			break;
		case 2:
			if (index_my_profile == -1) {
				do {
					system("cls");
					print_DragonForce();
					cout << endl;
					cout << "\nВы еще не вошли в свой аккаунт!\n";
					cout << "\n1. Войти.\n"; //+ //+
					cout << "2. Зарегестрироваться.\n"; //+ //+
					cout << "3. <-- Вернуться.\n"; //+ //+
					cout << "\nВаш выбор: ";
					cin >> menuProfile;
					cout << endl;
					switch (menuProfile)
					{
					case 1:
						fopen_s(&fp, "array_profiles.txt", "w");
						if (fp == NULL) {
							cout << "Ошибка открытия файла array_profiles.txt\n";
						}
						else {
							sign_in(arr_Profile, size_arr_Profile, index_my_profile);
							save_arr_profile(fp, arr_Profile, size_arr_Profile, index_my_profile);
							cout << "Ваш профиль сохранен.\n";
							menuProfile = 3;
							fclose(fp);
						}
						break;
					case 2:
						fopen_s(&fp, "array_profiles.txt", "w");
						if (fp == NULL) {
							cout << "Ошибка открытия файла array_profiles.txt\n";
						}
						else {
							register_profile(arr_Profile, size_arr_Profile, index_my_profile);
							save_arr_profile(fp, arr_Profile, size_arr_Profile, index_my_profile);
							cout << "Ваш профиль сохранен.\n";
							char a;
							cout << "\nНажмите что-нибудь чтобы продолжить.\n";
							a = _getch();
							menuProfile = 3;
							fclose(fp);
						}
						break;
					case 3:
						break;
					default:
						system("color 04");
						cout << "Ошибка ввода.";
						Sleep(2000);
						system("color 07");
						break;
					}
				} while (menuProfile != 3);
			}
			else {
				do {
					system("cls");
					print_DragonForce();
					cout << endl;
					profile_was_loaded = true; //?
					arr_Profile[index_my_profile].print_profile();
					cout << "\n1. Купленные игры.\n"; //+ //+
					cout << "2. Избранные игры.\n"; //+ //+
					cout << "3. Сохраненные игры.\n"; //+ //+
					cout << "4. Редактировать профиль.\n"; //+ //+
					cout << "5. Выйти из профиля.\n"; //+ //+
					cout << "6. <-- Вернуться.\n"; //+ //+
					cout << "\nВаш выбор: ";
					cin >> menuProfile;
					cout << endl;
					switch (menuProfile)
					{
					case 1:
						if (arr_Profile[index_my_profile].length_arr_Bought_Games > 0) {
							system("cls");
							print_DragonForce();
							cout << endl;
							cout << "Список купленных игр (" << arr_Profile[index_my_profile].length_arr_Bought_Games << "):\n\n";
							print_arr_game(arr_Profile[index_my_profile].arr_Bought_Games, arr_Profile[index_my_profile].length_arr_Bought_Games);
							do {
								cout << "\n1. Удалить игру.\n"; //+ //+
								cout << "2. Выйти.\n"; //+ //+
								cout << "\nВаш выбор: ";
								cin >> menuProfile_1;
								cout << endl;
								switch (menuProfile_1)
								{
								case 1:
								{
									for (;;) {
										cout << "Предупреждение: игру невозможно будет восстановить.\nВы точно хотите удалить игру?\n\n(Да/нет): ";
										cin >> str;
										cout << endl;
										if (strcmp(str, "Да") == 0 || strcmp(str, "да") == 0) {
											cout << "Введите номер игры которую хотите улалить: ";
											cin >> int_variable;
											int_variable -= 1;
											cout << "\nИгра \"" << arr_Profile[index_my_profile].arr_Bought_Games[int_variable].name.str << "\" удалена.\n\n";
											del_game(arr_Profile[index_my_profile].arr_Bought_Games, arr_Profile[index_my_profile].length_arr_Bought_Games, int_variable);
											char a;
											cout << "Нажмите что-нибудь чтобы продолжить.\n";
											a = _getch();
											menuProfile_1 = 2;
											break;
										}
										else if (strcmp(str, "нет") != 0 && strcmp(str, "Нет") != 0) {
											system("color 04");
											cout << "Ошибка ввода.\n\n";
											Sleep(2000);
											system("color 07");
										}
										else {
											break;
										}
									}
									break;
								}
								case 2:
									break;
								default:
									system("color 04");
									cout << "Ошибка ввода.\n\n";
									Sleep(2000);
									system("color 07");
									break;
								}
							} while (menuProfile_1 != 2);
						}
						else {
							cout << "\nУ вас нет купленных игр.\n";
							char a;
							cout << "\nНажмите что-нибудь чтобы продолжить.\n";
							a = _getch();
						}
						break;
					case 2:
						if (arr_Profile[index_my_profile].length_arr_Favourite_Games > 0) {
							system("cls");
							print_DragonForce();
							cout << endl;
							cout << "Список избранных игр (" << arr_Profile[index_my_profile].length_arr_Favourite_Games << "):\n\n";
							print_arr_game(arr_Profile[index_my_profile].arr_Favourite_Games, arr_Profile[index_my_profile].length_arr_Favourite_Games);
							do {
								cout << "\n1. Убрать игру из \"Избранное\".\n"; //+ //+
								cout << "2. Выйти.\n"; //+ //+
								cout << "\nВаш выбор: ";
								cin >> menuProfile_1;
								cout << endl;
								switch (menuProfile_1)
								{
								case 1:
									cout << "Введите номер игры которую хотите улалить: ";
									cin >> int_variable;
									int_variable -= 1;
									cout << "Игра \"" << arr_Profile[index_my_profile].arr_Favourite_Games[int_variable].name.str << "\" удалена из \"Избранное\".\n";
									del_game(arr_Profile[index_my_profile].arr_Favourite_Games, arr_Profile[index_my_profile].length_arr_Favourite_Games, int_variable);
									Sleep(2000);
									break;
								case 2:
									break;
								default:
									system("color 04");
									cout << "Ошибка ввода.\n\n";
									Sleep(2000);
									system("color 07");
									break;
								}
							} while (menuProfile_1 != 2);
						}
						else {
							cout << endl;
							cout << "У вас нет избранных игр.\n";
							char a;
							cout << "\nНажмите что-нибудь чтобы продолжить.\n";
							a = _getch();
						}
						break;
					case 3:
						if (arr_Profile[index_my_profile].length_arr_Saved_Games > 0) {
							system("cls");
							print_DragonForce();
							cout << endl;
							cout << "Список сохраненных игр (" << arr_Profile[index_my_profile].length_arr_Saved_Games << "):\n\n";
							print_arr_game(arr_Profile[index_my_profile].arr_Saved_Games, arr_Profile[index_my_profile].length_arr_Saved_Games);
							do {
								cout << "\n1. Убрать игру из \"Сохраненное\".\n"; //+ //+
								cout << "2. Выйти.\n"; //+ //+
								cout << "\nВаш выбор: ";
								cin >> menuProfile_1;
								cout << endl;
								switch (menuProfile_1)
								{
								case 1:
									cout << "Введите номер игры которую хотите улалить: ";
									cin >> int_variable;
									int_variable -= 1;
									cout << "Игра \"" << arr_Profile[index_my_profile].arr_Saved_Games[int_variable].name.str << "\" удалена из \"Сохраненное\".\n";
									del_game(arr_Profile[index_my_profile].arr_Saved_Games, arr_Profile[index_my_profile].length_arr_Saved_Games, int_variable);
									Sleep(2000);
									break;
								case 2:
									break;
								default:
									system("color 04");
									cout << "Ошибка ввода.\n\n";
									Sleep(2000);
									system("color 07");
									break;
								}
							} while (menuProfile_1 != 2);
						}
						else {
							cout << endl;
							cout << "У вас нет сохраненных игр.\n";
							char a;
							cout << "\nНажмите что-нибудь чтобы продолжить.\n";
							a = _getch();
						}
						break;
					case 4:
						arr_Profile[index_my_profile].change_my_profile();
						fopen_s(&fp, "array_profiles.txt", "w");
						if (fp == NULL) {
							cout << "Ошибка открытия файла array_profiles.txt.\n";
						}
						else {
							save_arr_profile(fp, arr_Profile, size_arr_Profile, index_my_profile);
							fclose(fp);
						}
						break;
					case 5:
						for (;;) {
							cout << "Вы точно хотите выйти из профиля?\n(Да/нет): ";
							cin >> str;
							cout << endl;
							if (strcmp(str, "Да") == 0 || strcmp(str, "да") == 0) {
								index_my_profile = -1;
								cout << "Вы вышли из своего профиля.\n";
								fopen_s(&fp, "array_profiles.txt", "w");
								if (fp == NULL) {
									cout << "Ошибка открытия файла array_profiles.txt\n";
								}
								else {
									save_arr_profile(fp, arr_Profile, size_arr_Profile, index_my_profile);
									char a;
									cout << "\nНажмите что-нибудь чтобы продолжить.\n";
									a = _getch();
									fclose(fp);
									break;
								}
							}
							else if (strcmp(str, "нет") != 0 && strcmp(str, "Нет") != 0) {
								system("color 04");
								cout << "Ошибка ввода.\n\n";
								Sleep(2000);
								system("color 07");
							}
							else {
								break;
							}
						}
						break;
					case 6:
						break;
					default:
						system("color 04");
						cout << "Ошибка ввода.\n\n";
						Sleep(2000);
						system("color 07");
						break;
					}
					if (index_my_profile == -1) {
						break;
					}
				} while (menuProfile != 6);
			}
			break;
		case 3:
			if (index_my_admin == -1) {
				do {
					system("cls");
					print_DragonForce();
					cout << endl;
					cout << "\nВы еще не вошли в свой аккаунт!\n";
					cout << "\n1. Войти.\n"; //+ //+
					cout << "2. <-- Вернуться.\n"; //+ //+
					cout << "\nВаш выбор: ";
					cin >> menuAdmin;
					cout << endl;
					switch (menuAdmin)
					{
					case 1:
						fopen_s(&fp, "array_admins.txt", "w");
						if (fp == NULL) {
							cout << "Ошибка открытия файла array_admins.txt\n";
						}
						else {
							sign_in_admin(arr_Admin, size_arr_Admin, index_my_admin);
							save_arr_admin(fp, arr_Admin, size_arr_Admin, index_my_admin);
							cout << "Ваш профиль сохранен.\n";
							menuAdmin = 3;
							fclose(fp);
						}
						menuAdmin = 2;
						break;
					case 2:
						break;
					default:
						system("color 04");
						cout << "Ошибка ввода.";
						Sleep(2000);
						system("color 07");
						break;
					}
				} while (menuAdmin != 2);
			}

			else {
				do {
					system("cls");
					print_DragonForce();
					cout << endl;
					arr_Admin[index_my_admin].print_admin();
					cout << endl;
					cout << "\n1. Редактировать игры.\n"; //+ //+
					cout << "2. Редактировать профили.\n"; //+ //+
					cout << "3. <-- Вернуться.\n"; //+ //+
					cout << "\nВаш выбор: ";
					cin >> menuAdmin;
					cout << endl;
					switch (menuAdmin)
					{
					case 1:
						do {
							system("cls");
							print_DragonForce();
							int_variable = print_arr_game_1(arr_Game, size_arr_Game);
							cout << "\n1. Редактировать.\n"; //+ //+
							cout << "2. Удалить.\n"; //+ //+
							cout << "3. Добавить новую игру.\n"; //+ //+
							cout << "4. <-- Вернуться.\n"; //+ //+
							cout << "\nВаш выбор: ";
							cin >> menuAdmin1;
							cout << endl;

							switch (menuAdmin1)
							{
							case 1:
								if (int_variable != -1) {
									arr_Game[int_variable].change_game();
									fopen_s(&fp, "array_games.txt", "w");
									if (fp == NULL) {
										cout << "Ошибка открытия файла array_games.txt\n";
									}
									else {
										save_arr_game(fp, arr_Game, size_arr_Game);
										cout << "Изменения сохранены.\n";
										char a;
										cout << "\nНажмите что-нибудь чтобы продолжить.\n";
										a = _getch();
										fclose(fp);
									}
								}
								break;
							case 2:
								del_game(arr_Game, size_arr_Game, int_variable);
								fopen_s(&fp, "array_games.txt", "w");
								if (fp == NULL) {
									cout << "Ошибка открытия файла array_games.txt\n";
								}
								else {
									save_arr_game(fp, arr_Game, size_arr_Game);
									char a;
									cout << "\nНажмите что-нибудь чтобы продолжить.\n";
									a = _getch();
									fclose(fp);
									break;
								}
								break;
							case 3:
								add_game(arr_Game, size_arr_Game);
								fopen_s(&fp, "array_games.txt", "w");
								if (fp == NULL) {
									cout << "Ошибка открытия файла array_games.txt\n";
								}
								else {
									save_arr_game(fp, arr_Game, size_arr_Game);
									char a;
									cout << "\nНажмите что-нибудь чтобы продолжить.\n";
									a = _getch();
									fclose(fp);
									break;
								}
								break;
							case 4:
								break;
							default:
								system("color 04");
								cout << "Ошибка ввода.\n\n";
								Sleep(2000);
								system("color 07");
								break;
							}
						} while (menuAdmin1 != 4);
						break;
					case 2:
						do {
							system("cls");
							print_DragonForce();
							int_variable = print_arr_profile_1(arr_Profile, size_arr_Profile);
							cout << "\n1. Редактировать.\n"; //+ //+
							cout << "2. Удалить.\n"; //+ //+
							cout << "3. <-- Вернуться.\n"; //+ //+
							cout << "\nВаш выбор: ";
							cin >> menuAdmin1;
							cout << endl;

							switch (menuAdmin1)
							{
							case 1:
								if (int_variable != -1) {
									arr_Profile[int_variable].change_profile();
									fopen_s(&fp, "array_profiles.txt", "w");
									if (fp == NULL) {
										cout << "Ошибка открытия файла array_profiles.txt.\n";
									}
									else {
										save_arr_profile(fp, arr_Profile, size_arr_Profile, index_my_profile);
										cout << "Изменения сохранены.\n";
										char a;
										cout << "\nНажмите что-нибудь чтобы продолжить.\n";
										a = _getch();
										fclose(fp);
									}
								}
								break;
							case 2:
								del_profile(arr_Profile, size_arr_Profile, int_variable);
								fopen_s(&fp, "array_profiles.txt", "w");
								if (fp == NULL) {
									cout << "Ошибка открытия файла array_profiles.txt\n";
								}
								else {
									save_arr_profile(fp, arr_Profile, size_arr_Profile, index_my_profile);
									char a;
									cout << "\nНажмите что-нибудь чтобы продолжить.\n";
									a = _getch();
									fclose(fp);
									break;
								}
								break;
							case 3:
								break;
							default:
								system("color 04");
								cout << "Ошибка ввода.\n\n";
								Sleep(2000);
								system("color 07");
								break;
							}
						} while (menuAdmin1 != 3);
						break;
					case 3:
						break;
					default:
						system("color 04");
						cout << "Ошибка ввода.\n\n";
						Sleep(2000);
						system("color 07");
						break;
					}
					} while (menuAdmin != 3);
				}
				break;
		case 4:
		{
			system("cls");
			print_DragonForce();
			cout << "\nDragon Force - это магазин видеоигр в котором вы можете найти игру на любой вкус!\n";
			cout << "Читайте, покупайте развлекайтесь!\n";
			cout << "Но помните, что тут есть админы, так что ведите себя хорошо!\n";
			cout << "Хорошего времяприпровождения! :)\n";
			char a;
			cout << "\nНажмите что-нибудь чтобы продолжить.\n";
			a = _getch();
			break;
		}
		case 5:
		{
			system("cls");
			print_DragonForce();
			int b=100;
			cout << "\nХорошего дня! Непременно ждем Вас снова!\n\n\n";
			SetConsoleTextAttribute(console_color, 14);
			cout << "                                                 /===-_---~~~~~~~~~------____\n";
			Sleep(b);
			cout << "                                                |===-~___                _,-'\n";
			Sleep(b);
			cout << "                 -==\\\\                         `//~\\\\   ~~~~`---.___.-~~\n";
			Sleep(b);
			cout << "             ______-==|                         | |  \\\\           _-~`\n";
			Sleep(b);
			cout << "       __--~~~  ,-/-==\\\\                        | |   `\\        ,'\n";
			Sleep(b);
			cout << "    _-~       /'    |  \\\\                      / /      \\      /\n";
			Sleep(b);
			cout << "  .'        /       |   \\\\                   /' /        \\   /'\n";
			Sleep(b);
			cout << " /  ____  /         |    \\`\\.__/-~~ ~ \ _ _/'  /          \\/'\n";
			Sleep(b);
			cout << "/-'~    ~~~~~---__  |     ~-/~         ( )   /'        _--~`\n";
			Sleep(b);
			cout << "                  \\_|      /        _)   ;  ),   __--~~\n";
			Sleep(b);
			cout << "                    '~~--_/      _-~/-  / \\   '-~ \\\n";
			Sleep(b);
			cout << "                   {\\__--_/}    / \\\\_>- )<__\\      \\\n";
			Sleep(b);
			cout << "                   /'   (_/  _-~  | |__>--<__|      |\n";
			Sleep(b);
			cout << "                  |0  0 _/) )-~     | |__>--<__|      |\n";
			Sleep(b);
			cout << "                  / /~ ,_/       / /__>---<__/      |\n";
			Sleep(b);
			cout << "                 o o _//        /-~_>---<__-~      /\n";
			Sleep(b);
			cout << "                 (^(~          /~_>---<__-      _-~\n";
			Sleep(b);
			cout << "                ,/|           /__>--<__/     _-~\n";
			Sleep(b);
			cout << "             ,//('(          |__>--<__|     /                  .----_ \n";
			Sleep(b);
			cout << "            ( ( '))          |__>--<__|    |                 /' _---_~\\  \n";
			Sleep(b);
			cout << "         `-)) )) (           |__>--<__|    |               /'  /     ~\\`\\ \n";
			Sleep(b);
			cout << "        ,/,'//( (             \\__>--<__\\    \\            /'  //        || \n";
			Sleep(b);
			cout << "      ,( ( ((, ))              ~-__>--<_~-_  ~--____---~' _/'/        /'\n";
			Sleep(b);
			cout << "    `~/  )` ) ,/|                 ~-_~>--<_/-__       __-~ _/\n";
			Sleep(b);
			cout << "  ._-~//( )/ )) `                    ~~-'_/_/ /~~~~~~~__--~\n";
			Sleep(b);
			cout << "   ;'( ')/ ,)(                              ~~~~~~~~~~\n";
			Sleep(b);
			cout << "  ' ') '( (/\n";
			Sleep(b);
			cout << "    '   '  `\n";
			SetConsoleTextAttribute(console_color, 15);
			break;
		}
		default:
			system("color 04");
			cout << "Ошибка ввода.\n\n";
			Sleep(2000);
			system("color 07");
			break;
		}
	} while (menu != 5);

	return 0;
}
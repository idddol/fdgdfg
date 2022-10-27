#include <iostream>
#include <cstring>

using namespace std;

bool Palindrom(char* str) //Ввод строки, введеной в функции input, проверяется, является ли она палиндромом
{
	for (int i = 0, j = strlen(str) - 1; i < j; i++, j--) {
		if (str[i] == ' ') i++;
		if (str[j] == ' ') j--;
		str[i] = tolower(str[i]);
		str[j] = tolower(str[j]);
		if (str[i] != str[j]) {
			return false;
			break;
		}
	}
	return true;
}

int find_substring1(char* str, char* sub, int& start)//Ввод строки, подстроки и стартовой позиции, ведется поиск первого вхождения подстроки в строке, меняется стартовая позиция
{
	for (int i = 0; i < start; i++) str[i] = '.';
	if (int(strlen(strstr(str, sub))) > 0) {
		start = strlen(str) - strlen(strstr(str, sub));
	}
	else {
		start = -1;
	}
	return start;
}

void find_substring2(char* str, char* sub) { //Ввод строки, подстроки, ведется поиск всех вхождений подстроки в строке
	int arr[256];
	int counter = 0;
	int start = 0;
	char str1[256];
	strcpy(str1, str);
	while (1) {
		char* ss = strstr(str1, sub);
		if (ss == NULL)
			break;

		start = strlen(str1) - strlen(ss);
		arr[counter] = start + counter * strlen(sub);
		memmove(&str1[start], &str1[start + strlen(sub)], strlen(str1) - start);

		counter++;
	}

	for (int i = 0; i < counter; i++) {
		cout << arr[i] << " ";
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int choice, start = 0;
	char cstr[256] = " ";
	char sub[256] = " ";
	cout << "Введите строку ";
	cin.getline(cstr, 256);
	while (true)
	{
		cout << "Какое задание выполнить? \n1.Проверка на палиндром \n2.Индекс первого слева вхождения подстроки \n3.Массив индексов вхождения подстроки \n4.Шифр Цезаря \n5.Текст \n6.Выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << bool(Palindrom(cstr));
			cout << endl;
			break;
		}
		case 2:
		{
			cout << "Введите подстроку "; cin >> sub;
			cout << "Введите позицию начала "; cin >> start;
			find_substring1(cstr, sub, start);
			cout << start;
			cout << endl;
			break;
		}
		case 3:
		{
			cout << "Введите подстроку ";
			cin >> sub;
			find_substring2(cstr, sub);
			cout << endl;
			break;
		}
		case 4:
		{

			cout << endl;
			break;
		}
		case 5:
		{
			cout << endl;
			break;
		}
		case 6:
		{
			cout << "До связи :D";
			return 0;
		}
		}
	}
}

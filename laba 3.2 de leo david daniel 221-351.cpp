#include <iostream>
using namespace std;

void task1(int *arr, int arr_size) {
	cout << "Введите массив ";
	for (int i = 0; i < arr_size; i++) {
		cin >> arr[i];
	}
}

void task2(int *arr, int arr_size) {
	for (int i = 0; i < arr_size; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

int func(int n) {
	int ch = 0;
	int nch = 0;
	int k = 0;
	while (n)
	{
		k++;
		if (!(k % 2))
		{
			ch += n % 10;
		}
		else {
			nch += n % 10;
		}
		n /= 10;
	}
	int s;
	if (!(k % 2))
	{
		s = nch;
	}
	else {
		s = ch;
	}
	return s;
}

void task3(int *arr, int arr_size) {
	int zamena = 0;
	for (int i = 0; i < arr_size; i++) {
		for (int j = i + 1; j < arr_size; j++) {
			if (func(arr[i]) > func(arr[j])) {
				zamena = arr[i];
				arr[i] = arr[j];
				arr[j] = zamena;
			}
		}
	}
	for (int i = 0; i < arr_size; i++) {
		cout << arr[i] << " ";
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int choice;
	int arr_size;
	cout << "Введите длину массива "; cin >> arr_size;
	int *arr = new int[arr_size];
	while (true)
	{
		cout << "Какое задание хотите выполнить? \n1.Ввод массива \n2.Вывод массива \n3.Сортировка по сумме цифр \n4.Сортировка по возрастанию последней цифры \n5.Выход" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			task1(arr, arr_size);
			cout << endl;
			break;
		}
		case 2:
		{
			task2(arr, arr_size);
			cout << endl;
			break;
		}
		case 3:
		{
			task3(arr, arr_size);
			cout << endl;
			break;
		}
		case 4:
		{
			cout << "Всего хорошего";
			cout << endl;
			break;
		}
		case 5:
		{
			delete[] arr;
			return 0;
		}
		}
	}
}

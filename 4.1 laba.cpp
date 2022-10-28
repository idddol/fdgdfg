#include <iostream>
#include <cstring>

using namespace std;

/*bool Palindrom(char* str) //Ввод строки,, проверяется, является ли она палиндромом
{
    for (int i = 0, j = strlen(str) - 1; i < j; i++,j--) {
        if (str[i] == ' ') i++;
        if (str[j] == ' ') j++;
        str[i] = tolower(str[i]);
        str[j] = tolower(str[j]);
        if (str[i] != str[j]) {
            return false;
            break;
        }
    }
    return true;
}*/

bool Palindrom(char* str) {  //Ввод строки, проверяется, является ли она палиндромом
    int i = 0;
    int j = strlen(str) - 1;
    while (i < j) {
        if (str[i] == ' ') i++;
        if (str[j] == ' ') j--;
        str[i] = tolower(str[i]);
        str[j] = tolower(str[j]);
        if (str[i] != str[j]) {
            return false;
            break;
        }
        i++;
        j--;

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

/*void find_substring2(char* str, char* sub) { //Ввод строки, подстроки, ведется поиск всех вхождений подстроки в строке
    int arr[256];
    int counter = 0;
    int start = 0;
    char str1[256];
    strcpy(str1, str);
    while (start != -1) {
        for (int i = 0; i < start; i++) str1[i] = '.';
        if (int(strstr(str1, sub)) > 0) {
            start = strlen(str) - strlen((strstr(str1, sub)));
            arr[counter] = start;
            counter++;
        }
        else {
            start = -1;
        }
    }
    for (int i = 0; i < counter; i++) cout << arr[i]<<" ";
    cout << endl;
}*/

void encrypted(char* text, int key) {  //Ввод строки, ввод ключа шифрования, строка меняется в соответствии с шифром Цезаря ВАЖНО только английский язык!
    char encr_text[256];
    const char* alp = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    strcpy(encr_text, text);
    for (int i = 0; i < strlen(text); i++) {
        if (strchr(alp, encr_text[i]))
            text[i] = char(int(encr_text[i]) + key);
        else text[i] = encr_text[i];
    }
}

void task4(char* str) { //Ввод строки, вывод всех слов в кавычках
    int f = 0;
    for (int i = 0; i <= strlen(str); i++) {
        if (f == 1 and str[i] != '"') cout << str[i];
        else {
            if (f == 0 and str[i] == '"') f = 1;
            else {
                f = 0;
                cout << " ";
            }
        }
    }
    cout << "\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int choice = 0, start = 0, key = 0;
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
            cout << "Введите ключ "; cin >> key;
            encrypted(cstr, key);
            cout << endl << cstr;
            cout << endl;
            break;
        }
        case 5:
        {
            task4(cstr);
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

#include <iostream>
#include <cstring>
#include <string> 
#include <fstream> 
#include <bitset>

using namespace std;

string file_format(const string file_path_full) {   // по введенному полному расположению файла выводит расширение
    int num;
    string abc;
    num = file_path_full.find_first_of('.');
    abc = file_path_full.substr(num, file_path_full.size() - num);
    return abc;
}

string file_name(const string file_path_full) { //  по введенному полному расположению файла выводит название
    int num, num1;
    string abc;
    num = file_path_full.find_last_of('.');
    num1 = file_path_full.find_last_of("\\");
    int a = file_path_full.size() - num1 - 1 - (file_path_full.size() - num);
    abc = file_path_full.substr(num1 + 1, a);
    return abc;
}

string file_path(const string file_path_full) { // по введенному полному расположению файла выводит расположение
    int num;
    string abc;
    num = file_path_full.find_last_of("\\");
    abc = file_path_full.substr(0, num);
    return abc;
}

string file_disk(const string file_path_full) {   // по введенному полному расположению файла выводит название диска
    return file_path_full.substr(0, 1);
}

string file_rename(string file_path_full) { // по введенному полному расположению файла и новому имени  переименовывает файл
    string new_name;
    cin >> new_name;
    file_path_full = file_path_full.substr(0, file_path_full.find_last_of("\\") + 1) + new_name + ".cpp";
    return file_path_full;
}

bool file_copy(const string file_path_full) {
    int num;
    fstream fs;
    fstream out;
    string temp;
    num = file_path_full.find_first_of('.');
    fs.open(file_path_full, fstream::in);
    out.open(file_path_full.substr(0, num) + "_copy" + file_path_full.substr(num, file_path_full.size() - num), fstream::out);
    while (!fs.eof()) {
        fs >> temp;
        out << temp << '\n';
    }
    return 1;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    string file_path_name;
    int a = 0;
    int choise;
    while (a == 0) {
        cout << "Что вы хотите выполнить?" "\n" << "1. Ввод" "\n" << "2. задание 1" "\n" << "3. задание 2" "\n" << "4. задание 3" "\n" << "5. Задание 4" "\n" "6. Задание 5" "\n" "7. Задание 6"  "\n" "8. Выход" "\n";
        cin >> choise;
        switch (choise)
        {
        case 1:
            cout << "Введите расположение файла без пробелов "; cin >> file_path_name;
            break;
        case 2:
            cout << file_format(file_path_name) << '\n';
            break;
        case 3:
            cout << file_name(file_path_name) << "\n";
            break;
        case 4:
            cout << file_path(file_path_name) << "\n";
            break;
        case 5:
            cout << file_disk(file_path_name) << "\n";
            break;
        case 6:
            cout << file_rename(file_path_name) << "\n";
            break;
        case 7:
            file_copy(file_path_name);
            break;
        case 8:
            cout << "Всего хорошего";
            a++;
        default:
            break;
        }


    }
}
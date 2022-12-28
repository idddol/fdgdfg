#include <iostream>
#include <string>
#include <vector>

using std::vector;

struct MyStruct
{
    std::string Surname, Name;
    int Age;
};

template <typename T>
int partition(vector<T>& values, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    auto pivotValue = values[pivotIndex];
    int i = left, j = right;
    while (i <= j) {
        while (values[i] < pivotValue) {
            i++;
        }
        while (values[j] > pivotValue) {
            j--;
        }
        if (i <= j) {
            auto temp = values[i];
            values[i] = values[j];
            values[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}

template <typename T>
void quicksort(vector<T>& values, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(values, left, right);
        quicksort(values, left, pivotIndex - 1);
        quicksort(values, pivotIndex, right);
    }
}



int main()
{
    setlocale(LC_ALL, "Russian");
    int a = 0;
    std::vector <MyStruct> db;
    std::vector <MyStruct> dbmir;
    vector <int> Ages;
    vector <std::string> Names;
    vector <std::string> Surnames;
    std::string Surname, Name;
    int Age;
    MyStruct dbin;
    int Choise = 0;
    while (Choise != 8) {
        std::cout << "Что вы хотите выполнить?" "\n" << "1. Сортировка числел с точкой" "\n" << "2. Сортировка чисел без точки" "\n" << "3. Сортировка символов" "\n" << "4. Ввод массива людей" "\n" << "5. Сортировка массива людей по возрасту" "\n" "6. Сортировка массива людей по имени" "\n" "7. Сортировка массива людей по фамилии" "\n" "8. Выход" "\n";
        std::cin >> Choise;
        if (Choise == 1) {
            vector <double> Doubles;
            std::cout << "Введите массив, окончанием которого будет -1 ";
            while (true) {
                double temp;
                std::cin >> temp;
                if (temp == -1) break;
                Doubles.push_back(temp);
            }
            quicksort(Doubles, 0, (Doubles.size() - 1));
            for (auto i : Doubles) {
                std::cout << i << ' ';
            }
            std::cout << std::endl;
        }
        if (Choise == 2) {
            vector <int> Ints;
            std::cout << "Введите массив, окончанием которого будет -1 ";
            while (true) {
                int temp;
                std::cin >> temp;
                if (temp == -1) break;
                Ints.push_back(temp);
            }
            quicksort(Ints, 0, (Ints.size() - 1));
            for (auto i : Ints) {
                std::cout << i << ' ';
            }
            std::cout << std::endl;
        }
        if (Choise == 3) {
            vector <char> Chars;
            std::cout << "Введите массив, окончанием которого будет A ";
            while (true) {
                char temp;

                std::cin >> temp;
                if (temp == 'A') break;
                Chars.push_back(temp);

            }
            quicksort(Chars, 0, (Chars.size() - 1));
            for (auto i : Chars) {
                std::cout << i << ' ';
            }
            std::cout << std::endl;
        }
        if (Choise == 4) {
            std::cout << "Введите масив людей формата \"Имя, Фамилия, Возраст\" ";
            while (a == 0)
            {
                std::cin >> Name >> Surname >> Age;
                if (Age == -1) break;
                dbin.Name = Name;
                dbin.Surname = Surname;
                dbin.Age = Age;
                db.push_back(dbin);
            }
        }
        if (Choise == 5) {
            dbmir = db;
            for (int i = 0; i < db.size(); i++) Ages.push_back(db[i].Age);
            quicksort(Ages, 0, (Ages.size() - 1));
            for (int i = 0; i < Ages.size(); i++) {
                for (int j = 0; j < dbmir.size(); j++) {
                    if (dbmir[j].Age == Ages[i]) {
                        std::cout << dbmir[j].Name << " " << dbmir[j].Surname << " " << db[j].Age << std::endl;
                        dbmir[j].Age = -1;
                    }
                }
            }
        }
        if (Choise == 6) {
            dbmir = db;
            for (int i = 0; i < db.size(); i++) Names.push_back(db[i].Name);
            quicksort(Names, 0, (Names.size() - 1));
            for (int i = 0; i < Names.size(); i++) {
                for (int j = 0; j < dbmir.size(); j++) {
                    if (dbmir[j].Name == Names[i]) {
                        std::cout << dbmir[j].Name << " " << dbmir[j].Surname << " " << db[j].Age << std::endl;
                        dbmir[j].Name = -1;
                    }
                }
            }
        }
        if (Choise == 7) {
            dbmir = db;
            for (int i = 0; i < db.size(); i++) Surnames.push_back(db[i].Surname);
            quicksort(Surnames, 0, (Surnames.size() - 1));
            for (int i = 0; i < Surnames.size(); i++) {
                for (int j = 0; j < dbmir.size(); j++) {
                    if (dbmir[j].Surname == Surnames[i]) {
                        std::cout << dbmir[j].Name << " " << dbmir[j].Surname << " " << db[j].Age << std::endl;
                        dbmir[j].Surname = -1;
                    }
                }
            }
        }
    }

}
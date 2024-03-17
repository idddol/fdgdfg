#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int proverkaI() {
    int var;
    string s1, s2;
    bool is_incorrect_input = true;
    while (is_incorrect_input)
    {
        cin >> s1;

        try
        {
            var = stoi(s1);
            s2 = to_string(var);
            if (s1 == s2 && var > 1)
                is_incorrect_input = false;
            else
                cout << "Некорректное значение! " << endl;
        }
        catch (invalid_argument)
        {
            cout << "Некорректное значение! " << endl;
        }
    }
    return var;
}
//double proverka() {
//    /*
//    Функция проверки вводимых значений
//    */
//    double var;
//    string s, s2;
//    bool is_incorrect_input = true;
//    while (is_incorrect_input)
//    {
//        cin >> s;
//
//        try
//        {
//            var = stod(s);
//            s2 = to_string(var);
//            s2.resize(s.size());
//            if (s == s2 && var > 0)
//                is_incorrect_input = false;
//            else
//                cout << "Incorrect input! " << endl;
//        }
//        catch (invalid_argument)
//        {
//            cout << "Incorrect input! " << endl;
//        }
//    }
//    return var;
//}


double proverka() {
    double var;
    string s1, s2;
    bool is_incorrect_input = true;
    while (is_incorrect_input)
    {

        try
        {
            cin >> var;
            is_incorrect_input = false;
        }
        catch (invalid_argument)
        {
            cout << "Некорректное значение! " << endl;
        }
    }
    cout << "var " << var << endl;
    return var;
}
double proverkaD() {
    double var;
    string s1, s2;
    bool is_incorrect_input = true;
    while (is_incorrect_input)
    {
        cin >> s1;

        try
        {
            cout << to_string(stod(s1)) << " " << stod(s1) << endl;
            var = stod(s1);
            s2 = to_string(var);
            s2.resize(s1.size());
            cout << s2 << " " << s1 << endl;
            if (s1 == s2) {
                is_incorrect_input = false;
            }
            else {
                cout << "Некорректное значение! " << endl;
            }
        }
        catch (invalid_argument)
        {
            cout << "Некорректное значение! " << endl;
        }
    }
    return var;
}
//вывод ср знач, целые + дробные, подписать результат,

bool wantTocontinue()
{
    string s;
    bool is_incorrect_input = true;
    while (is_incorrect_input)
    {
        cout << "Желаете продолжить? y/n > ";
        cin >> s;
        if (s == "y" || s == "Y")
            return true;
        else if (s == "n" || s == "N")
            return false;
        else {
            cout << "Попробуйте снова. Некорректное значение! " << endl;
        }
    }
}

int main()
{
    bool flag = true;
    while (flag) {
        setlocale(LC_ALL, "Russian");
        int n;
        cout << "Введите размер массива: " << endl;
        n = proverkaI();
        double* numbers = new double[n];
        int count = 0;
        double sum = 0;
        cout << "Введите массив: " << endl;
        for (int i = 0; i < n; i++) {
            numbers[i] = proverka();
            sum += numbers[i];
        }
        cout << sum << endl;
        double sr_znach = sum / n;
        for (int i = 0; i < n; i++) {
            if (numbers[i] - sr_znach > 0) {
                count++;
            }
        }
        cout << "Среднее значение: " << sr_znach << " Результат: " << count << endl;
        flag = wantTocontinue();
    }
}


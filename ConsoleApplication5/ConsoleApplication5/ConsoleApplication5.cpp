#include <iostream>
#include <string>

using namespace std;

bool anscheck()
{
    string s;
    bool is_incorrect_input = true;
    while (is_incorrect_input)
    {
        cout << "Do you want to continue? y/n > " << endl;
        cin >> s;
        if (s == "y" || s == "Y")
            return true;
        else
        {
            if (s == "n" || s == "N") {
                cout << "Goodbye =) " << endl;
                return false;
            }
            else
                cout << "Try again. Incorrect input! " << endl;
        }
    }
}

int proverka(int type) {
    int var;
    string s;
    bool is_incorrect_input = true;
    if (type == 0) {
        while (is_incorrect_input)
        {
            cin >> s;

            try
            {
                var = stoi(s);
                if (s.size() == to_string(var).size() && var > 1)
                    is_incorrect_input = false;
                else
                    cout << "Incorrect input! Try again: ";
            }
            catch (invalid_argument)
            {
                cout << "Incorrect input! Try again: ";
            }
        }
    }
    else {
        while (is_incorrect_input)
        {
            cin >> s;

            try
            {
                var = stoi(s);
                if (s.size() == to_string(var).size())
                    is_incorrect_input = false;
                else
                    cout << "Incorrect input! Try again: ";
            }
            catch (invalid_argument)
            {
                cout << "Incorrect input! Try again: ";
            }
        }
    }
    return var;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    bool flag = true;
    while (flag) {
        cout << "Введите переменную x: " << endl;
        int x = proverka(1);
        cout << "Введите переменную a: " << endl;
        int a = proverka(1);




        flag = anscheck();
    }
}

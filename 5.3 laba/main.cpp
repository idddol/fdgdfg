#include <iostream>
#include "Matrix.h"

using std::cout;
using std::cin;

int main()
{
    setlocale(LC_ALL, "Russian");
    int choise;
    int a = 0;
    while (a == 0)
    {
        std::cout << "Что вы хотите выполнить?" "\n" << "1. След" "\n" << "2. Ввод и вывод матрицы " "\n" << "3. Сумма матриц" "\n" << "4. Умножение матрицы на число" "\n" << "5. Разница матриц" "\n" "6. Смена знака" "\n" "7. Выход" "\n";
        cin >> choise;
        if (choise == 1) {
            Matrix m1;
            cin >> m1;
            cout << m1.trase() << '\n';
        }
        else if (choise == 2) {
            Matrix m1;
            cin >> m1;
            cout << m1 << '\n';
        }
        else if (choise == 3) {
            Matrix m1, m2;
            cin >> m1;
            cin >> m2;
            m1 + m2;
            cout << '\n';
        }
        else if (choise == 4) {
            Matrix m1;
            int k;
            cin >> m1 >> k;
            m1* k;
            cout << m1;
        }
        else if (choise == 5) {
            Matrix m1, m2;
            cin >> m1;
            cin >> m2;
            m1 - m2;
            cout << '\n';
        }
        else if (choise == 6) {
            Matrix m1;
            cin >> m1;
            -m1;
            cout << '\n';
        }
        else a++;
    }
}

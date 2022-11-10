#include <iostream>
#include "Matrix.h"

using std::cin;
using std::cout;

/*Matrix input() {
    int i, j;
    cout << "������� ����� ����� � �������� ";
    cin >> i >> j;
    cout << "������� ������� ";
    Matrix matr(i, j);
    return matr;
}*/

int main()
{
    setlocale(LC_ALL, "Russian");
    int choise;
    int a = 0;
    int k, i, j;
    Matrix matr1;
    Matrix matr2;
    Matrix matr3;
    while (a == 0) {
        std::cout << "��� �� ������ ���������?" "\n" << "1. ����" "\n" << "2. �����" "\n" << "3. �������� ���� ������" "\n" << "4. ��������� ���� ������" "\n" << "5. ���� �������" "\n" << "6. ��������� ������� �� �����" "\n" << "7. ���������� ��������" "\n" << "8. ���������� �����" "\n" << "9. ������� (i,j) ������� " "\n" << "10. �����" "\n";
        cin >> choise;
        switch (choise)
        {
        case 1:
            //matr1(2);
            cout << "������� ����� ����� � �������� ";
            cin >> i >> j;
            cout << "������� ������� ";
            matr1.make(i, j);
            //matr1 = input();
            break;
        case 2:
            matr1.output();
            break;
        case 3:
            cout << "������� ����� ����� � �������� ";
            cin >> i >> j;
            cout << '\n' << "������� ������� ";
            matr2.make(i, j);
            matr1.sum_matrix(matr2);
            matr1.output();
            break;
        case 4:
            cout << "������� ����� ����� � �������� ";
            cin >> i >> j;
            cout << "������� ������� ";
            matr2.make(i, j);
            matr1.mult_matrix(matr2);
            break;
        case 5:
            matr1.trase();
            break;
        case 6:
            cout << "������� ��������� ";
            cin >> k;
            matr1.mult_number(k);
            break;
        case 7:
            cout << matr1.get_col() << '\n';
            break;
        case 8:
            cout << matr1.get_row() << '\n';
            break;
        case 9:
            cout << "������� i � j ";
            cin >> i >> j;
            cout << matr1.get_elem(i, j) << '\n';
            break;
        case 10:
            cout << "����� ��������";
            a++;
        default:
            break;
        }
    }
}


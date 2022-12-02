#include <iostream>
#include "Circle.h";
#include "Position.h";
#include "Square.h";
#include "CircleInSq.h"

using std::cout;
using std::cin;

int main()
{
    setlocale(LC_ALL, "Russian");
    int choise;
    double x, y, side, rad;
    int a = 0;
    while (a == 0)
    {
        std::cout << "��� �� ������ ���������?" "\n" << "1. ���� �������" "\n" << "2. ���� ����� �������������" "\n" << "3. ���� ������� ����������" "\n" << "4. ���� �������� �������������" "\n" << "5. ���� ������� ��������" "\n" "6. ���� ���������� � �������� �� �������" "\n" "7. ���� ���������� � �������� �� ������� ��������" "\n" "8. �����" "\n";
        cin >> choise;
        if (choise == 1) {
            cout << "������� x � y "; cin >> x >> y;
            Position a(x, y);
            a.out();
        }
        if (choise == 2) {
            cout << "������� ���������� ������ � ������ "; cin >> x >> y >> rad;
            Circle a(x, y, rad);
            a.out();
        }
        if (choise == 3) {
            cout << "������� ������ "; cin >> rad;
            Circle a(rad);
            a.out();
        }
        if (choise == 4) {
            cout << "������� ���������� ������ � ������� "; cin >> x >> y >> side;
            Square a(x, y, side);
            a.out();
        }
        if (choise == 5) {
            cout << "������� ������� "; cin >> side;
            Square a(side);
            a.out();
        }
        if (choise == 6) {
            cout << "������� ���������� ������ � ������ "; cin >> x >> y >> rad;
            CircleInSq a(x, y, rad);
            a.Circle::out();
            a.Square::out();
        }
        if (choise == 7) {
            cout << "������� ������� "; cin >> side;
            CircleInSq a(side);
            a.Circle::out();
            a.Square::out();
        }
        if (choise == 8) {
            a++;
        }
    }
    return 0;
}
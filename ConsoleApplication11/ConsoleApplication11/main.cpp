#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<cstring>
#include<conio.h>
#include<cstdlib>
extern "C"
{
    int calcSumm(int, int) {};
}
int main()
{
    int k, a, b;
    std::ifstream in("myin.txt"); //��������� ���� ��� ���������� ���������� 
    in >> a >> b; //��������� int�
    in.close(); // ��������� ����
    //std:: cout<<a<<"\n";  //������� �������� a �� ����� 
  //std:: cout<<b;
    k = calcSumm(a, b);
    std::ofstream out("myout.txt"); // ��������� ���� ��� ������
    out << k << "\n"; //���������� ������ �������
    out.close(); //��������� ����
   // getch();
    return 0;
}

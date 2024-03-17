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
    std::ifstream in("myin.txt"); //Открываем файл для считывания информации 
    in >> a >> b; //считываем intы
    in.close(); // Закрываем файл
    //std:: cout<<a<<"\n";  //Выводим значение a на экран 
  //std:: cout<<b;
    k = calcSumm(a, b);
    std::ofstream out("myout.txt"); // Открываем файл для записи
    out << k << "\n"; //Записываем первую строчку
    out.close(); //Закрываем файл
   // getch();
    return 0;
}

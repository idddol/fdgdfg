#include<iostream>
#include<fstream>
#include<cstring>
#include<conio.h>
#include<cstdlib>

using namespace std;

//extern "C"
//{
//    int calcSumm(int, int);
//}


int main()
{
    setlocale(LC_ALL, "Russian");
    int k, a, b, c;
    int n = 0;
    //(-107/a + c-3*a)/(4-2*a*b)
    cout << "Введите a, b, c: \n";
    cin >> a >> b >> c; //считываем intы
    _asm {
        mov eax, -107
        mov ebx, a
        test ebx, ebx
        jz m
        cdq; готовимся к делению eax ==> edx:eax
        idiv a; eax = -107 / a
        mov ebx, c
        sub ebx, eax; ebx = c - 107 / a
        mov eax, 3
        imul eax, a; < edx:eax >= 3 * a
        jo m1
        sub ebx, eax; ebx = c - 107 / a - 3 * a


        push ebx; в стеке c - 107 / a - 3 * a

        mov eax, 2; eax = 2
        imul a; <edx:eax> = 2 * a
        jo m1
        imul b; <edx:eax> = 2 * a * b
        jo m1
        mov ebx, 4; ebx = 4
        sub ebx, eax; ebx = 4 - 2 * a * b

        pop eax; eax = c - 107 / a - 3 * a

        cdq; eax ==> <edx:eax> = c - 107 / a - 3 * a
        test ebx, ebx
        jz m
        idiv ebx; eax = (c - 107 / a - 3 * a) / (4 - 2 * a * b)
        jmp m3
        m : mov n, 1
        jmp m3
        m1 : mov n, 2
        m3 :
        mov k, eax

    }
    if (n == 0) {
        cout << k << "\n"; //Записываем первую строчку
    }
    else if (n == 1) {
        cout << "Ошибка деления на 0" << endl;
    }
    else if (n == 2) {
        cout << "Ошибка переполнения" << endl;
    }
    return 0;
}


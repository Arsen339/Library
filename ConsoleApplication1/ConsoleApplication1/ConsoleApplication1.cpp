/*Проект: Библиотека (статья в журнале)
Создайте структуру artical со следующими полями:
Тип данных	Назначение поля
char*	название журнала 
int	номер
int	год 
char*	Фамилия автора 
char*	имя автора 
char*	Название статьи 
Создать массив из n  статей (ввод с клавиатуры)
Реализовать функции : 
⦁	добавить новую статью;
⦁	распечатать информацию о статье в табличном виде;
⦁	найти все статьи заданного автора, результат вывести на экран;
⦁	Найти всех авторов заданного журнала (журнал – это название + номер + год),  результат отсортировать по алфавиту, запомнить в массиве и вывести на экран;*/



#define _CRT_SECURE_NO_WARNINGS //для использования функции strcpy
#include <iostream>
#include <clocale>
#include<fstream>
#include <string>
#include <string.h>
#include<stdio.h>
#include <iomanip>
#include <vector>
using namespace std;
struct hip {
    char* line;
    char* line1;
};



struct artical {

    char* introduce;
    int number;
    int year;

    char* surname;
    char* name;
    char* title;
};




void push_back(artical*& arr, int& size) {
    artical* newArray = new artical[size + 1];
    for (int i = 0; i < size; i++)
        newArray[i] = arr[i];
    delete[] arr;
    arr = newArray;
    size++;



}


int main()
{
    setlocale(LC_ALL, "Russian");
    int goon = 10;


    int n;
    char buff[80] = { 'q' };
    char buff1[80] = { 'q' };
    char buff2[80] = { 'q' };
    int buff3;
    int buff4;
    int flag = 0;





    cout << "Введите количество статей n" << endl;   cin >> n;

    artical* arr = new artical[n];
    for (int i = 0; i < n; i++) {

        cout << "Название журнала: ";
        cin >> buff;
        arr[i].introduce = new char[strlen(buff) + 1];
        strcpy(arr[i].introduce, buff);

        cout << "Номер журнала: "; cin >> arr[i].number;
        cout << "Год издания: "; cin >> arr[i].year;
        cout << "Фамилия автора: ";
        cin >> buff;
        arr[i].surname = new char[strlen(buff) + 1];
        strcpy(arr[i].surname, buff);

        cout << "Имя автора: ";
        cin >> buff;
        arr[i].name = new char[strlen(buff) + 1];
        strcpy(arr[i].name, buff);

        cout << "Название статьи: ";
        cin >> buff;
        arr[i].title = new char[strlen(buff) + 1];
        strcpy(arr[i].title, buff);
        cout << "Описание статьи завершено";
        cout << endl;
        cout << endl;
    }





    while (goon != 0) {
        hip* w = new hip[1];
        hip* matr = new hip[1];
        cout << "_________________________________Диалоговое окно____________________________________" << endl;
        cout << "Добавить новую статью  ................ 1" << endl;
        cout << "Распечатать архив статей .............. 2" << endl;
        cout << "Найти все статьи данного автора   ..... 3" << endl;
        cout << "Найти всех авторов данного журнала .... 4" << endl;
        cout << "Для выхода из программы введите 0 " << endl;
        cout << endl;
        cin >> goon;
        switch (goon) {

        case 1:
            push_back(arr, n);
            for (int i = n - 1; i < n; i++) {

                cout << "Название журнала: ";
                cin >> buff;
                arr[i].introduce = new char[strlen(buff) + 1];
                strcpy(arr[i].introduce, buff);	// копировать buff в динамическую память

                cout << "Номер журнала: "; cin >> arr[i].number;	// ввод поля «цена»
                cout << "Год издания: "; cin >> arr[i].year; // ввод поля «кол-во»

                cout << "Фамилия автора: ";
                cin >> buff;
                arr[i].surname = new char[strlen(buff) + 1];
                strcpy(arr[i].surname, buff);

                cout << "Имя автора: ";
                cin >> buff;
                arr[i].name = new char[strlen(buff) + 1];
                strcpy(arr[i].name, buff);

                cout << "Название статьи: ";
                cin >> buff;
                arr[i].title = new char[strlen(buff) + 1];
                strcpy(arr[i].title, buff);
                cout << "Описание статьи завершено";
                cout << endl;
                cout << endl;
            }
            break;

        case 2:
            for (int i = 0; i < n; i++)
            {
                cout << "Название журнала" << setw(23) << "Номер журнала" << setw(23) << "Год издания" << setw(23) << "Фамилия автора" << setw(23) << "Имя автора" << setw(23) << "Название статьи" << endl;
                cout << arr[i].introduce << setw(23) << arr[i].number << setw(26) << arr[i].year << setw(24) << arr[i].surname << setw(24) << arr[i].name << setw(23) << arr[i].title << endl;
                cout << endl;
            }
            break;


        case 3:

            flag = 0;
            cout << " Введите фамилию автора:  " << endl;
            cin >> buff1;
            w[0].line = new char[strlen(buff1) + 1];
            strcpy(w[0].line, buff1);
            cout << " Введите имя автора:  " << endl;
            cin >> buff2;
            w[0].line1 = new char[strlen(buff2) + 1];
            strcpy(w[0].line1, buff2);
            cout << " Введите имя автора:  " << endl;
            for (int i = 0; i < n; i++) {
                if (!strcmp(w[0].line, arr[i].surname) && !strcmp(arr[i].name, w[0].line1)) {
                    flag++;
                    cout << "Статья данного автора:" << endl;
                    cout << arr[i].title << endl;
                    cout << endl;
                }

            }
            if (flag == 0) {
                cout << "Статей данного автора не найдено" << endl;

            }
            delete[]w;
            break;

        case 4:


            flag = 0;
            cout << "Введите название журнала: " << endl;
            cin >> buff1;
            matr[0].line = new char[strlen(buff1) + 1];
            strcpy(matr[0].line, buff1);
            cout << "Введите год издания журнала:  " << endl;
            cin >> buff4;
            cout << "Введите номер журнала:  " << endl;
            cin >> buff3;
            for (int i = 0; i < n; i++) {
                if (!strcmp(arr[i].introduce, matr[0].line) && arr[i].year == buff4 && arr[i].number == buff3) {
                    flag++;
                    cout << arr[i].name << "   " << arr[i].surname << "   " << "Публиковал/публиковала статью в этом журнале" << endl;
                    cout << endl;
                }


            }
            if (flag == 0) {
                cout << "Авторов журнала не найдено или некорректно введено название журнала" << endl;

            }

            delete[]matr;
            break;


        }
    }
    system("pause");
    return 0;
}

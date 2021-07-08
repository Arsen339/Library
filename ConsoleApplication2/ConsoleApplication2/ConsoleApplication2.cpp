// Library(extended)
/*
Приспособить функции для работы со списком
⦁	добавить новую статью в заданную (по номеру) позицию;
⦁	удалить все статьи определенного года;
⦁	сортировать основной список по алфавиту (название журнала);

*/
#define _CRT_SECURE_NO_WARNINGS //для использования функции strcpy
#include <iostream>
#include <clocale>
#include<fstream>
#include <string>
#include <string.h>
#include<stdio.h>
#include <iomanip>
#include <vector>
#define NN 80


using namespace std;
struct artical {

    char* introduce;
    int number;
    int year;

    char* surname;
    char* name;
    char* title;
};

struct hip {
    char* line;
    char* line1;
    int CreatYear;
    int NumberOfMagazine;
};

struct List {
    artical art;
    List* next;
};

void Print(List* b) {
    List* print = b;
    while (print) {

        cout << "Название журнала" << setw(23) << "Номер журнала" << setw(23) << "Год издания" << setw(23) << "Фамилия автора" << setw(23) << "Имя автора" << setw(23) << "Название статьи" << endl;
        cout << print->art.introduce << setw(23) << print->art.number << setw(26) << print->art.year << setw(24) << print->art.surname << setw(24) << print->art.name << setw(23) << print->art.title << endl;
        cout << endl;
        print = print->next;

    }

}

void SelectivePrint(List* b, hip* mass) {
    List* print = b;
    while (print) {
        if (!strcmp(print->art.surname, mass[0].line) && !strcmp(print->art.name, mass[0].line1)) {
            cout << "Название журнала" << setw(23) << "Номер журнала" << setw(23) << "Год издания" << setw(23) << "Фамилия автора" << setw(23) << "Имя автора" << setw(23) << "Название статьи" << endl;
            cout << print->art.introduce << setw(23) << print->art.number << setw(26) << print->art.year << setw(24) << print->art.surname << setw(24) << print->art.name << setw(23) << print->art.title << endl;
            cout << endl;
        }
        print = print->next;

    }





}


void AuthorSearch(List* b, hip* mass) {
    List* print = b;
    while (print) {
        if (!strcmp(print->art.introduce, mass[0].line) && print->art.year == mass[0].CreatYear && print->art.number == mass[0].NumberOfMagazine) {
            cout << "Автор журнала: " << endl;
            cout << print->art.surname << "  " << print->art.name << endl;
            cout << endl;
        }
        print = print->next;

    }





}






void Init(List** begin, artical* mass, int am) {
    *begin = new List;
    (*begin)->art = mass[0];
    (*begin)->next;

    List* end = *begin;
    for (int i(0); i < am; i++) {

        end->next = new List;
        end = end->next;
        end->art = mass[i];
        end->next = NULL;

    }


}

//void Add_begin(List** begin, const  A& a) {
//    List* t = new List;
//    t->a = a;
//    t->next = *begin;
//    *begin = t;
//
//}
//
void Insert(List** begin, artical* mass, int position, int sizeofmas) {
    List* ins = new List;
    ins->art = mass[sizeofmas - 1];
    List* t = *begin;
    if (t->art.number >= position) {
        ins->next = t;
        *begin = ins;
        return;
    }

    List* t1 = t->next;
    while (t1) {
        if (t->art.number < position && position < t1->art.number) {
            t->next = ins;
            ins->next = t1;
            return;
        }
        t = t1;
        t1 = t1->next;
    }
    t->next = ins;
    ins->next = NULL;
}




void Delete(List** begin, int order) {
    if (*begin == NULL) {
        return;
    }
    List* t = *begin;
    List* t1 = t->next;
    while (t1) {
        if (t1->art.number == order) {
            t->next = t1->next;
            delete t1;
            return;

        }
        t = t1;
        t1 = t1->next;
    }
}


void DeleteYear(List** begin, int dateOfYear) {
    if (*begin == NULL) {
        return;
    }
    List* t = *begin;
    List* t1 = t->next;
    while (t1) {
        if (t1->art.year == dateOfYear) {
            t->next = t1->next;
            delete t1;
            return;

        }
        t = t1;
        t1 = t1->next;
    }
}




void Free(List** begin) {
    if (*begin == 0) return;
    List* p = *begin;
    List* t;
    while (p) {
        t = p;
        p = p->next;
        delete t;

    }

}



















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

    int DelYear;
    int location;
    int n;
    int NumberArea;
    int YearArea;
    char buff[80] = { 'q' };
    char buff1[80] = { 'q' };
    char buff2[80] = { 'q' };
    int buff3;
    int buff4;
    int flag = 0;



    string fname = "C:/Users/Comp/Source/Repos/Project3/Test1.txt";
    ofstream outf(fname);
    cout << "Введите количество статей n" << endl;   cin >> n;

    artical* arr = new artical[n];
    for (int i = 0; i < n; i++) {

        cout << "Название журнала: ";
        cin >> buff;
        outf << buff << endl;;
        arr[i].introduce = new char[strlen(buff) + 1];
        strcpy(arr[i].introduce, buff);

        cout << "Номер журнала: " << i + 1 << endl;
        arr[i].number = i + 1;
        outf << i + 1 << endl;
        cout << "Год издания: "; cin >> arr[i].year;
        outf << arr[i].year << endl;
        cout << "Фамилия автора: ";
        cin >> buff;
        outf << buff << endl;
        arr[i].surname = new char[strlen(buff) + 1];
        strcpy(arr[i].surname, buff);

        cout << "Имя автора: ";
        cin >> buff;
        outf << buff << endl;
        arr[i].name = new char[strlen(buff) + 1];
        strcpy(arr[i].name, buff);

        cout << "Название статьи: ";
        cin >> buff;
        outf << buff << endl;
        arr[i].title = new char[strlen(buff) + 1];
        strcpy(arr[i].title, buff);
        cout << "Описание статьи завершено";
        cout << endl;
        cout << endl;
    }
    outf.close();
    List* begin = NULL;
    Init(&begin, arr, n);
    Delete(&begin, 1);







    while (goon != 0) {
        hip* w = new hip[1];
        hip* matr = new hip[1];
        cout << "_________________________________Диалоговое окно____________________________________" << endl;
        cout << "Добавить новую статью   ............... 1" << endl;
        cout << "Распечатать архив статей .............. 2" << endl;
        cout << "Найти все статьи данного автора   ..... 3" << endl;
        cout << "Найти всех авторов данного журнала .... 4" << endl;
        cout << "Удалить статью определенного года.........5" << endl;
        cout << "Для выхода из программы введите 0 " << endl;
        cout << endl;
        cin >> goon;
        switch (goon) {

        case 1:
            cout << "Введите, каким номером вы хотите добавить статью" << endl;
            cin >> location;
            push_back(arr, n);
            for (int i = n - 1; i < n; i++) {

                cout << "Название журнала: ";
                cin >> buff;
                arr[i].introduce = new char[strlen(buff) + 1];
                strcpy(arr[i].introduce, buff);	// копировать buff в динамическую память


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

            for (int i = location - 1; i < n; i++) {
                arr[i].number = i + 2;
            }
            Free(&begin);
            Init(&begin, arr, n);
            Delete(&begin, 1);
            arr[n - 1].number = location;


            Insert(&begin, arr, location, n);
            Delete(&begin, n + 1);

            break;

        case 2:
            Print(begin);
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
            SelectivePrint(begin, w);



            delete[]w;
            break;

        case 4:


            flag = 0;
            cout << "Введите название журнала: " << endl;
            cin >> buff1;
            matr[0].line = new char[strlen(buff1) + 1];
            strcpy(matr[0].line, buff1);
            cout << "Введите год издания журнала:  " << endl;
            cin >> YearArea;
            matr[0].CreatYear = YearArea;
            cout << "Введите номер журнала:  " << endl;
            cin >> NumberArea;
            matr[0].NumberOfMagazine = NumberArea;
            AuthorSearch(begin, matr);


            delete[]matr;
            break;

        case 5:


            cout << "Введите год, статьи которого хотите удалить" << endl;
            cin >> DelYear;
            cout << DelYear;
            DeleteYear(&begin, DelYear);




        }



    }
    system("pause");
    return 0;
}

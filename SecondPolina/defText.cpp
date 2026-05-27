#include "defText.h"
#include "defStr.h"
#include <iostream>
#include <fstream>
using namespace std;

int inputText(Text& A, fstream& f)
{
    // Очистка предыдущего текста
    if (A.pS != nullptr)
        clearText(A);

    char ch;
    f.unsetf(ios::skipws);
    streampos startPos = f.tellg();

    // Подсчет количества строк
    A.L = 0;
    while (!f.eof())
    {
        f >> ch;
        if (f.eof()) break;
        if (ch == '\n')
            A.L++;
    }

    // Проверяем, есть ли последняя строка без \n
    f.clear();
    f.seekg(-1, ios::end);
    f >> ch;
    if (ch != '\n' && f.good()) {
        A.L++;
    }

    // Возврат к началу файла
    f.clear();
    f.seekg(startPos);

    // Если файл пуст
    if (A.L == 0)
    {
        A.pS = nullptr;
        return 0;
    }

    // Выделение памяти под массив указателей (двойной указатель)
    A.pS = new Str * [A.L];

    // Чтение всех строк
    for (unsigned i = 0; i < A.L; i++)
    {
        A.pS[i] = new Str;
        A.pS[i]->pA = nullptr;
        A.pS[i]->Len = 0;
        inputStr(*A.pS[i], f);
    }

    return 0;
}

void outText(Text& A, ofstream& fout)
{
    for (unsigned i = 0; i < A.L; i++)
    {
        if (A.pS[i] != nullptr && A.pS[i]->pA != nullptr)
        {
            fout << A.pS[i]->pA << endl;
            cout << A.pS[i]->pA << endl;
        }
    }
}

void clearText(Text& t)
{
    if (t.pS == nullptr)
        return;

    for (unsigned i = 0; i < t.L; i++)
    {
        if (t.pS[i] != nullptr)
        {
            clearStr(*t.pS[i]);
            delete t.pS[i];
            t.pS[i] = nullptr;
        }
    }

    delete[] t.pS;
    t.pS = nullptr;
    t.L = 0;
}
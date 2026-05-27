#include "defStr.h"
#include <iostream>
#include <fstream>
using namespace std;

int inputStr(Str& a, fstream& f)
{
    f.unsetf(ios::skipws);

    int capacity = 100;
    a.pA = new char[capacity];
    a.Len = 0;

    char ch;
    while (true)
    {
        f >> ch;
        if (f.eof() || ch == '\n')
            break;

        if (a.Len >= capacity - 1)
        {
            capacity *= 2;
            char* newBuffer = new char[capacity];
            for (unsigned i = 0; i < a.Len; i++)
                newBuffer[i] = a.pA[i];
            delete[] a.pA;
            a.pA = newBuffer;
        }

        a.pA[a.Len] = ch;
        a.Len++;
    }

    if (a.Len >= capacity)
    {
        char* newBuffer = new char[a.Len + 1];
        for (unsigned i = 0; i < a.Len; i++)
            newBuffer[i] = a.pA[i];
        delete[] a.pA;
        a.pA = newBuffer;
    }
    a.pA[a.Len] = '\0';

    return 0;
}

void outStr(Str& a, ofstream& fout)
{
    if (a.pA != nullptr)
    {
        fout << a.pA;
    }
}

void clearStr(Str& s) {
    if (s.pA != nullptr) {
        delete[] s.pA;
        s.pA = nullptr;
        s.Len = 0;
    }
}
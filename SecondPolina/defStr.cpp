#include "defStr.h"
#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

static void mySwap(char& a, char& b)
{
    char temp = a;
    a = b;
    b = temp;
}

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

void outStrToConsole(Str& a)
{
    if (a.pA != nullptr)
    {
        cout << a.pA;
    }
}

void clearStr(Str& s) {
    if (s.pA != nullptr) {
        delete[] s.pA;
        s.pA = nullptr;
        s.Len = 0;
    }
}

void reverseWordsInStr(Str& s)
{
    if (s.pA == nullptr || s.Len == 0)
        return;

    int start = -1;

    for (unsigned j = 0; j <= s.Len; j++)
    {
        char c = (j < s.Len) ? s.pA[j] : '\0';

        if (j < s.Len && isalpha((unsigned char)c))
        {
            if (start == -1)
                start = j;
        }
        else
        {
            if (start != -1)
            {
                int end = j;
                for (int c = 0; c < (end - start) / 2; c++)
                {
                    mySwap(s.pA[start + c], s.pA[end - 1 - c]);
                }
                start = -1;
            }
        }
    }
}
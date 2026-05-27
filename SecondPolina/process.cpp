#include "process.h"
#include "defText.h"
#include <iostream>
#include <fstream>
using namespace std;

void mySwap(char& a, char& b)
{
    char temp = a;
    a = b;
    b = temp;
}

void process(Text& txt)
{
    cout << "НАЧАЛО PROCESS - переворачивание слов в каждой строке" << endl;

    if (txt.L == 0 || txt.pS == nullptr)
    {
        cout << "Текст пуст" << endl;
        return;
    }

    for (unsigned i = 0; i < txt.L; i++)
    {
        if (txt.pS[i] == nullptr || txt.pS[i]->pA == nullptr)
            continue;

        Str* currentStr = txt.pS[i];
        int start = -1;

        for (unsigned j = 0; j <= currentStr->Len; j++)
        {
            char c = (j < currentStr->Len) ? currentStr->pA[j] : '\0';

            if (j < currentStr->Len && isalpha((unsigned char)c))
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
                        mySwap(currentStr->pA[start + c], currentStr->pA[end - 1 - c]);
                    }
                    start = -1;
                }
            }
        }
    }

    cout << "=== КОНЕЦ PROCESS ===" << endl;
}
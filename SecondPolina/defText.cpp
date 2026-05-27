#include "defText.h"
#include "defStr.h"
#include <iostream>
#include <fstream>
using namespace std;

int inputText(Text& A, fstream& f)
{
    if (A.pS != nullptr)
        clearText(A);

    char ch;
    f.unsetf(ios::skipws);
    streampos startPos = f.tellg();

    A.L = 0;
    while (!f.eof())
    {
        f >> ch;
        if (f.eof()) break;
        if (ch == '\n')
            A.L++;
    }

    f.clear();
    f.seekg(-1, ios::end);
    f >> ch;
    if (ch != '\n' && f.good()) {
        A.L++;
    }

    f.clear();
    f.seekg(startPos);

    if (A.L == 0)
    {
        A.pS = nullptr;
        return 0;
    }

    A.pS = new Str * [A.L];

    for (unsigned i = 0; i < A.L; i++)
    {
        A.pS[i] = new Str;
        A.pS[i]->pA = nullptr;
        A.pS[i]->Len = 0;
        inputStr(*A.pS[i], f);
    }

    return 0;
}

void outStrToFile(Str& str, ofstream& fout)
{
    if (str.pA != nullptr)
    {
        fout << str.pA << endl;
        cout << str.pA << endl;
    }
}

void outText(Text& A, ofstream& fout)
{
    for (unsigned i = 0; i < A.L; i++)
    {
        if (A.pS[i] != nullptr)
        {
            outStrToFile(*A.pS[i], fout);
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
#include "process.h"
#include "defText.h"
#include "defStr.h"
#include <iostream>
using namespace std;

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
        reverseWordsInStr(txt.pS[i]);
    }

    cout << "=== КОНЕЦ PROCESS ===" << endl;
}
#include <iostream>
#include <fstream>
#include <windows.h>
#include "defStr.h"
#include "defText.h"
#include "process.h"
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Text txt = { 0, nullptr };

    fstream f;
    f.open("text.txt", ios::in);
    if (!f.is_open())
    {
        cout << "Ошибка открытия файла" << endl;
        return 1;
    }

    if (f.peek() == EOF)
    {
        cout << "Файл пуст" << endl;
        f.close();
        return 0;
    }

    f.clear();
    f.seekg(0);

    inputText(txt, f);
    f.close();

    ofstream fout;
    fout.open("result.txt", ios::out);
    if (!fout.is_open())
    {
        cout << "Ошибка открытия файла result.txt" << endl;
        clearText(txt);
        return 1;
    }

    cout << "\nПрочитанные строки:" << endl;
    outText(txt, fout);

    process(txt);

    fout << "\nТекст после обработки:" << endl;
    outText(txt, fout);

    fout.close();

    clearText(txt);

    cout << "\nПрограмма успешно завершена" << endl;

    return 0;
}
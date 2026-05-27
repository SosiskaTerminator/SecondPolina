#ifndef TEXT_H
#define TEXT_H
#include "Str.h"
#include <iostream>
#include <fstream>
using namespace std;

struct Text
{
    unsigned L;     // количество строк
    Str** pS;       // двойной указатель на строки
};

#endif
#pragma once
#include <iostream>
#include <random>
#include "windows.h"
using namespace std;


string getCommand() {
    string command;
    getline(cin,command);
    for (char & i : command) {
        i = (char) tolower(i);
    }
    return command;
}

void clearStdin () {
    cin.clear();
    fflush(stdin);
}
void setlocaleRus () {
    setlocale(LC_ALL, "Rus");
}

void setlocale1251 () {
    setlocaleRus();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

int randomInteger (const int from, const int to) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(from,to);

    return dist(gen);
    //return (int)gen();
}

#pragma once
#include <iostream>
#include <random>
#include "windows.h"
using namespace std;


string getCommand() {
    cout << "\nВведите команду: ";
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

void setlocale1251 () {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

/*
void randomIntInit (int from, int to) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(from,to);
    // use gen(); or dist(gen);
}*/

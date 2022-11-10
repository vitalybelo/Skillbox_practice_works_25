#pragma once
#include <iostream>
#include "windows.h"
#include "use_lib.h"
#include "task1_structs.h"
using namespace std;

class Surgery {

private:

    Application2DXY scalpel;
    Application2DXY suture;
    ApplicationXY hemostat;
    ApplicationXY tweezers;
    bool isSutured = true;

public:

    void applyScalpel () {
        if (!isSutured) {
            cout << "\nПредыдущий разрез не зашит,\nпожалуйста завершите операцию\n\n";
            return;
        }
        cout << "\nВведите координаты начальной точки X Y: ";
        cin >> scalpel.Ax >> scalpel.Ay;
        cout << "Введите координаты конечной точки X Y: ";
        cin >> scalpel.Bx >> scalpel.By;

        if (coordinate2DXYisEqual(scalpel)) {
            cout << "Координаты начальной и конечной точки совпадают\n";
            cout << "Разрез не выполнен. Примените скальпель заново\n\n";
            return;
        }
        // TODO - придумать как сделать разрез ...

        cout << "Выполняется разрез:\n";
        cout << "\tA (x = " << scalpel.Ax << ", y = " << scalpel.Ay << ")\n";
        cout << "\tB (x = " << scalpel.Bx << ", y = " << scalpel.By << ")\n";
        Sleep(900);
        cout << "\tРазрез выполнен, продолжайте операцию ...\n\n";
        isSutured = false;
    }

    void applyHemostat () {
        cout << "\nВведите координаты точки зажима X Y: ";
        cin >> hemostat.x >> hemostat.y;
        // TODO - придумать как применить зажим ...

        cout << "\tЗажим применен в точке: (x = " << hemostat.x << ", y = " << hemostat.y << ")\n";
        cout << "\tПродолжайте операцию ...\n\n";
    }

    void applyTweezers () {
        cout << "\nВведите координаты применения пинцета X Y: ";
        cin >> tweezers.x >> tweezers.y;
        // TODO - придумать как применить пинцет ...

        cout << "\tПинцет применен в точке: (x = " << tweezers.x << ", y = " << tweezers.y << ")\n";
        cout << "\tПродолжайте операцию ...\n\n";
    }

    bool applySuture () {

        if (isSutured) {
            cout << "\nЗашивать нечего, разрез не был выполнен.\n\n";
            return false;
        }
        cout << "\nВведите координаты начальной точки X Y: ";
        cin >> suture.Ax >> suture.Ay;
        cout << "Введите координаты конечной точки X Y: ";
        cin >> suture.Bx >> suture.By;

        char yes_no;
        if (!coordinates2DXYisEqual(scalpel, suture)) {
            cout << "\nКоординаты SCALPEL и SUTURE - не совпадают.\n";
            do {
                clearStdin(); // avoid echo
                cout << "Применить для зашивания координаты разреза ? (y/n): ";
                cin >> yes_no;
                if (yes_no == 'n') {
                    cout << "Действие suture отменено.\n\n";
                    return false;
                }
            } while (yes_no != 'y');
        }
        // TODO - придумать как выполнить зашивание

        cout << "Зашиваем разрез:\n";
        cout << "\tA (x = " << scalpel.Ax << ", y = " << scalpel.Ay << ")\n";
        cout << "\tB (x = " << scalpel.Bx << ", y = " << scalpel.By << ")\n";
        Sleep(900);
        cout << "\tРазрез зашит, операция закончена.\n\n";
        isSutured = true;

        return true;
    }
};


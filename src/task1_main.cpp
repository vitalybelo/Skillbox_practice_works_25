#include <iostream>
#include "use_lib.h"
#include "task1_class.h"
using namespace std;

/**
 * В задании сказано:
 * Операция всегда начинается с команды scalpel и заканчивается командой suture.
 * Для окончания работы программы их параметры-точки должны совпасть.
 *
 * Реализована программа которая не позволяет делать несколько разрезов одновременно.
 * Пинцет и зажим можно применять бесконечно.
 *
 * Окончание операции требует совпадения точек зашивания и разреза (!)
 *
 */
int main() {
    setlocaleRus();

    string comm;
    Surgery surgery;

    bool surgeryOn = true;
    do {
        clearStdin();   // avoid echo on my pc station
        cout << "Введите пожалуйста команду: ";
        comm = getCommand();
        // SCALPEL
        if (comm == "scalpel" || comm == "1") {
            surgery.applyScalpel();
        // HEMOSTAT
        } else if (comm == "hemostat" || comm == "2") {
            surgery.applyHemostat();
        // TWEEZERS
        } else if (comm == "tweezers" || comm == "3") {
            surgery.applyTweezers();
        // SUTURE
        } else if (comm == "suture" || comm == "0") {
            surgeryOn = !surgery.applySuture();
        }

    } while (surgeryOn);

    return 0;
}

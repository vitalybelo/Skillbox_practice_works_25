#include <iostream>
#include "use_lib.h"
#include "task1_class.h"
using namespace std;

/**
 * � ������� �������:
 * �������� ������ ���������� � ������� scalpel � ������������� �������� suture.
 * ��� ��������� ������ ��������� �� ���������-����� ������ ��������.
 *
 * ����������� ��������� ������� �� ��������� ������ ��������� �������� ������������.
 * ������ � ����� ����� ��������� ����������.
 *
 * ��������� �������� ������� ���������� ����� ��������� � ������� (!)
 *
 */
int main() {
    setlocaleRus();

    string comm;
    Surgery surgery;

    bool surgeryOn = true;
    do {
        clearStdin();   // avoid echo on my pc station
        cout << "������� ���������� �������: ";
        comm = getCommand();
        if (comm == "scalpel" || comm == "1") {
            surgery.applyScalpel();
        } else if (comm == "hemostat" || comm == "2") {
            surgery.applyHemostat();
        } else if (comm == "tweezers" || comm == "3") {
            surgery.applyTweezers();
        } else if (comm == "suture" || comm == "0") {
            surgeryOn = !surgery.applySuture();
        }

    } while (surgeryOn);


    return 0;
}

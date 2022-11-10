#pragma once

class EmulatorKBD {

private:

    BufferArray buffer;

public:

    BufferArray getInput() {
        cout << "Ввод значения буфера (8):\n";
        for (int i = 0; i < buffer.size; i++) {
            cout << "Введите значение (" << i + 1 << "): ";
            cin >> buffer.element[i];
        }
        return buffer;
    }

};
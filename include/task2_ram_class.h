#pragma once

class EmulatorRAM {

private:

    BufferArray buffer{};

public:

    EmulatorRAM() {
        for (int i = 0; i < buffer.size; i++)
            buffer.element[i] = 0;
    }

    BufferArray read() {
        return buffer;
    }

    void write(const BufferArray &new_buffer) {

        for (int i = 0; i < buffer.size; i++)
            buffer.element[i] = new_buffer.element[i];
    }

    void erase() {

        for (int i = 0; i < buffer.size; i++)
            buffer.element[i] = 0;
    }

    string toString() {
        string result = "Buffer = {";
        for (int i = 0; i < buffer.size; i++)
            result += " " + to_string(buffer.element[i]);
        result += " }";
        return result;
    }

    void printBuffer() {
        cout << toString() << endl;
    }

};
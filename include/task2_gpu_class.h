#pragma once

class EmulatorGPU {

private:

    string result{};

public:

    string toString(struct BufferArray buffer) {
        result = "Buffer = {";
        for (int i = 0; i < buffer.size; i++)
            result += " " + to_string(buffer.element[i]);
        result += " }";
        return result;
    }

    static void toPrint(struct BufferArray buffer) {
        cout << "Buffer = {";
        for (int i = 0; i < buffer.size; i++)
            cout << " " << to_string(buffer.element[i]);
        cout << " }\n";
    }

};
#pragma once
#include <fstream>

class EmulatorHDD {

private:

    std::ifstream fileReader;
    std::ofstream fileWriter;

public:

    bool write(struct BufferArray buffer) {

        fileWriter.open(DATA_FILE, std::ios::out);
        if (fileWriter.is_open()) {
            for (int i = 0; i < buffer.size; i++) {
                fileWriter << buffer.element[i] << endl;
            }
            fileWriter.close();
            return true;
        }
        std::cout << "File write error\n";
        return false;
    }

    bool read(struct BufferArray &buffer) {

        fileReader.open(DATA_FILE, std::ios::in);
        if (fileReader.is_open()) {
            for (int i = 0; i < buffer.size; i++) {
                fileReader >> buffer.element[i];
            }
            fileReader.close();
            return true;
        }
        std::cout << "File read error\n";
        return false;
    }

};
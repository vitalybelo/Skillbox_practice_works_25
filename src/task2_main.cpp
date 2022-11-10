#include <iostream>
#include "use_lib.h"
#include "task2_macros.h"
#include "task2_structs.h"
#include "task2_ram_class.h"
#include "task2_disk_class.h"
#include "task2_cpu_class.h"
#include "task2_gpu_class.h"
#include "task2_kbd_class.h"
using namespace std;

/**
 * Все модули реализованы как классы
 * Структура BufferArray заведена для удобства обмена
 * Единственный метод требующий промежуточного буфера - load()
 * Все остальные методы обращаются в RAM для получения данных буфера или
 * используют метод write для обновления буфера (input() & load())
 *
 */
int main() {
    setlocaleRus();

    EmulatorRAM ram;
    EmulatorHDD disk;
    EmulatorCPU cpu;
    EmulatorKBD kbd;

    string comm;
    do {
        clearStdin();
        cout << "\nВведите команду: ";
        comm = getCommand();
        // DISPLAY
        if (comm == "display" || comm == "see") {
            EmulatorGPU::toPrint(ram.read());
            // INPUT
        } else if (comm == "input" || comm == "kbd") {
            ram.write(kbd.getInput());
            // SUM
        } else if (comm == "sum") {
            cout << "Сумма = " << cpu.compute(ram.read()) << endl;
            // ERASE
        } else if (comm == "clear" || comm == "erase") {
            ram.erase();
            // LOAD
        } else if (comm == "load") {
            BufferArray buffer;
            if (disk.read(buffer)) {
                ram.write(buffer);
            }
            // SAVE
        } else if (comm == "save") {
            disk.write(ram.read());
        }

    } while (comm != "exit" && comm != "quit");

    return 0;
}

#include <iostream>
#include "use_lib.h"
#include "task2_macros.h"
#include "task2_structs.h"
#include "task2_ram_class.h"
#include "task2_disk_class.h"
#include "task2_cpu_class.h"
#include "task2_gpu_class.h"
using namespace std;

int main() {
    setlocaleRus();

    EmulatorRAM ram;
    EmulatorHDD disk;
    EmulatorCPU cpu;
    EmulatorGPU gpu;
    BufferArray buffer;

    ram.printBuffer();

    for (int i = 0; i < buffer.size; i++) buffer.element[i] = i + 1;
    ram.write(buffer);
    ram.printBuffer();
    cout << "Sum = " << cpu.compute(ram.read()) << endl;


    disk.write(buffer);

    ram.erase();
    ram.printBuffer();
    cout << "Sum = " << cpu.compute(ram.read()) << endl;

    if (disk.read(buffer))
        ram.write(buffer);

    EmulatorGPU::toPrint(ram.read());


    return 0;
}

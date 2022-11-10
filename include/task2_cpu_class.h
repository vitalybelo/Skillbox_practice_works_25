#pragma once

class EmulatorCPU {

private:

    int bufferSum = 0;

public:

    int compute(struct BufferArray buffer) {
        bufferSum = 0;
        for (int i = 0; i < buffer.size; i++)
            bufferSum += buffer.element[i];
        return bufferSum;
    }

};
#pragma once

struct Application2DXY {
    double Ax = 0;
    double Ay = 0;
    double Bx = 0;
    double By = 0;
};

struct ApplicationXY {
    double x = 0;
    double y = 0;
};

bool coordinate2DXYisEqual (struct Application2DXY element) {

    return (element.Ax == element.Bx && element.Ay == element.By);
}
bool coordinates2DXYisEqual (struct Application2DXY element1, struct  Application2DXY element2) {

    return (element1.Ax == element2.Ax && element1.Ay == element2.Ay &&
            element1.Bx == element2.Bx && element1.By == element2.By);
}
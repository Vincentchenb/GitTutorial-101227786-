#ifndef RGB_H
#define RGB_H

#include "defs.h"

class RGB {
public:
    RGB(int r, int g, int b);
    RGB(CuColour colour);
    RGB();
    int getR();
    int getB();
    int getG();
    void setR(int r);
    void setB(int b);
    void setG(int g);
    void setColour(CuColour colour);
    CuColour getColour();

    // Static functions for commonly used colors
    static RGB WHITE();
    static RGB BLACK();
    static RGB RED();
    static RGB GREEN();
    static RGB BLUE();

private:
    int r;
    int b;
    int g;
};

#endif
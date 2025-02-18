#include "RGB.h"

RGB::RGB(int r, int g, int b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

RGB::RGB(CuColour colour) {
    r = (colour >> 16) & 0xFF;
    g = (colour >> 8) & 0xFF;
    b = colour & 0xFF;
}

RGB::RGB() {
    r = 0;
    g = 0;
    b = 0;
}

void RGB::setColour(CuColour colour) {
    r = (colour >> 16) & 0xFF;
    g = (colour >> 8) & 0xFF;
    b = colour & 0xFF;
}

int RGB::getR() {
    return r;
}

int RGB::getB() {
    return b;
}

int RGB::getG() {
    return g;
}

void RGB::setR(int r) {
    this->r = r;
}

void RGB::setB(int b) {
    this->b = b;
}

void RGB::setG(int g) {
    this->g = g;
}

CuColour RGB::getColour() {
    return (r << 16) + (g << 8) + b;
}

// Static function implementations
RGB RGB::WHITE() {
    return RGB(255, 255, 255);
}

RGB RGB::BLACK() {
    return RGB(0, 0, 0);
}

RGB RGB::RED() {
    return RGB(255, 0, 0);
}

RGB RGB::GREEN() {
    return RGB(0, 255, 0);
}

RGB RGB::BLUE() {
    return RGB(0, 0, 255);
}
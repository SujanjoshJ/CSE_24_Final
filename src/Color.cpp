#include "Color.h"

Color::Color() {
    r = 0.0;
    g = 0.0;
    b = 0.0;
    size = 1;
}

Color::Color(float r, float g, float b, int size) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->size = size;
}

float Color::getR() const {
    return r;
}

float Color::getG() const {
    return g;
}

float Color::getB() const {
    return b;
}

int Color::getSize() const{
    return size;
}
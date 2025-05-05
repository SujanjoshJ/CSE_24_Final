#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
    float x;
    float y;
    float size;
    float r;
    float g;
    float b;

public:
    Rectangle();
    Rectangle(float x, float y, float r, float g, float b, int s);
    void draw();
    float setSize(int s);
    bool contains(float mx, float my);
    void setColor(float r, float g, float b);
    void setPos(float x, float y);
    void setterSize(int s);
};

#endif
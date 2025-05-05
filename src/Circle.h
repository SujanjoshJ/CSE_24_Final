#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape{
    float x;
    float y;
    float radius;
    float r;
    float g;
    float b;

public:
    Circle();
    Circle(float x, float y, float r, float g, float b, int s);
    void draw();
    float setSize(int s);
    bool contains(float mx, float my);
    void setColor(float r, float g, float b);
    void setPos(float x, float y);
    void setterSize(int s);
};

#endif
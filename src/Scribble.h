#ifndef SCRIBBLE_H
#define SCRIBBLE_H

#include "Shape.h"
#include "Point.h"
#include <vector>

class Scribble: public Shape {
    std::vector<Point*> points;
    int size;

public:

    void addPoint(float x, float y, float r, float g, float b, int size);

    void draw();

    int setSize(int s);
    bool contains(float mx, float my);
    void setColor(float r, float g, float b);
    void setPos(float x, float y);
    void setterSize(int s);
    
};
#endif
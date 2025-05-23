#ifndef POINT_H
#define POINT_H

#include "Shape.h"

class Point: public Shape{
    float x;
    float y;
    float r;
    float g;
    float b;
    int size;

public:
    Point();
    Point(float x, float y);
    Point(float x, float y, float r, float g, float b);
    Point(float x, float y, float r, float g, float b, int size);

    void draw();

    int setSize(int s);

    float getX() const;
    float getY() const;
    float getR() const;
    float getG() const;
    float getB() const;
    int getSize() const;
   

    // create setters for scribble to build off of

    bool contains(float mx, float my);

    void setColor(float r, float g, float b);
    void setPos(float mx, float my);
    void setterSize(int s);



};

#endif
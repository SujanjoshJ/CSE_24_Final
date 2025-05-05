#ifndef CANVAS_H
#define CANVAS_H

#include <bobcat_ui/all.h>
#include <vector>
#include <algorithm>
#include "Point.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Shape.h"
#include "Triangle.h"
#include "Polygon.h"
#include "Scribble.h"

class Canvas : public bobcat::Canvas_ {
    std::vector<Shape*> shapes;
    Scribble* curr;

public:
    Canvas(int x, int y, int w, int h);

    void addPoint(float x, float y, float r, float g, float b, int size);

    void addRectangle(float x, float y, float r, float g, float b, int size);

    void addCircle(float x, float y, float r, float g, float b, int size);

    void addTriangle(float x, float y, float r, float g, float b, int size);

    void addPolygon(float x, float y, float r, float g, float b, int size);

    void startScribble();

    void updateScribble(float x, float y, float r, float g, float b, int size);

    void endScribble();

    void front(Shape* selected);

    void back(Shape* selected);

    void move(Shape* selected, float mx, float my);

    void clear();

    void render();

    Shape* getSelectedShape(float mx, float my);
};

#endif
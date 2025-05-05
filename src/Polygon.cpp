#include "Polygon.h"
#include <GL/freeglut.h>

Polygon::Polygon() {
    x = 0.0;
    y = 0.0;
    size = 0.4;
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

float Polygon::setSize(int s){
    if (s == 1){
        size = 0.2;
        return size;
    } else if (s == 2) {
        size = 0.4;
        return size;
    } else if (s == 3) {
        size = 0.6;
        return size;
    }
    return size;
}

Polygon::Polygon(float x, float y, float r, float g, float b, int s) {
    this->x = x;
    this->y = y;
    this->size = setSize(s);
    this->r = r;
    this->g = g;
    this->b = b;
}
void Polygon::setterSize(int s){
    float temp = setSize(s);
    this->size = temp;
}

void Polygon::draw() {
    glColor3f(r, g, b);

    glBegin(GL_POLYGON);
        glVertex2f(x, y + size/2);
        glVertex2f(x + size/2, y);
        glVertex2f(x, y - size/2);
        glVertex2f(x - size/2, y);
    glEnd();
}

bool Polygon::contains(float mx, float my) {
    if (mx >= x - size/2 && mx <= x + size/2 && my <= y + size/2 && my >= y - size/2) {
        return true;
    }
    return false;
}

void Polygon::setColor(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

void Polygon::setPos(float x, float y){
    this->x = x;
    this->y = y;
}
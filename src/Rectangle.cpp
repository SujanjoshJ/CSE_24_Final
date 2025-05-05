#include "Rectangle.h"
#include <GL/freeglut.h>
#include <bobcat_ui/return_button.h>

Rectangle::Rectangle() {
    x = 0.0;
    y = 0.0;
    size = 0.4;
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

Rectangle::Rectangle(float x, float y, float r, float g, float b, int s) {
    this->x = x;
    this->y = y;
    this->size = setSize(s);
    this->r = r;
    this->g = g;
    this->b = b;
}

float Rectangle::setSize(int s){
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

void Rectangle::draw() {
    glColor3f(r, g, b);

    glBegin(GL_POLYGON);
        glVertex2f(x - size/2, y + size/2);
        glVertex2f(x + size/2, y + size/2);
        glVertex2f(x + size/2, y - size/2);
        glVertex2f(x - size/2, y - size/2);
    glEnd();
}

bool Rectangle::contains(float mx, float my) {
    if (mx >= x - size/2 && mx <= x + size/2 && my <= y + size/2 && my >= y - size/2) {
        return true;
    }
    return false;
}

void Rectangle::setterSize(int s){
    float temp = setSize(s);
    this->size = temp;
}

void Rectangle::setColor(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

void Rectangle::setPos(float x, float y){
    this->x = x;
    this->y = y;
}
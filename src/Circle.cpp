#include "Circle.h"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <cmath>

Circle::Circle() {
    x = 0.0;
    y = 0.0;
    radius = 0.2;
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

Circle::Circle(float x, float y, float r, float g, float b, int s) {
    this->x = x; 
    this->y = y; 
    this->radius = setSize(s);
    this->r = r; 
    this->g = g; 
    this->b = b; 
}

void Circle::setterSize(int s){
    float temp = setSize(s);
    this->radius = temp;
}

void Circle::draw() {
    glColor3f(r, g, b);

    float inc = M_PI / 32;
    glBegin(GL_POLYGON);
        for (float theta = 0; theta <= 2 * M_PI; theta += inc){
            glVertex2d(x + cos(theta) * radius, y + sin(theta) * radius);
        }
    glEnd();
}
float Circle::setSize(int s){
    if (s == 1){
        radius = 0.1;
        return radius;
    } else if (s == 2) {
        radius = 0.2;
        return radius;
    } else if (s == 3) {
        radius = 0.3;
        return radius;
    }
    return radius;
}


bool Circle::contains(float mx, float my) {
    if (mx >= x - radius && mx <= x + radius && my <= y + radius && my >= y - radius) {
        return true;
    }
    return false;
}

void Circle::setColor(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

void Circle::setPos(float x, float y){
    this->x = x;
    this->y = y;
}
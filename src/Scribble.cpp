#include "Scribble.h"

void Scribble::addPoint(float x, float y, float r, float g, float b, int size){
    points.push_back(new Point(x, y, r, g, b, size));
}

void Scribble::draw(){
    for (unsigned int i = 0; i < points.size(); i++){
        points[i]->draw();
    }
}

bool Scribble::contains(float mx, float my) {
    for (unsigned int i = 0; i < points.size(); i++){
        float x = points[i]->getX();
        float y = points[i]->getY();
        if (x == mx && y == my){
            return true;
        }
    }
    return false;
}

void Scribble::setColor(float r, float g, float b){
    for (unsigned int i = 0; i < points.size(); i++){
        float r = points[i]->getR();
        float g = points[i]->getG();
        float b = points[i]->getB();
    }
}


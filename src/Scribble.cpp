#include "Scribble.h"
#include "Point.h"

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
        float radius = 0.05;
        //int size = points[i]->getSize();
        // if (x == mx && y == my){
        //     return true;
        // }
        if (mx >= x - radius && mx <= x + radius && my <= y + radius && my >= y - radius) {
            return true;
        }
    }
    return false;
}

void Scribble::setColor(float r, float g, float b){
    for (unsigned int i = 0; i < points.size(); i++){
        points[i]->setColor(r, g, b);
    }
}
void Scribble::setPos(float x, float y){
    for (unsigned int i = 0; i < points.size(); i++){
        points[i]->setPos(x, y);
    }

}


#include "Scribble.h"
#include "Point.h"
#include <iostream>

void Scribble::addPoint(float x, float y, float r, float g, float b, int size){
    int s = setSize(size);
    points.push_back(new Point(x, y, r, g, b, s));
}
int Scribble::setSize(int s){
    if (s == 1){
        size = 3;
        return size;
    } else if (s == 2) {
        size = 7;
        return size;
    } else if (s == 3) {
        size = 14;
        return size;
    }
    return size;
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

void Scribble::setterSize(int s){
    for (unsigned int i = 0; i < points.size(); i++){
        int temp = setSize(s);
        points[i]->setterSize(temp);
    }
}
void Scribble::setPos(float x, float y){
    // int tx=points[0]->getX();
    // int ty=points[0]->getY();
    // points[0]->setPos(x,y)
    int tx,ty;
    for (unsigned int i = 0; i < points.size(); i++){
        if(i==0){
            tx = points[i]->getX();
            ty = points[i]->getY();
            points[i]->setPos(x,y);
            continue;
            
        }

        points[i]->setPos(x+(points[i]->getX()-tx), y+(points[i]->getY()-ty));
        // points[i]->setPos(x+(float)i, y+(float)i);
        std::cout<<"tx:"<<tx<<",ty:"<<ty<<",x:"<<points[i]->getX()<<",y:"<<points[i]->getY()<<std::endl;

    }

}


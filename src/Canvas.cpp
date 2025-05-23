#include "Canvas.h"
#include "Circle.h"
#include "Scribble.h"
#include <GL/freeglut.h>
#include <cstdlib>

Canvas::Canvas(int x, int y, int w, int h) : Canvas_(x, y, w, h) {
    curr = nullptr;
}

void Canvas::addPoint(float x, float y, float r, float g, float b, int size) {
    shapes.push_back(new Point(x, y, r, g, b, size));
}

void Canvas::addRectangle(float x, float y, float r, float g, float b, int size) {
    shapes.push_back(new Rectangle(x, y, r, g, b, size));
}

void Canvas::addCircle(float x, float y, float r, float g, float b, int size) {
    shapes.push_back(new Circle(x, y, r, g, b, size));
}

void Canvas::addTriangle(float x, float y, float r, float g, float b, int size){
    shapes.push_back(new Triangle(x, y, r, g, b, size));
}

void Canvas::addPolygon(float x, float y, float r, float g, float b, int size){
    shapes.push_back(new Polygon(x, y, r, g, b, size));
}

void Canvas::front(Shape* selected) {
    Shape* temp = nullptr;
    for (unsigned int i = 0; i < shapes.size(); i++){
        if (selected == shapes[i]){
            temp = shapes[i];
            shapes.erase(shapes.begin()+i);
        }
    }
    shapes.push_back(temp);

}

void Canvas::back(Shape* selected) {
    Shape* temp = nullptr;
    for (unsigned int i = 0; i < shapes.size(); i++){
        if (selected == shapes[i]){
            temp = shapes[i];
            shapes.erase(shapes.begin()+i);
        }
    }
    shapes.insert(shapes.begin(), temp);
}

void Canvas::clear() {
    for (unsigned int i = 0 ; i < shapes.size(); i++) {
        delete shapes[i];
    }
    shapes.clear();
}

void Canvas::render() {
    for (unsigned int i = 0 ; i < shapes.size(); i++) {
        shapes[i]->draw();
    }
    if (curr){
        curr->draw();
    }
}

void Canvas::startScribble(){
    curr = new Scribble();
}

void Canvas::updateScribble(float x, float y, float r, float g, float b, int size){
    if (curr){
        curr->addPoint(x, y, r, g, b, size);
    }
}

void Canvas::endScribble(){
    if (curr){
        shapes.push_back(curr);
        curr = nullptr;
    }
}

void Canvas::move(Shape* selected, float mx, float my){
    for (unsigned int i = 0; i <shapes.size(); i++){
        if (selected == shapes[i]){
            shapes[i]->setPos(mx, my);
        }
    }
}

Shape* Canvas::getSelectedShape(float mx, float my) {
    Shape* selectedShape = nullptr;

    for (unsigned int i = 0; i < shapes.size(); i++) {
        // ask every shape if we clicked on it
        if (shapes[i]->contains(mx, my)) {
            std::cout << "Clicked on shape[" << i << "]" << std::endl;
            selectedShape = shapes[i];
            break;
        }
    }

    if (selectedShape == nullptr) {
        std::cout << "No selected shape" << std::endl;
    }

    return selectedShape;
}
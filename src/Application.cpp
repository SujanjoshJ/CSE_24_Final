#include "Application.h"
#include "Enums.h"
#include "Canvas.h"

using namespace bobcat;
using namespace std;

void Application::onCanvasMouseDown(bobcat::Widget* sender, float mx, float my) {
    TOOL tool = toolbar->getTool();
    Color color = colorSelector->getColor();

    if (tool == PENCIL) {
        // canvas->addPoint(mx, my, color.getR(), color.getG(), color.getB(), 7);
        canvas->startScribble();
        canvas->redraw();
    }
    else if (tool == ERASER) {
        canvas->addPoint(mx, my, 1.0, 1.0, 1.0, 14);
        canvas->redraw();
    }
    else if (tool == RECTANGLE) {
        canvas->addRectangle(mx, my, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == CIRCLE) { 
        canvas->addCircle(mx, my, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == TRIANGLE){
        canvas->addTriangle(mx, my, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == POLYGON){
        canvas->addPolygon(mx, my, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == MOUSE) {
        selectedShape = canvas->getSelectedShape(mx, my);
    }

}

void Application::onCanvasDrag(bobcat::Widget* sender, float mx, float my) {
    TOOL tool = toolbar->getTool();
    Color color = colorSelector->getColor();

    if (tool == PENCIL) {
        // canvas->addPoint(mx, my, color.getR(), color.getG(), color.getB(), 7);
        canvas->updateScribble(mx, my, color.getR(), color.getG(), color.getB(), 7);
        canvas->redraw();
    }
    else if (tool == ERASER) {
        canvas->addPoint(mx, my, 1.0, 1.0, 1.0, 14);
        canvas->redraw();
    }
    else if (tool == MOUSE){
        canvas->move(selectedShape, mx, my);
        canvas->redraw();
    }
}

void Application::onToolbarChange(bobcat::Widget* sender) {
    ACTION action = toolbar->getAction();

    if (action == CLEAR) {
        canvas->clear();
        canvas->redraw();
    }
    else if (action == FRONT && selectedShape){
        canvas->front(selectedShape);
        canvas->redraw();
    }
    else if (action == BACK && selectedShape){
        canvas->back(selectedShape);
        canvas->redraw();
    }
}

void Application::onCanvasMouseUp(bobcat::Widget* sender, float mx, float my) {
    canvas->endScribble();
}

void Application::onColorSelectorChange(bobcat::Widget* sender) {
    Color color = colorSelector->getColor();

    if (selectedShape) {
        cout << "Update selected shape color" << endl;
        selectedShape->setColor(color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
}

Application::Application() {
    window = new Window(25, 75, 500, 500, "Lecture 21");

    selectedShape = nullptr;

    toolbar = new Toolbar(0, 0, 50, 500);
    canvas = new Canvas(50, 0, 450, 450);
    colorSelector = new ColorSelector(50, 450, 450, 50);
    colorSelector->box(FL_BORDER_BOX);

    window->add(toolbar);
    window->add(canvas);
    window->add(colorSelector);

    ON_MOUSE_DOWN(canvas, Application::onCanvasMouseDown);
    ON_DRAG(canvas, Application::onCanvasDrag);
    ON_CHANGE(toolbar, Application::onToolbarChange);
    ON_CHANGE(colorSelector, Application::onColorSelectorChange);
    ON_MOUSE_UP(canvas, Application::onCanvasMouseUp);

    window->show();
}
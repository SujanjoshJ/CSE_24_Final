#include "ColorSelector.h"
#include "Color.h"
#include "Enums.h"
#include <FL/Enumerations.H>
#include <bobcat_ui/int_input.h>
#include <bobcat_ui/textbox.h>
using namespace bobcat;

void ColorSelector::visualizeSelectedColor() {
    redInput->value(0);
    greenInput->value(0);
    blueInput->value(0);
    size = 2;
}

void ColorSelector::onClick(bobcat::Widget* sender) {
    if (sender == sizeUp){
        action = SIZEUP;
    }
    else if (sender == sizeDown){
        action = SIZEDOWN;
    }

    if (onChangeCb) {
        onChangeCb(this);
    }

    sizeHandler();
    redraw();
}

void ColorSelector::sizeHandler(){
    if (action == SIZEUP && size < 3){
        size += 1;
        std::cout << "Size: " << size << std::endl;
    } else if (action == SIZEDOWN && size > 1){
        size -= 1;
        std::cout << "Size: " << size << std::endl;
    } else {
        std::cout << "Minimum or maximum achieved" << std::endl;
    }
}

Color ColorSelector::getColor() const {
    int redNum = redInput->value();
    int grnNum = greenInput->value();
    int bluNum = blueInput->value();
    if (redNum <= 255 && grnNum <= 255 && bluNum <= 255){
        return Color((float)redNum/255.0, (float)grnNum/255.0, (float)bluNum/255.0, size);
    }
    else if (redInput->empty() || greenInput->empty() || blueInput->empty()){
        std::cout << "Input a number \n";
        return Color(0.0, 0.0, 0.0, size);
    }
    else {
        std::cout << "Input Color invalid! \n";
        return Color(0.0, 0.0, 0.0, size);
    }
}

ColorSelector::ColorSelector(int x, int y, int w, int h) : Group(x, y, w, h) {
    sizeUp = new Image(x + 300, y, 50, 50, "./assets/plus.png");
    sizeDown = new Image(x + 350, y, 50, 50, "./assets/minus.png");
    redLabel = new TextBox(x, y, 50, 20, "RED");
    greenLabel= new TextBox(x + 50, y, 50, 20, "GRN");
    blueLabel = new TextBox(x + 100, y, 50, 20, "BLUE");
    redInput = new IntInput(x, y + 20, 50, 30, "");
    greenInput = new IntInput(x + 50, y + 20, 50, 30, "");
    blueInput = new IntInput(x + 100, y + 20, 50, 30, "");


    color = RED;
    action = NONE;

    
    //label background colors are not working, not sure why
    redLabel->labelcolor(FL_BLACK);
    redLabel->color(FL_RED);
    blueInput->labelcolor(FL_BLACK);
    blueLabel->color(FL_BLUE);
    greenInput->labelcolor(FL_BLACK);
    greenLabel->color(FL_GREEN);


    visualizeSelectedColor();

    
    ON_CLICK(sizeUp, ColorSelector::onClick);
    ON_CLICK(sizeDown, ColorSelector::onClick);
    /*ON_CLICK(indigoButton, ColorSelector::onClick);
    ON_CLICK(violetButton, ColorSelector::onClick);*/
}
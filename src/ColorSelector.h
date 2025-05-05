#ifndef COLOR_SELECTOR_H
#define COLOR_SELECTOR_H

#include <bobcat_ui/all.h>
#include <bobcat_ui/int_input.h>
#include <bobcat_ui/textbox.h>
#include "Color.h"
#include "Enums.h"

class ColorSelector : public bobcat::Group {
    /*bobcat::Button* redButton;
    bobcat::Button* orangeButton;
    bobcat::Button* yellowButton;
    bobcat::Button* greenButton;
    bobcat::Button* blueButton;
    bobcat::Button* indigoButton;
    bobcat::Button* violetButton;*/
    bobcat::Image* sizeUp;
    bobcat::Image* sizeDown;
    bobcat::IntInput* redInput;
    bobcat::IntInput* greenInput;
    bobcat::IntInput* blueInput;
    bobcat::TextBox* redLabel;
    bobcat::TextBox* greenLabel;
    bobcat::TextBox* blueLabel;

    COLOR color;
    ACTION action;
    int size;
    void sizeHandler();
    void visualizeSelectedColor();
    void onClick(bobcat::Widget* sender);

public:
    ColorSelector(int x, int y, int w, int h);

    Color getColor() const;

    int setSize() const;
};

#endif
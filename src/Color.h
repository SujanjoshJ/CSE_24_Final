#ifndef COLOR_H
#define COLOR_H

class Color {
    float r;
    float g;
    float b;
    int size;

public:
    Color();
    Color(float r, float g, float b, int size);

    float getR() const;
    float getG() const;
    float getB() const;
    int getSize() const;
};

#endif
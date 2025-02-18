#ifndef TEXTAREA_H
#define TEXTAREA_H

#include <iostream>
#include <string>
#include <X11/Xlib.h>
#include "RGB.h"
#include "defs.h" // Include defs.h to use the Rectangle struct

using namespace std;

class TextArea {
public:
    // Constructors
    TextArea(int x, int y, int width, int height, const string& id, const string& text, 
             const RGB& fill = RGB::WHITE(), const RGB& border = RGB::BLACK());
    TextArea(const Rectangle& dimensions, const string& id, const string& text, 
             const RGB& fill = RGB::WHITE(), const RGB& border = RGB::BLACK());
    TextArea(const TextArea& other); // Copy constructor

    // Getters
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;
    string getId() const;
    string getText() const;
    RGB getFill() const;
    RGB getBorder() const;

    // Setters
    void setPosition(int x, int y);
    void setSize(int width, int height);
    void setText(const string& text);
    void setFill(const RGB& fill);
    void setBorder(const RGB& border);

    // Member functions
    void draw(Display* display, Window win, GC gc, int x, int y);
    bool overlaps(const TextArea& ta) const;
    void print() const;

private:
    Rectangle dimensions; // Use the Rectangle struct from defs.h
    string id;
    string text;
    RGB fill;
    RGB border;
};

#endif
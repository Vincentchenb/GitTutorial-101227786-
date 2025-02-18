#include "TextArea.h"
#include <iomanip>

// Constructor with individual dimensions
TextArea::TextArea(int x, int y, int width, int height, const string& id, const string& text, 
                   const RGB& fill, const RGB& border)
    : dimensions{x, y, width, height}, id(id), text(text), fill(fill), border(border) {}

// Constructor with Rectangle
TextArea::TextArea(const Rectangle& dimensions, const string& id, const string& text, 
                   const RGB& fill, const RGB& border)
    : dimensions(dimensions), id(id), text(text), fill(fill), border(border) {}

// Copy constructor
TextArea::TextArea(const TextArea& other)
    : dimensions(other.dimensions), id(other.id), text("DUPLICATE"), fill(other.fill), border(other.border) {}

// Getters
int TextArea::getX() const { return dimensions.x; }
int TextArea::getY() const { return dimensions.y; }
int TextArea::getWidth() const { return dimensions.width; }
int TextArea::getHeight() const { return dimensions.height; }
string TextArea::getId() const { return id; }
string TextArea::getText() const { return text; }
RGB TextArea::getFill() const { return fill; }
RGB TextArea::getBorder() const { return border; }

// Setters
void TextArea::setPosition(int x, int y) {
    dimensions.x = x;
    dimensions.y = y;
}

void TextArea::setSize(int width, int height) {
    dimensions.width = width;
    dimensions.height = height;
}

void TextArea::setText(const string& text) {
    this->text = text;
}

void TextArea::setFill(const RGB& fill) {
    this->fill = fill;
}

void TextArea::setBorder(const RGB& border) {
    this->border = border;
}

// Draw the TextArea
void TextArea::draw(Display* display, Window win, GC gc, int x, int y) {
    // Draw the filled rectangle
    XSetForeground(display, gc, fill.getColour());
    XFillRectangle(display, win, gc, x, y, dimensions.width, dimensions.height);

    // Draw the border
    XSetForeground(display, gc, border.getColour());
    XDrawRectangle(display, win, gc, x, y, dimensions.width, dimensions.height);

    // Draw the text
    const char* font_name = "fixed";
    XID font = XLoadFont(display, font_name);
    XFontStruct* font_info = XQueryFont(display, font);
    if (!font_info) {
        XCloseDisplay(display);
        return; // Failed to query font
    }
    XSetFont(display, gc, font);

    int text_width = XTextWidth(font_info, text.c_str(), text.length());
    int length = text.length();

    // Ensure text fits within the TextArea
    while (text_width > dimensions.width - 10 && length > 0) {
        length--;
        text_width = XTextWidth(font_info, text.c_str(), length);
    }

    int offsetX = (dimensions.width - text_width) / 2;
    int text_height = font_info->ascent + font_info->descent;
    int offsetY = (dimensions.height - text_height) / 2 + font_info->ascent;

    XDrawImageString(display, win, gc, x + offsetX, y + offsetY, text.c_str(), length);

    // Cleanup
    XFreeFontInfo(NULL, font_info, 1);
}

// Check if this TextArea overlaps with another
bool TextArea::overlaps(const TextArea& ta) const {
    return dimensions.overlaps(ta.dimensions);
}

// Print TextArea information
void TextArea::print() const {
    cout << "TextArea id: " << id << endl;
    cout << "Preferred location: " << dimensions.x << ", " << dimensions.y << endl;
    cout << "Size: " << dimensions.width << ", " << dimensions.height << endl;
    cout << "Text: " << text << endl;
}
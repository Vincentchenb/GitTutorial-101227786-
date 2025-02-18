#include <iostream>
using namespace std;
#include "TAArray.h"

// Constructor
TAArray::TAArray() {
    size = 0;
    elements = new TextArea*[MAX_COMPONENTS];
}

// Destructor
TAArray::~TAArray() {
    delete[] elements;
}

// Add to back of array
bool TAArray::add(TextArea* ta) {
    if (size >= MAX_COMPONENTS) return false;
    
    // Add at the end of the array
    elements[size] = ta;
    ++size;
    return true;
}

// Add at specific index
bool TAArray::add(TextArea* ta, int index) {
    // Check if array is full or index is invalid
    if (size >= MAX_COMPONENTS || index < 0 || index > size) {
        return false;
    }
    
    // Shift elements to make space
    for (int i = size; i > index; --i) {
        elements[i] = elements[i-1];
    }
    
    // Insert at the specified index
    elements[index] = ta;
    ++size;
    return true;
}

// Get by ID
TextArea* TAArray::get(string id) {
    for (int i = 0; i < size; ++i) {
        if (elements[i]->getId() == id) {
            return elements[i];
        }
    }
    return NULL;
}

// Get by index
TextArea* TAArray::get(int index) {
    if (index < 0 || index >= size) return NULL;
    return elements[index];
}

// Const get by ID
TextArea* TAArray::get(string id) const {
    for (int i = 0; i < size; ++i) {
        if (elements[i]->getId() == id) {
            return elements[i];
        }
    }
    return NULL;
}

// Const get by index
TextArea* TAArray::get(int index) const {
    if (index < 0 || index >= size) return NULL;
    return elements[index];
}

// Remove by ID
TextArea* TAArray::remove(string id) {
    int index = 0;
    // Find the index of the element to remove
    while (index < size && elements[index]->getId() != id) {
        ++index;
    }
    // If element not found, return NULL
    if (index >= size) return NULL;
    return remove(index);
}

// Remove by index
TextArea* TAArray::remove(int index) {
    // Check if index is valid
    if (index < 0 || index >= size) return nullptr;
    
    // Store the element to be removed
    TextArea* ta = elements[index];
    
    // Shift elements to fill the gap
    for (int i = index; i < size - 1; ++i) {
        elements[i] = elements[i + 1];
    }
    
    --size;
    return ta;
}

// Get current size
int TAArray::getSize() const {
    return size;
}

// Print all TextAreas
void TAArray::print() const {
    cout << endl << endl << "TextAreas:" << endl;
    for (int i = 0; i < size; ++i) {
        elements[i]->print();
    }
    cout << endl;
}
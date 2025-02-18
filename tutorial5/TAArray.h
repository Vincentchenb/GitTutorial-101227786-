#ifndef TAARRAY_H
#define TAARRAY_H

#include "TextArea.h"
#include "defs.h"

class TAArray {
    private:
        TextArea** elements;   // Dynamically allocated array of TextArea pointers
        int size;              // Current number of elements in the array
    
    public:
        // Constructor and destructor
        TAArray();
        ~TAArray();
        
        // Add functions
        bool add(TextArea* ta);                   // Add to back of array
        bool add(TextArea* ta, int index);        // Add at specific index
        
        // Get functions
        TextArea* get(string id);                 // Get by ID
        TextArea* get(int index);                 // Get by index
        
        // Const get functions
        TextArea* get(string id) const;     // Const get by ID
        TextArea* get(int index) const;     // Const get by index
        
        // Remove functions
        TextArea* remove(string id);              // Remove by ID
        TextArea* remove(int index);              // Remove by index
        
        // Size accessor
        int getSize() const;                      // Get current size
        
        // Utility function
        void print() const;                       // Print all TextAreas
};

#endif
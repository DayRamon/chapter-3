#pragma once 

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <exception>
using std::exception;

template<typename T>
class DynamicArray
{
private:
    int p_size;
    T* p_ptr;

    class OutOfRange : public exception {
    private:
        const char* msg;

    public:
        OutOfRange() : msg("ERROR: INVALID RANGE ENTERED. ") {}
        OutOfRange(const char* nMsg) : msg(nMsg) {}
        const char* what() noexcept {
            return msg;
        }
    };

public:
    //precondition: none
    //postcondition: constructs an empty DynamicArray
    DynamicArray();

    //precondition: capacity >= 0
    //postcondition: constructs an empty DynamicArray with allocated capacity
    DynamicArray(int);

    //precondition: source DynamicArray must be valid
    //postcondition: creates a deep copy of the given DynamicArray
    DynamicArray(const DynamicArray&);

    //precondition: none
    //postcondition: releases allocated memory
    ~DynamicArray();

    //precondition: none
    //postcondition: appends item to the end of the array, resizing if needed
    void append(const T&);

    //precondition: 0 <= index <= size()
    //postcondition: inserts item at index, shifting elements to the right
    void insert(const T&, const int&);

    //precondition: 0 <= index < size()
    //postcondition: returns const reference to element at index
    const T& retrieve(const int&) const;

    //precondition: 0 <= index < size()
    //postcondition: removes element at index, shifting remaining elements left
    void remove(const int&);

    //precondition: none
    //postcondition: returns true if the element exists in the array, false otherwise
    bool exists(const T&) const;

    //precondition: none
    //postcondition: returns the current number of elements in the array
    int size() const;

    //precondition: none
    //postcondition: removes all elements, array becomes empty
    void clear();

    //precondition: none
    //postcondition: removes one or all occurrences of needle depending on allOrOne
    //               returns true if at least one element was erased
    bool erase(const T& needle, bool allOrOne);

    //precondition: source DynamicArray must be valid
    //postcondition: replaces this DynamicArray with a deep copy of the source
    DynamicArray& operator=(const DynamicArray&);

    //precondition: none
    //postcondition: returns raw pointer to array data (const access)
    const T* data() const;

    friend class Statistical;
};

#endif

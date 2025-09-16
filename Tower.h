#pragma once
#include "DynamicArray.h"
#include "DynamicArray.cpp"
#include "Disc.h"
#include <exception>
using std::exception;

class Tower
{
private:
    DynamicArray<Disc> stack;
    int maxSize;

    class InvalidMove : public exception {
    private:
        const char* msg;
    public:
        InvalidMove() : msg("ERROR: INVALID MOVE. ") {};
        InvalidMove(const char* nMsg) : msg(nMsg) {};

        const char* what() const noexcept override {
            return msg;
        };
    };

public:
    /**
     * @pre  maxCapacity > 0
     * @post Creates a Tower with maximum capacity = maxCapacity, initially empty.
     */
    Tower(int maxCapacity) {
        maxSize = maxCapacity;
    };

    /**
     * @pre  Tower must be empty.
     * @post Fills the tower with discs from maxSize down to 1 (largest on bottom, smallest on top).
     */
    void init() {
        for (int i = maxSize; i > 0; i--) {
            Disc newVal;
            newVal.setPriority(i);
            newVal.setState(true);
            stack.append(newVal);
        }
    }

    /**
     * @pre  newDisc is valid.
     *       If stack is not empty, top disc priority >= newDisc.priority.
     * @post Adds newDisc to the top of the stack.
     *       Throws InvalidMove if newDisc is larger than the current top.
     */
    void addDisc(const Disc& newDisc) {
        if (stack.size() != 0 && stack.retrieve(stack.size() - 1).getPriority() < newDisc.getPriority()) {
            throw InvalidMove("ERROR: INVALID MOVE WAS ATTEMPTED. ");
        }
        else {
            stack.append(newDisc);
        }
    }

    /**
     * @pre  Tower must not be empty.
     * @post Removes and returns the top disc from the tower.
     *       Throws InvalidMove if tower is empty.
     */
    Disc removeDisk() {
        if (stack.size() == 0) throw InvalidMove("ERROR: INVALID MOVE WAS ATTEMPTED. ");
        Disc temp = stack.retrieve(stack.size() - 1);
        stack.remove(stack.size() - 1);
        return temp;
    }

    /**
     * @pre  None.
     * @post Tower becomes empty (all discs removed).
     */
    void clear() {
        stack.clear();
    }

    /**
     * @pre  None.
     * @post Returns true if tower is empty, false otherwise.
     */
    bool empty() const noexcept {
        return stack.size() == 0;
    }

    /**
     * @pre  None.
     * @post Returns the priority of the top disc.
     *       Returns 0 if the tower is empty.
     */
    int peekTopPriority() const noexcept {
        if (stack.size() == 0) return 0;
        else {
            return stack.retrieve(stack.size() - 1).getPriority();
        }
    }

    /**
     * @pre  None.
     * @post Returns the number of discs currently on the tower.
     */
    int size() const noexcept {
        return stack.size();
    }

    /**
     * @pre  None.
     * @post Returns the maximum number of discs this tower can hold.
     */
    int capacity() const noexcept {
        return maxSize;
    }

    /**
     * @pre  0 <= index < size().
     * @post Returns a reference to the disc at the given index.
     *       Throws InvalidMove if index is out of range.
     */
    const Disc& peekAt(int index) const {
        if (index < 0 || index >= stack.size()) throw InvalidMove("Invalid peek index");
        return stack.retrieve(index);
    }

    /**
     * @pre  None.
     * @post Returns true if tower is completely filled to capacity, false otherwise.
     */
    bool isFull() const {
        return stack.size() == capacity();
    }
};

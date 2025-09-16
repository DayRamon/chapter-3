#pragma once 
#ifndef DISC_H
#define DISC_h
#include "Gamesquare.h"
class Disc : public GameSquare {
private:
    int priority;

    class outOfRange : public std::exception {
        std::string msg;
    public:
        outOfRange() noexcept : msg("ERROR: OUT OF REASONABLE RANGE.") {}
        explicit outOfRange(const char* nMsg) noexcept : msg(nMsg) {}
        const char* what() const noexcept override {
            return msg.c_str();
        }
    };

public:
    Disc() : GameSquare(), priority(0) {}

    Disc(bool curState, int priority) : GameSquare(curState) {
        if (priority < 0)
            throw outOfRange("ERROR: PRIORITY CAN'T BE BELOW 0.");
        this->priority = priority;
    }

    Disc(const Disc& rhs) : GameSquare(rhs), priority(rhs.priority) {}
    Disc(Disc&& rhs) noexcept : GameSquare(std::move(rhs)), priority(rhs.priority) {
        rhs.priority = 0;
        rhs.setState(false);
    }

    void setPriority(int nPriority) {
        if (nPriority < 0)
            throw outOfRange("ERROR: PRIORITY CAN'T BE BELOW 0.");
        priority = nPriority;
    }

    int getPriority() const noexcept {
        return priority;
    }

    Disc& operator=(const Disc& rhs) {
        if (this != &rhs) {
            GameSquare::operator=(rhs);
            priority = rhs.priority;
        }
        return *this;
    }

    Disc& operator=(Disc&& rhs) noexcept {
        if (this != &rhs) {
            GameSquare::operator=(std::move(rhs));
            priority = rhs.priority;
            rhs.priority = 0;
            rhs.setState(false);
        }
        return *this;
    }

    bool operator<=(const Disc& rhs) const noexcept {
        return priority <= rhs.priority;
    }
};

#endif

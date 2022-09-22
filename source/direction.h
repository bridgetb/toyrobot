#ifndef DIRECTION_H
#define DIRECTION_H

#include <string>

namespace toy {

enum class Direction {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3
};

struct Coordinates {
    int x;
    int y;
    
    bool operator<(const Coordinates& other) const {
        if (x < other.x) return true;
        if (x > other.x) return false;
        return y < other.y;
    }

    bool operator==(const Coordinates& other) const {
        return x == other.x && y == other.y;
    }
};

static Direction ToDirection(const std::string& direction) {
    if (direction == "NORTH") {
        return Direction::NORTH;
    } else if (direction == "EAST") {
        return Direction::EAST;
    } else if (direction == "SOUTH") {
        return Direction::SOUTH;
    } else if (direction == "WEST") {
        return Direction::WEST;
    }
    throw std::runtime_error("Invalid direction: " + direction);
}

} // namespace toy

#endif

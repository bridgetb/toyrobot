#include "robot.h"

#include <iostream>
#include <sstream>
#include <string>

using namespace toy;

std::string ToDirectionString(const Direction direction) {
    if (direction == Direction::NORTH) {
        return "NORTH";
    } else if (direction == Direction::EAST) {
        return "EAST";
    } else if (direction == Direction::SOUTH) {
        return "SOUTH";
    } else {
        return "WEST";
    }
}

Robot::Robot(int table_width, int table_depth) :
_table_width(table_width),
_table_depth(table_depth) {
}

Coordinates Robot::GetPosition() const {
    return _position;
}

Direction Robot::GetDirection() const {
    return _facing_direction;
}

void Robot::Place(const Coordinates& start, Direction facing) {
    if (start.x < _table_width && start.y < _table_depth && start.x >= 0 && start.y >= 0) {
        _is_placed = true;
        _position = start;
        _facing_direction = facing;
    }
}

bool Robot::Move() {
    if (!_is_placed) {
        return false;
    }
    
    if (_facing_direction == Direction::NORTH) {
        if (_position.y < _table_depth - 1) {
            _position.y++;
        } else {
            return false;
        }
    } else if (_facing_direction == Direction::SOUTH) {
        if (_position.y > 0) {
            _position.y--;
        } else {
            return false;
        }
    } else if (_facing_direction == Direction::EAST) {
        if (_position.x < _table_width - 1) {
            _position.x++;
        } else {
            return false;
        }
    } else if (_facing_direction == Direction::WEST) {
        if (_position.x > 0) {
            _position.x--;
        } else {
            return false;
        }
    }
    return true;
}

void Robot::RotateLeft() {
    if (!_is_placed) {
        return false;
    }
    
    if (_facing_direction == Direction::NORTH) {
        _facing_direction = Direction::WEST;
    } else if (_facing_direction == Direction::EAST) {
        _facing_direction = Direction::NORTH;
    } else if (_facing_direction == Direction::SOUTH) {
        _facing_direction = Direction::EAST;
    } else if (_facing_direction == Direction::WEST) {
        _facing_direction = Direction::SOUTH;
    }
}

void Robot::RotateRight() {
    if (!_is_placed) {
        return false;
    }
    
    if (_facing_direction == Direction::NORTH) {
        _facing_direction = Direction::EAST;
    } else if (_facing_direction == Direction::EAST) {
        _facing_direction = Direction::SOUTH;
    } else if (_facing_direction == Direction::SOUTH) {
        _facing_direction = Direction::WEST;
    } else if (_facing_direction == Direction::WEST) {
        _facing_direction = Direction::NORTH;
    }
}

std::string Robot::Report() const {
    if (!_is_placed) {
        return "";
    }
    std::stringstream ss;
    ss << _position.x << "," << _position.y << ",";
    ss << ToDirectionString(_facing_direction);
    
    return ss.str();
}

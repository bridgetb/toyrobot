#ifndef ROBOT_H
#define ROBOT_H

#include <string>
#include <unordered_map>
#include <utility>

#include "direction.h"

namespace toy {

const std::string kPlace = "PLACE";
const std::string kMove = "MOVE";
const std::string kLeft = "LEFT";
const std::string kRight = "RIGHT";
const std::string kReport = "REPORT";
const int DEFAULT_TABLE_LENGTH = 5;

class Robot {
public:
    Robot(int table_width = DEFAULT_TABLE_LENGTH, int table_depth = DEFAULT_TABLE_LENGTH);
    Coordinates GetPosition() const;
    Direction GetDirection() const;
    void Place(const Coordinates& start, Direction facing);
    bool Move();
    void RotateLeft();
    void RotateRight();
    std::string Report() const;
        
private:
    bool _is_placed = false;
    Coordinates _position;
    Direction _facing_direction;
    int _table_width;
    int _table_depth;
    
};

} // namespace toy

#endif

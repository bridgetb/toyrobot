#include <iostream>
#include <fstream>
#include <sstream>

#include "robot.h"

using namespace toy;

int main(int argc, const char* argv[]) {
    Robot robot;
    for (std::string line; std::getline(std::cin, line);) {
        if (line.find(kPlace) == 0) {
            line = line.substr(kPlace.size());
            std::istringstream iss(line);
            std::string part;
            Coordinates position;
            Direction direction;
            try {
                if (std::getline(iss, part, ',')) {
                    position.x = std::stoi(part);
                }
                if (std::getline(iss, part, ',')) {
                    position.y = std::stoi(part);
                }
                if (std::getline(iss, part)) {
                    direction = ToDirection(part);
                }
            } catch (...) {
                continue;
            }
            robot.Place(position, direction);
        } else if (line == kMove) {
            robot.Move();
        } else if (line == kLeft) {
            robot.RotateLeft();
        } else if (line == kRight) {
            robot.RotateRight();
        } else if (line == kReport) {
            std::cout << robot.Report() << std::endl;
        }
    }

    return 0;
}

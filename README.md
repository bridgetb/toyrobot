Setup
=====
To run the game/simulation, build the source folder with CMake and run the `toy_robot` executable. A convenience (`build_mac.sh`) script is provided in the root directory which works on macOS only.

The tests are also built in the same CMakeLists.txt and require googletest to be installed and on the PATH.

Test Cases
==========
The following test cases are covered in robot_test.cpp:
20 cases where the robot is placed in the four corners and borders of the board, then moved once, followed by a position verification.
5 cases to check that the report string is as expected after a sequence of event(s).
The equivalent commands would be (each test case separated by two new lines):

```
PLACE 0,0,NORTH
MOVE
REPORT
Output: 0,1,NORTH


PLACE 0,0,SOUTH
MOVE
REPORT
Output: 0,0,SOUTH


PLACE 0,0,EAST
MOVE
REPORT
Output: 1,0,EAST


PLACE 0,0,WEST
MOVE
REPORT
Output: 0,0,WEST


PLACE 0,4,NORTH
MOVE
REPORT
Output: 0,4,NORTH


PLACE 0,4,SOUTH
MOVE
REPORT
Output: 0,3,SOUTH


PLACE 0,4,EAST
MOVE
REPORT
Output: 1,4,EAST


PLACE 0,4,WEST
MOVE
REPORT
Output: 0,4,WEST


PLACE 4,4,NORTH
MOVE
REPORT
Output: 4,4,NORTH


PLACE 4,4,SOUTH
MOVE
REPORT
Output: 4,3,SOUTH


PLACE 4,4,EAST
MOVE
REPORT
Output: 4,4,EAST


PLACE 4,4,WEST
MOVE
REPORT
Output: 3,4,WEST


PLACE 4,0,NORTH
MOVE
REPORT
Output: 4,1,NORTH


PLACE 4,0,SOUTH
MOVE
REPORT
Output: 4,0,SOUTH


PLACE 4,0,EAST
MOVE
REPORT
Output: 4,0,EAST


PLACE 4,0,WEST
MOVE
REPORT
Output: 3,0,WEST


PLACE 2,0,NORTH
MOVE
REPORT
Output: 2,1,NORTH


PLACE 0,2,EAST
MOVE
REPORT
Output: 1,2,EAST


PLACE 4,2,WEST
MOVE
REPORT
Output: 3,2,WEST


PLACE 2,4,SOUTH
MOVE
REPORT
Output: 2,3,SOUTH


Other test cases:
PLACE 8,0,EAST
REPORT
Output: (No output - blank line expected)


PLACE 1,-8,EAST
REPORT
Output: (No output - blank line expected)


PLACE 0,0,NORTH
MOVE
REPORT
Output: 0,1,NORTH


PLACE 0,0,NORTH
LEFT
REPORT
Output: 0,0,WEST


PLACE 0,0,NORTH
RIGHT
REPORT
Output: 0,0,EAST


PLACE 1,2,EAST
MOVE
MOVE
LEFT
MOVE
REPORT
Output: 3,3,NORTH
```

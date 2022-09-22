#include "gtest/gtest.h"

#include "robot.h"

using namespace toy;

struct MoveInfo {
    Coordinates start_position;
    Direction start_direction;
    Coordinates end_position;
};

class RobotMoveTest : public ::testing::TestWithParam<MoveInfo> {
public:
    RobotMoveTest() = default;
    
protected:
    Robot _robot;
};

TEST_P(RobotMoveTest, MoveFromPosition) {
    MoveInfo test_data = GetParam();
    _robot.Place(test_data.start_position, test_data.start_direction);
    _robot.Move();
    ASSERT_EQ(test_data.end_position, _robot.GetPosition());
    ASSERT_EQ(test_data.start_direction, _robot.GetDirection());
}

INSTANTIATE_TEST_SUITE_P(RobotTests,
                         RobotMoveTest,
    ::testing::Values(// Bottom left
                      MoveInfo{Coordinates{0,0}, Direction::NORTH, Coordinates{0,1}},
                      MoveInfo{Coordinates{0,0}, Direction::SOUTH, Coordinates{0,0}},
                      MoveInfo{Coordinates{0,0}, Direction::EAST, Coordinates{1,0}},
                      MoveInfo{Coordinates{0,0}, Direction::WEST, Coordinates{0,0}},
                      // Top left
                      MoveInfo{Coordinates{0,4}, Direction::NORTH, Coordinates{0,4}},
                      MoveInfo{Coordinates{0,4}, Direction::SOUTH, Coordinates{0,3}},
                      MoveInfo{Coordinates{0,4}, Direction::EAST, Coordinates{1,4}},
                      MoveInfo{Coordinates{0,4}, Direction::WEST, Coordinates{0,4}},
                      // Top right
                      MoveInfo{Coordinates{4,4}, Direction::NORTH, Coordinates{4,4}},
                      MoveInfo{Coordinates{4,4}, Direction::SOUTH, Coordinates{4,3}},
                      MoveInfo{Coordinates{4,4}, Direction::EAST, Coordinates{4,4}},
                      MoveInfo{Coordinates{4,4}, Direction::WEST, Coordinates{3,4}},
                      // Bottom right
                      MoveInfo{Coordinates{4,0}, Direction::NORTH, Coordinates{4,1}},
                      MoveInfo{Coordinates{4,0}, Direction::SOUTH, Coordinates{4,0}},
                      MoveInfo{Coordinates{4,0}, Direction::EAST, Coordinates{4,0}},
                      MoveInfo{Coordinates{4,0}, Direction::WEST, Coordinates{3,0}},
                      // Border
                      MoveInfo{Coordinates{2,0}, Direction::NORTH, Coordinates{2,1}},
                      MoveInfo{Coordinates{0,2}, Direction::EAST, Coordinates{1,2}},
                      MoveInfo{Coordinates{4,2}, Direction::WEST, Coordinates{3,2}},
                      MoveInfo{Coordinates{2,4}, Direction::SOUTH, Coordinates{2,3}}
    )
);


class RobotReportTest : public ::testing::Test {
public:
    RobotReportTest() = default;
    
protected:
    Robot _robot;
};

TEST_F(RobotReportTest, PlaceOutside) {
    // Reporting the position of an unplaced robot returns an empty string report
    Coordinates start{8, 0};
    _robot.Place(start, Direction::EAST);
    EXPECT_EQ("", _robot.Report());
    
    Coordinates negative_start{1, -8};
    _robot.Place(negative_start, Direction::EAST);
    EXPECT_EQ("", _robot.Report());
}

TEST_F(RobotReportTest, MoveThenReport) {
    Coordinates start{0, 0};
    _robot.Place(start, Direction::NORTH);
    _robot.Move();
    ASSERT_EQ("0,1,NORTH", _robot.Report());
}

TEST_F(RobotReportTest, RotateLeft) {
    Coordinates start{0, 0};
    _robot.Place(start, Direction::NORTH);
    _robot.RotateLeft();
    ASSERT_EQ("0,0,WEST", _robot.Report());
}

TEST_F(RobotReportTest, RotateRight) {
    Coordinates start{0, 0};
    _robot.Place(start, Direction::NORTH);
    _robot.RotateRight();
    ASSERT_EQ("0,0,EAST", _robot.Report());
}

TEST_F(RobotReportTest, SequenceThenReport) {
    Coordinates start{1, 2};
    _robot.Place(start, Direction::EAST);
    _robot.Move();
    _robot.Move();
    _robot.RotateLeft();
    _robot.Move();
    ASSERT_EQ("3,3,NORTH", _robot.Report());
}

int main(int argc, char * argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    int result = RUN_ALL_TESTS();
    return result;
}

cmake_minimum_required(VERSION 3.8)
project(ex2)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(SOURCE_FILES src/Board.cpp src/Board.h src/ConsoleDisplay.cpp src/ConsoleDisplay.h src/Display.cpp src/Display.h src/GameRunner.cpp src/GameRunner.h src/Player.cpp src/Player.h src/HumanPlayer.cpp src/HumanPlayer.h src/Rules.cpp src/Rules.h src/RegularRules.cpp src/RegularRules.h src/ComputerPlayer.cpp src/ComputerPlayer.h src/Menu.cpp src/Menu.h tests/MenuTest.cpp)
set(TESTS_FILES tests/BoardTest.cpp src/Menu.cpp src/Menu.h tests/MenuTest.cpp)

add_executable(ex2 ${SORCE_FILES} src/main.cpp src/Board.cpp src/Board.h src/ConsoleDisplay.cpp src/ConsoleDisplay.h src/Display.cpp src/Display.h src/GameRunner.cpp src/GameRunner.h src/Player.cpp src/Player.h src/HumanPlayer.cpp src/HumanPlayer.h src/Rules.cpp src/Rules.h src/RegularRules.cpp src/RegularRules.h src/ComputerPlayer.cpp src/ComputerPlayer.h src/Menu.cpp src/Menu.h)
add_executable(tests tests/gtest_main.cpp ${TESTS_FILES} ${SOURCE_FILES})

target_link_libraries(tests gtest gtest_main)
add_test(tests tests)
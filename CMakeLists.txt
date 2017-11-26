cmake_minimum_required(VERSION 3.8)
project(ex2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Board.cpp Board.h ConsoleDisplay.cpp ConsoleDisplay.h Display.cpp Display.h GameRunner.cpp GameRunner.h Player.cpp Player.h HumanPlayer.cpp HumanPlayer.h Rules.cpp Rules.h RegularRules.cpp RegularRules.h ComputerPlayer.cpp ComputerPlayer.h)
add_executable(ex2 ${SOURCE_FILES} Board.cpp Board.h ConsoleDisplay.cpp ConsoleDisplay.h Display.cpp Display.h GameRunner.cpp GameRunner.h Player.cpp Player.h HumanPlayer.cpp HumanPlayer.h Rules.cpp Rules.h RegularRules.cpp RegularRules.h ComputerPlayer.cpp ComputerPlayer.h)
cmake_minimum_required(VERSION 3.5)
project(PomodoroTray)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

add_executable(PomodoroTray
    main.cpp
    pomodoro.cpp
    pomodoro.h    # <<-- Add this!
)

target_link_libraries(PomodoroTray Qt5::Widgets)

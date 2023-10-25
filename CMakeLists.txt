cmake_minimum_required(VERSION 3.5)

project(QMavlinkNpu VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
# find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

find_package(MAVSDK REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        qmavlinknpu.cpp
        qmavlinknpu.h
        qmavlinknpu.ui
)

add_executable(QMavlinkNpu ${PROJECT_SOURCES})
target_link_libraries(QMavlinkNpu PRIVATE 
        Qt${QT_VERSION_MAJOR}::Widgets 
        MAVSDK::mavsdk
)

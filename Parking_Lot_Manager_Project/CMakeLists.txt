cmake_minimum_required(VERSION 3.10)

# Project name
project(ParkingLotManager)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable with the source files
add_executable(parking_lot
    main.cpp
    ParkingLot.cpp
)

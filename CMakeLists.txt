cmake_minimum_required(VERSION 3.10)

project(QuantEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(QuantEngine
    src/main.cpp
    src/DataGenerator.cpp
    src/CSVLoader.cpp
    src/Order.cpp
    src/Trade.cpp
    src/Position.cpp
    src/Portfolio.cpp
    src/MovingAverage.cpp
    src/BackEngine.cpp
    src/PerformanceAnalyzer.cpp
)
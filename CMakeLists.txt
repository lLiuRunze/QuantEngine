cmake_minimum_required(VERSION 3.10)

project(QuantEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(QuantEngine
    src/main.cpp
    src/data/DataGenerator.cpp
    src/data/CSVLoader.cpp
    src/core/Order.cpp
    src/core/Trade.cpp
    src/core/Position.cpp
    src/core/Portfolio.cpp
    src/strategy/MovingAverage.cpp
    src/engine/BackEngine.cpp
    src/analytics/PerformanceAnalyzer.cpp
    src/engine/ParameterSweep.cpp
)
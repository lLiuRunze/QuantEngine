#pragma once

#include <map>
#include <string>
#include "core/Position.h"

struct BacktestConfig
{
    double initCash;

    std::map<std::string, Position> initPositions;
};
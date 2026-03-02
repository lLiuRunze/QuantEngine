#pragma once
#include <vector>
#include <memory>
#include "core/Portfolio.h"

class Strategy; // 前向声明：Strategy 只作为 unique_ptr 的模板参数及指针调用

class BackEngine
{
private:
    const std::vector<double> &data;
    std::unique_ptr<Strategy> strategy; // unique_ptr 自动管理内存，无需手动 delete
    Portfolio portfolio;
    std::vector<double> equityCurve;

public:
    BackEngine(const std::vector<double> &prices,
               std::unique_ptr<Strategy> strategy,
               Portfolio portfolio);
    void run();
    double getFinalValue() const;
    const std::vector<double> &getEquityCurve() const;
};

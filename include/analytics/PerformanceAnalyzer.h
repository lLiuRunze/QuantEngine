#pragma once
#include <vector> // 原来错误地包含了 <iostream>，PerformanceAnalyzer 只用 std::vector

class PerformanceAnalyzer
{
private:
    const std::vector<double> &equity_;
    std::vector<double> returns_;

public:
    PerformanceAnalyzer(const std::vector<double> &equity_) : equity_(equity_) {}
    void calReturns();
    double getTotalReturn() const;
    double getSharpRatio() const;
    double getMaxDrawdown() const;
};

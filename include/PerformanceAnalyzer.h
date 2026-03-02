#pragma once
#include<iostream>

class PerformanceAnalyzer{
    private:
        const std::vector<double> &equity_;
        std::vector<double> returns_;
    public:
        PerformanceAnalyzer(const std::vector<double> &equity_) : equity_(equity_) {};
        void calReturns();
        double getTotalReturn() const;
        double getSharpRatio() const;
        double getMaxDrawdown() const;
};
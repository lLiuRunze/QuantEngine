#include "analytics/PerformanceAnalyzer.h"
#include <cmath>
#include <numeric>

void PerformanceAnalyzer::calReturns()
{
    returns_.reserve(equity_.size() - 1);
    for (size_t i = 1; i < equity_.size(); ++i)
        returns_.push_back(equity_[i] / equity_[i - 1] - 1);
}

double PerformanceAnalyzer::getTotalReturn() const
{
    return std::accumulate(returns_.begin(), returns_.end(), 0.0);
}

double PerformanceAnalyzer::getSharpRatio() const
{
    const double mean = getTotalReturn() / returns_.size();
    const double variance = std::inner_product(returns_.begin(), returns_.end(),
                                               returns_.begin(), 0.0) /
                                returns_.size() -
                            mean * mean;
    return mean / std::sqrt(variance);
}

double PerformanceAnalyzer::getMaxDrawdown() const
{
    double max_drawdown = 0.0;
    double peak = equity_[0];
    for (size_t i = 1; i < equity_.size(); ++i)
    {
        if (equity_[i] > peak)
        {
            peak = equity_[i];
        }
        else
        {
            const double drawdown = (peak - equity_[i]) / peak;
            if (drawdown > max_drawdown)
                max_drawdown = drawdown;
        }
    }
    return max_drawdown;
}

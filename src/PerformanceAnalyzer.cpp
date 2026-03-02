#include "PerformanceAnalyzer.h"
#include <cmath>
#include<vector>
#include<numeric>

// void calReturns();
// double getTotalReturn() const;
// double getSharpRatio() const;
// double getMaxDrawdown() const;

void PerformanceAnalyzer::calReturns(){
    returns_.reserve(equity_.size() - 1);
    for (int i = 1; i < equity_.size(); ++i)
    {
        double ret = equity_[i] / equity_[i-1] - 1;
        returns_.push_back(ret);
    }
}
double PerformanceAnalyzer::getTotalReturn() const{
    return std::accumulate(returns_.begin(), returns_.end(), 0.0);
}
double PerformanceAnalyzer::getSharpRatio() const{
    double mean_return = getTotalReturn() / returns_.size();
    double std_return = std::sqrt(std::inner_product(returns_.begin(), returns_.end(), returns_.begin(), 0.0) / returns_.size() - mean_return * mean_return);
    return mean_return / std_return;
}
double PerformanceAnalyzer::getMaxDrawdown() const{
    double max_drawdown = 0.0;
    double peak_value = equity_[0];
    for (int i = 1; i < equity_.size();++i){
        if(equity_[i] > peak_value){
            peak_value = equity_[i];
        }else{
            double drawdown = (peak_value - equity_[i]) / peak_value;
            if(drawdown > max_drawdown){
                max_drawdown = drawdown;
            }
        }
    }
    return max_drawdown;
}

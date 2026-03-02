#include "data/DataGenerator.h"
#include "strategy/MovingAverage.h"
#include "engine/BackEngine.h"
#include "core/Portfolio.h"
#include "core/Position.h"
#include "analytics/PerformanceAnalyzer.h"
#include <iostream>
#include <memory>

int main()
{
    DataGenerator gen;
    std::vector<double> data = gen.generateData(100, -0.05, 0.2, 5, 0.01);

    auto strategy = std::make_unique<MovingAverage>(5); // unique_ptr，自动释放内存
    Portfolio portfolio(100000.0, {{"SINGLE", Position("SINGLE")}});
    BackEngine engine(data, std::move(strategy), std::move(portfolio));
    engine.run();

    std::cout << "Final Portfolio Value: " << engine.getFinalValue() << std::endl;

    PerformanceAnalyzer analyzer(engine.getEquityCurve());
    analyzer.calReturns();
    std::cout << "Total Return: " << analyzer.getTotalReturn() << std::endl;
    std::cout << "Sharpe Ratio: " << analyzer.getSharpRatio() << std::endl;
    std::cout << "Max Drawdown: " << analyzer.getMaxDrawdown() << std::endl;

    return 0;
}
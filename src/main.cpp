#include "DataGenerator.h"
#include "CSVLoader.h"
#include "Order.h"
#include "Trade.h"
#include "Position.h"
#include "Portfolio.h"
#include "MovingAverage.h"
#include <iostream>

int main()
{
    DataGenerator gen;
    vector<double> data = gen.generateData(10, 0.05, 0.2, 5, 0.01);
    // for(auto price :data){
    //     std::cout << price << std::endl;
    // }
    // gen.saveToCSV(data, "/Users/liurunze/Desktop/file/DA/QR/QuantEngine/data/generated_data.csv");

    // CSVLoader loader;
    // vector<double> loadedData = loader.load("/Users/liurunze/Desktop/file/DA/QR/QuantEngine/data/generated_data.csv");
    // std::cout << "Loaded Data:" << std::endl;
    // for (const auto& price : loadedData) {
    //     std::cout << price << std::endl;
    // }

    // Order order("SINGLE", 100, 10.5);
    // std::cout << "Order Details:" << std::endl;
    // std::cout << "Symbol: " << order.getSymbol() << std::endl;
    // std::cout << "Quantity: " << order.getQuantity() << std::endl;
    // std::cout << "Price: " << order.getPrice() << std::endl;

    // Trade trade("SINGLE", 100, 10.5, "2024-06-01 10:00:00");
    // Trade trade2("SINGLE", -50, 11.0, "2024-06-01 11:00:00");
    // Trade trade3("SINGLE", 30, 9.5, "2024-06-01 12:00:00");
    // std::cout << "Trade Details:" << std::endl;
    // std::cout << "Symbol: " << trade.getSymbol() << std::endl;
    // std::cout << "Quantity: " << trade.getQuantity() << std::endl;
    // std::cout << "Price: " << trade.getPrice() << std::endl;
    // std::cout << "Time: " << trade.getTime() << std::endl;
    // Position position("SINGLE");
    // position.update(trade);
    // position.update(trade2);
    // position.update(trade3);
    // std::cout << "Position Details:" << std::endl;
    // std::cout << "Symbol: " << position.getSymbol() << std::endl;
    // std::cout << "Quantity: " << position.getQuantity() << std::endl;
    // std::cout << "Average Price: " << position.getAvgPrice() << std::endl;

    // Portfolio portfolio(100000.0, {{"SINGLE", position}});
    // portfolio.executeOrder(Order("SINGLE", 100, 10.5), 10.5, "2024-06-01 10:00:00");
    // portfolio.executeOrder(Order("SINGLE", -50, 11.0), 11.0, "2024-06-01 11:00:00");
    // portfolio.executeOrder(Order("SINGLE", 30, 9.5), 9.5, "2024-06-01 12:00:00");
    // std::cout << "Portfolio Details:" << std::endl;
    // std::cout << "Cash: " << portfolio.getCash() << std::endl;
    // std::cout << "Total Value: " << portfolio.getTotalValue(10.0) << std::endl; 
    // std::cout << "Positions:" << std::endl;
    // for (const auto &entry : portfolio.getPositions()) {
    //     const Position &pos = entry.second;
    //     std::cout << "Symbol: " << pos.getSymbol() << ", Quantity: " << pos.getQuantity() << ", Average Price: " << pos.getAvgPrice() << std::endl;
    // }
    // std::cout << "Trade History:" << std::endl;
    // for (const auto &trade : portfolio.getTradeHistory()) {
    //     std::cout << "Symbol: " << trade.getSymbol() << ", Quantity: " << trade.getQuantity() << ", Price: " << trade.getPrice() << ", Time: " << trade.getTime() << std::endl;
    // }

    Strategy *strategy = new MovingAverage(5);
    Portfolio portfolio(100000.0, {{"SINGLE", Position("SINGLE")}});
    for(int i = 0; i < data.size(); i++){
        double price = data[i];
        strategy->onBar(price);
        int signal = strategy->getSignal();
        if (signal ==1){
            Order buyorder("SINGLE", 100, price);
            portfolio.executeOrder(buyorder, price, std::to_string(i));
        }
        if(signal == -1){
            Order sellorder("SINGLE", -100, price);
            portfolio.executeOrder(sellorder, price, std::to_string(i));
        }
    }
    std::cout << "Final Portfolio Value: " << portfolio.getTotalValue(data.back()) << std::endl;
    std::cout << "Trade History:" << std::endl;
    for (const auto &trade : portfolio.getTradeHistory()) {
        std::cout << "Symbol: " << trade.getSymbol() << ", Quantity: " << trade.getQuantity() << ", Price: " << trade.getPrice() << ", Time: " << trade.getTime() << std::endl;
    }
    std::cout << "Final return " << (portfolio.getTotalValue(data.back()) - 100000.0) / 100000.0 * 100 << "%" << std::endl;
    delete strategy;

    return 0;
}
#pragma once

class Strategy
{
public:
    virtual void onBar(double price) = 0;
    virtual int getSignal() const = 0;
    virtual ~Strategy() = default;
};

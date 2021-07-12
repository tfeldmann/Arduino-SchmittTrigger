#pragma once

template <typename T = int>
class SchmittTrigger
{
public:
    SchmittTrigger()
    {
    }

    SchmittTrigger(T lower, T upper)
    {
        set_thresholds(lower, upper);
    }

    void set_thresholds(T lower, T upper)
    {
        lower_ = lower;
        upper_ = upper;
    }

    void input(T value)
    {
        if (value >= upper_)
            state_ = true;
        if (value <= lower_)
            state_ = false;
    }

    bool output()
    {
        return state_;
    }

private:
    T lower_ = 0;
    T upper_ = 0;
    bool state_ = false;
};

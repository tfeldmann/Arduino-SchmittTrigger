#pragma once

template <typename T = int>
class SchmittTrigger {
public:
    SchmittTrigger()
        : lower_(0)
        , upper_(0)
        , state_(false) {};

    SchmittTrigger(T lower, T upper)
        : lower_(lower)
        , upper_(upper)
        , state_(false) {};

    void set_thresholds(T lower, T upper)
    {
        lower_ = lower;
        upper_ = upper;
    }

    bool input(T value)
    {
        if (value <= lower_) {
            state_ = false;
        }
        if (value >= upper_) {
            state_ = true;
        }
        return state_;
    }

    bool output()
    {
        return state_;
    }

private:
    T lower_;
    T upper_;
    bool state_;
};

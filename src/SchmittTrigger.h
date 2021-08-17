#pragma once

template <typename T = int>
class SchmittTrigger
{
public:
    SchmittTrigger()
    {
    }

    SchmittTrigger(T switch_off_point, T switch_on_point)
    {
        set_thresholds(switch_off_point, switch_on_point);
    }

    void set_thresholds(T switch_off_point, T switch_on_point)
    {
        switch_off_point_ = switch_off_point;
        switch_on_point_ = switch_on_point;
    }

    void input(T value)
    {
        if (value >= switch_on_point_)
            state_ = true;
        if (value <= switch_off_point_)
            state_ = false;
    }

    bool output()
    {
        return state_;
    }

private:
    T switch_off_point_ = 0;
    T switch_on_point_ = 0;
    bool state_ = false;
};

#include <iostream>

struct BloodPressure
{
    unsigned int systolic;
    unsigned int diastolic;

    enum BloodPressureLevel
    {
        HYPOTENSION,
        NOMINAL,
        ELEVATED,
        HYPERTENSION,
    };

    BloodPressureLevel diagnosis()
    {
        if (systolic >= 140 or diastolic >= 90)
            return HYPERTENSION;
        if (systolic >= 120 or diastolic >= 80)
            return ELEVATED;
        if (systolic < 90 or diastolic < 60)
            return HYPOTENSION;
        return NOMINAL;
    }
};

int main ()
{
    BloodPressure bp;

    bp.systolic = 119;
    bp.diastolic = 79;

    typedef BloodPressure::BloodPressureLevel BPLEnum;

    if (bp.diagnosis() == BPLEnum::NOMINAL)
    {
        std::cout
            << "You have good blood pressure"
            << std::endl;
    }
    else
    {
        std::cout
            << "You have bad blood pressure, please go to the doctor"
            << std::endl;
    }
}

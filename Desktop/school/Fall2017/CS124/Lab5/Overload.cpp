#include "lab.h"
bool operator<(AQIData& lhs,AQIData& rhs)
{
    return (lhs.AQI < rhs.AQI);
}
bool operator>(AQIData& lhs,AQIData& rhs)
{
    return (lhs.AQI > rhs.AQI);
}

bool operator>=(AQIData& lhs, AQIData& rhs)
{
    return (lhs.AQI >= rhs.AQI);
}

bool operator<=(AQIData& lhs, AQIData& rhs)
{
    return (rhs.AQI <= rhs.AQI);
}

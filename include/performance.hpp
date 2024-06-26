#pragma once

#include <string>

namespace data
{
    struct Performance
    {
        long long time_spend;
        long long memory_usage;
        std::string data_struct;
        std::string date;
        std::string time;
    };
    
} // namespace data

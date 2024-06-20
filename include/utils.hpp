#pragma once

#include "performance.hpp"
#include <vector>

namespace utils
{
    void print_duration(const long long &time);
    void write_report(const long long &time, const std::string &text);
    bool write_all_report(const std::vector<data::Performance> &infos);
    auto get_system_time() -> std::string;
    auto get_system_date() -> std::string;
} // namespace data
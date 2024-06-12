#include "utils.hpp"
#include "performance.hpp"
#include <string>
#include <fstream>
#include <windows.h>
#include <psapi.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

namespace utils
{
    void print_duration(const long long &time)
    {
        std::cout << std::endl;
        std::cout << "#############################" << std::endl;
        std::cout << "Duration test is: " << time << " milliseconds" << std::endl;
        std::cout << "#############################" << std::endl;
    }

    void write_report(const long long &time, const std::string &text)
    {
        std::string file_test = "\nDuration test from " + text + " is: " + std::to_string(time) + " milliseconds\n";
        std::ofstream out("../report.txt", std::ios_base::app);
        out.clear();
        out << file_test;
        out.close();
    }

    bool write_all_report(const std::vector<data::Performance> &infos)
    {
        try
        {
            for (size_t i = 0; i < infos.size(); i++)
            {
                std::string file_test;
                file_test = "\n| " + infos.at(i).date + " | " + infos.at(i).time + " | " + infos.at(i).data_struct + " | " + std::to_string(infos.at(i).time_spend) +" milliseconds "+" | " + std::to_string(infos.at(i).memory_usage) + " Bytes |";
                std::ofstream out("../README.md", std::ios_base::app);
                out << file_test;
                out.close();
            }
            return true;
        }
        catch (...)
        {
            return false;
        }
    }

    long long get_memory_usage()
    {
        PROCESS_MEMORY_COUNTERS pmc;
        if (GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc)))
        {
            auto memory_usage = (pmc.WorkingSetSize / 1024);
            return memory_usage;
        }
        else
        {
            return 0;
        }
    }

    auto get_system_time() -> std::string
    {
        time_t now = time(0);
        const auto time = *localtime(&now);
        return std::to_string(time.tm_hour) + ":" + std::to_string(time.tm_min) + ":" + std::to_string(time.tm_sec);
    }

    auto get_system_date() -> std::string
    {
        time_t now = time(0);
        const auto date = *localtime(&now);
        auto year = date.tm_year + 1900;
        return std::to_string(date.tm_mday) + "/" + std::to_string(date.tm_mon) + "/" + std::to_string(year);
    }
} // namespace utils

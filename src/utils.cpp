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

    void write_all_report(const std::vector<data::Performance> &infos)
    {
        for (size_t i = 0; i < infos.size(); i++)
        {
            std::string file_test = "\nDuration test from " + infos.at(i).data_struct + " is: " + std::to_string(infos.at(i).time_spend) + " milliseconds.\n" + 
            "Usage of memory: " + std::to_string(infos.at(i).memory_usage) + " KB\n";
            std::ofstream out("../report.txt", std::ios_base::app);
            out << file_test;
            out.close();
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
} // namespace utils

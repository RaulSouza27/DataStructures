#include "array_test.hpp"
#include "list_test.hpp"
#include "vector_test.hpp"
#include "utils.hpp"
#include "catch.hpp"
#include <chrono>

namespace data
{
    long long array_time();
    long long list_time();
    long long vector_time();

    TEST_CASE("Testing fill, print and clear performance")
    {
        std::vector<Performance> perf;
        Performance array;
        array.time_spend = array_time();
        array.data_struct = "std::array";
        array.memory_usage = utils::get_memory_usage();
        perf.push_back(array);

        Performance vector;
        vector.time_spend = vector_time();
        vector.data_struct = "std::vector";
        vector.memory_usage = utils::get_memory_usage();
        perf.push_back(vector);

        Performance list;
        list.time_spend = list_time();
        list.data_struct = "std::list";
        list.memory_usage = utils::get_memory_usage();
        perf.push_back(list);

        utils::write_all_report(perf);
    }

    long long array_time()
    {
        ArrayTest test;
        auto start_array = std::chrono::high_resolution_clock::now();
        test.fill_array();
        test.print_array();
        test.clear_array();
        auto end_array = std::chrono::high_resolution_clock::now();
        auto time_array = std::chrono::duration_cast<std::chrono::milliseconds>(end_array - start_array);
        return time_array.count();
    }

    long long list_time()
    {
        ListTest test;
        auto start = std::chrono::high_resolution_clock::now();
        test.fill_list();
        test.print_list();
        test.clear_list();
        auto end = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        return time.count();
    }

    long long vector_time()
    {
        VectorTest test;
        auto start = std::chrono::high_resolution_clock::now();
        test.fill_vector();
        test.print_vector();
        test.clear_vector();
        auto end = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        return time.count();
    }

} // namespace data

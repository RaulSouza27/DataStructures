#include "array_test.hpp"
#include "list_test.hpp"
#include "vector_test.hpp"
#include "deque_test.hpp"
#include "queue_test.hpp"
#include "utils.hpp"
#include "catch.hpp"
#include <chrono>

namespace data
{
    long long array_time(ArrayTest &);
    long long list_time(ListTest &);
    long long vector_time(VectorTest &);
    long long deque_time(DequeTest &);
    long long queue_time(QueueTest &);

    TEST_CASE("Testing fill, print and clear performance")
    {
        ArrayTest array_test;
        ListTest list_test;
        VectorTest vector_test;
        DequeTest deque_test;
        QueueTest queue_test;

        std::vector<Performance> perf;
        Performance array;
        array.time_spend = array_time(array_test);
        array.data_struct = "std::array";
        array.date = utils::get_system_date();
        array.time = utils::get_system_time();
        array.memory_usage = sizeof(ArrayTest);
        perf.push_back(array);

        Performance vector;
        vector.time_spend = vector_time(vector_test);
        vector.data_struct = "std::vector";
        vector.date = utils::get_system_date();
        vector.time = utils::get_system_time();
        vector.memory_usage = vector_test.get_vector().size() + sizeof(VectorTest);
        perf.push_back(vector);

        Performance list;
        list.time_spend = list_time(list_test);
        list.data_struct = "std::list";
        list.date = utils::get_system_date();
        list.time = utils::get_system_time();
        list.memory_usage = list_test.get_list().size() + sizeof(ListTest);
        perf.push_back(list);

        Performance deque;
        deque.time_spend = deque_time(deque_test);
        deque.data_struct = "std::deque";
        deque.date = utils::get_system_date();
        deque.time = utils::get_system_time();
        deque.memory_usage = deque_test.get_deque().size() + sizeof(DequeTest);
        perf.push_back(deque);

        Performance queue;
        queue.time_spend = queue_time(queue_test);
        queue.data_struct = "std::queue";
        queue.date = utils::get_system_date();
        queue.time = utils::get_system_time();
        queue.memory_usage = queue_test.get_queue().size() + sizeof(QueueTest);
        perf.push_back(queue);

        REQUIRE(utils::write_all_report(perf));
    }

    long long array_time(ArrayTest &test)
    {
        auto start_array = std::chrono::high_resolution_clock::now();
        test.fill_array();
        test.print_array();
        auto end_array = std::chrono::high_resolution_clock::now();
        auto time_array = std::chrono::duration_cast<std::chrono::milliseconds>(end_array - start_array);
        return time_array.count();
    }

    long long list_time(ListTest &test)
    {
        auto start = std::chrono::high_resolution_clock::now();
        test.fill_list();
        test.print_list();
        auto end = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        return time.count();
    }

    long long vector_time(VectorTest &test)
    {
        auto start = std::chrono::high_resolution_clock::now();
        test.fill_vector();
        test.print_vector();
        auto end = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        return time.count();
    }

    long long deque_time(DequeTest &test)
    {
        auto start = std::chrono::high_resolution_clock::now();
        test.fill_deque();
        test.print_deque();
        auto end = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        return time.count();
    }

    long long queue_time(QueueTest &test)
    {
        auto start = std::chrono::high_resolution_clock::now();
        test.fill_queue();
        test.print_queue();
        auto end = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        return time.count();
    }

} // namespace data

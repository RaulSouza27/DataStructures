#include "queue_test.hpp"
#include <iostream>

namespace data
{
    void QueueTest::fill_queue()
    {
        for (size_t i = 0; i < 255; i++)
        {
            my_queue.push(i);
        }
    }

    void QueueTest::print_queue()
    {
        for (size_t i = 0; i < my_queue.size(); i++)
        {
            std::cout << my_queue.front()+i << " ";
        }
    }

    auto QueueTest::get_queue() -> std::queue<uint8_t>&
    {
        return my_queue;
    }
} // namespace data

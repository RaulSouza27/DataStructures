#include "deque_test.hpp"
#include <iostream>

namespace data
{
    void DequeTest::fill_deque()
    {
        for (size_t i = 0; i < 255; i++)
        {
            my_deque.push_back(i);
        }
    }

    void DequeTest::print_deque()
    {
        for (size_t i = 0; i < my_deque.size(); i++)
        {
            std::cout << "Deque item: " << my_deque.at(i);
        }
    }

    auto DequeTest::get_deque() -> std::deque<uint8_t>&
    {
        return my_deque;
    }
} // namespace data

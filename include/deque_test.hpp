#pragma once

#include <deque>

namespace data
{
    class DequeTest
    {
    private:
        std::deque<uint8_t> my_deque;
    public:
        void fill_deque();
        void print_deque();
        auto get_deque() -> std::deque<uint8_t>&;
    };
    
} // namespace data

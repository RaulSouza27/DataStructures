#pragma once

#include <queue>

namespace data
{
    class QueueTest
    {
    private:
        std::queue<uint8_t> my_queue;
    public:
        void fill_queue();
        void print_queue();
        auto get_queue() -> std::queue<uint8_t>&;
    };
    
} // namespace data

#pragma once

#include <list>

namespace data
{
    class ListTest
    {
    private:
        std::list<uint8_t> my_list;
    public:
        void fill_list();
        void print_list();
        auto get_list() -> std::list<uint8_t>&;
    };
    
} // namespace data

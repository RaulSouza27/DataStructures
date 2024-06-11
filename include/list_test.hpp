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
        void clear_list();
    };
    
} // namespace data

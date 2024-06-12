#include "list_test.hpp"
#include <iostream>

namespace data
{
    void ListTest::fill_list()
    {
        for (size_t i = 0; i < 255; i++)
        {
            my_list.push_back(i);
        }
    }

    void ListTest::print_list()
    {
        for(const auto& element : my_list)
        {
            std::cout << element << " ";
        }
    }

    auto ListTest::get_list() -> std::list<uint8_t>&
    {
        return my_list;
    }
} // namespace data

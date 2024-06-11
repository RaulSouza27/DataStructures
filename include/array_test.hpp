#pragma once

#include <array>
#include <cstdint>
#include <iostream>

namespace data
{
    class ArrayTest
    {
    private:
        std::array<uint8_t, 255> array_test;
    public:
        void fill_array();
        void clear_array();
        void print_array();
    };
    
} // namespace data

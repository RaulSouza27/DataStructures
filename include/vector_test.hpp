#pragma once

#include <vector>
#include <cstdint>

namespace data
{
    class VectorTest
    {
    private:
        std::vector<uint8_t> vector_test;
    public:
        void fill_vector();
        void print_vector();
        void clear_vector();
    };
} // namespace data

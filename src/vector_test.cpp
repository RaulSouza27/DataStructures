#include "vector_test.hpp"
#include <iostream>

namespace data
{
    void VectorTest::fill_vector()
    {
        for (size_t i = 0; i < 255; i++)
        {
            vector_test.push_back(i);
        }
    }

    auto VectorTest::get_vector() -> std::vector<uint8_t>&
    {
        return vector_test;
    }

    void VectorTest::print_vector()
    {
        for (size_t i = 0; i < vector_test.size(); i++)
        {
            std::cout << vector_test.at(i);
        }
        
    }

} // namespace data

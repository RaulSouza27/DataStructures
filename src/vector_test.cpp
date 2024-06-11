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

    void VectorTest::print_vector()
    {
        for (size_t i = 0; i < vector_test.size(); i++)
        {
            vector_test.pop_back();
        }
        
    }

    void VectorTest::clear_vector()
    {
        for (size_t i = 0; i < vector_test.size(); i++)
        {
            std::cout << vector_test.at(i);
        }
        
    }

} // namespace data

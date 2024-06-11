#include "array_test.hpp"

namespace data
{
    void ArrayTest::fill_array()
    {
        for (size_t i = 0; i < 255; i++)
        {
            array_test.at(i) = i;
        }
    }

    void ArrayTest::clear_array()
    {
        for (size_t i = 0; i < 255; i++)
        {
            array_test.at(i) = 0;
        }
    }

    void ArrayTest::print_array()
    {
        for (size_t i = 0; i < array_test.size(); i++)
        {
            std::cout << "Array item: " << array_test.at(i);
        }
    }
} // namespace data

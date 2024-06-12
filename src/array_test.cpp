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

    auto ArrayTest::get_array() -> std::array<uint8_t, 255>&
    {
        return array_test;
    }

    void ArrayTest::print_array()
    {
        for (size_t i = 0; i < array_test.size(); i++)
        {
            std::cout << "Array item: " << array_test.at(i);
        }
    }
} // namespace data

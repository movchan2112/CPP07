#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

int main(void)
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    Array<int> numbers(MAX_VAL);
    int *mirror = new int[MAX_VAL];

    for (int i = 0; i < MAX_VAL; ++i)
    {
        const int value = std::rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    Array<int> tmp = numbers;
    Array<int> test(tmp);

    for (int i = 0; i < MAX_VAL; ++i)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "Error: values differ after copy." << std::endl;
            delete[] mirror;
            return 1;
        }
    }

    try
    {
        numbers[-2] = 0;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception (negative index): " << e.what() << std::endl;
    }

    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception (upper bound): " << e.what() << std::endl;
    }

    for (int i = 0; i < MAX_VAL; ++i)
        numbers[i] = std::rand();

    delete[] mirror;

    std::cout << "Array size: " << numbers.size() << std::endl;
    std::cout << "All tests completed." << std::endl;
    return 0;
}

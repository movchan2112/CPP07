#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printElement(const T &value)
{
    std::cout << value << " ";
}

void incrementInt(int &value)
{
    ++value;
}

int main(void)
{
    int numbers[] = {1, 2, 3, 4, 5};
    const std::size_t numbersLen = sizeof(numbers) / sizeof(numbers[0]);

    std::cout << "Before increment: ";
    iter(numbers, numbersLen, printElement<int>);
    std::cout << std::endl;

    iter(numbers, numbersLen, incrementInt);

    std::cout << "After increment:  ";
    iter(numbers, numbersLen, printElement<int>);
    std::cout << std::endl;

    const std::string words[] = {"hello", "template", "world"};
    const std::size_t wordsLen = sizeof(words) / sizeof(words[0]);

    std::cout << "Const array:      ";
    iter(words, wordsLen, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}

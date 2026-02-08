#include <iostream>
#include <stdexcept> // std::out_of_range

template <typename T>
class Array {
private:
    T*            arr;
    unsigned int  len;

public:
    // Default ctor: empty array
    Array() : arr(NULL), len(0) {}

    // Ctor(n): n default-initialized elements
    Array(unsigned int n) : arr(NULL), len(n) {
        if (len > 0)
            arr = new T[len](); // () => value-init (int -> 0)
    }

    // Copy ctor: deep copy
    Array(const Array& other) : arr(NULL), len(other.len) {
        if (len > 0) {
            arr = new T[len]();
            for (unsigned int i = 0; i < len; ++i)
                arr[i] = other.arr[i];
        }
    }

    // Dtor
    ~Array() {
        delete[] arr; // safe even if arr == NULL
    }

    // Assignment: deep copy, self-assignment safe
    Array& operator=(const Array& other) {
        if (this == &other)
            return *this;

        // allocate first (basic exception safety)
        T* newArr = NULL;
        if (other.len > 0) {
            newArr = new T[other.len]();
            for (unsigned int i = 0; i < other.len; ++i)
                newArr[i] = other.arr[i];
        }

        delete[] arr;
        arr = newArr;
        len = other.len;
        return *this;
    }

    // [] with bounds checking
    T& operator[](unsigned int i) {
        if (i >= len)
            throw std::out_of_range("Array index out of bounds");
        return arr[i];
    }

    const T& operator[](unsigned int i) const {
        if (i >= len)
            throw std::out_of_range("Array index out of bounds");
        return arr[i];
    }

    // size()
    unsigned int size() const {
        return len;
    }
};

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    std::cout << numbers[0] << '\n';
    numbers[0] = 12;
    std::cout << numbers[0] << '\n';
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }

//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
}
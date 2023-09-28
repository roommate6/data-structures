#include <iostream>

#include "Vector.hpp"

int main()
{
    Vector<int> integers;

    std::cout << "Before PushBack(obj);" << std::endl;
    std::cout << "Size: " << integers.GetSize() << ' ' << "Capacity: " << integers.GetCapacity() << std::endl;

    integers.PushBack(12);
    integers.PushBack(13);
    integers.PushBack(21);
    integers.PushBack(22);

    std::cout << "After PushBack(obj);" << std::endl;
    std::cout << "Size: " << integers.GetSize() << ' ' << "Capacity: " << integers.GetCapacity() << std::endl;

    std::cout << std::endl;
    std::cout << "Elements before PopBack():" << std::endl;

    for (int i = 0; i < integers.GetSize(); ++i)
    {
        std::cout << integers.GetElementAt(i) << std::endl;
    }

    integers.PopBack();

    std::cout << std::endl;
    std::cout << "Elements after PopBack():" << std::endl;

    for (int i = 0; i < integers.GetSize(); ++i)
    {
        std::cout << integers.GetElementAt(i) << std::endl;
    }

    integers.Clear();

    std::cout << std::endl;
    std::cout << "Elements after Clear():" << std::endl;

    for (int i = 0; i < integers.GetSize(); ++i)
    {
        std::cout << integers.GetElementAt(i) << std::endl;
    }

    return 0;
}
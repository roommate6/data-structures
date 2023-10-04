#include "SimpleList.hpp"

int main()
{
    SimpleList<int> list;

    list.PushBack(1);
    list.PushBack(2);
    list.PushBack(3);
    list.PushBack(4);
    list.PushBack(7);
    list.PushBack(10);
    list.PushFront(9021);

    for (int x : list)
    {
        std::cout << x << " ";
    }

    return 0;
}
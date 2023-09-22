#include <iostream>

#include "Pair.hpp"

int main()
{
    Pair<int, std::string> idPerson(1, "Alex");

    std::cout << idPerson.GetFirst() << ' ' << idPerson.GetSecond() << std::endl;

    return 0;
}

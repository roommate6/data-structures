#include <iostream>

#include "Pair.hpp"

int main()
{
    int id;
    std::cin >> id;

    Pair<int, std::string> idPerson(id, "Alex");
    std::cout << idPerson.GetFirst() << ' ' << idPerson.GetSecond() << std::endl;

    return 0;
}

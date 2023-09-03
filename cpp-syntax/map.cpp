// sample code to learn how to use map to sort and traverse elements.

#include <cstdlib>
#include <climits>
#include <map>
#include <iostream>

void ascending()
{
    std::cout << "Ascending order." << std::endl;
    std::map<int, int> m;
    m[1] = 2; m[2] = 3; m[3] = 4;

    std::cout << "Traverse through the map." << std::endl;
    for (auto &p : m) {
        std::cout << p.first << " -> " << p.second << std::endl;
    }

    std::cout << "Traverse through the map within [INT_MIN, 3]." << std::endl;
    auto end = m.upper_bound(3);
    for (auto it = m.lower_bound(INT_MIN); it != end; ++it) {
        std::cout << it->first << " -> " << it->second << std::endl;
    }

    return;
}

void descending()
{
    std::cout << "Descending order." << std::endl;
    std::map<int, int, std::greater<int>> m;
    m[1] = 2; m[2] = 3; m[3] = 4;

    std::cout << "Traverse through the map." << std::endl;
    for (auto &p : m) {
        std::cout << p.first << " -> " << p.second << std::endl;
    }

    std::cout << "Traverse through the map within [INT_MIN, 3]." << std::endl;
    auto end = m.lower_bound(INT_MIN);
    for (auto it = m.upper_bound(3); it != end; ++it) {
        std::cout << it->first << " -> " << it->second << std::endl;
    }

    return;
}

int main(int argc, char **argv)
{
    (void)argc; (void)argv;

    ascending();
    descending();

    return EXIT_SUCCESS;
}
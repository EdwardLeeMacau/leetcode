// Learn how to use tuple, and figure out the comparability of tuple.

#include <iostream>
#include <tuple>

using Key = std::tuple<int, int>;

int main(int argc, char **argv)
{
    (void)argc; (void)argv;

    Key k1 = std::make_tuple(1, 2);
    Key k2 = std::make_tuple(1, 3);

    std::cout << "k1 < k2: " << (k1 < k2) << std::endl;
    std::cout << "k1 = k2: " << (k1 == k2) << std::endl;
    std::cout << "k1 > k2: " << (k1 > k2) << std::endl;

    return 0;
}
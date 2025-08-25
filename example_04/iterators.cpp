#include <iostream>
#include <vector>

int main()
{
    std::vector<int> items = {1,2,3,4};

    for (int i = 0; i < items.size(); i++)
    {
        std::cout << items[i] << std::endl;
    }

    for (auto it = items.begin(); it != items.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    for (auto &i : items)
    {
        std::cout << i << std::endl;
    }
}

#include <iostream>
#include <list>
#include <iterator>

void mergeLists(std::list<int>& list1, std::list<int>& list2)
{
    auto it1 = std::prev(list1.end());
    auto it2 = std::prev(list2.end());
    auto it3 = list1.end(); //чтобы вставлять элементы из второго списка перед последним вставленным элементом (изначально это конец списка)

    while (!list2.empty())
    {
        if (*it2 > *it1)
        {
            list1.splice(it3, list2, it2);
            it2 = std::prev(list2.end());
        }
        else
            --it1;
        --it3;
    }
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    if (n < 1 || m < 1)
    {
        std::cout << "Not valid array size";
        return -1;
    }

    std::list<int> list1;
    std::list<int> list2;

    for (int i = 0; i < n; ++i)
    {
        int val;
        std::cin >> val;
        list1.push_back(val);
    }

    for (int i = 0; i < m; ++i)
    {
        int val;
        std::cin >> val;
        list2.push_back(val);
    }

    mergeLists(list1, list2);

    for (auto i : list1)
        std::cout << i << ' ';
}
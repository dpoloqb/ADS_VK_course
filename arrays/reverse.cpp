#include <iostream>
#include <vector>

void reverseArray(std::vector<int>& arr) 
{
    size_t left = 0;
    size_t right = arr.size() - 1;

    while (left < right)
    {
        std::swap(arr[left], arr[right]);
        ++left;
        --right;
    }

    for (auto i : arr)
        std::cout << i << ' ';
}

int main()
{
    int len = 0;
    std::cin >> len;
    if (len < 1)
    {
        std::cout << "Not valid array size";
        return -1;
    }

    std::vector<int> arr(len);
    for (int i = 0; i < len; ++i)
        std::cin >> arr[i];

    reverseArray(arr);
}
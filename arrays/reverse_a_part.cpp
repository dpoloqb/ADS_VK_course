#include <iostream>
#include <vector>

void reverseArray(std::vector<int>& arr, size_t left, size_t right) 
{
    while (left < right)
    {
        std::swap(arr[left], arr[right]);
        ++left;
        --right;
    }
}

int main()
{
    int len = 0;
    std::cin >> len;

    std::vector<int> arr(len);
    for (int i = 0; i < len; ++i)
        std::cin >> arr[i];

    size_t k = 0;
    std::cin >> k;

    reverseArray(arr, 0, len - 1);
    reverseArray(arr, 0, (k % len) - 1);
    reverseArray(arr, (k % len), len - 1);

    for (auto i : arr)
        std::cout << i << ' ';
}
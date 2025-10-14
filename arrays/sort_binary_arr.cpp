#include <iostream>
#include <vector>

void sort_binary_arr(std::vector<int>& nums) 
{
    size_t left = 0;
    size_t right = nums.size() - 1;

    while (left < right)
    {
        if (nums[left] == 0)
            ++left;
        else if (nums[right] == 1)
            --right;
        else
            std::swap(nums[left], nums[right]);
    }
}

int main()
{
    int n = 0;
    std::cin >> n;

    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        std::cin >> nums[i];

    sort_binary_arr(nums);

    for (auto i : nums)
        std::cout << i << ' ';
}
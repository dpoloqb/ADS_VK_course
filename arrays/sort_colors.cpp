#include <iostream>
#include <vector>

void sort_colors(std::vector<int>& nums) 
{
    size_t low = 0;
    size_t mid = 0;
    size_t high = nums.size() - 1;

    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            std::swap(nums[mid], nums[low]);
            ++mid;
            ++low;
        }
        else if (nums[mid] == 2)
        {
            std::swap(nums[mid], nums[high]);
            --high;
        }
        else
            ++mid;
    }
}

int main()
{
    int n = 0;
    std::cin >> n;
    if (n < 1)
    {
        std::cout << "Not valid array size";
        return -1;
    }

    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        std::cin >> nums[i];

    if (n > 1)
        sort_colors(nums);

    for (auto i : nums)
        std::cout << i << ' ';
}
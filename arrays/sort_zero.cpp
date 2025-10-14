#include <iostream>
#include <vector>

void sort_zero(std::vector<int>& nums) 
{
    size_t evenPointer = 0;

    for (size_t pointer = 1; pointer < nums.size(); ++pointer)
    {
        if (nums[pointer] != 0)
        {
            std::swap(nums[pointer], nums[evenPointer]);
            ++evenPointer;
        }
    }
}

int main()
{
    int n = 0;
    std::cin >> n;

    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        std::cin >> nums[i];

    sort_zero(nums);

    for (auto i : nums)
        std::cout << i << ' ';
}
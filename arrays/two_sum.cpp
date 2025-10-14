#include <iostream>
#include <vector>

void twoSum(const std::vector<int>& nums, int target) 
{
    size_t left = 0;
    size_t right = nums.size() - 1;

    while (left < right)
    {
        int sum = nums[left] + nums[right];
        if (sum == target)
        {
            std::cout << left << ' ' << right << std::endl; 
            return;
        }
        else if (sum < target)
            ++left;
        else
            --right;
    }

    std::cout << "No numbers to make a target sum";
}

int main()
{
    int len = 0;
    std::cin >> len;

    std::vector<int> nums(len);
    for (int i = 0; i < len; ++i)
        std::cin >> nums[i];
    
    int target;
    std::cin >> target;

    twoSum(nums, target);
}
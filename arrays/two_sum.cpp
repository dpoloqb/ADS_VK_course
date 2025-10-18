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
    if (len < 1)
    {
        std::cout << "Not valid array size";
        return -1;
    }

    std::vector<int> nums(len);
    for (int i = 0; i < len; ++i)
        std::cin >> nums[i];
    
    int target;
    std::cin >> target;

    if (len == 1)
    {
        if (target == nums[0])
        {
            std::cout << '0' << ' ' << "0";
            return 0;
        }
        else 
        {
            std::cout << "No numbers to make a target sum";
            return 0;
        }
    }

    twoSum(nums, target);
}
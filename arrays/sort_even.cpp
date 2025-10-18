#include <iostream>
#include <vector>

void sort_even(std::vector<int>& nums) 
{
    size_t evenPointer = 0;

    for (size_t pointer = 1; pointer < nums.size(); ++pointer)
    {
        if ((nums[pointer] % 2) == 0)
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
    if (n < 1)
    {
        std::cout << "Not valid array size";
        return -1;
    }

    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        std::cin >> nums[i];

    sort_even(nums);

    for (auto i : nums)
        std::cout << i << ' ';
}
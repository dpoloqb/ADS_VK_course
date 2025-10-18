#include <iostream>
#include <vector>

void mergeArrays(std::vector<int>& nums1, std::vector<int>& nums2) 
{
    int pointer1 = nums1.size() - nums2.size() - 1;
    int pointer2 = nums2.size() - 1;
    int pointer3 = nums1.size() - 1;

    while (pointer2 >= 0)
    {
        if ((pointer1 >= 0) && (nums1[pointer1] >= nums2[pointer2]))
        {
            nums1[pointer3] = nums1[pointer1];
            --pointer1;
        }
        else
        {
            nums1[pointer3] = nums2[pointer2];
            --pointer2;
        }
        --pointer3;
    }
}

int main()
{
    int n = 0, m = 0;
    std::cin >> n >> m;
    if (n < 1 || m < 1)
    {
        std::cout << "Not valid array size";
        return -1;
    }

    std::vector<int> nums1(n + m);
    for (int i = 0; i < n; ++i)
        std::cin >> nums1[i];

    std::vector<int> nums2(m);
    for (int i = 0; i < m; ++i)
        std::cin >> nums2[i];

    mergeArrays(nums1, nums2);

    for (auto i : nums1)
        std::cout << i << ' ';
}
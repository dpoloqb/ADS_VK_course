//isPalindrome using two-pointer method
#include <iostream>
#include <string>

bool isPalindrome(const std::string& a)
{
    int left = 0;
    int right = a.size() - 1;

    while (left != right)
    {
        if (a[left] != a[right])
            return false;
        ++left;
        --right;
    }
    
    return true;
}

int main()
{
    std::string a;
    std::cin >> a;
    
    if (a.empty())
    {
        std::cout << "Can't work with empty string";
        return 0;
    }

    if (isPalindrome(a))
        std::cout << "yes";
    else
        std::cout << "no";
}
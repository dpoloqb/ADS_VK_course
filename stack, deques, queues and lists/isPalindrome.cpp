#include <iostream>
#include <stack>
#include <string>

bool isPalindrome(const std::string& a)
{
    std::stack<char> stack;
    for (auto i : a)
        stack.push(i);

    for (auto i : a)
    {
        if (stack.top() != i)
            return false;
        stack.pop();
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
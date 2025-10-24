#include <iostream>
#include <queue>
#include <string>

bool isSubsequence(const std::string& a, const std::string& b)
{
    std::queue<char> q;
    for (auto i : a)
        q.push(i);
    
    for (auto i : b)
        if (i == q.front())
            q.pop();

    return (q.size()) == 0; 

}

int main()
{
    std::string a, b;
    std::cin >> a >> b;
    
    if (a.empty() || b.empty())
    {
        std::cout << "Can't work with empty strings";
        return 0;
    }

    if (isSubsequence(a, b))
        std::cout << "yes";
    else
        std::cout << "no";
}
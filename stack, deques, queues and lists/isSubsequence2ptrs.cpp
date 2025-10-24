/*isSubsequence using two-pointer method*/
#include <iostream>
#include <string>

bool isSubsequence(const std::string& a, const std::string& b)
{
    for (int i = 0, j = 0; j < b.size(); ++j)
    {
        if (a[i] == b[j])
        {
            ++i;
            if (i == a.size())
                return true;
        } 
    }
    return false;
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
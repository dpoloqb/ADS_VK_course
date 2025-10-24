//isPalindrome using deque
#include <iostream>
#include <string>
#include <deque>

bool isPalindrome(const std::string& a)
{
    std::deque<char> deque;
    for (auto i : a)
        deque.push_back(i);

    while (!deque.empty())
    {
        if (deque.front() != deque.back())
            return false;
        deque.pop_back();
        if (!deque.empty()) //если количество букв в слове нечётное, то эта проверка на последней итерации уберегает от удаления из пустого дэка
            deque.pop_front();
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
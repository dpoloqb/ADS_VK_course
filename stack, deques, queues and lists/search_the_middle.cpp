#include <iostream>
#include <vector>

template<typename T>
struct ListNode
{
    T data;
    ListNode<T>* next = nullptr;
    ListNode(T data_) : data (data_) {}
};

template<typename T>
class LinkedList
{
    ListNode<T>* head;
    size_t size = 0;
    const std::vector<T> values; 

public:
    LinkedList(const std::vector<T>& values_) : values (values_)
    {
        if (values.size() < 1)
            throw std::invalid_argument("Wrong list size");

        size = values.size();
        head = new ListNode<T>(values[0]);
        ListNode<T>* current = head;
        std::vector<ListNode<T>*> nodes = {head}; 

        for (size_t i = 1; i < size; ++i)
        {
            current->next = new ListNode<T>(values[i]);
            current = current->next;
            nodes.push_back(current);
        }

    }

    ListNode<T>* search_the_middle()
    {
        ListNode<T>* slow = head;
        ListNode<T>* fast = head->next;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    void print()
    {
        std::cout << "Head: " << head << " | " <<  head->data << std::endl;
        ListNode<T>* current = head->next;

        for (size_t i = 1; i < size; ++i)
        {
            std::cout << "Node " << i << ": " <<  current << " | " << current->data << std::endl;
            current = current->next;
        }

    }

    ~LinkedList()
    {
        ListNode<T>* current = head;

        for (size_t i = 0; i < size; ++i)
        {
            ListNode<T>* toDelete = current;
            current = current->next;
            delete toDelete;
        } 
    }
};

int main()
{
    size_t n;

    std::cout << "Enter list size:" << std::endl;
    std::cin >> n;

    std::vector<int> values(n);

    std::cout << "Enter values for nodes of list:" << std::endl;
    for (size_t i = 0; i < n; ++i)
        std::cin >> values[i];

    LinkedList<int> list{values};

    ListNode<int>* MiddleNode = list.search_the_middle();
    
    std::cout << "Middle of the list: " << MiddleNode << " | " << MiddleNode->data;
}
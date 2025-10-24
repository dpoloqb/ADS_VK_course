#include <iostream>
#include <vector>

template<typename T>
struct ListNode
{
    T data;
    ListNode<T>* next = nullptr;
    ListNode() {}
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
    
    void delete_list_element(T val)
    {
        ListNode<T>* dummy = new ListNode<T>();

        dummy->next = head;
        ListNode<T>* prev = dummy;
        ListNode<T>* cur = head;
        
        while (cur != nullptr)
        {
            if (cur->data == val)
            {
                ListNode<T>* deletedNode = new ListNode{*(prev)}; //узел, ->next которого является отвязанный элемент. Это нужно, чтобы удалить отвязанный элемент из списка
                //очень важно, чтобы deletedNode был именно prev, а не prev->next(удаляемый узел), тк в противном будет просто создана копия удаляемого узела, и сам узел мы не удалим
                prev->next = cur->next;
                --size;
                //сейчас cur - это то же, что и deletedNode->next. Если удалить deletedNode->next, то cur будет невалидным, поэтому нужно сдвинуть cur
                cur = cur->next;
                delete deletedNode->next;
                delete deletedNode;
            }
            else
            {
                prev = cur;
                cur = cur->next;
            }
        }
        head = dummy->next;
        delete dummy;
        if (size == values.size())
            std::cout << "There is no target element in the list" << std::endl;
    }

    bool is_empty()
        { return head == nullptr; }
    
    void print()
    {
        std::cout << "Head: " << head << " | " << head->data << std::endl;
        ListNode<T>* current = head->next;
        
        for (size_t i = 1; i < size; ++i)
        {
            std::cout << "Node " << i << ": " <<  current << " | " << current->data << std::endl;
            current = current->next;
        }
        std::cout << std::endl;
        
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

    std::cout << "Enter value, that will be deleted in the list:" << std::endl;
    int val;
    std::cin >> val;

    std::cout << "Before:" << std::endl;
    list.print();

    list.delete_list_element(val);

    
    std::cout << std::endl << "After:" << std::endl;
    if (list.is_empty())
    {
        std::cout << "The list is empty";
        return 0;
    }
    list.print();
}
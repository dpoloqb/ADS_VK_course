#include <iostream>
#include <vector>

template<typename T>
struct ListNode
{
    T data;
    ListNode<T>* next = nullptr;
    ListNode(T data_) : data (data_) {}
};

//Несмотря на то, что мой список управляет памятью и требует нетривиального определения деструктора, вопреки rule of five я не определяю копирующий и перемещающий конструкторы и операторы присваивания, тк я буду использовать один список
template<typename T>
class LinkedList
{
    ListNode<T>* head;
    size_t size = 0;
    const std::vector<T> values; //значения в узлах
    int cyclePos;

public:
    LinkedList(const std::vector<T>& values_, int cyclePos_ = -1) : values (values_), cyclePos (cyclePos_)
    {
        if (values.size() < 1)
            throw std::invalid_argument("Wrong list size");

        size = values.size();
        head = new ListNode<T>(values[0]);
        ListNode<T>* current = head;
        std::vector<ListNode<T>*> nodes = {head}; //для удобного обращения к узлу, если надо будет создать цикличность (чтобы не проходиться по списку)

        for (size_t i = 1; i < size; ++i) //заполняем список значениями
        {
            current->next = new ListNode<T>(values[i]);
            current = current->next;
            nodes.push_back(current);
        }

        if (cyclePos >= 0) //зацикливаем конец списка с указанным извне элементом (если он определён)
        {
            if (cyclePos >= size)
                cyclePos = cyclePos % size; //обработка некорректного случая

            current->next = nodes[cyclePos];
        }
    }

    bool is_cycle()
    {
        if (head == nullptr || head->next == nullptr)
            return false;
        
        ListNode<T>* slowptr = head;
        ListNode<T>* fastptr = head->next;
    
        while (slowptr != fastptr)
        {
            if (fastptr == nullptr || fastptr->next == nullptr)
                return false;
    
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }
        return true;
    }

    void print() //если вдруг понадобится
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
    int cyclePos;

    std::cout << "Enter list size:" << std::endl;
    std::cin >> n;

    std::vector<int> values(n);

    std::cout << "Enter values for nodes of list:" << std::endl;
    for (size_t i = 0; i < n; ++i)
        std::cin >> values[i];

    std::cout << "Enter position, where the list will be cycled (if you want default list, enter any negative number):" << std::endl;
    std::cin >> cyclePos;

    LinkedList<int> list{values, cyclePos};

    if (list.is_cycle())
        std::cout << "cycled";
    else
        std::cout << "not cycled";
}
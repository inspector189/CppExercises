#include <iostream>

//push_back(), insert(), remove(), print()
struct Element {

    int m_value;
    Element* m_next;

    Element(int newValue)
    {
        m_value = newValue;
        m_next = nullptr;
        std::cout << "Utworzenie Elementu\n";
    }
    ~Element()
    {
        std::cout << "Usunieto Element :(\n";
    }
};

struct List {

    Element* head = nullptr;

    ~List()
    {
        Element* current = head;
        while (current != nullptr)
        {
            Element* nextCurrent = current->m_next;
            delete current;
            current = nextCurrent;
        }
    }

    bool is_empty()
    {
        return !head;
    }

    void push_back(int newValue)
    {
        if (is_empty())
        {
            head = new Element(newValue);
        }
        else 
        {
            Element* current = head;
            while(current->m_next != nullptr)
            {
                current = current->m_next;
            }
            current->m_next = new Element(newValue);
        }
    }

    int size()
    {
        int counter = 0;
        Element* current = head;

        while (current != nullptr)
        {
            counter++;
            current = current->m_next;
        }

        return counter;
    }

    void insert(int index, int newValue)
    {
        if (index == 0)
        {
            head = new Element(newValue);
        }
        else 
        {
            int counter = 0;
            Element* current = head;

            while (current != nullptr)
            {
                if (counter == index - 1)
                {
                    Element* tail = current->m_next;
                    current->m_next = new Element(newValue);
                    current->m_next->m_next = tail;
                    return;
                }
                counter++;
                current = current->m_next;
            }
        }
    }

    void remove(int index)
    {
        if (index == 0)
        {
            Element* prevHead = head;
            head = head->m_next;
            delete prevHead;
        }
        else 
        {
            int counter = 0;
            Element* current = head;
            while (current != nullptr)
            {
                if (counter == index - 1)
                {
                    Element* prevCurrent = current->m_next;
                    current->m_next = current->m_next->m_next;
                    delete prevCurrent;
                }
                counter++;
                current = current->m_next;
            }
        }
       
    }

    void print()
    {
        Element* current = head;
        while (current != nullptr)
        {
            std::cout << current->m_value << std::endl;
            current = current->m_next;

        }
    }
};

int main()
{
    List list;
    
    //std::cout << list.is_empty()<<" ";

    list.push_back(2);
    list.push_back(3);
    list.push_back(1);

    list.insert(1, 4);

    list.remove(2);

    // std::cout << list.is_empty();
    return 0;
}



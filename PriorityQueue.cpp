#include <iostream>

struct PriorityQueue {
private:
    int size = 0;
    int* data = nullptr;
public:
    PriorityQueue()
    {
        size = 0;
        data = nullptr;
        std::cout << "PriorityQueue created!\n";
    }
    ~PriorityQueue()
    {
        delete[] data;
        std::cout << "PriorityQueue deleted!\n";
    }
    void add(int elem)
    {     
        int* new_tab = new int [size + 1];

        int i = 0;
        for (; i < size; i++)
        {
            if (data[i] < elem)
            {
                new_tab[i] = data[i];
            }
            else
            {
                break;
            }
        }
        new_tab[i] = elem;
        for (; i < size; i++)
        {
            new_tab[i + 1] = data[i];
        }

        delete[] data;
        data = new_tab;
        size++;
    }
    void remove(int elem)
    {
        int index_to_remove = -1;
        for (int i = 0; i < size; i++)
        {
            if (data[i] == elem)
            {
                index_to_remove = i;
                break;
            }
        }

        bool wasDelete = false;
        int* new_tab = new int[size - 1];
        for (int i = 0; i < size - 1; i++)
        {
            if (i == index_to_remove)
            {
                wasDelete = true;
            }
            new_tab[i] = data[i + wasDelete];
        }
        size--;
        delete[] data;
        data = new_tab;

    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << data[i] <<" ";
        }
        std::cout << std::endl;
    }
};
int main()
{
    std::cout << "Hello World!\n";

    { PriorityQueue pQ;  
        pQ.add(5);
        pQ.add(3);
        pQ.add(4);
        pQ.add(1);
        pQ.add(2);
        pQ.print();
        pQ.remove(2);
        pQ.remove(3);
        pQ.print();
    }

    return 0;
}



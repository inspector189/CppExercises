#include <iostream>

class Vector {
private:
    int* data;       
    int capacity;    
    int size;        

    void resize() {
        capacity *= 2;  
        int* newData = new int[capacity]; 
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData; 
    }

public:
    Vector() : size(0), capacity(2) {
        data = new int[capacity];
    }

    void push_back(int value) {
        if (size >= capacity) {
            resize(); 
        }
        data[size++] = value; 
    }

    void pop_back() {
        if (size > 0) {
            size--; 
        }
        else {
            std::cout << "Vector is empty. Nothing to remove." << std::endl;
        }
    }

    void print() const {
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    ~Vector() {
        delete[] data; 
    }
};

int main() {
    Vector myVector;

    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);
    myVector.push_back(40);
    myVector.push_back(50);

    std::cout << "Vector contents after push_back: ";
    myVector.print();

    myVector.pop_back();

    std::cout << "Vector contents after pop_back: ";
    myVector.print();

    return 0;
}
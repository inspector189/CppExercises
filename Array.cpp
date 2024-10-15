#include <iostream>
#include <algorithm>

class Array {
private:
    int** array = nullptr;
    int size = 0;

public:
    Array()
    {
        array = nullptr;
        size = 0;
    }  

    void push_back(int value) {
        int** newArray = new int* [size + 1];

        for (int i = 0; i < size; ++i) {
            newArray[i] = array[i];
        }

        newArray[size] = new int(value);
        size++;

        delete[] array;
        array = newArray;

        sort();
    }

    void remove(int value) {
        int indexToRemove = -1;
        for (int i = 0; i < size; ++i) {
            if (*array[i] == value) {
                indexToRemove = i;
                break;
            }
        }

        if (indexToRemove == -1) {
            std::cout << "Value not found." << std::endl;
            return;
        }

        int** newArray = new int* [size - 1];
        int j = 0;

        for (int i = 0; i < size; ++i) {
            if (i != indexToRemove) {
                newArray[j] = array[i];
                j++;
            }
            else {
                delete array[i]; 
            }
        }

        size--;

        delete[] array;
        array = newArray;
    }

    void delete_array() {
        for (int i = 0; i < size; ++i) {
            delete array[i];
        }
        delete[] array;
        array = nullptr;
        size = 0;
    }

    void sort() {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - 1 - i; ++j) {
                if (*array[j] > *array[j + 1]) {
                    int* temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }

    void print() const {
        for (int i = 0; i < size; ++i) {
            std::cout << *array[i] << " ";
        }
        std::cout << std::endl;
    }

    ~Array() {
        delete_array();
    }
};

int main() {
    Array arr;

    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(4);

    std::cout << "Array contents after push_back: ";
    arr.print();

    arr.remove(3);

    std::cout << "Array contents after removing 3: ";
    arr.print();

    arr.delete_array();
    std::cout << "Array contents after deleting array: ";
    arr.print();

    return 0;
}

#include <iostream>
#include<functional>

class Element {
    Element* m_left;
    Element* m_right;
    int m_value;
public:
    Element(int value)
    {
        m_value = value;
        m_left = nullptr;
        m_right = nullptr;
    }
    ~Element()
    {
        delete m_left;
        delete m_right;
    }
    int getValue()
    {
        return m_value;
    }
    Element* getLeft()
    {
        return m_left;
    }
    Element* getRight()
    {
        return m_right;
    }
    void setLeft(Element *left)
    {
        m_left = left;
    }
    void setRight(Element *right)
    {
        m_right = right;
    }

};


class Tree {
    Element* m_root;
    
public:
    Tree()
    {
        m_root = nullptr;
    }
    ~Tree()
    {
        delete m_root;
    }
    bool is_empty()
    {
        return !m_root;
    }
    //Dodanie elementu - przejscie po wszystkim - sprawdzenie < | > - okreslenie left/right - wycieki pamieci - size() = wskazniki/referencja;
    void addElement(int value)
    {
        if (is_empty())
        {
            m_root = new Element(value);
        }
        else 
        {
            Element* current = m_root;
            while (true)
            {
                if (value < current->getValue())
                {
                    if (!current->getLeft())
                    {
                        current->setLeft(new Element(value));
                        break;
                    }
                    else 
                    {
                        current = current->getLeft();
                    }

                }
                else 
                {
                    if (value > current->getValue())
                    {
                        if (!current->getRight())
                        {
                            current->setRight(new Element(value));
                            break;
                        }
                        else
                        {
                            current = current->getRight();
                        }
                    }
                    else 
                    {
                        break;
                    }
                }
            }
        }
    }
    void writeTree()
    {
        preorder(m_root, [](Element* elem) {std::cout << elem->getValue() << std::endl; });
    }

    int size() {
        int count = 0;
        preorder(m_root, [&count](Element* elem) {count++; });
        return count;
    }
private:
    void preorder(Element* elem, std::function<void(Element*)> func)
    {
        if (!elem)
        {
            return;
        }
        func(elem);
        preorder(elem->getLeft(), func);
        preorder(elem->getRight(), func);
    }

};


int main()
{
    Tree tree;
    tree.addElement(5);
    tree.addElement(3);
    tree.addElement(7);
    tree.addElement(2);
    tree.addElement(4);
    tree.addElement(6);
    tree.addElement(8);
    tree.addElement(1);
    tree.addElement(9);
    tree.addElement(10);
    tree.addElement(12);
    tree.addElement(11);
    tree.addElement(13);
    tree.addElement(14);
    tree.addElement(15);
    tree.writeTree();
    std::cout << "Size of the tree: " << tree.size() << std::endl;
    return 0;
}



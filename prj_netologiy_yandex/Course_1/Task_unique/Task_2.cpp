#include"Task_2.h"


#include <iostream>
#include <vector>
#include <memory>

class node
{
public:
    int m_value;
    std::weak_ptr<node> parent;//shared заменен на weak
    node(int value) : m_value{ value } {};
    ~node() { std::cout << "destructor called\n"; }
};



void Task_2() {

    {
        auto node1 = std::make_shared<node>(1);
        auto node2 = std::make_shared<node>(2);
        node1->parent = node2;
        node2->parent = node1;
    }

};
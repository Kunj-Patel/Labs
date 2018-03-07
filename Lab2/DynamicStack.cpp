#include "DynamicStack.hpp"
#include "cstdlib"
#include "iostream"

using namespace std;

typedef DynamicStack::StackItem StackItem;  // for simplicity
const StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack() //check for 16
{
    capacity_ = 16;
    init_capacity_ = 16;

    items_ = new StackItem[capacity_];
}

DynamicStack::DynamicStack(unsigned int capacity)
{
    capacity_ = capacity;
    init_capacity_ = capacity;

    items_ = new StackItem[capacity_];
}

DynamicStack::~DynamicStack()
{
    delete[]items_;
    items_ = NULL;
}

bool DynamicStack::empty() const
{
    if (items_[0] == NULL || size_ == 0)
        return true;
    return false;
}

int DynamicStack::size() const
{
    return size_;
}

void DynamicStack::push(StackItem value) //possibly use copy constructor
{
    if(size_ == capacity_)
    {
        capacity_ = capacity_ * 2;
        StackItem* upgrade = new StackItem[capacity_];

        for (int i = 0; i < init_capacity_; i++)
        {
            upgrade[i] = items_[i];
        }

        delete[]items_;
        items_ = upgrade;
        init_capacity_ = capacity_;

        for (int i = size_; i >= 0; i--) {
            upgrade[i] = upgrade[i - 1];
        }
        upgrade[0] = value;
        size_++;
    }

    else {
        for (int i = size_; i >= 0; i--) {
            items_[i] = items_[i - 1];
        }
        items_[0] = value;
        size_++;
    }
}

StackItem DynamicStack::pop() //test more
                                //test for 16
{
    int temp = items_[0];

    if (size_ == 0 || capacity_ == 0) {
        return EMPTY_STACK;
    }

    else {
        for (int i = 0; i < capacity_; i++) {
            items_[i] = items_[i + 1];
        }
        size_ = size_ - 1;

        int cap = init_capacity_ * 0.25;
        if (size_ <= cap) {
            int testCap = capacity_ / 2;
            if (testCap > init_capacity_) {
                capacity_ = capacity_ / 2;
                StackItem* upgrade = new StackItem[capacity_];

                for (int i = 0; i < init_capacity_; i++)
                {
                    upgrade[i] = items_[i];
                }

                delete[]items_;
                items_ = upgrade;
                init_capacity_ = capacity_;

            }
        }
        return temp;
    }
}

StackItem DynamicStack::peek() const
{
   int temp = items_[0];

    if (size_ == 0 || capacity_ == 0)
        return EMPTY_STACK;

    return temp;
}

void DynamicStack::print() const
{
    for (int i = 0; i < size_; i++) {
        cout << items_[i] << endl;
    }
}

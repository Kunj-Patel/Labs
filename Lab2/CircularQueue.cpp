#include<cstring>
#include<iostream>
#include "CircularQueue.hpp"
#include <cstdlib>
using namespace std;

typedef CircularQueue::QueueItem QueueItem;
const QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue()
{
	size_ = 0;
	head_ = -1;
	tail_ = -1;
	capacity_ = 16;
	
	items_ = new QueueItem[capacity_];
}

CircularQueue::CircularQueue(unsigned int capacity)
{
	size_ = 0;
	head_ = -1;
	tail_ = -1;
	capacity_ = capacity;
	
	items_ = new QueueItem[capacity_];
}

CircularQueue::~CircularQueue()
{
	delete[]items_;
	items_ = NULL;
}

bool CircularQueue::empty() const
{
	if (size_ == 0)
		return true;
	return false;
}

bool CircularQueue::full() const 
{
	if (size_ == capacity_)
		return true;
	return false;
}

int CircularQueue::size() const
{  
	return size_;
}

bool CircularQueue::enqueue(QueueItem value)
{	
	if (head_ == -1 && tail_ == -1)
	{
		head_= tail_= 0;
		items_[tail_] = value;
		size_++;
		return true;	
	}

	else

	tail_ = (tail_+1)%capacity_;
	items_[tail_] = value;
	size_++;
	return true;

	if((tail_+1)%capacity_ == head_ || size_ == capacity_)
		return false;
}

QueueItem CircularQueue::dequeue()
{	
	if(size_ != 0)
	{
		return items_[head_];
		items_[head_] = NULL;
		head_ = (head_+1)%capacity_;
		size_--;
	}

	if((head_+1)%capacity_ == tail_+1 || size_ == 0)
		size_--;
		return EMPTY_QUEUE;
}

QueueItem CircularQueue::peek() const
{
	if((head_+1)%capacity_ == tail_+ 1 || size_ == 0)
		return EMPTY_QUEUE;
	return items_[head_];
}

void CircularQueue::print() const
{
	if (size_ == 0)
		cout << EMPTY_QUEUE;
	
	while (head_ != tail_)  
		cout << items_[head_];
		head_ == (head_+1)%capacity_;
}

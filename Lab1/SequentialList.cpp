// .cpp files contain code definitions for methods that have been declared
// in the according .hpp file. The skeleton has been set up here for you.
// That is, the methods have been initiated, and your mission, should you 
// choose to accept it (which you should for marks), is to fill in each method
// with the appropriate code.
//
// A note about the "::" syntax: generally, this means "the thing on the right
// belongs to the thing on the left." So, SequentialList::empty() means the method
// empty() belongs to the class SequentialList. This allows empty() to access (and
// potentially change) the member variables in class SequentialList.

#include "SequentialList.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

// This is the constructor.
SequentialList::SequentialList(unsigned int cap)
{
	if(cap < 0)        
		capacity_ = 0;
	capacity_ = cap;
	size_ = 0;
	data_ = new DataType[capacity_];
}

SequentialList::~SequentialList()
{
	delete[]data_;
	data_ = NULL;
}

bool SequentialList::empty() const
{
	if(capacity_ == 0 || size_ == 0)
		return true;
	return false;
}

unsigned int SequentialList::size() const
{	
	return size_;
}

unsigned int SequentialList::capacity() const	
{
	return capacity_;
}

bool SequentialList::full() const				
{
	if (size_ == capacity_)
		return true;
	return false;
}

void SequentialList::print() const
{
	if(capacity_ == 0)
		cout << "List cannot hold any data b/c capacity is 0.";
		
	for(int i = 0; i < capacity_; i++)
		cout << data_[i] << endl;
}

// NOTE on inserts: do NOT grow the array if we reach capacity. Simply return false.
bool SequentialList::insert_front(DataType val)
{
	if(size_ == capacity_)
		return false;
	
	for(int i = size_; i >= 0; i--)
	{
		data_[i] = data_[i-1];
	}

	data_[0] = val;
	size_++;
	
	return true;
}

bool SequentialList::remove_front()
{	
	if(size_ == 0 || capacity_ == 0)
		return false;

	for(int i = 0; i < capacity_; i++)
	{
		data_[i] = data_[i+1];
	}
	size_= size_-1;
	
	return true;
}

bool SequentialList::insert_back(DataType val)
{
	if(size_ == capacity_)
		return false;

	data_[size_] = val;
	size_++;
	
	return true;
}

bool SequentialList::remove_back()
{
	if(size_ == 0 || capacity_==0)
		return false;
	
	data_[size_-1] = NULL;
	size_= size_-1;
	
	return true;
}

bool SequentialList::insert(DataType val, unsigned int index)
{
	if(index > capacity_ || index < 0 || index > size_)
		return false;
	
	data_[index] = val;
	return true;
}

bool SequentialList::remove(unsigned int index)
{
	if(size_ == 0 || capacity_==0)
		return false;
	
	data_[index] = NULL;
	
	for(int i = index; i < capacity_; i++)
	{
		data_[i] = data_[i+1];
	}
	size_= size_-1;
	
	return true;
}

unsigned int SequentialList::search(DataType val) const
{
	if(size_ == 0 || capacity_== 0 )
		return false;
	
	for(int loc = 0; loc < capacity_; loc++)
		if (data_[loc] == val)
			return loc;
			
	return size_;
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
	if(size_ == 0 || capacity_==0)
		return false;
	
	if(index < capacity_ && index >= 0)
		return data_[index];
		return true;
		
	cout << "Index is out of bounds. Value in last element is: ";
	return data_[capacity_-1];
}

bool SequentialList::replace(unsigned int index, DataType val)
{
	if(size_ == 0 || capacity_==0)
		return false;
		
	if(index < capacity_ && index >= 0)
		data_[index] = val;
	
	return true;
}

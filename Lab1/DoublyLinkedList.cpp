#include "DoublyLinkedList.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

DoublyLinkedList::Node::Node(DataType data)
{
	value = data;
	next = NULL;
	prev = NULL;
}

DoublyLinkedList::DoublyLinkedList()
{
	size_ = 0;
	head_= NULL;
	tail_= NULL;
}

DoublyLinkedList::~DoublyLinkedList()	//Fix - currently causes program to crash
{
//	Node* destroy;
//	destroy = head_;
//	
//	while(head_ -> next != NULL)
//	{
//		head_-> next;
//	}
//	
//	delete destroy;
//	destroy = head_;
}

bool DoublyLinkedList::empty() const
{
	if(size_== 0)
		return true; 
	return false;
}

unsigned int DoublyLinkedList::size() const
{
	return size_;
}

void DoublyLinkedList::print() const
{
	Node* temp;
	if(head_)
	{
		temp = head_;
		while(temp != NULL)
		{
			cout << temp -> value << endl;
			temp = temp -> next;
		}
	}
	
	else 
	cout << "List is empty";
}

bool DoublyLinkedList::insert_front(DataType value)
{		
	if( size_ < 0 || size_ == CAPACITY)
		return false;
		
	Node *addNode;
	addNode = new Node(value);
	addNode -> next = head_;
	
	if (size_== 0)
	{
		tail_ = addNode;
		head_ = addNode;
		size_++;
	}
	
	else
	{
		head_ -> prev = addNode;
		head_ = addNode;
		size_++;
	}
	return true;
}

bool DoublyLinkedList::remove_front()
{
	if(size_ == 0)
		return false;
		
	if (size_ == 1)
	{
		Node* lastNode = head_;
		//head_ = lastNode -> next;
		head_ = NULL;
		tail_ = NULL;
	
		delete lastNode;
		lastNode -> prev = NULL;
		lastNode -> next = NULL;
		size_--;
	}
	
	else
	{
		Node* lastNode = head_;
		head_ = lastNode -> next;
		head_ -> prev = NULL;
		delete lastNode;
		size_--;
	}
	return true;
}

bool DoublyLinkedList::insert_back(DataType value)
{
	if( size_ < 0 || size_ == CAPACITY)
		return false;
	
	Node *addNode;
	addNode = new Node(value);
	addNode -> prev = tail_;
	
	if (size_ == 0)
	{
		head_ = addNode;
		tail_ = addNode;
		size_++;
	}
	
	else
	{
		tail_ -> next = addNode;
		tail_ = addNode;
		size_++;
	}
	return true;
}

bool DoublyLinkedList::remove_back()
{
	if (size_ == 0)
		return false;
		
	if (size_ == 1)
	{
		Node* lastNode = tail_;
		tail_ = lastNode -> prev;
		head_ = NULL;
		delete lastNode;
		size_--;
	}
	
	else
	{
		Node* lastNode = tail_;
		tail_ = lastNode -> prev;
		tail_ -> next = NULL;
		delete lastNode;
		size_--;
	}
	return true;
}

bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
	
	if( size_ < 0 || size_ == CAPACITY)
		return false;
	
	Node* insert;
	insert = new Node(value);
	
	Node* temp1;
	temp1 = head_;
	
	Node* temp2;
	temp2 = head_;
	
	for(int i = 0; i < index-1; i++)
		temp1 -> next;
	
	for(int k = 0; k < index+1; k++)
		temp2 -> next;
	
	temp1 -> next = insert;
	insert -> prev = temp1;
	temp2 -> prev = insert;
	insert -> next = temp2; 
	
	size_++;
	return true;
}

bool DoublyLinkedList::remove(unsigned int index) //Test and Fix
{
	if(size_ == 0)
		return false;
		
	Node* remove;
	remove = head_;
	
	Node* temp1;
	temp1 = head_;
	
	Node* temp2;
	temp2 = head_;
	
	for(int i = 0; i < index; i++)
		remove -> next;
	
	for(int j = 0; j < index-1; j++)
		temp1 -> next;
	
	for(int k = 0; k < index+1; k++)
		temp2 -> next;
	
	delete remove;
	remove = NULL;
	
	temp1 -> next = temp2;
	temp2 -> prev = temp1;
	
	size_--;
	return true;
}

unsigned int DoublyLinkedList::search(DataType value) const   //Test and fix
{
	Node* search;
	search = head_;
	int index = 0;
	
	for (int i = 0 ; i < size_; i++)
	{
		if(search -> value == value)
			return index;
	
		index ++;
		search = search -> next;
	}
	return size_;
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const //Test and fix
{
	Node* temp;
	temp = head_;
	
	for (int i = 0; i<index; i++)
	{
		if(temp -> next == NULL)
			return temp -> value;
		temp = temp -> next;
	}
	
	return temp -> value;	
}

bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
	if (size_ == 0)
		return false;
	
	Node* temp;
	temp  = head_;
	
	for (int i = 0; i <index; i++)
		temp -> next;
	
	temp -> value = value;
	temp = NULL;
	return true;
}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
	Node* temp;
	temp = head_;
	
	for(int i = 0; i < index; i++)
		temp -> next;
}

bool DoublyLinkedList::full() const
{
	if (size_ == CAPACITY)
		return true;
	return false;
}

unsigned int DoublyLinkedList::capacity() const
{
	return CAPACITY;
} 

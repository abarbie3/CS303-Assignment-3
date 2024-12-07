#include <iostream>
#include <stdexcept>
using namespace std;
#pragma once

//create struct with pointers and data for the linked list
template<typename Item_Type>
struct Node {
	Item_Type data;
	Node* next;
	Node(const Item_Type& item, Node* next_ptr = nullptr) :
		data(item), next(next_ptr) {}
};

//Queue created with a linked list
template<typename Item_Type>
class queue {
private:
	Node<Item_Type>* front_of_queue;
	Node<Item_Type>* back_of_queue;
	size_t num_items;
public:
	queue(); //constructor
	~queue(); //destructor
	void push(const Item_Type& item); //push value onto the queue
	void pop(); //remove the value at the front of the queue
	const Item_Type& front() const; //return the front of the queue
	size_t size() const; //return the size of the queue
	bool empty() const; //return if the queue is empty or not
	void print_list(); //display what's in theq queue
	void move_to_rear(); //move the first value of the queue to the end of the queue
};
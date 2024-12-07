#include "Q1Function.h"

//constructor
template<typename Item_Type>
queue<Item_Type>::queue() {
	front_of_queue = nullptr;
	back_of_queue = nullptr;
	num_items = 0;
}

//destructor
template<typename Item_Type>
queue<Item_Type>::~queue() {
	while (!empty()) {
		pop();
	}
}

//push value onto the queue
template<typename Item_Type>
void queue<Item_Type>::push(const Item_Type& item) {
	Node<Item_Type>* new_node = new Node<Item_Type>(item);
	if (empty()) {
		front_of_queue = back_of_queue = new_node;
	}
	else {
		back_of_queue->next = new_node;
		back_of_queue = new_node;
	}
	num_items++;
}

//remove the value at the front of the queue
template<typename Item_Type>
void queue<Item_Type>::pop() {
	if (empty()) {
		throw out_of_range("Queue is empty");
	}
	Node<Item_Type>* old_front = front_of_queue;
	front_of_queue = front_of_queue->next;
	if (front_of_queue == nullptr) {
		back_of_queue = nullptr;
	}
	delete old_front;
	num_items--;
}

//return the front of the queue
template<typename Item_Type>
const Item_Type& queue<Item_Type>::front() const {
	if (empty())
		throw out_of_range("Queue is empty");
	return front_of_queue->data;
}

//return the size of the queue
template<typename Item_Type>
size_t queue<Item_Type>::size() const {
	return num_items;
}

//return if the queue is empty or not
template<typename Item_Type>
bool queue<Item_Type>::empty() const { 
	return front_of_queue == nullptr;
}

//display what's in the queue
template<typename Item_Type>
void queue<Item_Type>::print_list() {

	Node<Item_Type>* current_ptr = front_of_queue;
	while (current_ptr) {
		cout << current_ptr->data <<  " ";
		current_ptr = current_ptr->next;
	}
	cout << endl;
}

//move the first value of the queue to the end of the queue
template<typename Item_Type>
void  queue<Item_Type>::move_to_rear() {
	if (empty()) {
		return;
	}

	Item_Type temp = front(); 
	pop(); 
	push(temp); 
}

template class queue<int>;

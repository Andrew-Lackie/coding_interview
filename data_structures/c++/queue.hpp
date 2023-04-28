#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "linked_list.hpp"

class Queue {
	private:
	 LinkedList lList;

	public:
	 int size() {
		 return lList.getSize();
	 }

	 bool isEmpty() {
		 return size() == 0;
	 }

	 int peek() {
		 return lList.peek();
	 }

	 int dequeue() {
		 return lList.dropNode();
	 }

	 void enqueue(int elem) {
		 return lList.appendNode(elem);
	 }

	 Queue(int elem) {

	 };


};

#endif

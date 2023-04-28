#ifndef STACK_HPP
#define STACK_HPP

#include "linked_list.hpp"

class Stack {
	private:
	 LinkedList lList;

	public:
	 int size() {
		 return lList.getSize();
	 }

	 bool isEmpty() {
		 return size() == 0;
	 }

	 void push(int elem) {
		 lList.pushNode(elem);
	 }

	 int pop() {
		 return lList.popNode();
	 }

	 int peek() {
		 return lList.peek();
	 }

	 Stack(int elem) {
		 push(elem);
	 };


};

#endif

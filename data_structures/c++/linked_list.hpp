#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>

using namespace std;

struct Node {
	struct Node *next;
	int data;
};

class LinkedList {
	protected:
		int size;
		Node *head;
		Node *tail;

	public:
		LinkedList() {
			head = nullptr;
			tail = nullptr;
		}

		void printList() {
			Node *curr = head;

			while (curr != nullptr) {
				cout << curr->data << '\n';
				curr = curr->next;
			}
		}

		int peek() {
			if (head == nullptr) {
				return -1;
			}

			return head->data;
		}

		int getSize() {
			Node *curr = head;

			while (curr != nullptr) {
				size++;
			}

			return size;
		}

		void appendNode(int value) {
			Node *temp = new Node;
			temp->data = value;
			temp->next = nullptr;

			if (head == nullptr) {
				head = temp;
				tail = temp;
			}

			else {
				tail->next = temp;
				tail = temp;
			}
		}

		void pushNode(int value) {
			Node *temp = new Node;
			temp->data = value;
			temp->next = nullptr;

			if (head == nullptr) {
				head = temp;
				tail = temp;
			}

			else {
				temp->next = head;
				head = temp;
			}
		}

		void insertNode(int position, int value) {
			Node *prev = new Node;
			Node *curr = new Node;
			Node *temp = new Node;
			curr = head;

			for (int i = 0; i < position - 1; i++) {
				prev = curr;
				curr = curr->next;
			}

			temp->data = value;
			temp->next = curr;
			prev->next = temp;
		}

		int dropNode() {

			int retval = 0;

			if (head == nullptr) {
				return -1;
			}

			else if (head->next == nullptr) {
				retval = head->data;
				delete head;

				return retval;
			}

			else {

				Node *curr = new Node;
				while (curr->next->next != nullptr) {
					curr = curr->next;
				}

				retval = curr->next->data;
				delete curr->next;
				curr->next = nullptr;

				return retval;
			}

		}

		int popNode() {

			int retval = 0;
			Node *temp = new Node;

			if (head == nullptr) {
				return -1;
			}

			else {

				temp = head->next;
				retval = head->data;

				head = temp;
				delete temp;

				return retval;
			}
		}

		int removeNode(int position) {
			int retval = 0;

			if (head == nullptr) {
				return -1;
			}

			else if (position == 0) {
				return popNode();
			}

			else {
				Node *curr = head;
				Node *temp = nullptr;

				for (int i = 0; i < position - 1; i++) {

					if (curr->next == nullptr) {
						return -1;
					}
					curr = curr->next;
				}

				curr = temp->next;
				retval = temp->data;
				curr->next = temp->next;
				delete temp;

				return retval;
			}
		}
};

#endif

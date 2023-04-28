#ifndef BST_H
#define BST_H

#include <iostream>

using namespace std;

class Node {
	public:
		struct Node *left;
		struct Node *right;
		int data;

		Node(int d) {
			data = d;
			left = nullptr;
			right = nullptr;
		}
};

class BinarySearchTree {
	private:
		int nodeCount = 0;
		Node *root = nullptr;

	public:

		int size() {
			return nodeCount;
		}

		bool isEmpty() {
			return size() == 0;
		}

		Node* search(Node *node, int key) {
			if (node == nullptr || node->data == key) {
				return root;
			}

			if (node->data < key) {
				return search(node->right, key);
			}

			else {
				return search(root->left, key);
			}

		}

		Node* insert(Node* node, int data) {
			if (node == nullptr) {
				return new Node(data);
			}

			else {
				Node* curr;

				if (data <= node->data) {
					curr = insert(node->left, data);
					node->left = curr;
				}
				else {
					curr = insert(node->right, data);
					node->right = curr;
				}
			}

			return node;
		}

		Node* deleteNode(Node* node, int k) {
			if (node == nullptr) {
				return node;
			}

			if (node->data > k) {
				node->left = deleteNode(node->left, k);
				return node;
			}

			else if (node->data < k) {
				node->right = deleteNode(node->right, k);
			}

			if (node->left == nullptr) {
				Node* temp = node->right;
				delete node;

				return temp;
			}

			else if (node->right == nullptr) {
				Node* temp = node->left;
				delete root;

				return temp;
			}

			else {
				Node* parent = node;

				Node *succ = node->right;
				while (succ->left != nullptr) {
					parent = succ;
					succ = succ->left;
				}

				if (parent != node) {
					parent->left = succ->right;
				}
				else {
					parent->right = succ->right;
				}

				node->data = succ->data;

				delete succ;
				return node;
			}
		}
};

#endif

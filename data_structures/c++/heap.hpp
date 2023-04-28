#ifndef BINARY_HEAP_HPP
#define BINARY_HEAP_HPP

#include <iostream>

using namespace std;

class BinaryHeap {
	private:
		const static int MAX_SIZE = 15;
		int heap[MAX_SIZE];
		int size;

	public:
		BinaryHeap() {
			size = 0;
		}

		static int parent(int i) {
			return (i - 1) / 2;
		}

		static int leftChild(int i) {
			return 2*i + 1;
		}

		static int rightChild(int i) {
			return 2*i + 2;
		}

		static void swap(int *x, int *y) {
			int temp = *x;
			*x = *y;
			*y = temp;
		}

		void insert(int data) {
			if (size >= MAX_SIZE) {
				cout << "The heap is full." << '\n';
			}

			heap[size] = data;
			size = size + 1;

			int i = size - 1;
			while (i != 0 && heap[BinaryHeap::parent(i)] < heap[i]) {
				BinaryHeap::swap(&heap[BinaryHeap::parent(i)], &heap[i]);
				i = BinaryHeap::parent(i);
			}
		}

		void maxHeapify(int i) {
			int left = BinaryHeap::leftChild(i);

			int right = BinaryHeap::rightChild(i);

			int largest = i;

			if (left <= size && heap[left] > heap[largest]) {
					largest = left;
			}

			if (right <= size && heap[right] > heap[largest]) {
					largest = right;
			}

			if (largest != i) {
					int temp = heap[i];
					heap[i] = heap[largest];
					heap[largest] = temp;
					maxHeapify(largest);
			}

		}

		int getMax() {
			return heap[0];
		}

		int removeMax() {
			int maxItem = heap[0];

			heap[0] = heap[size - 1];
			size = size - 1;

			maxHeapify(0);
			return maxItem;
		}
};

#endif

#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP

#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		vector<int> sortArray(vector<int>& arr) {

			for (size_t i = 0; i < arr.size(); i++) {
				for (size_t j = 0; j < arr.size() - i - 1; j++) {
					if (arr[j] > arr[j + 1]) {
						int temp;
						temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
					}
				}
			}
			return arr;
		}
};

#endif

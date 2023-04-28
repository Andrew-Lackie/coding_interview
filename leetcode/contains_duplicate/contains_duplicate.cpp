#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
	public:

// Brute force solution

		bool containsDuplicateBruteForce(vector<int>& nums) {
			bool value = false;
			for (size_t i = 0; i < nums.size(); i++) {
				for (size_t j = i + 1; j < nums.size(); j++) {
					if (nums[i] == nums[j]) {
						value = true;
					}
				}
			}

			return value;
		}

// Sorting and loop

		bool containsDuplicateSort(vector<int>& nums) {
			sort(nums.begin(), nums.end());

			bool flag = false;

			for (size_t i = 0; i < nums.size() - 1; i++) {
				if (nums[i] == nums[i + 1]) return true;
				else
					flag = false;
			}

			return flag;
		}
};

int main() {

	Solution solution;

	vector<int> nums = {1, 2, 3, 1};

	//bool value = solution.containsDuplicateBruteForce(nums);
	bool value = solution.containsDuplicateSort(nums);

	if (value) {
		cout << "true";
	}

	else {
		cout << "false";
	}

}

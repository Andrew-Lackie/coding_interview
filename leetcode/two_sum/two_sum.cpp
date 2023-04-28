#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {

			vector<int> arr = {};

		// Loop over the array twice and check whether there is a solution

			for (size_t i = 0; i < nums.size(); i++) {
				for (size_t j = 0; j < nums.size(); j++) {


					if (nums[i] + nums[j] == target) {

		// Ignore entries where a value added to itself is a solution

						if (i == j) {
							continue;
						}

		// If the indicies are different then return and array with them

						else {
							arr = {static_cast<int>(i), static_cast<int>(j)};
							return arr;
						}
					}
				}
			}

		// If no solution is found, return an empty array

		return arr;
		}
};

int main() {

	// Create a solution object

	Solution solution;

	// Create a vector

	vector<int> nums = {2, 7, 11, 15};

	// Call the method using the array and target

	vector<int> arr = solution.twoSum(nums, 9);

	// Loop through the array returned by the method and print the indices

	cout << "[";

	for (size_t i = 0; i < arr.size(); i++) {
		cout << arr[i];
		if (i != arr.size() - 1) {
			cout << ',';
		}
	}

	cout << "]" << '\n';

}

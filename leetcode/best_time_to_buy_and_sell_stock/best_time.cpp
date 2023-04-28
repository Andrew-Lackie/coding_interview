#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:

		int maxProfit(vector<int>& prices) {

			int maxProfit = 0;
			for (size_t i = 0; i < prices.size() - 1; i++) {
				for (size_t j = i + 1; j < prices.size(); j++) {
					if (prices[j] - prices[i] > maxProfit) {
						maxProfit = prices[j] - prices[i];
					}
				}
			}

			return maxProfit;
		}
};

int main() {
	Solution solution;

	vector<int> arr = {7, 1, 5, 3, 6, 4};

	int profit = solution.maxProfit(arr);

	cout << profit;
}

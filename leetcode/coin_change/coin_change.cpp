#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

	public:
		int addCoin(vector<int>& coins, int amount, int coin) {

			if (amount > 0) {
				return coin + addCoin(coins, amount % coin, coin + 1);
			}
			else {
				return 0;
			}
		}

		int coinChange(vector<int>& coins, int amount) {
			sort(coins.begin(), coins.end());

			int coin_count = addCoin(coins, amount, coins[coins.size() - 1]);

			return coin_count;
		}
};

int main() {

	Solution solution;

	vector<int> coins = {1, 5, 10};

	int coin_count = solution.coinChange(coins, 100);

	cout << coin_count;

}

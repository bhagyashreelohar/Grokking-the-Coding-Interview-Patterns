/*
Problem Statement:
=============================
Given an array of characters where each character represents a fruit tree,
you are given two baskets, and your goal is to put maximum number of fruits
in each basket. The only restriction is that each basket can have only one type of fruit.

You can start with any tree, but you can’t skip a tree once you have started.
You will pick one fruit from each tree until you cannot, i.e., you will stop
when you have to pick from a third fruit type.

Write a function to return the maximum number of fruits in both baskets.


Example:
=============================
Input: Fruit=['A', 'B', 'C', 'A', 'C']
Output: 3
Explanation: We can put 2 'C' in one basket and one 'A' in the other from the subarray ['C', 'A', 'C']

Time Complexity:
=============================
Time complexity of the algorithm will be O(N+N), which is asymptotically equivalent to O(N).

Space Complexity:
=============================
The algorithm runs in constant space O(1).

*/

using namespace std;

#include<iostream>
#include<unordered_map>
#include<vector>


class FruitesIntoBaskets {
	public:
	static int findMaxFruits(const vector<char>& arr) {
		int windowStart = 0, windowEnd = 0;
		int maxLength = 0;
		unordered_map<char, int> baskets;

		for (windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
			int fruit = arr[windowEnd];
			baskets[fruit]++;

			while(baskets.size() > 2) {
				fruit = arr[windowStart];
				baskets[fruit]--;
				if (baskets[fruit] == 0) {
					baskets.erase(fruit);
				}

				windowStart++;
			}

			maxLength = max(maxLength, windowEnd - windowStart + 1);
		}

		return maxLength;
	}
};

int main(int argc, char* argv[]) {
	cout << "Maximum number of fruits: "
		<< FruitesIntoBaskets::findMaxFruits(vector<char>{'A', 'B', 'C', 'A', 'C'}) << endl;
	cout << "Maximum number of fruits: "
		<< FruitesIntoBaskets::findMaxFruits(vector<char>{'A', 'B', 'C', 'B', 'B', 'C'}) << endl;

}

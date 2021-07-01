/*
Problem Statement:
=============================
Given an array of positive numbers and a positive number ‘S,’ find the length of
the smallest contiguous subarray whose sum is greater than or equal to ‘S’.
Return 0 if no such subarray exist.

Example:
=============================
Input: [2, 1, 5, 2, 3, 2], S=7 
Output: 2
Explanation: The smallest subarray with a sum greater than or equal to '7' is [5, 2]


Time Complexity:
=============================
The time complexity of the above algorithm will be O(N). The outer for loop runs
for all elements, and the inner while loop processes each element only once; therefore,
the time complexity of the algorithm will be O(N+N),
which is asymptotically equivalent to O(N).

Space Complexity:
=============================
The algorithm runs in constant space O(1).

*/

using namespace std;

#include<iostream>
#include<limits>
#include<vector>

class SmallSizeSubArraySum {
	public:
	static int findSmallSubArraiSize(int S, const vector<int>& arr) {
		int windowSum = 0, windowStart = 0;
		int windowSize = numeric_limits<int>::max();

		for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
			windowSum += arr[windowEnd];

			while (windowSum >= S) {
				windowSize = min(windowSize, windowEnd - windowStart + 1);
				windowSum -= arr[windowStart];
				windowStart++;
			}

		}
		return windowSize == numeric_limits<int>::max() ? 0 : windowSize;
	}
};

void check_result(int subArraySize) {
	if (subArraySize == 0) {
		cout << "SubArray does not exists." << endl;
		return;
	}
	cout << "Smallest subarray length: " << subArraySize << endl;
}

int main(int argc, char* argv[]) {
	int smallSubArraySize;

	// Test Case 1:
	smallSubArraySize = SmallSizeSubArraySum::findSmallSubArraiSize(7, vector<int>{2, 1, 5, 2, 3, 2});
	check_result(smallSubArraySize);

	// Test Case 1:
	smallSubArraySize = SmallSizeSubArraySum::findSmallSubArraiSize(7, vector<int>{2, 1, 5, 2, 8});
	check_result(smallSubArraySize);
	
	// Test Case 3:
	smallSubArraySize = SmallSizeSubArraySum::findSmallSubArraiSize(8, vector<int>{1, 1, 0, 0, 5});
	check_result(smallSubArraySize);
}


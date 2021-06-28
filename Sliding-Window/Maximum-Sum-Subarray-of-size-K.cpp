/*
Problem Statement:
	Given an array of positive numbers and a positive number ‘k,’ find the maximum sum
        of any contiguous subarray of size ‘k’.

Example:

Input: [2, 1, 5, 1, 3, 2], k=3 
Output: 9
Explanation: Subarray with maximum sum is [5, 1, 3].


Time Complexity:
	The time complexity of the above algorithm will be O(N). 
	The for loop runs for all elements therefore the time complexity of the algorithm will be O(N).

Space Complexity:
	The algorithm runs in constant space O(1).


*/

using namespace std;

#include<iostream>
#include<vector>

class MaximumSumSubarrayOfSizeK {
	public:
	static int findMaxSumSubarray(uint64_t k, const vector<int>& arr) {
		int maxSum = 0, windowSum = 0;
		int windowStart = 0;

		for (uint64_t windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
			windowSum += arr[windowEnd];

			if (windowEnd >= k - 1) {
				maxSum = max(maxSum, windowSum);
				windowSum -= arr[windowStart];
				windowStart++;
			}
		}
		return maxSum;
	}
};

int main(int argc, char* argv[]) {
	int result;
	result  = MaximumSumSubarrayOfSizeK::findMaxSumSubarray(3, vector<int> {1, 3, 4, 6, 1, 4, 1, 8, 2});
	cout << "Result : " << result << endl;

	result = MaximumSumSubarrayOfSizeK::findMaxSumSubarray(2, vector<int> {2, 1, 5, 1, 3, 2});
	cout << "Result : " << result << endl;
}

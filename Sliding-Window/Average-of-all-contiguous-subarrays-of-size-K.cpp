/*
Problem Statement:
Given an array, find the average of all contiguous subarrays of size ‘K’ in it.

Example:

Input: Array=[1, 3, 2, 6, -1, 4, 1, 8, 2], K=5
Output: [2.2, 2.8, 2.4, 3.6, 2.8]
Explanation:

Let’s solve this:

1. For the first 5 numbers (subarray from index 0-4), the average is: (1+3+2+6-1)/5 => 2.2
2. The average of next 5 numbers (subarray from index 1-5) is: (3+2+6-1+4)/5 => 2.8
3. For the next 5 numbers (subarray from index 2-6), the average is: (2+6-1+4+1)/5 => 2.4
4. So on…


Time Complexity:
	The time complexity of the above algorithm will be O(N). 
	The for loop runs for all elements therefore the time complexity of the algorithm will be O(N).

Space Complexity:
	The algorithm runs in constant space O(ArraySize - windowSize + 1).

*/

using namespace std;

#include <iostream>
#include <vector>

class AverageofSubArrayOfSizeK {
	public:
	static vector<double> findAverage(uint64_t k, const vector<int>& arr) {
		vector<double> result(arr.size() - k + 1);
		double windowSum = 0.0;
		int windowStart = 0;
		for (uint64_t windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
			windowSum += arr[windowEnd];

			if (windowEnd >= k - 1) {
				result[windowStart] = windowSum / k;
				windowSum -= arr[windowStart];
				windowStart += 1;
			}
		}
		return result;
	}
};

int main(int argc, char* argv[]) {
	
	vector<double> result = AverageofSubArrayOfSizeK::findAverage(5, vector<int> {1, 3, 2, 6, -1, 4, 1, 8, 2});
	for (double d : result) {
		cout << d << " ";
	}
	cout << endl;
}

/*
Problem Statement:
=============================
Given a string, find the length of the longest substring, which has no repeating characters.

Example:
=============================
Input: String="aabccbb"
Output: 3
Explanation: The longest substring without any repeating characters is "abc".

Time Complexity:
=============================
The above algorithm’s time complexity will be O(N), where ‘N’ is the number
of characters in the input string.

Space Complexity:
=============================
The algorithm runs in constant space O(1).

*/

using namespace std;

#include<iostream>
#include<unordered_map>

class LogestSubString {
	public:
	static int findMaxLength(string S) {
		int windowEnd, windowStart = 0;
		int maxLength = 0;
		unordered_map<char, int> hashMap;

		for (windowEnd = 0; windowEnd < S.length(); windowEnd++) {
			char c = S[windowEnd];
			if (hashMap.find(c) != hashMap.end()) {
				windowStart = max(windowStart, hashMap[c] + 1);
			}
			hashMap[c] = windowEnd;
			maxLength = max(maxLength, windowEnd - windowStart + 1);
		}

		return max(maxLength, windowEnd - windowStart);
	}
};

int main(int argc, char* argv[]) {
	int maxLength;

	maxLength = LogestSubString::findMaxLength("aabccbb");
	cout << "Length of the longest substring: " << maxLength << endl;

	maxLength = LogestSubString::findMaxLength("abbbb");
	cout << "Length of the longest substring: " << maxLength << endl;

	maxLength = LogestSubString::findMaxLength("abcfde");
	cout << "Length of the longest substring: " << maxLength << endl;
}

/*
Problem Statement:
=============================
Given a string, find the length of the longest substring in it with no more than K distinct characters.
You can assume that K is less than or equal to the length of the given string.

Example:
=============================
Input: String="araaci", K=2
Output: 4
Explanation: The longest substring with no more than '2' distinct characters is "araa".

Time Complexity:
=============================
The time complexity of the algorithm will be O(N+N), which is asymptotically equivalent to O(N).

Space Complexity:
=============================
The algorithm runs in constant space O(1).

*/

using namespace std;

#include<iostream>
#include<unordered_map>

class SmallSubStringKDistinct {
	public:
	static int findLength(int K, const string& S) {
		int windowStart = 0, maxLength = 0;
		unordered_map<char, int> hash_map;

		for(int windowEnd = 0; windowEnd < S.length(); windowEnd++) {
			char rightChar = S[windowEnd];
			hash_map[rightChar]++;

			while((int)hash_map.size() > K) {
				char leftChar = S[windowStart];
				hash_map[leftChar]--;
				if (hash_map[leftChar] == 0) {
					hash_map.erase(leftChar);
				}
				windowStart++;
			}
			maxLength = max(maxLength, windowEnd - windowStart + 1);
		}

		return maxLength;
	}
};


int main(int argc, char* argv[]) {
	cout << "Length of the longest substring: " << SmallSubStringKDistinct::findLength(2, "araaci")
		<< endl;

	cout << "Length of the longest substring: " << SmallSubStringKDistinct::findLength(1, "araaci")
		<< endl;

	cout << "Length of the longest substring: " << SmallSubStringKDistinct::findLength(3, "cbbebi")
		<< endl;
}

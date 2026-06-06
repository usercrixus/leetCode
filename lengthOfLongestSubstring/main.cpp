#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <iostream>

class Solution {
public:
	int lengthOfLongestSubstring(std::string s)
	{
		std::vector<int> lastSeen(256, -1);
		int max = 0;
		int start = 0;
		for (int i = 0; i < s.length(); i++)
		{
			start = std::max(start, lastSeen[s[i]] + 1);
			max = std::max(max, i - start + 1);
			lastSeen[s[i]] = i;
		}
		return max;
	}
};

int main()
{
	Solution s;
	std::string t = "abcabcbb";
	std::cout << "result " << s.lengthOfLongestSubstring(t) << std::endl;
	std::cout << "expected : 3" << std::endl;
}
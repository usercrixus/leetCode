#include <string>
#include <iostream>

class Solution {
public:
    std::string getPalindrome(const std::string &s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return s.substr(left + 1, right - 1 - left);
    }

    std::string longestPalindrome(std::string s)
    {
        int i = 0;
        std::string res = "";
        while (i < s.length())
        {
            std::string odd = getPalindrome(s, i, i);
            std::string even = getPalindrome(s, i, i + 1);
            if (odd.size() > res.size())
                res = odd;
            if (even.size() > res.size())
                res = even;
            i++;
        }
        return res;
    }
};

int main()
{
    std::string test = "babad";
    Solution s;
    std::cout << s.longestPalindrome(test) << std::endl;
}
